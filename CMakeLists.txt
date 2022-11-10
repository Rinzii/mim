cmake_minimum_required(VERSION 3.18)
project(mathematical)

set(CMAKE_CXX_STANDARD 20)

add_library(mathematical library.cpp include/math.hpp include/vector1.hpp include/vector2.hpp include/vector3.hpp include/vector4.hpp include/float16.hpp include/matrix2.hpp include/matrix3.hpp include/matrix4.hpp)
