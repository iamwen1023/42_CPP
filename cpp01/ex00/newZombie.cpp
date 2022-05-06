#include "Zombie.hpp"


Zombie* newZombie( std::string name )
{
    Zombie *newone =  new Zombie(name);
    return newone;
}