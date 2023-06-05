// Copyright (c) 2023-Present Mim contributors (see LICENSE.txt)

#pragma once

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <type_traits>

// System Detection
#include "mim/internal/config/architecture.hpp"
#include "mim/internal/config/compiler.hpp"
#include "mim/internal/config/compiler_features.hpp"
#include "mim/internal/config/compiler_traits.hpp"
#include "mim/internal/config/platform.hpp"


// Active states
#define MIM_DISABLE   0
#define MIM_ENABLE    1



namespace riot
{
    namespace detail
    {

        template<typename T>
        struct IsInt
        {
            enum test
            {
                value = 0
            };
        };

        template<>
        struct IsInt<unsigned int>
        {
            enum test
            {
                value = ~0
            };
        };

        template<>
        struct IsInt<signed int>
        {
            enum test
            {
                value = ~0
            };
        };
    } // namespace detail

    using uint = unsigned int;
} // namespace riot



#if defined(MIM_SIMD)
    #define MIM_SIMD MIM_ENABLE
#else
    #define MIM_SIMD MIM_DISABLE
#endif





