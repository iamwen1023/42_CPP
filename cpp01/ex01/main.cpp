#include "Zombie.hpp"
#define N 5 
int main(void)
{
    int index(0);
    Zombie *newone = zombieHorde(N , "zombiearr");
    while (index < N)
    {
        newone->announce();
        index++;
    }
    delete [] newone;

    return 0;
}