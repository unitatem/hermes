#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "page_mock.hpp"
#include <iostream>

#include "../../src/library/book.hpp"

using ::testing::_;
using ::testing::DoAll;
using ::testing::Invoke;
using ::testing::Return;

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

TEST(LibraryTest, get_pointer_value)
{
    // Given
    int secret = 0;

    auto print_parameters = [](void *type, void *secret_p) {
        std::cout << "type=" << *static_cast<int*>(type) << " secret=" << *static_cast<int*>(secret_p) << std::endl;
    };

    auto get_parameter = [&secret](void*, void *secret_p) {
        secret = *static_cast<int*>(secret_p);
    };

    PageMock page_mock;
    EXPECT_CALL(page_mock, insert(_, _))
        .WillOnce(DoAll(Invoke(print_parameters),
                        Invoke(get_parameter),
                        Return(0)));

    // When
    Book book;
    int status = book.insert();

    // Then
    EXPECT_EQ(0, status);
    EXPECT_EQ(77, secret);
}