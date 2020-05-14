cmake_minimum_required(VERSION 3.15)
project(cppProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppProject main.cpp Matrix.cpp Matrix.hpp Vector.hpp Vector.cpp)