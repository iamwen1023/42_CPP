#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>
#include <iostream>
 
class Zombie
{
    public:
        Zombie(void);
        Zombie(std::string);
        ~Zombie(void);
        void announce( void );
    private:
        std::string _name;

};

Zombie* zombieHorde( int N, std::string name );

#endif