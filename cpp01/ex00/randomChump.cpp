#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie newone(name);
    newone.announce();
}