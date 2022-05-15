
#include "HumanB.hpp"

HumanB::HumanB(std::string name):_name(name)
{
    this->_Weapon = NULL;
    std::cout << "HumanB constructor\n";
    return ;
}
HumanB::~HumanB()
{
    std::cout << "HumanB Deconstructor\n";
    return ;
}
void HumanB::attack()
{
    std::string type(this->_Weapon->getType());
    if (type.empty() == false)
        std::cout << this->_name << "attacks with their " << this->_Weapon->getType() << std::endl;
    else
        std::cout << this->_name << "attacks with their heads!" << std::endl;
}

void HumanB::setWeapon(Weapon &Weapon)
{
    this->_Weapon = &Weapon;
}