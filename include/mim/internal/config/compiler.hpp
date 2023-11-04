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

// We assume implicit C++17 support with mim.

/// MIM_COMPILER_CPP20_ENABLED
#if !defined(MIM_COMPILER_CPP20_ENABLED) && defined(__cplusplus)
	#if (__cplusplus >= 202002L)
		#define MIM_COMPILER_CPP20_ENABLED 1
	#elif defined(_MSVC_LANG) && (_MSVC_LANG >= 202002L) // C++20+
		#define MIM_COMPILER_CPP20_ENABLED 1
	#endif
#endif

#if !defined(MIM_COMPILER_CPP23_ENABLED) && defined(__cplusplus)
	#if (__cplusplus >= 202300L) # TODO: This is a place holder till C++23 has an offical version number.
		#define MIM_COMPILER_CPP23_ENABLED 1
	#elif defined(_MSVC_LANG) && (_MSVC_LANG >= 202300L) // C++23+
		#define MIM_COMPILER_CPP23_ENABLED 1
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
