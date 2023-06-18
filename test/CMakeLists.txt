cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(mim-test)

if(NOT TARGET mim)
    find_package(mim CONFIG REQUIRED)
endif()

add_library(mim-test)
add_library(mim::test ALIAS mim-test)
target_link_libraries(mim-test PUBLIC
        mim::mim
        gtest::gtest
        )
target_include_directories(mim-test PUBLIC .)
target_sources(mim-test PRIVATE
        mim_test_main.cpp
)


add_executable(mim-test-common)
target_sources(mim-test-common PRIVATE
        common/mimMath_tests.cpp
        common/random_tests.cpp
        )
target_link_libraries(mim-test-common PRIVATE
        mim::test
        gtest::gtest
        )


add_executable(mim-test-half)
target_sources(mim-test-half PRIVATE
        half/half_tests.cpp
        )
target_link_libraries(mim-test-half PRIVATE
        mim::test
        gtest::gtest
        )


add_executable(mim-test-matrix)
target_sources(mim-test-matrix PRIVATE
        mat/mat2x2_tests.cpp
        mat/mat2x3_tests.cpp
        mat/mat2x4_tests.cpp
        mat/mat3x2_tests.cpp
        mat/mat3x3_tests.cpp
        mat/mat3x4_tests.cpp
        mat/mat4x2_tests.cpp
        mat/mat4x3_tests.cpp
        mat/mat4x4_tests.cpp

        mat/mat2x2_func_tests.cpp
        mat/mat2x3_func_tests.cpp
        mat/mat2x4_func_tests.cpp
        mat/mat3x2_func_tests.cpp
        mat/mat3x3_func_tests.cpp
        mat/mat3x4_func_tests.cpp
        mat/mat4x2_func_tests.cpp
        mat/mat4x3_func_tests.cpp
        mat/mat4x4_func_tests.cpp
        )
target_link_libraries(mim-test-matrix PRIVATE
        mim::test
        gtest::gtest
        )


add_executable(mim-test-quat)
target_sources(mim-test-quat PRIVATE
        quat/quat_tests.cpp
        quat/quat_func_tests.cpp
        )
target_link_libraries(mim-test-quat PRIVATE
        mim::test
        gtest::gtest
        )


add_executable(mim-test-vector)
target_sources(mim-test-vector PRIVATE
        vec/vector1_tests.cpp
        vec/vector2_tests.cpp
        vec/vector3_tests.cpp
        vec/vector4_tests.cpp

        vec/vector1_func_tests.cpp
        vec/vector2_func_tests.cpp
        vec/vector3_func_tests.cpp
        vec/vector4_func_tests.cpp
        )
target_link_libraries(mim-test-vector PRIVATE
        mim::test
        gtest::gtest
        )



if(MIM_OS_WINDOWS)
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

# Only supported compilers currently are MSVC, GNU and Clang
if(CMAKE_CXX_COMPILER_ID STREQUAL MSVC)
    target_compile_options(mim-test PUBLIC
            /W4 /WX /permissive /analyze /std:c++20
            )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL GNU OR CMAKE_CXX_COMPILER_ID STREQUAL Clang)
  target_compile_options(mim-test PUBLIC
          -Wall -Wextra -Wno-pedantic -Wno-unused-function
          )
endif()




# Only test vectors
add_test(NAME mim-test-common COMMAND mim-test-common)
add_test(NAME mim-test-half COMMAND mim-test-half)
add_test(NAME mim-test-matrix COMMAND mim-test-matrix)
add_test(NAME mim-test-quat COMMAND mim-test-quat)
add_test(NAME mim-test-vector COMMAND mim-test-vector)



