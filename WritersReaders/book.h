#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

class Book
{
 private:
    std::mutex bk;    
    const char *bName;
 public:
    Book(const char *bookName);
    void block();
    void relase();
    const char* get_title();
};
