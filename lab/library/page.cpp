#include "page.hpp"

#include <iostream>

void Page::refresh() { std::cout << "Page::refresh()" << std::endl; }

int Page::insert(void*, void*) { return 0; }

std::ostream& operator<<(std::ostream& os, const Page& page) {
  os << "Page:{ ";
  os << "page_nr: " << page.m_page_nr << " ";
  os << "text: " << page.m_text << " ";
  os << "}";
  return os;
}
