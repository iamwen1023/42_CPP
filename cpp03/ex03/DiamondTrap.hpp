#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string.h>

class DiamondTrap :public ScavTrap, public FragTrap
{
    public:
        DiamondTrap(void);
        DiamondTrap(std::string const name);
        DiamondTrap(DiamondTrap const &src);
        ~DiamondTrap(void);
        void whoAmI();
    private:
        std::string _name;
};
#endif