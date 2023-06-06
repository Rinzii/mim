// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

// MIM_COMPILER_HAS_FEATURE
#ifndef MIM_COMPILER_HAS_FEATURE
#if defined(__clang__)
#define MIM_COMPILER_HAS_FEATURE(x) __has_feature(x)
#else
#define MIM_COMPILER_HAS_FEATURE(x) 0
#endif
#endif

// MIM_COMPILER_HAS_BUILTIN
#ifndef MIM_COMPILER_HAS_BUILTIN
#if defined(__clang__)
#define MIM_COMPILER_HAS_BUILTIN(x) __has_builtin(x)
#else
#define MIM_COMPILER_HAS_BUILTIN(x) 0
#endif
#endif

// TODO: Add checks for every feature in C++11, C++14, C++17, C++20, and C++23.
// This is so we can dynamically enable/disable features based on compiler support.
