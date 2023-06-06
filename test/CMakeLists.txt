project(mim-test)

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

if (NOT TEST_MIM_DISABLE_COMMON_TESTS )
    target_sources(${PROJECT_NAME} PRIVATE
            common/mimMath_tests.cpp
            common/random_tests.cpp
            )
endif ()

if (NOT TEST_MIM_DISABLE_HALF_TESTS )
    target_sources(${PROJECT_NAME} PRIVATE
            half/half_tests.cpp
            )
endif ()

if (NOT TEST_MIM_DISABLE_MATRIX_TESTS )
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
            )
endif ()

if (NOT TEST_MIM_DISABLE_QUATERNION_TESTS )
    target_sources(${PROJECT_NAME} PRIVATE
            quat/quat_tests.cpp
            )
endif ()

if (NOT TEST_MIM_DISABLE_VECTOR_TESTS )
    target_sources(${PROJECT_NAME} PRIVATE
            vec/vector1_tests.cpp
            vec/vector2_tests.cpp
            vec/vector3_tests.cpp
            vec/vector4_tests.cpp
            )
endif ()

if(MIM_OS_WINDOWS)
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()


target_link_libraries(mim-test PRIVATE
    mim::mim
    gtest::gtest

    ${PThreadLib}
    )

add_test(NAME mim-test COMMAND mim-test)

add_test(NAME mim-test-verbose COMMAND mim-test --verbose)



