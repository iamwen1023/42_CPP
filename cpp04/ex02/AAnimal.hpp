#ifndef ANIMAL_HPP
#define ANIMAL_HPP 
#include <string.h>
#include <iostream>
class AAnimal
{
    public:
        AAnimal(void);								
	    AAnimal(AAnimal const & src);
        virtual ~AAnimal(void);
        AAnimal & operator=(AAnimal const & rhs);
        std::string getType(void) const;
        virtual void makeSound(void) const = 0;
        virtual void	printOutIdeas( void ) const = 0;
		virtual void	addIdea(std::string idea)  = 0;
    protected:
        std::string type;
};

#endif