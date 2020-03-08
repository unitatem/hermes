cmake_minimum_required(VERSION 3.10)
project(googletest_mvp

set(CMAKE_CXX_STANDARD 17)

option(TESTS "enable/disable tests" ON)

add_subdirectory(src)

if (TESTS)
    add_subdirectory(tests)
endif ()
