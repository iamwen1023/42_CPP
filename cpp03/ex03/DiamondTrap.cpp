#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    std::cout << "DiamondTrap Default constructor called" << std::endl;
    this->_name = ClapTrap::getName().appende("_clap_name");
    ScavTrap::setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}
DiamondTrap::DiamondTrap(std::string const name): ClapTrap(name)
{
    std::cout << "DiamondTrap String constructor called" << std::endl;
    this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}
DiamondTrap::DiamondTrap(DiamondTrap const &src):ClapTrap(src)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    *this = src;
}
DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}
void DiamondTrap::whoAmI()
{

}
