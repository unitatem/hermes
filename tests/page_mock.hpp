#ifndef PAGE_MOCK_HPP_
#define PAGE_MOCK_HPP_

#include "gmock/gmock.h"

// #include "../src/page.hpp"
#include <iostream>

class Page
{
public:
    void refresh();
    // MOCK_METHOD0(refresh, void());
};
using PageMock = Page;

#endif // PAGE_MOCK_HPP_
