#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
    public:
        ClapTrap(void);								
	    ClapTrap(std::string const name);
	    ClapTrap(ClapTrap const & src);
        ~ClapTrap(void);
        ClapTrap & operator=(ClapTrap const & rhs);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        int getAttackDamage( void ) const;
        int getHitPoints( void ) const;
        int getEnergyPoints( void ) const;
        std::string getName( void ) const;
        void setAttackDamage(int amount);
        void setHitPoints(int amount);
        void setEnergyPoints(int amount);
        void setName(std::string name);

    private:
       std::string _name;
       int _hit_points;
       int _energy_points;
       int _attack_damage;

};
# endif