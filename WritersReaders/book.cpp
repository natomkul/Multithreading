#include "book.h"

Book::Book(const char *bookName) : bName(bookName) {}

std::unique_lock<std::mutex> Book::block()
{
     return std::unique_lock<std::mutex> (bk);
}

const char* Book::get_title()
{
    return bName;
}

int Book::get_count()
{
    return count;
}

void Book::wait_write(std::unique_lock<std::mutex> &lck, int val)
{
    cv.wait(lck, [&] { return this->count == val; });
}

void Book::wait_read(std::unique_lock<std::mutex> &lck, int val)
{
    cv.wait(lck, [&] { return this->count != val; });
}

void Book::counter()
{
    count++;

    if (count == 4)
    {
        count = 0;
    }

     printf("count %d\n", count);

     cv.notify_all();
}
