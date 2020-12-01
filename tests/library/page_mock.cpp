#include "page_mock.hpp"

#include "../../src/library/page.hpp"

static PageMock* mock_impl;

PageMock::PageMock()
{
    mock_impl = this;
}

PageMock::~PageMock()
{
    mock_impl = nullptr;
}

void Page::refresh()
{
    mock_impl->refresh();
}
