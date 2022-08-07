#include <iostream>

#include "src/library/page.hpp"

void Page::refresh() {
  std::cout << "(interceptor) Page::refresh()" << std::endl;
}
