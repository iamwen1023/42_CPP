#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    std::cout << "weapon constructor\n";
    this->_type = type;
    return ;
}
Weapon::~Weapon()
{
    std::cout << "weapon DEconstructor\n";
    return ;
}
const std::string &Weapon::getType()const
{
    return this->_type;
}
void Weapon::setType(std::string type)
{
    this->_type = type;
}