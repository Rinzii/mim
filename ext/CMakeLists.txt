project(mim-ext)

include(FetchContent)



if (MIM_BUILD_TEST)
  # PThreads are not available on Windows
  # So tell gtest to not use them.
  if(MIM_WINDOWS)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)
  endif()

  set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
  set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
  set(gtest_build_samples OFF CACHE BOOL "" FORCE)
  set(gtest_build_tests OFF CACHE BOOL "" FORCE)


  FetchContent_Declare(
          googletest
          GIT_REPOSITORY https://github.com/google/googletest.git
          GIT_TAG v1.14.0
  )
  FetchContent_MakeAvailable(googletest)

  add_library(gtest::gtest ALIAS gtest)
endif()

find_package(Threads REQUIRED)

add_library(mim-ext INTERFACE)
add_library(mim::ext ALIAS mim-ext)

if(MIM_BUILD_TEST)
  target_link_libraries(mim-ext INTERFACE
          gtest::gtest
          )
endif ()

target_link_libraries(mim-ext INTERFACE
        Threads::Threads
        )
