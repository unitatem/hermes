enable_testing()

include(googletest/googletest.cmake)
fetch_googletest(${PROJECT_BINARY_DIR}/googletest)

add_executable(book_test
    book_test.cpp
    ../src/book.cpp)
target_link_libraries(book_test
    gtest
    gmock_main
    PageMock)

add_library(PageMock SHARED
    page_mock.cpp)
target_link_libraries(PageMock
    gmock)

add_library(PageFake SHARED
    page_fake.cpp)
