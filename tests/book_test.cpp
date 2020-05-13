#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "page_mock.hpp"

#include "../src/book.hpp"

using ::testing::Return;

TEST(test, success)
{
    PageMock page_mock;
    // EXPECT_CALL(page_mock, refresh()).WillOnce(Return());

    Book book;
    book.refresh();
}
