include(cmake/Macros.cmake)

# TODO: I need more data on CYGWIN and MSYS to know if they are supported or not.
#       Try to look into this further at a later date.

# check for cygwin
if(CYGWIN)
  if(NOT MIM_NO_CMAKE_WARNINGS)
    message(WARNING "MIM:
      Cygwin may not be supported. If you notice any issues please report it!
      REPORT ALL ISSUES HERE: https://github.com/Rinzii/mim/issues/

      To disable this warning set MIM_NO_CMAKE_WARNINGS to ON
    " )
  endif ()
endif()

# check for msys
if(MSYS)
  if(NOT MIM_NO_CMAKE_WARNINGS)
    message(WARNING "MIM:
      MSYS may not be supported. If you notice any issues please report it!
      REPORT ALL ISSUES HERE: https://github.com/Rinzii/mim/issues/

      To disable this warning set MIM_NO_CMAKE_WARNINGS to ON
    " )
  endif ()
endif()



# detect our OS
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
  set(MIM_OS_WINDOWS 1)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  set(MIM_OS_LINUX 1)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
  set(MIM_OS_MACOS 1)
elseif(CMAKE_SYSTEM_NAME MATCHES "^k?FreeBSD$")
  set(MIM_OS_FREEBSD 1)
elseif(CMAKE_SYSTEM_NAME MATCHES "^OpenBSD$")
  set(MIM_OS_OPENBSD 1)
elseif(CMAKE_SYSTEM_NAME MATCHES "^NetBSD$")
  set(MIM_OS_NETBSD 1)
else()
  message(FATAL_ERROR "Unsupported OS: ${CMAKE_SYSTEM_NAME}")
endif()


# detect the compiler
# Note: The detection order is important because:
# - Visual Studio can both use MSVC and Clang
# - GNUCXX can still be set on macOS when using Clang
if(MSVC)
  set(MIM_COMPILER_MSVC 1)

  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(MIM_COMPILER_CLANG_CL 1)
  endif()
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(MIM_COMPILER_CLANG 1)
elseif(CMAKE_COMPILER_IS_GNUCXX)
  set(MIM_COMPILER_GCC 1)

  execute_process(COMMAND "${CMAKE_CXX_COMPILER}" "--version" OUTPUT_VARIABLE GCC_COMPILER_VERSION)
  string(REGEX MATCHALL ".*(tdm[64]*-[1-9]).*" MIM_COMPILER_GCC_TDM "${GCC_COMPILER_VERSION}")
else()
  message(FATAL_ERROR "Unsupported compiler")
  return()
endif()


# detect the architecture (note: this test won't work for cross-compilation)
include(CheckTypeSize)
check_type_size(void* SIZEOF_VOID_PTR)
if(${SIZEOF_VOID_PTR} STREQUAL "4")
  set(MIM_ARCH_32BITS 1)
elseif(${SIZEOF_VOID_PTR} STREQUAL "8")
  set(MIM_ARCH_64BITS 1)
else()
  message(FATAL_ERROR "Unsupported architecture")
  return()
endif()
