cmake_minimum_required(VERSION 3.12)
project(hw_1_integral)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        hw_1_integral
        main.cpp
        functors.h
        functors.cpp
        util.h
        util.cpp
)