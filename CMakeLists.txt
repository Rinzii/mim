cmake_minimum_required(VERSION 3.18)
project(mim VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(mim)
add_library(mim::mim ALIAS mim)
