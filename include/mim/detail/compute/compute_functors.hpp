// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"

namespace mim
{
    namespace detail
    {
        template<template<std::size_t S, typename T, qualifier Q> class VectorT, std::size_t S, typename R, typename T, qualifier Q>
        struct functor1{};

        template<template<std::size_t S, typename T, qualifier Q> class VectorT, typename R, typename T, qualifier Q>
        struct functor1<VectorT, 1, R, T, Q>
        {
            constexpr static VectorT<1, R, Q> compute(R (*Func) (T x), VectorT<1, T, Q> const& v)
            {
                return VectorT<1, R, Q>(Func(v.x));
            }
        };

        template<template<std::size_t S, typename T, qualifier Q> class VectorT, typename R, typename T, qualifier Q>
        struct functor1<VectorT, 2, R, T, Q>
        {
            constexpr static VectorT<2, R, Q> compute(R (*Func) (T x), VectorT<2, T, Q> const& v)
            {
                return VectorT<2, R, Q>(Func(v.x), Func(v.y));
            }
        };

        template<template<std::size_t S, typename T, qualifier Q> class VectorT, typename R, typename T, qualifier Q>
        struct functor1<VectorT, 3, R, T, Q>
        {
            constexpr static VectorT<3, R, Q> compute(R (*Func) (T x), VectorT<3, T, Q> const& v)
            {
                return VectorT<3, R, Q>(Func(v.x), Func(v.y), Func(v.z));
            }
        };

        template<template<std::size_t S, typename T, qualifier Q> class VectorT, typename R, typename T, qualifier Q>
        struct functor1<VectorT, 4, R, T, Q>
        {
            constexpr static VectorT<4, R, Q> compute(R (*Func) (T x), VectorT<4, T, Q> const& v)
            {
                return VectorT<4, R, Q>(Func(v.x), Func(v.y), Func(v.z), Func(v.w));
            }
        };

        template<template<std::size_t S, typename T, qualifier Q> class VectorT, std::size_t S, typename R, typename T, qualifier Q>
        struct functor2{};

        template<template<std::size_t S, typename T, qualifier Q> class VectorT, typename R, typename T, qualifier Q>
        struct functor2<VectorT, 1, R, T, Q>
        {
            constexpr static R compute(R (*Func) (T x, T y), VectorT<1, T, Q> const& v1, VectorT<1, T, Q> const& v2)
            {
                return Func(v1.x, v2.x);
            }
        };

        template<template<std::size_t S, typename T, qualifier Q> class VectorT, typename R, typename T, qualifier Q>
        struct functor2<VectorT, 2, R, T, Q>
        {
            constexpr static VectorT<2, R, Q> compute(R (*Func) (T x, T y), VectorT<2, T, Q> const& v1, VectorT<2, T, Q> const& v2)
            {
                return VectorT<2, R, Q>(Func(v1.x, v2.x), Func(v1.y, v2.y));
            }
        };

        template<template<std::size_t S, typename T, qualifier Q> class VectorT, typename R, typename T, qualifier Q>
        struct functor2<VectorT, 3, R, T, Q>
        {
            constexpr static VectorT<3, R, Q> compute(R (*Func) (T x, T y), VectorT<3, T, Q> const& v1, VectorT<3, T, Q> const& v2)
            {
                return VectorT<3, R, Q>(Func(v1.x, v2.x), Func(v1.y, v2.y), Func(v1.z, v2.z));
            }
        };

        template<template<std::size_t S, typename T, qualifier Q> class VectorT, typename R, typename T, qualifier Q>
        struct functor2<VectorT, 4, R, T, Q>
        {
            constexpr static VectorT<4, R, Q> compute(R (*Func) (T x, T y), VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2)
            {
                return VectorT<4, R, Q>(Func(v1.x, v2.x), Func(v1.y, v2.y), Func(v1.z, v2.z), Func(v1.w, v2.w));
            }
        };


    }

} // namespace mim
