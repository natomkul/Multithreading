#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <cstdlib>
#include "book.h"
#include "reader.h"
#include "writer.h"

int main()
{
    srand(time(NULL));
    Book *bk = new Book("test.txt");
    Writer w(bk);
    Reader r(bk);
}
