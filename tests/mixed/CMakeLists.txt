set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/mixed/tests)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/mixed/tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/mixed/tests)

add_executable(exception_test exception_test.cpp)
target_link_libraries(exception_test gtest gmock_main)
gtest_discover_tests(exception_test)

add_executable(lambda_test lambda_test.cpp)
target_link_libraries(lambda_test gtest gmock_main)
gtest_discover_tests(lambda_test)

add_executable(matcher_explanation_test matcher_explanation_test.cpp)
target_link_libraries(matcher_explanation_test gtest gmock_main)
gtest_discover_tests(matcher_explanation_test)

add_executable(unique_ptr_mock_test unique_ptr_mock_test.cpp)
target_link_libraries(unique_ptr_mock_test gtest gmock_main)
gtest_discover_tests(unique_ptr_mock_test)

add_executable(struct_cmp_test struct_cmp_test.cpp)
target_link_libraries(struct_cmp_test gtest gmock_main)
gtest_discover_tests(struct_cmp_test)

add_executable(visitor_test visitor_test.cpp)
target_link_libraries(visitor_test gtest gmock_main)
gtest_discover_tests(visitor_test)
