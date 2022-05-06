
#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon &weap):_Weapon_tool(weap), _name(name)
{
    std::cout << "HumanA constructor\n";
    return ;
}
HumanB::~HumanB()
{
    std::cout << "HumanA Deconstructor\n";
    return ;
}
void HumanB::attack()
{
    std::cout << this->_name << "attacks with their " << this->_Weapon_tool.getType() << std::endl;
}