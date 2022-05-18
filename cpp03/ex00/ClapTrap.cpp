#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):_name("Default"),_hit_points(10),_energy_points(10),_attack_damage(0)
{
    std::cout << "Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string const name):_name(name),_hit_points(10),_energy_points(10),_attack_damage(0)
{
    std::cout << "String constructor called" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}
ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const & rhs)
{
    std::cout << "Assignment operator called" << std::endl;
    this->_name = rhs.getName();
    this->_hit_points = rhs.getHitPoints();
    this->_energy_points = rhs.getEnergyPoints();
    this->_attack_damage = rhs.getAttackDamage();
    return (*this);
}

int ClapTrap::getAttackDamage( void ) const
{
    return this->_attack_damage;
}
int ClapTrap::getHitPoints( void ) const
{
    return this->_hit_points;
}
int ClapTrap::getEnergyPoints( void ) const
{
    return this->_energy_points;
}
std::string ClapTrap::getName( void ) const
{
    return this->_name;
}


void ClapTrap::attack(const std::string& target)
{
    if (this->_energy_points > 0 && this->_attack_damage > 0)
    {
        std::cout << "ClapTrap " << this->_name <<" attacks "<< target << ", causing "<< this->_attack_damage << " points of damage!\n";
        this->_energy_points -= 1;
    }
    else 
    {
        std::cout << "ClapTrap " << this->_name << " dose not have enough energy points or attack damage <= 0\n";
    }
    //?target.takeDamage()?
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount <= 0)
    {
        std::cout << amount << "<= 0" << std::endl;
        return ;
    }
    std::cout << this->_name << " take " << amount << " Damage." << std::endl;
    this->_hit_points -= amount;
    if (this->_hit_points <= 0)
    {
        std::cout << this->_name << "is dead!" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{   
    if (amount <= 0)
    {
        std::cout << amount << "<= 0" << std::endl;
        return ;
    }
    if (this->_energy_points > 0)
    {
        std::cout << this->_name << " is Repaired +" << amount << std::endl;
        this->_hit_points += amount;
        this->_energy_points -= 1;
    }
    else
    {
        std::cout << "ClapTrap " << this->getName() << " dose not have enough energy points\n";
    }
}