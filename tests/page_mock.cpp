#include "page_mock.hpp"

void Page::refresh()
{
    std::cout << "(interceptor) Page::refresh()" << std::endl;
}
