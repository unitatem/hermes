#include "page_mock.hpp"

#include "lab/library/page.hpp"

static PageMock *mock_impl = nullptr;

PageMock::PageMock() { mock_impl = this; }

PageMock::~PageMock() { mock_impl = nullptr; }

void Page::refresh() { mock_impl->refresh(); }

int Page::insert(void *type, void *secret_p) {
    return mock_impl->insert(type, secret_p);
}
