#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "example/library/book.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::AllOf;
using ::testing::ContainerEq;
using ::testing::Eq;
using ::testing::ExplainMatchResult;
using ::testing::Field;
using ::testing::Not;
using ::testing::Pointwise;

using BooksContainer = std::vector<Book>;

class MatcherFixture : public ::testing::Test {
protected:
    void SetUp() override {}

    BooksContainer create_books() {
        BooksContainer books(10);
        std::generate(std::begin(books), std::end(books), [b = 0]() mutable {
            Book book;
            book.m_author = "Author_" + std::to_string(b);
            book.m_title = "Title " + std::to_string(b);
            book.m_pages = std::vector<Page>(10);
            std::generate(std::begin(book.m_pages), std::end(book.m_pages),
                          [p = 0]() mutable {
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

MATCHER(PageEq, "") {
    const Page& lhs = std::get<0>(arg);
    const Page& rhs = std::get<1>(arg);
    return ExplainMatchResult(AllOf(Field(&Page::m_page_nr, Eq(rhs.m_page_nr)),
                                    Field(&Page::m_text, Eq(rhs.m_text))),
                              lhs, result_listener);
}

MATCHER(BookEq, "") {
    const Book& lhs = std::get<0>(arg);
    const Book& rhs = std::get<1>(arg);
    return ExplainMatchResult(
        AllOf(Field(&Book::m_author, Eq(rhs.m_author)),
              Field(&Book::m_title, Eq(rhs.m_title)),
              Field(&Book::m_pages, Pointwise(PageEq(), rhs.m_pages))),
        lhs, result_listener);
}

// Wraps matcher and one of comparison objects in order to compare with incoming
// `arg`. `arg` is an object feeded by GoogleTest framework. `value` is an
// object explicitelly specified by a client.
MATCHER_P2(MatchWith, matcher, value, "") {
    const auto& lhs = arg;
    const auto& rhs = value;

    return ExplainMatchResult(
        matcher, std::make_pair<decltype(lhs), decltype(rhs)>(lhs, rhs),
        result_listener);
}

// Match RateBook's object with Book's object.
// Expects `arg` as a std::tuple where first element is RatedBook
// and second element is Book.
MATCHER(RatedBook2BookEq, "") {
    const RatedBook& rated_book = std::get<0>(arg);
    const Book& book = std::get<1>(arg);
    return ExplainMatchResult(
        AllOf(Field(&RatedBook::m_book, MatchWith(BookEq(), book))), rated_book,
        result_listener);
}

TEST_F(MatcherFixture, good_weather) {
    // Given
    const BooksContainer books_reference = create_books();
    const BooksContainer books = create_books();

    // Then
    EXPECT_THAT(books, Pointwise(BookEq(), books_reference));
}

TEST_F(MatcherFixture, bad_weather) {
    // Given
    const BooksContainer books_reference = create_books();
    BooksContainer books = create_books();

    // When
    books[0].m_pages[0].m_page_nr = 42;

    // Then
    EXPECT_THAT(books, Not(Pointwise(BookEq(), books_reference)));
}

TEST_F(MatcherFixture, compare_apples_and_oranges) {
    // Given
    const BooksContainer books_reference = create_books();
    const BooksContainer books = create_books();

    // When
    std::vector<RatedBook> rated_books;
    std::transform(
        std::begin(books), std::end(books), std::back_inserter(rated_books),
        [n = 0](const Book& book) mutable { return RatedBook(book, ++n); });
    ASSERT_EQ(books.size(), rated_books.size());

    // Then
    EXPECT_THAT(rated_books, Pointwise(RatedBook2BookEq(), books_reference));
}
