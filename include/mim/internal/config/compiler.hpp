// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

/*
 * Currently supported defines include:
 *      MIM_COMPILER_MSVC
 *      MIM_COMPILER_GCC
 *      MIM_COMPILER_CLANG
 *      MIM_COMPILER_CLANG_CL
 *
 *      MIM_COMPILER_VERSION = <integer>
 *      MIM_COMPILER_NAME = <string>
 *      MIM_COMPILER_STRING = <string>
 */

// TODO: I'd like to add support for CUDA and HIP based compilers at some point.

// Note: This is used to generate the MIM_COMPILER_STRING macros
#ifndef INTERNAL_STRINGIFY
	#define INTERNAL_STRINGIFY(x) INTERNAL_PRIMITIVE_STRINGIFY(x)
#endif
#ifndef INTERNAL_PRIMITIVE_STRINGIFY
	#define INTERNAL_PRIMITIVE_STRINGIFY(x) #x
#endif

/// MIM_COMPILER_CPP11_ENABLED
#if !defined(MIM_COMPILER_CPP11_ENABLED) && defined(__cplusplus)
	#if (__cplusplus >= 201103L) // Clang and GCC defines this like so in C++11 mode.
		#define MIM_COMPILER_CPP11_ENABLED 1
	#elif defined(__GNUC__) && defined(__GXX_EXPERIMENTAL_CXX0X__)
		#define MIM_COMPILER_CPP11_ENABLED 1
	#elif defined(_MSC_VER) && _MSC_VER >= 1600 // Microsoft unilaterally enables its C++11 support; there is no way to disable it.
		#define MIM_COMPILER_CPP11_ENABLED 1
	#endif
#endif

/// MIM_COMPILER_CPP14_ENABLED
#if !defined(MIM_COMPILER_CPP14_ENABLED) && defined(__cplusplus)
	#if (__cplusplus >= 201402L) // Clang and GCC defines this like so in C++14 mode.
		#define MIM_COMPILER_CPP14_ENABLED 1
	#elif defined(_MSC_VER) && (_MSC_VER >= 1900) // VS2015+
		#define MIM_COMPILER_CPP14_ENABLED 1
	#endif
#endif

/// MIM_COMPILER_CPP17_ENABLED
#if !defined(MIM_COMPILER_CPP17_ENABLED) && defined(__cplusplus)
	#if (__cplusplus >= 201703L)
		#define MIM_COMPILER_CPP17_ENABLED 1
	#elif defined(_MSVC_LANG) && (_MSVC_LANG >= 201703L) // C++17+
		#define MIM_COMPILER_CPP17_ENABLED 1
	#endif
#endif

/// MIM_COMPILER_CPP20_ENABLED
#if !defined(MIM_COMPILER_CPP20_ENABLED) && defined(__cplusplus)
	#if (__cplusplus >= 202002L)
		#define MIM_COMPILER_CPP20_ENABLED 1
	#elif defined(_MSVC_LANG) && (_MSVC_LANG >= 202002L) // C++20+
		#define MIM_COMPILER_CPP20_ENABLED 1
	#endif
#endif

// Clang's GCC-compatible driver.
#if defined(__clang__) && !defined(_MSC_VER)
	#define MIM_COMPILER_CLANG 1
	#define MIM_COMPILER_VERSION (__clang_major__ * 100 + __clang_minor__)
	#define MIM_COMPILER_NAME "clang"
	#define MIM_COMPILER_STRING MIM_COMPILER_NAME __clang_version__

// GCC (a.k.a. GNUC)
#elif defined(__GNUC__) // GCC compilers exist for many platforms.
	#define MIM_COMPILER_GCC 1
	#define MIM_COMPILER_GNUC 1
	#define MIM_COMPILER_VERSION (__GNUC__ * 1000 + __GNUC_MINOR__)
	#define MIM_COMPILER_NAME "GCC"
	#define MIM_COMPILER_STRING MIM_COMPILER_NAME " compiler, version " INTERNAL_STRINGIFY(__GNUC__) "." INTERNAL_STRINGIFY(__GNUC_MINOR__)

#elif defined(_MSC_VER)
	#define MIM_COMPILER_MSVC 1
	#define MIM_COMPILER_MICROSOFT 1
	#define MIM_COMPILER_VERSION _MSC_VER
	#define MIM_COMPILER_NAME "Microsoft Visual C++"
	#define MIM_COMPILER_STRING MIM_COMPILER_NAME " compiler, version " INTERNAL_STRINGIFY(_MSC_VER)

	#if defined(__clang__)
		// Clang's MSVC-compatible driver.
		#define MIM_COMPILER_CLANG_CL 1
	#endif

#endif
