#ifndef MIM_SETUP_INCLUDED

#include <cassert>
#include <cstddef>

#define MIM_VERSION_MAJOR 0
#define MIM_VERSION_MINOR 1
#define MIM_VERSION_PATCH 0
#define MIM_VERSION_REVISION 0
#define MIM_VERSION 0100
#define MIM_VERSION_STRING "MIM: version 0.1.0.0"

#define MIM_SETUP_INCLUDED MIM_VERSION



// Detect our platform

#include "../simd/platform.hpp"



#if defined(_M_ARM64) || defined(__LP64__) || defined(_M_X64) || defined(__ppc64__) || defined(__x86_64__)
#	define MIM_ARCH	    MIM_ARCH_64
#elif defined(__i386__) || defined(__ppc__) || defined(__ILP32__) || defined(_M_ARM)
#	define MIM_ARCH	    MIM_ARCH_32
#else
#	define MIM_ARCH	    MIM_ARCH_32
#endif

#if !defined(MIM_ARCH) && MIM_COMPILER != 0
#	error "MIM_ARCH not defined, your compiler may not be supported. Add #define MIM_ARCH 0 to ignore this error."
#endif





#endif // MIM_SETUP_INCLUDED