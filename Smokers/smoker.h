#include "tamper.h"
#include "matches.h"
#include <thread>
#include <vector>
#include <chrono>

#define TIME_WAIT std::chrono::milliseconds(1000)

class Smoker
{
 private:
    int id_s;
    std::thread smk;

    Matches *matches;
    Tamper *tampers;

    void packing();
    void lighting();
    void smoking();
    bool process(Matches *matches, Tamper *tampers);
 public:
    Smoker(int id, Matches *matches, Tamper *tampers);

    ~Smoker();
};
