#include "smoker.h"

int main()
{
    Matches *mat = new Matches(4);
    Tamper *tam = new Tamper(2);

    Smoker smok(1, mat, tam);    
    Smoker smok2(2, mat, tam);    
    Smoker smok3(3, mat, tam);    
    Smoker smok4(4, mat, tam);    
    Smoker smok5(5, mat, tam);    
    Smoker smok6(6, mat, tam);    
}
