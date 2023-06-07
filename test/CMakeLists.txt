cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(mim-test)

if(NOT TARGET mim)
    find_package(mim CONFIG REQUIRED)
endif()

add_library(mim-test)
add_library(mim::test ALIAS mim-test)
target_link_libraries(mim-test PUBLIC mim::mim)
target_include_directories(mim-test PUBLIC .)

# Options to conditionally disable tests for faster build times when testing specific components.
# By default, all tests are enabled.
option(TEST_MIM_DISABLE_COMMON_TESTS "Disable mimMath tests" OFF)
option(TEST_MIM_DISABLE_HALF_TESTS "Disable half tests" OFF)
option(TEST_MIM_DISABLE_MATRIX_TESTS "Disable matrix tests" OFF)
option(TEST_MIM_DISABLE_QUATERNION_TESTS "Disable quaternion tests" OFF)
option(TEST_MIM_DISABLE_VECTOR_TESTS "Disable vector tests" OFF)

message(STATUS "COMMON TESTS:     ${TEST_MIM_DISABLE_COMMON_TESTS}")
message(STATUS "HALF TESTS:       ${TEST_MIM_DISABLE_HALF_TESTS}")
message(STATUS "MATRIX TESTS:     ${TEST_MIM_DISABLE_MATRIX_TESTS}")
message(STATUS "QUATERNION TESTS: ${TEST_MIM_DISABLE_QUATERNION_TESTS}")
message(STATUS "VECTOR TESTS:     ${TEST_MIM_DISABLE_VECTOR_TESTS}")

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        mim_test_main.cpp
        )

target_sources(${PROJECT_NAME} PRIVATE
        common/mimMath_tests.cpp
        common/random_tests.cpp
        )



target_sources(${PROJECT_NAME} PRIVATE
        half/half_tests.cpp
        )



target_sources(${PROJECT_NAME} PRIVATE
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


target_sources(${PROJECT_NAME} PRIVATE
        quat/quat_tests.cpp
        quat/quat_func_tests.cpp
        )



target_sources(${PROJECT_NAME} PRIVATE
        vec/vector1_tests.cpp
        vec/vector2_tests.cpp
        vec/vector3_tests.cpp
        vec/vector4_tests.cpp

        vec/vector1_func_tests.cpp
        vec/vector2_func_tests.cpp
        vec/vector3_func_tests.cpp
        vec/vector4_func_tests.cpp
        )


if(MIM_OS_WINDOWS)
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else ()
  target_compile_options(dj-test PUBLIC
          -Wall -Wextra -Wpedantic -Wconversion -Werror=return-type -Wunused
          )
endif()


target_link_libraries(mim-test PRIVATE
    mim::mim
    gtest::gtest

    ${PThreadLib}
    )

# Only test vectors
add_test(NAME mim-test-vectors COMMAND mim-test --gtest_filter=Vec* --gtest_color=yes)

# Only test matrices
add_test(NAME mim-test-matrices COMMAND mim-test --gtest_filter=Mat* --gtest_color=yes)

# Only test quaternions
add_test(NAME mim-test-quaternions COMMAND mim-test --gtest_filter=Quat* --gtest_color=yes)

# Only test common
add_test(NAME mim-test-common COMMAND mim-test --gtest_filter=Common* --gtest_color=yes)



