#include "Zombie.hpp"

int main(void)
{
    Zombie *newone = newZombie("zombieinheap");
    newone->announce();
    delete newone;

    randomChump("zombieinstack");
    return 0;
}