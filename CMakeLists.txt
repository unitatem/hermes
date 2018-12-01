cmake_minimum_required(VERSION 3.10)
project(dedal)

set(CMAKE_CXX_STANDARD 17)

option(TESTS "enable/disable tests" ON)

add_executable(dedal src/main.cpp)
add_subdirectory(src)
target_link_libraries(dedal
        dedal_core
        )

if (TESTS)
    add_subdirectory(tests)
endif ()
