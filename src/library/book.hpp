#ifndef BOOK_HPP_
#define BOOK_HPP_

#include <string>
#include <vector>

#include "page.hpp"

class Book
{
public:
    void refresh();

    int insert();

    std::string m_title;
    std::string m_author;
    std::vector<Page> m_pages;
};

#endif // BOOK_HPP_
