#include <iostream>

#include "lab/library/page.hpp"

void Page::refresh() {
    std::cout << "(interceptor) Page::refresh()" << std::endl;
}
