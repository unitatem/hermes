include(git_lib_builder.cmake)

set(BUILD_SHARED_LIBS ON)

add_subdirectory(googletest)

set(CMAKE_BUILD_TYPE Release)

set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
add_subdirectory(benchmark)
