set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/containers_benchmark/tests)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/containers_benchmark/tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/containers_benchmark/tests)

add_executable(vector_benchmark
    vector.cpp)
target_link_libraries(vector_benchmark
    benchmark_main)
# gtest_discover_tests(visitor_test)
