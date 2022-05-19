#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string.h>

class DiamondTrap :public ScavTrap, public FragTrap
{
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const &src);
        ~DiamondTrap(void);
        DiamondTrap &operator=(DiamondTrap const & rhs);
        void attack(const std::string& target);
        void whoAmI();
        std::string getName( void ) const;
    private:
        std::string _name;
};
#endif