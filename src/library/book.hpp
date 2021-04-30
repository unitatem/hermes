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

#endif // BOOK_HPP_
