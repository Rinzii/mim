// Copyright (c) 2023-Present Mim contributors (see LICENSE)

// This code is heavily inspired by the code found here:
// https://gist.github.com/rygorous/2156668

#pragma once

#include <cstdint>

#include "mim/internal/setup.hpp"

// Disable warnings for conversion from float to int
MIM_ENABLE_IGNORE_GCC_WARNING(-Wconversion)

#if defined(MIM_ARCH_SSE2)
#include <emmintrin.h>
#endif

namespace mim {
class Float16Compressor {
  protected:
	union FloatBits {
		float fl;
		int32_t sint;
		uint32_t uint;
	};

	static int32_t constexpr shift = 13;	 // mantissa bits: 13, exponent bits: 16
	static int32_t constexpr shiftSign = 16; // sign bits: 1, left shift amount: 15

	static int32_t constexpr inf32 = 0x7F800000;  // FP32 infinity bit pattern
	static int32_t constexpr max32 = 0x477FE000;  // max FP16 normal as a FP32 bit pattern
	static int32_t constexpr min32 = 0x38800000;  // min FP16 normal as a FP32 bit pattern
	static int32_t constexpr sign32 = 0x80000000; // FP32 sign bit pattern

	static int32_t constexpr inf16 = inf32 >> shift;	   // FP16 infinity bit pattern
	static int32_t constexpr nan16 = (inf16 + 1) << shift; // min FP16 NaN as a FP32 bit pattern
	static int32_t constexpr max16 = max32 >> shift;	   // max FP16 normal bit pattern
	static int32_t constexpr min16 = min32 >> shift;	   // min FP16 normal bit pattern
	static int32_t constexpr sign16 = sign32 >> shiftSign; // FP16 sign bit pattern

	static int32_t constexpr mul32to16 = 0x52000000; // multiplier to convert FP32 to FP16
	static int32_t constexpr mul16to32 = 0x33800000; // multiplier to convert FP16 to FP32

	static int32_t constexpr sub32 = 0x003FF; // maximum float32 subnormal value, down shifted
	static int32_t constexpr nor32 = 0x00400; // minimum float32 normal value, down shifted

	static int32_t constexpr maxDiff = inf16 - max16 - 1; // diff. between max FP16 normal and infinity
	static int32_t constexpr minDiff = min16 - sub32 - 1; // diff. between min FP16 normal and max float32 subnormal

  public:
	static uint16_t Compress(float value) {
		FloatBits value_bits, shift_bits;
		value_bits.fl = value;

		// Extract the sign of the floating-point number.
		uint32_t sign_bits = value_bits.sint & sign32;
		value_bits.sint ^= sign_bits;
		sign_bits >>= shiftSign; // logical shift

		// Calculate the shifted bits of the floating-point number.
		shift_bits.sint = mul32to16;
		shift_bits.sint = static_cast<int32_t>(shift_bits.fl * value_bits.fl); // correct subnormals

		// Adjust the floating-point number's bits based on certain conditions.
		value_bits.sint ^= (shift_bits.sint ^ value_bits.sint) & -(min32 > value_bits.sint);
		value_bits.sint ^= (inf32 ^ value_bits.sint) & -((inf32 > value_bits.sint) & (value_bits.sint > max32));
		value_bits.sint ^= (nan16 ^ value_bits.sint) & -((nan16 > value_bits.sint) & (value_bits.sint > inf32));

		// Shift the floating-point number's bits.
		value_bits.uint >>= shift; // logical shift

		// Further adjust the floating-point number's bits based on certain conditions.
		value_bits.sint ^= ((value_bits.sint - maxDiff) ^ value_bits.sint) & -(value_bits.sint > max16);
		value_bits.sint ^= ((value_bits.sint - minDiff) ^ value_bits.sint) & -(value_bits.sint > sub32);

		// Combine the sign and bits of the compressed number and return it.
		return static_cast<uint16_t>(value_bits.uint | sign_bits);
	}

