#include "reader.h"
#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include "book.h"

Reader::Reader(std::vector<Book*> books) : books(books) 
{
    rd = std::thread(&Reader::read, this);
}

Reader::~Reader()
{
    if (rd.joinable())
    {
        rd.join();
    }
}

void Reader::read()
{
    int idx = rand() % 2;
    Book* bn = books[idx];

    const char *fname = bn->get_title();

    FILE *f = fopen(fname, "r");
    
    if (!f)
    {
        perror("Couldnt open file");
        return;
    }

    char buff[5];

    while (fgets(buff, sizeof(buff), f) != NULL) {
        printf("%d: %s", idx, buff);
    }

    fclose(f);

    return;
}
