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

FragTrap::FragTrap(FragTrap const &src):ClapTrap()
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = src;
}
FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << std::endl;
}
FragTrap &FragTrap::operator=(FragTrap const & rhs)
{
    std::cout << "FragTrap Assignment operator called" << std::endl;
    this->_name = rhs.getName();
    this->_hit_points = rhs.getHitPoints();
    this->_energy_points = rhs.getEnergyPoints();
    this->_attack_damage = rhs.getAttackDamage();
    return (*this);
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap :Positive high fives request!" << std::endl;
}

void FragTrap::initHP()
{
     this->_hit_points = 100;
}
void FragTrap::initAD()
{
     this->_attack_damage = 30;
}