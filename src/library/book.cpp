#include "book.hpp"

#include "page.hpp"
#include <iostream>

void Book::refresh()
{
    std::cout << "Book::refresh()" << std::endl;
    Page page;
    page.refresh();
}

int Book::insert()
{
    Page page;

    int type = 1;
    int secret = 77;
    void *secret_p = &secret;

    int status = page.insert(&type, secret_p);
    return status;
}