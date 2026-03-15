#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>
#include <condition_variable>

class Book
{
 private:
    std::mutex bk;    
    const char *bName;
    int count = 0;
    std::condition_variable cv;

 public:
    Book(const char *bookName);

    std::unique_lock<std::mutex> block();

    const char* get_title();

    int get_count();

    void counter();

    void wait_write(std::unique_lock<std::mutex> &, int);
    void wait_read(std::unique_lock<std::mutex> &, int);
};
