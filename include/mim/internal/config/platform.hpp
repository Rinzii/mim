// Copyright (c) 2023-Present Mim contributors (see LICENSE.txt)

#pragma once

// Reference for all preprocessor macros used here
// https://sourceforge.net/p/predef/wiki/OperatingSystems/
// https://gcc.gnu.org/onlinedocs/cpp/Predefined-Macros.html
// https://learn.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=msvc-170

// Cygwin
// This is a pseudo-platform which will be defined along with MIM_PLATFORM_LINUX when
// using the Cygwin build environment.
#if defined(__CYGWIN__)
#define MIM_PLATFORM_CYGWIN 1
#define MIM_PLATFORM_DESKTOP 1
#endif

// MinGW
// This is a pseudo-platform which will be defined along with RIOT_PLATFORM_WINDOWS when
// using the MinGW Windows build environment.
#if defined(__MINGW32__) || defined(__MINGW64__)
#define MIM_PLATFORM_MINGW 1
#define MIM_PLATFORM_DESKTOP 1
#endif

#if defined(_WIN32) || defined(__WIN32__) || defined(_WIN64)
#ifdef MIM_PLATFORM_WINDOWS
#undef MIM_PLATFORM_WINDOWS
#endif
#define MIM_PLATFORM_WINDOWS 1

#ifdef _WIN64 // VC++ defines both _WIN32 and _WIN64 when compiling for Win64.
#define MIM_PLATFORM_WINDOWS_64 1
#else
#define MIM_PLATFORM_WINDOWS_32 1
#endif

// We assume a Windows device is a desktop device
#ifdef MIM_PLATFORM_DESKTOP
#undef MIM_PLATFORM_DESKTOP
#endif

#define MIM_PLATFORM_DESKTOP 1

#elif defined(__APPLE__) || defined(__MACH__)
#include <TargetConditionals.h>

// Apple family of operating systems.

// Check that what we plan to define is not already defined
#ifdef MIM_PLATFORM_APPLE
#undef MIM_PLATFORM_APPLE
#endif
#ifdef MIM_PLATFORM_POSIX
#undef MIM_PLATFORM_POSIX
#endif

#define MIM_PLATFORM_APPLE 1
#define MIM_PLATFORM_POSIX 1

// iPhone
// TARGET_OS_IPHONE will be defined on gcc.
#if defined(__IPHONE__) || (defined(TARGET_IPHONE_SIMULATOR) && TARGET_IPHONE_SIMULATOR) || (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE)

// Check that what we plan to define is not already defined
#ifdef MIM_PLATFORM_IPHONE
#undef MIM_PLATFORM_IPHONE
#endif
#define MIM_PLATFORM_IPHONE 1
#define MIM_POSIX_THREADS_AVAILABLE 1

#ifdef MIM_PLATFORM_MOBILE
#undef MIM_PLATFORM_MOBILE
#endif
#define MIM_PLATFORM_MOBILE 1

// Macintosh OSX
// __MACH__ is defined by the GCC compiler.
#elif defined(__MACH__)

// Check that what we plan to define is not already defined
#ifdef MIM_PLATFORM_OSX
#undef MIM_PLATFORM_OSX
#endif
#ifdef MIM_PLATFORM_UNIX
#undef MIM_PLATFORM_UNIX
#endif
#ifdef MIM_PLATFORM_POSIX
#undef MIM_PLATFORM_POSIX
#endif

#define MIM_PLATFORM_OSX 1
#define MIM_PLATFORM_UNIX 1
#define MIM_PLATFORM_POSIX 1

#ifdef MIM_PLATFORM_DESKTOP
#undef MIM_PLATFORM_DESKTOP
#endif

#define MIM_PLATFORM_DESKTOP 1
#else
#error Unknow Apple Platform
#endif

#elif defined(__linux) || defined(__linux__)

// Check that what we plan to define is not already defined
#ifdef MIM_PLATFORM_LINUX
#undef MIM_PLATFORM_LINUX
#endif
#ifdef MIM_PLATFORM_UNIX
#undef MIM_PLATFORM_UNIX
#endif
#ifdef MIM_PLATFORM_POSIX
#undef MIM_PLATFORM_POSIX
#endif

#define MIM_PLATFORM_LINUX 1
#define MIM_PLATFORM_UNIX 1
#define MIM_PLATFORM_POSIX 1

#ifdef MIM_PLATFORM_DESKTOP
#undef MIM_PLATFORM_DESKTOP
#endif

#define MIM_PLATFORM_DESKTOP 1

#elif defined(__ANDROID__)

// Check that what we plan to define is not already defined
#ifdef MIM_PLATFORM_ANDROID
#undef MIM_PLATFORM_ANDROID
#endif
#ifdef MIM_PLATFORM_LINUX
#undef MIM_PLATFORM_LINUX
#endif
#ifdef MIM_PLATFORM_UNIX
#undef MIM_PLATFORM_UNIX
#endif
#ifdef MIM_PLATFORM_POSIX
#undef MIM_PLATFORM_POSIX
#endif

#define MIM_PLATFORM_ANDROID 1
#define MIM_PLATFORM_LINUX 1
#define MIM_PLATFORM_UNIX 1
#define MIM_PLATFORM_POSIX 1

#ifdef MIM_PLATFORM_MOBILE
#undef MIM_PLATFORM_MOBILE
#endif
#define MIM_PLATFORM_MOBILE 1

#else
#error Mim does not support this platform
#endif
