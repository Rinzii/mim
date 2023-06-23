// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/internal/setup.hpp"

#if MIM_SIMD_AVX512F
	#include <immintrin.h>
#elif MIM_SIMD_AVX2
	#include <immintrin.h>
#elif MIM_SIMD_AVX
	#include <immintrin.h>
#elif MIM_SIMD_SSE4_2
	#if MIM_COMPILER_CLANG
		#include <popcntintrin.h>
	#endif
	#include <nmmintrin.h>
#elif MIM_SIMD_SSE4_1
	#include <smmintrin.h>
#elif MIM_SIMD_SSSE3
	#include <tmmintrin.h>
#elif MIM_SIMD_SSE3
	#include <pmmintrin.h>
#elif MIM_SIMD_SSE2
	#include <emmintrin.h>
#elif MIM_SIMD_SSE
	#include <xmmintrin.h>
#elif MIM_SIMD_NEON
	#include "neon.h"
#endif

#if MIM_SIMD_SSE2
using mim_f32vec4 = __m128;
using mim_i32vec4 = __m128i;
using mim_u32vec4 = __m128i;
using mim_f64vec4 = __m128d;
using mim_i64vec4 = __m128i;
using mim_u64vec4 = __m128i;

using mim_vec4 = mim_f32vec4;
using mim_ivec4 = mim_i32vec4;
using mim_uvec4 = mim_u32vec4;
using mim_dvec4 = mim_f64vec4;
#endif

#if MIM_SIMD_AVX
using mim_f64vec4 = __m256d;
using mim_dvec4 = mim_f64vec4;
#endif

#if MIM_SIMD_AVX2
using mim_i64vec4 = __m256i;
using mim_u64vec4 = __m256i;
#endif

// TODO: Add support for AVX512F once I have a CPU that supports it.
#if MIM_SIMD_AVX512F
using mim_i128vec4 = __m512i;
using mim_u128vec4 = __m512i;
#endif

#if MIM_SIMD_NEON
using mim_f32vec4 = float32x4_t;
using mim_i32vec4 = int32x4_t;
using mim_u32vec4 = uint32x4_t;
#endif
