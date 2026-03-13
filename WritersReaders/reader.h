#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include "book.h"

class Reader
{
 private:
    std::vector<Book*> books;
    std::thread rd;
 public:
    Reader(std::vector<Book*> books);
    ~Reader();
    void read();
};
