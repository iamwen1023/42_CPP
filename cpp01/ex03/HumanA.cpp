
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weap):_name(name),_Weapon(weap)
{
    std::cout << "HumanA constructor\n";
    return ;
}
HumanA::~HumanA()
{
    std::cout << "HumanA Deconstructor\n";
    return ;
}
void HumanA::attack()
{
    std::cout << this->_name << "attacks with their " << this->_Weapon.getType() << std::endl;
}
