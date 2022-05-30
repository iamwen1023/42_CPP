#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP 
#include <string.h>
#include <iostream>
class WrongAnimal
{
    public:
        WrongAnimal(void);								
	    WrongAnimal(WrongAnimal const & src);
        virtual ~WrongAnimal(void);
        WrongAnimal & operator=(WrongAnimal const & rhs);
        std::string getType(void) const;
        virtual void makeSound(void) const;
    protected:
        std::string type;
};

#endif