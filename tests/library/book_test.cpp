#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "page_mock.hpp"
#include <iostream>

#include "../../src/library/book.hpp"

using ::testing::Invoke;

TEST(test, success)
{
    PageMock page_mock;
    EXPECT_CALL(page_mock, refresh())
        .WillOnce(Invoke([](){ std::cout << "PageMock::refresh()" << std::endl; }));

    Book book;
    book.refresh();
}
