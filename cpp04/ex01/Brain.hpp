#ifndef BRAIN_HPP
#define BRAIN_HPP 
#include <string.h>
#include <iostream>
class Brain
{
    public:
        Brain(void);								
	    Brain(Brain const & src);
        ~Brain(void);
        Brain & operator=(Brain const & rhs);
        void addIdea( std::string idea );
        void printOutIdeas(void) const;

        std::string ideas[100];
};

#endif