// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/internal/config/compiler.hpp"
#include "compiler_features.hpp"

// https://learn.microsoft.com/en-us/cpp/intrinsics/compiler-intrinsics?view=msvc-170
// https://clang.llvm.org/docs/LanguageExtensions.html
// https://gcc.gnu.org/onlinedocs/gcc-4.8.5/gcc/X86-Built-in-Functions.html

// ------------------------------------------------------------------------
// MIM_STRINGIFY
//
// Example usage:
//     printf("Line: %s", MIM_STRINGIFY(__LINE__));
//
#ifndef MIM_STRINGIFY
#define MIM_STRINGIFY(x) MIM_STRINGIFYIMPL(x)
#define MIM_STRINGIFYIMPL(x) #x
#endif

// https://gcc.gnu.org/onlinedocs/cpp/Pragmas.html
// https://clang.llvm.org/docs/UsersManual.html#controlling-diagnostics-via-pragmas
#ifndef MIM_WARNING
#if defined(MIM_COMPILER_CLANG) || defined(MIM_COMPILER_GCC)
#define MIM_WARNING(msg) _Pragma(MIM_STRINGIFY(GCC warning msg)
#else
#define MIM_WARNING(msg)
#endif
#endif


#ifndef MIM_ALIGNED_TYPEDEF
#if MIM_COMPILER_MSVC
#define MIM_ALIGNED_TYPEDEF(type, name, alignment) typedef __declspec(align(alignment)) type name
#elif MIM_COMPILER_CLANG || MIM_COMPILER_GCC
#define MIM_ALIGNED_TYPEDEF(type, name, alignment) typedef type name __attribute__((aligned(alignment)))
#else
#define MIM_ALIGNED_TYPEDEF(type, name, alignment) typedef type name
#endif
#endif

#ifndef MIM_IF_CONSTEXPR
#ifndef MIM_COMPILER_NO_IF_CONSTEXPR
#define MIM_IF_CONSTEXPR if constexpr
#else
#define MIM_IF_CONSTEXPR if
#endif
#endif

#ifndef MIM_NODISCARD
#if defined(MIM_COMPILER_CPP17_ENABLED)
#define MIM_NODISCARD [[nodiscard]]
#else
#if defined(MIM_COMPILER_MSVC)
#include <sal.h>
#define MIM_NODISCARD                                                                                                                                          \
	__checkReturn // Check that GNUC is at least 7.1
				  // This is required as GNUC 7.0 has a bug where it will not warn if the return value is not used
#elif defined(MIM_COMPILER_GCC) && (((__GNUC__ * 100) + __GNUC_MINOR__) >= 701) || defined(MIM_COMPILER_CLANG)
#define MIM_NODISCARD __attribute__((warn_unused_result))
#else
#define MIM_NODISCARD
#endif
#endif
#endif

#ifndef MIM_INLINE
#define MIM_INLINE inline
#endif

#ifndef MIM_FORCE_INLINE
#ifndef MIM_DISABLE_FORCED_INLINING
#if defined(MIM_COMPILER_MSVC)
#define MIM_FORCE_INLINE __forceinline
#elif defined(MIM_COMPILER_GCC) && (((__GNUC__ * 100) + __GNUC_MINOR__) >= 301) || defined(MIM_COMPILER_CLANG)
#if defined(__cplusplus)
#define MIM_FORCE_INLINE inline __attribute__((always_inline))
#else
#define MIM_FORCE_INLINE __inline__ __attribute__((always_inline))
#endif
#else
#if defined(__cplusplus)
#define MIM_FORCE_INLINE inline
#else
#define MIM_FORCE_INLINE __inline
#endif
#endif
#else // If MIM_DISABLE_FORCED_INLINING is defined then don't force inlining
#if defined(__cplusplus)
#define MIM_FORCE_INLINE inline
#else
#define MIM_FORCE_INLINE __inline
#endif
#endif
#endif

#ifndef MIM_NOINLINE
#if defined(MIM_COMPILER_MSVC)
#define MIM_NOINLINE __declspec(noinline)
#elif defined(MIM_COMPILER_GCC) || defined(MIM_COMPILER_CLANG)
#define MIM_NOINLINE __attribute__((noinline))
#else
#define MIM_NOINLINE
#endif
#endif

#ifndef MIM_DEPRECATED
#if !defined(MIM_COMPILER_CPP14_ENABLED)
#define MIM_DEPRECATED
#elif defined(MIM_COMPILER_MSVC)
#define MIM_DEPRECATED __declspec(deprecated)
#elif defined(MIM_COMPILER_GCC) || defined(MIM_COMPILER_CLANG)
#define MIM_DEPRECATED __attribute__((deprecated))
#else
#define MIM_DEPRECATED [[deprecated]]
#endif
#endif

#ifndef MIM_DEPRECATED_MESSAGE
#if !defined(MIM_COMPILER_CPP14_ENABLED)
#define MIM_DEPRECATED_MESSAGE(message)
#elif defined(MIM_COMPILER_MSVC)
#define MIM_DEPRECATED_MESSAGE(message) __declspec(deprecated(message))
#elif defined(MIM_COMPILER_GCC) || defined(MIM_COMPILER_CLANG)
#define MIM_DEPRECATED_MESSAGE(message) __attribute__((deprecated(message)))
#else
#define MIM_DEPRECATED_MESSAGE(message) [[deprecated(message)]]
#endif
#endif

