#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "page_mock.hpp"
#include <iostream>

#include "../../src/library/book.hpp"

using ::testing::Invoke;

TEST(LibraryTest, good_weather)
{
    //Given
    PageMock page_mock;
    EXPECT_CALL(page_mock, refresh())
        .WillOnce(Invoke([](){ std::cout << "PageMock::refresh()" << std::endl; }));

    // When
    Book book;
    book.refresh();
}
