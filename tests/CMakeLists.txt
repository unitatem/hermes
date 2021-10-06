enable_testing()

include(GoogleTest)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/tests)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/tests)

add_executable(main_test main_test.cpp)
target_link_libraries(main_test gtest gmock_main)
gtest_discover_tests(main_test)

