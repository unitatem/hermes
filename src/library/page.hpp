#ifndef PAGE_HPP_
#define PAGE_HPP_

#include <ostream>
#include <string>

class Page {
 public:
  void refresh();

  int insert(void* type, void* object);

  friend std::ostream& operator<<(std::ostream& os, const Page& page);

  int m_page_nr;
  std::string m_text;
};

#endif  // PAGE_HPP_
