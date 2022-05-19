#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap Default constructor called" << std::endl;
    this->_name = "DEfualt";
    ClapTrap::_name = _name.append("_clap_name");
    FragTrap::initHP();
    ScavTrap::initEP();
	FragTrap::initAD();
}
DiamondTrap::DiamondTrap(std::string name): ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap String constructor called" << std::endl;
    this->_name = name;
    ClapTrap::_name = name.append("_clap_name");
    FragTrap::initHP();
    ScavTrap::initEP();
	FragTrap::initAD();
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

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
    std::cout << "DiamondTrap attack called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const & rhs)
{
    std::string	nameToBe = rhs._name;
    std::cout << "DiamondTrap Assignment operator called" << std::endl;
    this->_name = nameToBe;
    ClapTrap::_name = nameToBe.append("_clap_name");
    this->_hit_points = rhs.getHitPoints();
    this->_energy_points = rhs.getEnergyPoints();
    this->_attack_damage = rhs.getAttackDamage();
    return (*this);
}
void DiamondTrap::whoAmI()
{
    std::cout << "my name : " << this->_name
             << " my ClapTrap name : " << this->ClapTrap::_name << std::endl;
}
