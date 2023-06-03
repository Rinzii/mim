// Copyright WizWorks, Inc. All Rights Reserved.

#pragma once

#include "system/core.hpp"
#include "math/internal/setup.hpp"
#include "math/simd/simdSetup.hpp"

namespace mim
{

    enum qualifier
    {
        packed_highp,
        packed_mediump,
        packed_lowp,

#if defined(RIOT_SIMD)
        aligned_highp,
        aligned_mediump,
        aligned_lowp,
        aligned = aligned_highp,
#endif

        highp = packed_highp,
        mediump = packed_mediump,
        lowp = packed_lowp,
        packed = packed_highp,

#if defined(RIOT_SIMD)
        defaultp = aligned_highp,
#else
        defaultp = packed_highp,
#endif
    };

    using precision = qualifier;

    template<size_t S, typename T, qualifier Q = defaultp> struct VectorT;
    template<size_t C, size_t R, typename T, qualifier Q = defaultp> struct MatrixT;
    template<typename T, qualifier Q = defaultp> struct QuaternionT;

    namespace detail
    {
        template <riot::qualifier P>
        struct IsAligned
        {
            static const bool value = false;
        };

#if RIOT_SIMD
        template <>
        struct IsAligned<riot::aligned_highp>
        {
            static const bool value = true;
        };

        template <>
        struct IsAligned<riot::aligned_mediump>
        {
            static const bool value = true;
        };

        template <>
        struct IsAligned<riot::aligned_lowp>
        {
            static const bool value = true;
        };
#endif

        template<size_t S, typename T, bool is_aligned>
        struct Storage
        {
            using type = struct Type
            {
                T data[S];
            };
        };

#if !defined(RIOT_COMPILER_NO_ALIGNOF)
        template<size_t S, typename T>
        struct Storage<S, T, true>
        {
            using type = struct alignas(S * sizeof(T)) Type
            {
                T data[S];
            };
        };

        template<typename T>
        struct Storage<3, T, true>
        {
            using type = struct alignas(4 * sizeof(T)) Type
            {
                T data[4];
            };
        };
#endif

#if RIOT_SIMD_SSE2

        template<>
        struct Storage<4, float, true>
        {
            using type = riot_f32vec4;
        };

        template<>
        struct Storage<4, int32_t, true>
        {
            using type = riot_i32vec4;
        };

        template<>
        struct Storage<4, uint32_t, true>
        {
            using type = riot_u32vec4;
        };

        template<>
        struct Storage<2, double, true>
        {
            using type = riot_f32vec2;
        };

        template<>
        struct Storage<2, int64_t, true>
        {
            using type = riot_i64vec2;
        };

        template<>
        struct Storage<2, uint64_t, true>
        {
            using type = riot_u64vec2;
        };
#endif
#if RIOT_SIMD_AVX
        template<>
        struct Storage<4, double, true>
        {
            using type = riot_f64vec4;
        };
#endif
#if RIOT_SIMD_AVX2
        template<>
        struct Storage<4, int64_t, true>
        {
            using type = riot_i64vec4;
        };

        template<>
        struct Storage<4, uint64_t, true>
        {
            using type = riot_u64vec4;
        };
#endif
#if RIOT_SIMD_NEON

        template<>
        struct Storage<4, float, true>
        {
            using type = riot_f32vec4;
        };

        template<>
        struct Storage<4, int32_t, true>
        {
            using type = riot_i32vec4;
        };

        template<>
        struct Storage<4, uint32_t, true>
        {
            using type = riot_u32vec4;
        };
#endif

    } // namespace detail
} // namespace riot
