#include "reader.h"
#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include "book.h"

Reader::Reader(Book *bn)
{
    rd = std::thread(&Reader::run, this, bn);
}

Reader::~Reader()
{
    if (rd.joinable())
    {
        rd.join();
    }
}

void Reader::run(Book *bn)
{
    while(true)
    {
        this->read(bn);
    }
}

void Reader::read(Book *bn)
{
    auto lk = bn->block();
    bn->wait_read(lk, 0);

    const char *fname = bn->get_title();

    FILE *f = fopen(fname, "r");
    
    if (!f)
    {
        perror("Couldnt open file");
        return;
    }

    char buff[10];

    while (fgets(buff, sizeof(buff), f) != NULL) {
        printf("%s", buff);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
    
    fclose(f);
    bn->counter();

    return;
}
