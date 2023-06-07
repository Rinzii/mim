cmake_minimum_required(VERSION 3.18)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_DEBUG_POSTFIX "-d")
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# We will hit 1.0.0 when we have a stable API
# We will hit 0.1.0 when we have finished the basic API
set(build_version 0.0.3)

project(mim VERSION ${build_version})

set(is_root_project OFF)

# Check if we are the root project
if(PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
  set(is_root_project ON)
endif()

# TO THE IMPLEMENTOR: If MIM_BUILD_TEST is set to OFF then googletest can be deleted from the ext folder.
option(MIM_BUILD_TEST "Build mim tests" ${is_root_project})
option(MIM_INSTALL "Setup install and package steps" ${is_root_project})
option(MIM_NO_CMAKE_WARNINGS "Suppress mim warnings outputted through cmake" OFF)
option(MIM_DISABLE_FORCED_INLINING "Disable forced inlining of functions in mim" OFF)



include(GNUInstallDirs)

configure_file(src/version.hpp.in "${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME}/version.hpp" @ONLY)

# include the global configuration file
include(cmake/GlobalConfig.cmake)


add_library(${PROJECT_NAME})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_include_directories(${PROJECT_NAME} PRIVATE src)

# Add the source files

include(header_list.cmake)
target_sources(${PROJECT_NAME} PRIVATE ${mim_headers})

target_sources(${PROJECT_NAME} PRIVATE
        src/random.cpp
        )


# Currently everything is headers only


# Currently we are only a static LIB but I'd like to enable the ability to be dynamic!

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

if(CMAKE_CXX_COMPILER_ID STREQUAL Clang OR CMAKE_CXX_COMPILER_ID STREQUAL GNU)
  target_compile_options(${PROJECT_NAME} PRIVATE
          -Wall -Wextra -Wpedantic -Wconversion -Werror=return-type -Wunused
          )
endif()

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

# Disabled for now but may be enabled in the future
#if (MIM_DISABLE_FORCED_INLINING)
#  target_compile_definitions(${PROJECT_NAME} PUBLIC MIM_DISABLE_FORCED_INLINING)
#endif ()

if (MIM_BUILD_TEST)
  enable_testing()
  add_subdirectory(ext)
  add_subdirectory(test)
endif()

if(MIM_INSTALL)
  include(GNUInstallDirs)
  include(CMakePackageConfigHelpers)

  # install targets
  install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-targets
          LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
          ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
          RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
          INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
          )

  # install headers from include
  install(DIRECTORY include/
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
          FILES_MATCHING PATTERN "*.hpp"
          )

  # install generated headers
  install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include/"
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
          FILES_MATCHING PATTERN "*.hpp"
          )

  # install and export targets
  install(EXPORT ${PROJECT_NAME}-targets
          FILE ${PROJECT_NAME}-targets.cmake
          NAMESPACE ${PROJECT_NAME}::
          DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
          )
  # configure ${PROJECT_NAME}-config.cmake
  configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/config.cmake.in"
          "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
          INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
          )

  # install ${PROJECT_NAME}-config.cmake
  install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
          DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
          )

  # configure ${PROJECT_NAME}-config-version.cmake
  write_basic_package_version_file(
          "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake"
          VERSION ${build_version}
          COMPATIBILITY AnyNewerVersion
  )

  # install ${PROJECT_NAME}-config-version.cmake
  install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake"
          DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
          )
endif()
