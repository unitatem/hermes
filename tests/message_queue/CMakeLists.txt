set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/message_queue/tests)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/message_queue/tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/message_queue/tests)

add_executable(message_queue_test
    message_queue_test.cpp)
target_link_libraries(message_queue_test
    gtest
    gmock_main)
gtest_discover_tests(message_queue_test)

add_executable(processor_test
    processor_test.cpp)
target_link_libraries(processor_test
    gtest
    gmock_main)
gtest_discover_tests(processor_test)
