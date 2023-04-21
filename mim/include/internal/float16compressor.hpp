// This code is heavily inspired by the code found here:
// https://gist.github.com/rygorous/2156668

#ifndef MIM_FLOAT16COMPRESSOR_H
#define MIM_FLOAT16COMPRESSOR_H

#include <cstdint>

namespace mim 
{
	class Float16Compressor 
	{
	protected:
		union FloatBits 
		{
			float fl;
			int32_t sint;
			uint32_t uint;
		};

		static int32_t const shift = 13;	 				// mantissa bits: 13, exponent bits: 16
		static int32_t const shiftSign = 16; 				// sign bits: 1, left shift amount: 15

		static int32_t const inf32 = 0x7F800000;  			// FP32 infinity bit pattern
		static int32_t const max32 = 0x477FE000;  			// max FP16 normal as a FP32 bit pattern
		static int32_t const min32 = 0x38800000;  			// min FP16 normal as a FP32 bit pattern
		static int32_t const sign32 = 0x80000000; 			// FP32 sign bit pattern

		static int32_t const inf16 = inf32 >> shift;	   	// FP16 infinity bit pattern
		static int32_t const nan16 = (inf16 + 1) << shift; 	// min FP16 NaN as a FP32 bit pattern
		static int32_t const max16 = max32 >> shift;	   	// max FP16 normal bit pattern
		static int32_t const min16 = min32 >> shift;	   	// min FP16 normal bit pattern
		static int32_t const sign16 = sign32 >> shiftSign; 	// FP16 sign bit pattern

		static int32_t const mul32to16 = 0x52000000; 		// multiplier to convert FP32 to FP16
		static int32_t const mul16to32 = 0x33800000; 		// multiplier to convert FP16 to FP32

		static int32_t const sub32 = 0x003FF; 				// maximum float32 subnormal value, down shifted
		static int32_t const nor32 = 0x00400; 				// minimum float32 normal value, down shifted

		static int32_t const maxDiff = inf16 - max16 - 1; 	// diff. between max FP16 normal and infinity
		static int32_t const minDiff = min16 - sub32 - 1;  	// diff. between min FP16 normal and max float32 subnormal


	public:
		static uint16_t Compress(float value) 
		{
			FloatBits value_bits, shift_bits;
			value_bits.fl = value;

			// Extract the sign of the floating-point number.
			uint32_t sign_bits = value_bits.sint & sign32;
			value_bits.sint ^= sign_bits;
			sign_bits >>= shiftSign; // logical shift

			// Calculate the shifted bits of the floating-point number.
			shift_bits.sint = mul32to16;
			shift_bits.sint = (int32_t)(shift_bits.fl * value_bits.fl); // correct subnormals

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
			return (uint16_t)(value_bits.uint | sign_bits);
		}

		static float Decompress(uint16_t compressed_value) 
		{
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

	};
}

#endif // MIM_FLOAT16COMPRESSOR_H
