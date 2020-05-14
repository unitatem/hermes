cmake_minimum_required(VERSION 3.10)
project(hermes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(TESTS "enable/disable tests" ON)

add_subdirectory(src)

if (TESTS)
    add_subdirectory(tests)
endif ()
