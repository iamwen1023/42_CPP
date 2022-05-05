#include "Zombie.hpp"


Zombie* zombieHorde( int N, std::string name)
{
    int index(0);
    Zombie *newone =  new Zombie[N];
    while (index < N)
    {
        newone[index] = Zombie(name);
        index++;
    }
    return newone;
}