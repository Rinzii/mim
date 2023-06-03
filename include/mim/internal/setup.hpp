// Copyright WizWorks, Inc. All Rights Reserved.

#ifndef RIOT_MATH_SETUP_HPP

#include <cassert>
#include <cstddef>

#define RIOT_MATH_VERSION_MAJOR 0
#define RIOT_MATH_VERSION_MINOR 1
#define RIOT_MATH_VERSION_PATCH 0

#define RIOT_MATH_VERSION (RIOT_MATH_VERSION_MAJOR * 100) + (RIOT_MATH_VERSION_MINOR * 10) + (RIOT_MATH_VERSION_PATCH)

#define RIOT_MATH_SETUP_HPP RIOT_MATH_VERSION


#define RIOT_MATH_DISABLE   0
#define RIOT_MATH_ENABLE    1


#include "system/config/Compiler.hpp"
#include "system/config/CompilerTraits.hpp"
#include "system/config/Platform.hpp"
#include "system/config/Architecture.hpp"

#include <cstdint>
#include <type_traits>



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



#if defined(RIOT_SIMD)
#define RIOT_MATH_SIMD RIOT_MATH_ENABLE
#else
#define RIOT_MATH_SIMD RIOT_MATH_DISABLE
#endif



#define RIOT_MATH_HIGHP		1
#define RIOT_MATH_MEDIUMP	2
#define RIOT_MATH_LOWP		3




#endif // RIOT_MATH_SETUP_HPP
