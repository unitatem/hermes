#include "book.hpp"

#include "page.hpp"
#include <iostream>

void Book::refresh()
{
    std::cout << "Book::refresh()" << std::endl;
    Page page;
    page.refresh();
}