#ifndef MIM_FALLTHROUGH
#if defined(MIM_COMPILER_CPP17_ENABLED)
#define MIM_FALLTHROUGH [[fallthrough]]
#elif defined(MIM_COMPILER_GCC) || defined(MIM_COMPILER_CLANG)
#define MIM_FALLTHROUGH __attribute__((fallthrough))
#elif defined(MIM_COMPILER_MSVC)
#define MIM_FALLTHROUGH __fallthrough
#else
#define MIM_FALLTHROUGH
#endif
#endif


#if defined(MIM_COMPILER_MSVC)
#define MIM_PRAGMA(x) __pragma(x)
#elif defined(MIM_COMPILER_GCC) || defined(MIM_COMPILER_CLANG)
#define MIM_PRAGMA(x) _Pragma(#x)
#else
#define MIM_PRAGMA(x)
#endif





// ------------------------------------------------------------------------
// MIM_DISABLE_GCC_WARNING / MIM_RESTORE_GCC_WARNING
//
// Example usage:
//     // Only one warning can be ignored per statement, due to how GCC works.
//     MIM_DISABLE_GCC_WARNING(-Wuninitialized)
//     MIM_DISABLE_GCC_WARNING(-Wunused)
//     <code>
//     MIM_RESTORE_GCC_WARNING()
//     MIM_RESTORE_GCC_WARNING()
//
#ifndef MIM_DISABLE_GCC_WARNING
#if defined(MIM_COMPILER_GNUC)
#define MIMGCCWHELP0(x) #x
#define MIMGCCWHELP1(x) MIMGCCWHELP0(GCC diagnostic ignored x)
#define MIMGCCWHELP2(x) MIMGCCWHELP1(#x)
#endif

#if defined(MIM_COMPILER_GNUC) && (MIM_COMPILER_VERSION >= 4006) // Can't test directly for __GNUC__ because some compilers lie.
#define MIM_DISABLE_GCC_WARNING(w)   \
				_Pragma("GCC diagnostic push")  \
				_Pragma(MIMGCCWHELP2(w))
#else
#define MIM_DISABLE_GCC_WARNING(w)
#endif
#endif

#ifndef MIM_RESTORE_GCC_WARNING
#if defined(MIM_COMPILER_GNUC) && (MIM_COMPILER_VERSION >= 4006)
#define MIM_RESTORE_GCC_WARNING()    \
				_Pragma("GCC diagnostic pop")
#else
#define MIM_RESTORE_GCC_WARNING()
#endif
#endif


// ------------------------------------------------------------------------
// MIM_ENABLE_GCC_WARNING_AS_ERROR / MIM_DISABLE_GCC_WARNING_AS_ERROR
//
// Example usage:
//     // Only one warning can be treated as an error per statement, due to how GCC works.
//     MIM_ENABLE_GCC_WARNING_AS_ERROR(-Wuninitialized)
//     MIM_ENABLE_GCC_WARNING_AS_ERROR(-Wunused)
//     <code>
//     MIM_DISABLE_GCC_WARNING_AS_ERROR()
//     MIM_DISABLE_GCC_WARNING_AS_ERROR()
//
#ifndef MIM_ENABLE_GCC_WARNING_AS_ERROR
#if defined(MIM_COMPILER_GNUC)
#define MIMGCCWERRORHELP0(x) #x
#define MIMGCCWERRORHELP1(x) MIMGCCWERRORHELP0(GCC diagnostic error x)
#define MIMGCCWERRORHELP2(x) MIMGCCWERRORHELP1(#x)
#endif

#if defined(MIM_COMPILER_GNUC) && (MIM_COMPILER_VERSION >= 4006) // Can't test directly for __GNUC__ because some compilers lie.
#define MIM_ENABLE_GCC_WARNING_AS_ERROR(w)   \
				_Pragma("GCC diagnostic push")  \
				_Pragma(MIMGCCWERRORHELP2(w))
#else
#define MIM_ENABLE_GCC_WARNING_AS_ERROR(w)
#endif

#if defined(MIM_COMPILER_GNUC) && (MIM_COMPILER_VERSION >= 4004)
#define MIM_DISABLE_GCC_WARNING(w)   \
				_Pragma(MIMGCCWERRORHELP2(w))
#else
#define MIM_DISABLE_GCC_WARNING(w)
#endif
#endif

#ifndef MIM_DISABLE_GCC_WARNING_AS_ERROR
#if defined(MIM_COMPILER_GNUC) && (MIM_COMPILER_VERSION >= 4006)
#define MIM_DISABLE_GCC_WARNING_AS_ERROR()    \
				_Pragma("GCC diagnostic pop")
#else
#define MIM_DISABLE_GCC_WARNING_AS_ERROR()
#endif
#endif



