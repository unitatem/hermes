cmake_minimum_required(VERSION 3.10)
project(mwe_googletest)

set(CMAKE_CXX_STANDARD 17)

option(TESTS "enable/disable tests" ON)

add_executable(mwe_googletest src/main.cpp)
add_subdirectory(src)
target_link_libraries(mwe_googletest
        mwe_googletest_math
        )

if (TESTS)
    add_subdirectory(tests)
endif ()
