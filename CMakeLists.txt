cmake_minimum_required(VERSION 3.10)
project(hermes)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(TESTS "enable/disable tests" ON)

add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wshadow
    -Wnon-virtual-dtor
    -pedantic
    )

include_directories(include)
add_subdirectory(src)

if (TESTS)
    add_subdirectory(tests)
endif ()
