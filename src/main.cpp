#include <iostream>

#include "book.hpp"

int main()
{
    std::cout << "START" << std::endl;

    Book book;
    book.refresh();

    std::cout << "END" << std::endl;
    return 0;
}
