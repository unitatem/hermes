cmake_minimum_required(VERSION 2.8.2)

project(benchmark-download NONE)

include(ExternalProject)
ExternalProject_Add(benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG master
        SOURCE_DIR "@DESTINATION_ROOT@/benchmark-src"
        BINARY_DIR "@DESTINATION_ROOT@/benchmark-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        TEST_COMMAND ""
        )
