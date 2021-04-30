#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../../src/library/book.hpp"

using ::testing::AllOf;
using ::testing::ContainerEq;
using ::testing::Eq;
using ::testing::ExplainMatchResult;
using ::testing::Field;
using ::testing::Pointwise;

using BooksContainer = std::vector<Book>;

class MatcherFixture : public ::testing::Test
{
protected:
    void SetUp() override {}

    BooksContainer create_books()
    {
        BooksContainer books(10);
        std::generate(std::begin(books), std::end(books), [b = 0]() mutable {
            Book book;
            book.m_author = "Author_" + std::to_string(b);
            book.m_title = "Title " + std::to_string(b);
            book.m_pages = std::vector<Page>(10);
            std::generate(std::begin(book.m_pages), std::end(book.m_pages), [p = 0]() mutable {
                Page page;
                page.m_page_nr = p;
                page.m_text = "Text " + std::to_string(p);
                ++p;
                return page;
            });
            ++b;
            return book;
        });
        return books;
    }
};

MATCHER(PageEq, "")
{
    const Page& lhs = std::get<0>(arg);
    const Page& rhs = std::get<1>(arg);
    return ExplainMatchResult(
        AllOf(
            Field(&Page::m_page_nr, Eq(rhs.m_page_nr)),
            Field(&Page::m_text, Eq(rhs.m_text))),
        lhs,
        result_listener);
}

MATCHER(BookEq, "")
{
    const Book& lhs = std::get<0>(arg);
    const Book& rhs = std::get<1>(arg);
    return ExplainMatchResult(
        AllOf(
            Field(&Book::m_author, Eq(rhs.m_author)),
            Field(&Book::m_title, Eq(rhs.m_title)),
            Field(&Book::m_pages, Pointwise(PageEq(), rhs.m_pages))),
        lhs,
        result_listener);
}

TEST_F(MatcherFixture, good_weather)
{
    // Given
    const BooksContainer books_reference = create_books();
    const BooksContainer books = create_books();

    // Then
    EXPECT_THAT(books, Pointwise(BookEq(), books_reference));
}
