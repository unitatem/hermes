#ifndef PAGE_MOCK_HPP_
#define PAGE_MOCK_HPP_

#include "gmock/gmock.h"

class PageMock
{
public:
    PageMock();
    ~PageMock();

    MOCK_METHOD0(refresh, void());
};

#endif // PAGE_MOCK_HPP_
