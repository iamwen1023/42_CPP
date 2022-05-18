#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
    std::cout << "FragTrap Default constructor called" << std::endl;
    this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}
FragTrap::FragTrap(std::string const name): ClapTrap(name)
{
    std::cout << "FragTrap String constructor called" << std::endl;
    this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}
FragTrap::FragTrap(FragTrap const &src):ClapTrap(src)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = src;
}
FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << std::endl;
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap :Positive high fives request!" << std::endl;
}