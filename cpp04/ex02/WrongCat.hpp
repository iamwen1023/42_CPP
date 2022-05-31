#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP 
#include <string.h>
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal
{
    public:
        WrongCat(void);								
	    WrongCat(WrongCat const & src);
        ~WrongCat(void);
        WrongCat & operator=(WrongCat const & rhs);
        void makeSound(void) const;
};

#endif