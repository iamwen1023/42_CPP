#ifndef ANIMAL_HPP
#define ANIMAL_HPP 
#include <string.h>
#include <iostream>
class Animal
{
    public:
        Animal(void);								
	    Animal(Animal const & src);
        virtual ~Animal(void);
        Animal & operator=(Animal const & rhs);
        std::string getType(void) const;
        virtual void makeSound(void) const;
        virtual void	printOutIdeas( void ) const ;
		virtual void	addIdea(std::string idea) ;
    protected:
        std::string type;
};

#endif