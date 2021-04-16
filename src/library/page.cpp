#include "page.hpp"

#include <iostream>

void Page::refresh()
{
    std::cout << "Page::refresh()" << std::endl;
}

int Page::insert(void*, void*)
{
    return 0;
}
