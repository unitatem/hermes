#include "book.hpp"

#include <algorithm>
#include <iostream>

void Book::refresh()
{
    std::cout << "Book::refresh()" << std::endl;
    Page page;
    page.refresh();
}

int Book::insert()
{
    Page page;

    int type = 1;
    int secret = 77;
    void *secret_p = &secret;

    int status = page.insert(&type, secret_p);
    return status;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << "Book:{ ";
    os << "title: " << book.m_title << " ";
    os << "author: " << book.m_author << " ";

    os << "pages:[ ";
    std::for_each(std::begin(book.m_pages), std::end(book.m_pages), [&os](const auto& obj) mutable {
        os << obj << ", ";
    });
    os << "] ";

    os << "}";
    return os;
}

RatedBook::RatedBook(const Book book, int rating)
    : m_book(book), m_rating(rating) {}

std::ostream& operator<<(std::ostream& os, const RatedBook& rated_book)
{
    os << "RatedBook:{ ";
    os << "book: " << rated_book.m_book << ", ";
    os << "rating: " << rated_book.m_rating << ", ";
    return os;
}