#ifndef MIM_ENABLE_IGNORE_GCC_WARNING
    #if defined(MIM_COMPILER_GNUC)
        #define MIMGCCIGNOREHELP0(x) #x
        #define MIMGCCIGNOREHELP1(x) MIMGCCIGNOREHELP0(GCC diagnostic ignored x)
        #define MIMGCCIGNOREHELP2(x) MIMGCCIGNOREHELP1(#x)
    #endif
#endif

#ifndef MIM_ENABLE_IGNORE_GCC_WARNING
#if defined(MIM_COMPILER_GNUC) && (MIM_COMPILER_VERSION >= 4006) // Can't test directly for __GNUC__ because some compilers lie.
#define MIM_ENABLE_IGNORE_GCC_WARNING(w)   \
                _Pragma("GCC diagnostic push")  \
                _Pragma(MIMGCCIGNOREHELP2(w))
#else
#define MIM_ENABLE_IGNORE_GCC_WARNING(w)
#endif
#endif

#ifndef MIM_DISABLE_IGNORE_GCC_WARNING
#if defined(MIM_COMPILER_GNUC) && (MIM_COMPILER_VERSION >= 4004)
#define MIM_DISABLE_IGNORE_GCC_WARNING   \
                _Pragma("GCC diagnostic pop")
#else
#define MIM_DISABLE_IGNORE_GCC_WARNING
#endif
#endif



// ------------------------------------------------------------------------
// MIM_DISABLE_CLANG_WARNING / MIM_RESTORE_CLANG_WARNING
//
// Example usage:
//     // Only one warning can be ignored per statement, due to how clang works.
//     MIM_DISABLE_CLANG_WARNING(-Wuninitialized)
//     MIM_DISABLE_CLANG_WARNING(-Wunused)
//     <code>
//     MIM_RESTORE_CLANG_WARNING()
//     MIM_RESTORE_CLANG_WARNING()
//
#ifndef MIM_DISABLE_CLANG_WARNING
#if defined(MIM_COMPILER_CLANG) || defined(MIM_COMPILER_CLANG_CL)
#define MIMCLANGWHELP0(x) #x
#define MIMCLANGWHELP1(x) MIMCLANGWHELP0(clang diagnostic ignored x)
#define MIMCLANGWHELP2(x) MIMCLANGWHELP1(#x)

#define MIM_DISABLE_CLANG_WARNING(w)   \
				_Pragma("clang diagnostic push")  \
				_Pragma(MIMCLANGWHELP2(-Wunknown-warning-option))\
				_Pragma(MIMCLANGWHELP2(w))
#else
#define MIM_DISABLE_CLANG_WARNING(w)
#endif
#endif

#ifndef MIM_RESTORE_CLANG_WARNING
#if defined(MIM_COMPILER_CLANG) || defined(MIM_COMPILER_CLANG_CL)
#define MIM_RESTORE_CLANG_WARNING()    \
				_Pragma("clang diagnostic pop")
#else
#define MIM_RESTORE_CLANG_WARNING()
#endif
#endif


// ------------------------------------------------------------------------
// MIM_DISABLE_ALL_CLANG_WARNINGS / MIM_RESTORE_ALL_CLANG_WARNINGS
//
// The situation for clang is the same as for GCC. See above.
// ------------------------------------------------------------------------


// ------------------------------------------------------------------------
// MIM_ENABLE_CLANG_WARNING_AS_ERROR / MIM_DISABLE_CLANG_WARNING_AS_ERROR
//
// Example usage:
//     // Only one warning can be treated as an error per statement, due to how clang works.
//     MIM_ENABLE_CLANG_WARNING_AS_ERROR(-Wuninitialized)
//     MIM_ENABLE_CLANG_WARNING_AS_ERROR(-Wunused)
//     <code>
//     MIM_DISABLE_CLANG_WARNING_AS_ERROR()
//     MIM_DISABLE_CLANG_WARNING_AS_ERROR()
//
#ifndef MIM_ENABLE_CLANG_WARNING_AS_ERROR
#if defined(MIM_COMPILER_CLANG) || defined(MIM_COMPILER_CLANG_CL)
#define MIMCLANGWERRORHELP0(x) #x
#define MIMCLANGWERRORHELP1(x) MIMCLANGWERRORHELP0(clang diagnostic error x)
#define MIMCLANGWERRORHELP2(x) MIMCLANGWERRORHELP1(#x)

#define MIM_ENABLE_CLANG_WARNING_AS_ERROR(w)   \
				_Pragma("clang diagnostic push")  \
				_Pragma(MIMCLANGWERRORHELP2(w))
#else
#define MIM_DISABLE_CLANG_WARNING(w)
#endif
#endif

#ifndef MIM_DISABLE_CLANG_WARNING_AS_ERROR
    #if defined(MIM_COMPILER_CLANG) || defined(MIM_COMPILER_CLANG_CL)
        #define MIM_DISABLE_CLANG_WARNING_AS_ERROR()    \
                    _Pragma("clang diagnostic pop")
    #else
        #define MIM_DISABLE_CLANG_WARNING_AS_ERROR()
    #endif
#endif
