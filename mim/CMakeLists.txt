file(GLOB ROOT_SOURCE *.cpp)
file(GLOB ROOT_INLINE *.inl)
file(GLOB ROOT_HEADER *.hpp)

file(GLOB_RECURSE CORE_SOURCE ./internal/*.cpp)
file(GLOB_RECURSE CORE_INLINE ./internal/*.inl)
file(GLOB_RECURSE CORE_HEADER ./internal/*.hpp)

# need to fix this
#configure_file(internal/build_version.hpp.in "${CMAKE_CURRENT_BINARY_DIR}/internal/build_version.hpp" @ONLY)

add_library(mim INTERFACE)

target_include_directories(mim INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        )

install(TARGETS mim EXPORT glm)

if(BUILD_STATIC_LIBS)
    add_library(mim_static STATIC
            ${ROOT_SOURCE} ${ROOT_INLINE} ${ROOT_HEADER}
            ${CORE_SOURCE} ${CORE_INLINE} ${CORE_HEADER}
            )
    target_link_libraries(mim_static PUBLIC mim)
    add_library(mim::mim_static ALIAS mim_static)
endif()

if(BUILD_SHARED_LIBS)
    add_library(mim_shared SHARED
            ${ROOT_SOURCE} ${ROOT_INLINE} ${ROOT_HEADER}
            ${CORE_SOURCE} ${CORE_INLINE} ${CORE_HEADER}
            )
    target_link_libraries(mim_shared PUBLIC mim)
    add_library(mim::mim_shared ALIAS mim_shared)
endif()


