#include <cstdlib>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>
#include "writer.h"
#include "book.h"

Writer::Writer(Book *bn)
{
    wr = std::thread(&Writer::run, this, bn);
}

Writer::~Writer()
{
    if (wr.joinable())
    {
        wr.join();
    }
}

void Writer::run(Book *bn)
{
    while(true)
    {
        this->write(bn);
    }
}

void Writer::write(Book *bn)
{
    auto lk = bn->block();
    bn->wait_write(lk, 0);

    const char *fname = bn->get_title();

    FILE *f = fopen(fname, "w");
    
    if (!f)
    {
        perror("Couldnt open file");
        return;
    }

    int buff = rand() % 1000;
    
    fprintf(f, "%d \n", buff);

    printf("Writer: %d \n", buff);

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    fclose(f);
    bn->counter();

    return;
}

