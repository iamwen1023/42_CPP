#ifndef CAT_HPP
#define CAT_HPP 
#include <string.h>
#include "AAnimal.hpp"
#include "Brain.hpp"
class Cat : public AAnimal
{
    public:
        Cat(void);								
	    Cat(Cat const & src);
        ~Cat(void);
        Cat & operator=(Cat const & rhs);
        void makeSound(void) const;
        void addIdea( std::string idea );
        void printOutIdeas(void) const;
    private:
        Brain *CatBrain;

};

#endif