set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/benchmark_containers/tests)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/benchmark_containers/tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/benchmark_containers/tests)

add_executable(benchmark_vector
    vector.cpp)
target_link_libraries(benchmark_vector
    benchmark_main)
# gtest_discover_tests(visitor_test)
