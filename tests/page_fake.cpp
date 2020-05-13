#include "../src/page.hpp"

#include <iostream>

void Page::refresh()
{
    std::cout << "(interceptor) Page::refresh()" << std::endl;
}
