#include <iostream>

#include "book.hpp"

int main() {
    std::cout << "START" << std::endl;

    Book book;
    book.refresh();

    std::cout << "book.insert() = " << book.insert() << " (expected = 0)"
              << std::endl;

    std::cout << "END" << std::endl;
    return 0;
}
