#include <iostream>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>
#include "book.h"

class Writer
{
 private:
    std::thread wr;

    void run(Book *bn);
 public:
    Writer(Book *bn);
    ~Writer();
    void write(Book *bn);
};
