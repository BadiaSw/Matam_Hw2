cmake_minimum_required(VERSION 3.28)
project(wet)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic-errors -Werror")
add_executable(wet
        tests.cpp
        Utilities.cpp
        Utilities.h
        Matrix.cpp
        Matrix.h)
