
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weap):_Weapon_tool(weap), _name(name)
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
    std::cout << this->_name << "attacks with their " << this->_Weapon_tool.getType() << std::endl;
}
