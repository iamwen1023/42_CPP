#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
}
ScavTrap::ScavTrap(std::string const name):ClapTrap(name)
{
    std::cout << "ScavTrap String constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = src;
}
ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const & rhs)
{
    std::cout << "ScavTrap Assignment operator called" << std::endl;
    this->_name = rhs.getName();
    this->_hit_points = rhs.getHitPoints();
    this->_energy_points = rhs.getEnergyPoints();
    this->_attack_damage = rhs.getAttackDamage();
    return (*this);
}

void ScavTrap::guardGate(void)
{
    std::cout<< "ScavTrap is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->getEnergyPoints() > 0 && this->getAttackDamage() > 0)
    {
        std::cout << "ScavTrap " << this->getName() <<" attacks "<< target << ", causing "<< this->getAttackDamage() << " points of damage!\n";
        this->setEnergyPoints(this->getEnergyPoints() - 1);
    }
    else 
    {
        std::cout << "ScavTrap " << this->getName() << " dose not have enough energy points or attack damage <= 0 \n";
    }
}