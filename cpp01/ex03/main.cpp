#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{

    Weapon cluba = Weapon("crude spiked club");
    HumanA bob("Bob", cluba);
    bob.attack();
    cluba.setType("some other type of club");
    bob.attack();

    Weapon clubb = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(clubb);
    jim.attack();
    clubb.setType("some other type of club");
    jim.attack();

    return 0;
}