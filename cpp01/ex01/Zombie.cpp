#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "dummy constructor is created" << std::endl;
}
Zombie::Zombie(std::string name) :_name(name)
{
    std::cout << this->_name << " is created" << std::endl;
    return ;
}

Zombie::~Zombie( void )
{
    std::cout << this->_name << " is destroyed" << std::endl;
    return ;
}

void Zombie::announce( void )
{
    std::cout << this->_name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}