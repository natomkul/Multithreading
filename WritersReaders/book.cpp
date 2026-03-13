#include "book.h"

Book::Book(const char *bookName) : bName(bookName) {}

void Book::block()
{
    bk.lock();
}

void Book::relase()
{
    bk.unlock();
}

const char* Book::get_title()
{
    return bName;
}
