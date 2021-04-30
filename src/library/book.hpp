#ifndef BOOK_HPP_
#define BOOK_HPP_

#include <string>
#include <ostream>
#include <vector>

#include "page.hpp"

class Book
{
public:
    void refresh();

    int insert();

    friend std::ostream& operator<<(std::ostream& os, const Book& book);

    std::string m_title;
    std::string m_author;
    std::vector<Page> m_pages;
};

class RatedBook
{
public:
    RatedBook(const Book book, int rating);

    // This is not a smart idea but I will use it just for testing purposes
    const Book m_book;
    double m_rating;

    friend std::ostream& operator<<(std::ostream& os, const RatedBook& rated_book);
};

#endif // BOOK_HPP_
