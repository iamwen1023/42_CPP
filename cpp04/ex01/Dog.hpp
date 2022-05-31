#ifndef DOG_HPP
#define DOG_HPP 
#include <string.h>
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
    public:
        Dog(void);								
	    Dog(Dog const & src);
        ~Dog(void);
        Dog & operator=(Dog const & rhs);
        void makeSound(void) const;
        void addIdea( std::string idea );
        void printOutIdeas(void) const;
    private:
        Brain *dogBrain;
};

#endif