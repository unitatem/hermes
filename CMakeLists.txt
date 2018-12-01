cmake_minimum_required(VERSION 3.12)
project(dedal)

set(CMAKE_CXX_STANDARD 17)

add_executable(dedal src/main.cpp src/my_math.cpp src/my_math.h)
