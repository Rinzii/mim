// Copyright (c) 2023-Present Mim contributors (see LICENSE.txt)

#pragma once

#include <cassert>
#include <cstddef>
#include <type_traits>

// System Detection
#include "mim/internal/config/architecture.hpp"
#include "mim/internal/config/compiler_traits.hpp"
#include "mim/internal/config/platform.hpp"

// Active states
#define MIM_DISABLE 0
#define MIM_ENABLE 1

#ifndef MIM_HAS_EXTENDED_INTEGER_TYPES
#if MIM_COMPILER_CPP11_ENABLED
#define MIM_HAS_EXTENDED_INTEGER_TYPES MIM_ENABLE
#else
#define MIM_HAS_EXTENDED_INTEGER_TYPES MIM_DISABLE
#endif
#endif

#if MIM_HAS_EXTENDED_INTEGER_TYPES
#include <cstdint>
#endif

namespace mim {
namespace detail {
#if MIM_HAS_EXTENDED_INTEGER_TYPES
typedef std::uint8_t u8;
typedef std::int8_t i8;
typedef std::uint16_t u16;
typedef std::int16_t i16;
typedef std::uint32_t u32;
typedef std::int32_t i32;
typedef std::uint64_t u64;
typedef std::int64_t i64;

#elif (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) // C99 has 64 bit types available
typedef uint8_t u8;
typedef int8_t i8;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint64_t u64;
typedef int64_t i64;
#elif MIM_COMPILER_MSVC && (MIM_COMPILER_MSVC >= 1300)			   // VC7.0 and later
typedef unsigned __int8 u8;
typedef signed __int8 i8;
typedef unsigned __int16 u16;
typedef signed __int16 i16;
typedef unsigned __int32 u32;
typedef signed __int32 i32;
typedef unsigned __int64 u64;
typedef signed __int64 i64;
#elif MIM_COMPILER_GCC && (MIM_COMPILER_GCC >= 30400)			   // GCC 3.4 and later
#pragma GCC diagnostic ignored "-Wlong-long"
__extension__ typedef unsigned char u8;
__extension__ typedef signed char i8;
__extension__ typedef unsigned short u16;
__extension__ typedef signed short i16;
__extension__ typedef unsigned int u32;
__extension__ typedef signed int i32;

__extension__ typedef unsigned long long u64;
__extension__ typedef signed long long i64;
#elif MIM_COMPILER_CLANG && MIM_COMPILER_CLANG >= 209 // Clang 2.9 and later
#pragma clang diagnostic ignored "-Wc++11-long-long"
typedef unsigned char u8;
typedef signed char i8;
typedef unsigned short u16;
typedef signed short i16;
typedef unsigned int u32;
typedef signed int i32;
typedef unsigned long long u64;
typedef signed long long i64;
#else // unknown compiler
typedef unsigned char u8;
typedef signed char i8;
typedef unsigned short u16;
typedef signed short i16;
typedef unsigned int u32;
typedef signed int i32;
typedef unsigned long long u64;
typedef signed long long i64;
#endif
} // namespace detail
} // namespace mim

namespace riot {
namespace detail {

template <typename T>
struct IsInt {
	enum test { value = 0 };
};

template <>
struct IsInt<unsigned int> {
	enum test { value = ~0 };
};

template <>
struct IsInt<signed int> {
	enum test { value = ~0 };
};
} // namespace detail

using uint = unsigned int;
} // namespace riot

#if defined(MIM_SIMD)
#define MIM_SIMD MIM_ENABLE
#else
#define MIM_SIMD MIM_DISABLE
#endif