	static float Decompress(uint16_t compressed_value) {
		FloatBits compressed_bits;
		compressed_bits.uint = compressed_value;

		// Extract the sign of the compressed value.
		int32_t sign_bits = compressed_bits.sint & sign16;
		compressed_bits.sint ^= sign_bits;
		sign_bits <<= shiftSign;

		// Adjust the bits of the compressed value based on certain conditions.
		compressed_bits.sint ^= ((compressed_bits.sint + minDiff) ^ compressed_bits.sint) & -(compressed_bits.sint > sub32);
		compressed_bits.sint ^= ((compressed_bits.sint + maxDiff) ^ compressed_bits.sint) & -(compressed_bits.sint > max16);

		FloatBits shift_bits;
		shift_bits.sint = mul16to32;

		// Calculate the shifted bits of the compressed value.
		shift_bits.fl *= compressed_bits.sint;

		// Mask out the bits of the compressed value that are not significant.
		int32_t mask_bits = -(nor32 > compressed_bits.sint);

		// Shift the compressed value's bits.
		compressed_bits.sint <<= shift;

		// Adjust the bits of the compressed value based on certain conditions.
		compressed_bits.sint ^= (shift_bits.sint ^ compressed_bits.sint) & mask_bits;

		// Combine the sign and bits of the decompressed number and return it.
		compressed_bits.sint |= sign_bits;
		return compressed_bits.fl;
	}

#if defined(RIOT_ARCH_SSE2)
	// main part taken from https://gist.github.com/rygorous/2156668
	static inline __m128i CompressSSE(__m128 f) {
		__m128i mask_sign = _mm_set1_epi32(0x80000000u);
		__m128i mask_round = _mm_set1_epi32(~0xfffu);
		__m128i c_f32infty = _mm_set1_epi32(255 << 23);
		__m128i c_magic = _mm_set1_epi32(15 << 23);
		__m128i c_nanbit = _mm_set1_epi32(0x200);
		__m128i c_infty_as_fp16 = _mm_set1_epi32(0x7c00);
		__m128i c_clamp = _mm_set1_epi32((31 << 23) - 0x1000);

		__m128 msign = _mm_castsi128_ps(mask_sign);
		__m128 justsign = _mm_and_ps(msign, f);
		__m128i f32infty = c_f32infty;
		__m128 absf = _mm_xor_ps(f, justsign);
		__m128 mround = _mm_castsi128_ps(mask_round);
		__m128i absf_int = _mm_castps_si128(absf); // pseudo-op, but val needs to be copied once so count as mov
		__m128i b_isnan = _mm_cmpgt_epi32(absf_int, f32infty);
		__m128i b_isnormal = _mm_cmpgt_epi32(f32infty, _mm_castps_si128(absf));
		__m128i nanbit = _mm_and_si128(b_isnan, c_nanbit);
		__m128i inf_or_nan = _mm_or_si128(nanbit, c_infty_as_fp16);

		__m128 fnosticky = _mm_and_ps(absf, mround);
		__m128 scaled = _mm_mul_ps(fnosticky, _mm_castsi128_ps(c_magic));
		__m128 clamped = _mm_min_ps(scaled, _mm_castsi128_ps(c_clamp)); // logically, we want PMINSD on "biased", but this should gen better code
		__m128i biased = _mm_sub_epi32(_mm_castps_si128(clamped), _mm_castps_si128(mround));
		__m128i shifted = _mm_srli_epi32(biased, 13);
		__m128i normal = _mm_and_si128(shifted, b_isnormal);
		__m128i not_normal = _mm_andnot_si128(b_isnormal, inf_or_nan);
		__m128i joined = _mm_or_si128(normal, not_normal);

		__m128i sign_shift = _mm_srli_epi32(_mm_castps_si128(justsign), 16);
		__m128i final = _mm_or_si128(joined, sign_shift);

		// make output the same layout as _mm_cvtps_ph
		__m128i tmp_lo = _mm_shufflelo_epi16(final, _MM_SHUFFLE(2, 0, 2, 0));
		__m128i tmp_hi = _mm_shufflehi_epi16(tmp_lo, _MM_SHUFFLE(2, 0, 2, 0));

		__m128i output = _mm_and_si128(_mm_shuffle_epi32(tmp_hi, _MM_SHUFFLE(0, 0, 2, 0)), _mm_setr_epi32(0xFFFFFFFF, 0xFFFFFFFF, 0, 0));

		return output;
	}

#endif
	MIM_DISABLE_IGNORE_GCC_WARNING

};
} // namespace mim
