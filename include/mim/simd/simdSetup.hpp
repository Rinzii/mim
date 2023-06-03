// Copyright WizWorks, Inc. All Rights Reserved.

#pragma once

#include "system/core.hpp"


#if RIOT_SIMD_AVX512F
    #include <immintrin.h>
#elif RIOT_SIMD_AVX2
    #include <immintrin.h>
#elif RIOT_SIMD_AVX
    #include <immintrin.h>
#elif RIOT_SIMD_SSE4_2
    #if RIOT_COMPILER_CLANG
        #include <popcntintrin.h>
    #endif
    #include <nmmintrin.h>
#elif RIOT_SIMD_SSE4_1
    #include <smmintrin.h>
#elif RIOT_SIMD_SSSE3
    #include <tmmintrin.h>
#elif RIOT_SIMD_SSE3
    #include <pmmintrin.h>
#elif RIOT_SIMD_SSE2
    #include <emmintrin.h>
#elif RIOT_SIMD_SSE
    #include <xmmintrin.h>
#elif RIOT_SIMD_NEON
    #include "neon.h"
#endif


#if RIOT_SIMD_SSE2
    using riot_f32vec4 =    __m128;
    using riot_i32vec4 =    __m128i;
    using riot_u32vec4 =    __m128i;
    using riot_f64vec4 =    __m128d;
    using riot_i64vec4 =    __m128i;
    using riot_u64vec4 =    __m128i;

    using riot_vec4 =       riot_f32vec4;
    using riot_ivec4 =      riot_i32vec4;
    using riot_uvec4 =      riot_u32vec4;
    using riot_dvec4 =      riot_f64vec4;
#endif

#if RIOT_SIMD_AVX
    using riot_f64vec4 =    __m256d;
    using riot_dvec4 =      riot_f64vec4;
#endif

#if RIOT_SIMD_AVX2
    using riot_i64vec4 =    __m256i;
    using riot_u64vec4 =    __m256i;
#endif

// TODO: Add support for AVX512F once I have a CPU that supports it.
#if RIOT_SIMD_AVX512F
    using riot_i128vec4 =   __m512i;
    using riot_u128vec4 =   __m512i;
#endif

#if RIOT_SIMD_NEON
    using riot_f32vec4 =    float32x4_t;
    using riot_i32vec4 =    int32x4_t;
    using riot_u32vec4 =    uint32x4_t;
#endif



