#include <iostream>

#include "example/library/page.hpp"

void Page::refresh() {
    std::cout << "(interceptor) Page::refresh()" << std::endl;
}
