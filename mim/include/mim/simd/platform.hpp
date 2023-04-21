#pragma once

// Check for AVX2 support
#if defined(__AVX2__)
    #define MIM_HAS_AVX2 1
#else
    #define MIM_HAS_AVX2 0
#endif

// Check for AVX support
#if defined(__AVX__)
    #define MIM_HAS_AVX 1
#else
    #define MIM_HAS_AVX 0
#endif

// Check for SSE4.2 support
#if defined(__SSE4_2__)
    #define MIM_HAS_SSE4_2 1
#else
    #define MIM_HAS_SSE4_2 0
#endif

// Check for SSE4.1 support
#if defined(__SSE4_1__)
    #define MIM_HAS_SSE4_1 1
#else
    #define MIM_HAS_SSE4_1 0
#endif

// Check for SSE3 support
#if defined(__SSE3__)
    #define MIM_HAS_SSE3 1
#else
    #define MIM_HAS_SSE3 0
#endif

// Check for SSE2 support
#if defined(__SSE2__)
    #define MIM_HAS_SSE2 1
#else
    #define MIM_HAS_SSE2 0
#endif