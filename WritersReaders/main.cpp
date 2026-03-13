#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <cstdlib>
#include "book.h"
#include "reader.h"

int main()
{
    std::vector<Book*> books;
    books.push_back(new Book("test1.txt"));
    books.push_back(new Book("test.txt"));
    //Reader r(books);
    Reader R = new Reader (books);
}
