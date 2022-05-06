#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weap);
        ~HumanA();
        void attack();

    private:
        std::string _name;
        Weapon &_Weapon_tool;

};

#endif
