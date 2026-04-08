#include "smoker.h"

Smoker::Smoker(int id, Matches *matches, Tamper *tampers) 
                 : id_s(id), matches(matches), tampers(tampers)
{
    smk = std::thread(&Smoker::process, this, matches, tampers);
}

Smoker::~Smoker()
{
    if (smk.joinable())
    {
        smk.join();
    }
}

void Smoker::packing()
{
    while (true)
    {
        printf("Smoker %d: trying pack\n", id_s);
        std::this_thread::sleep_for(TIME_WAIT);

        if (tampers->aquireT())
        {
            printf("Smoker %d: packing\n", id_s);
            std::this_thread::sleep_for(TIME_WAIT);
            tampers->relaseT(); 
            break;
        }
    }
}

void Smoker::lighting()
{
    while (true)
    {
        printf("Smoker %d: getting matches\n", id_s);
        std::this_thread::sleep_for(TIME_WAIT);
    
        if (matches->aquireM())
        {
            printf("Smoker %d: lighting\n", id_s);
            std::this_thread::sleep_for(TIME_WAIT);
            matches->relaseM();
            break;
        }
    }
}

void Smoker::smoking()
{
    printf("Smoker %d: smoking\n", id_s);
    std::this_thread::sleep_for(TIME_WAIT);
    return;
}

bool Smoker::process(Matches *matches, Tamper *tampers)
{
    while (true)
    {
        packing();
        lighting();
        smoking();
    }
}

