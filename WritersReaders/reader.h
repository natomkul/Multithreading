#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include "book.h"

class Reader
{
 private:
    std::thread rd;

    void run(Book *bn);
 public:
    Reader(Book *bn);
    ~Reader();
    void read(Book *bn);
};
