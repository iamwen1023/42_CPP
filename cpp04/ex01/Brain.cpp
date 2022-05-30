#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain Default constructor called" << std::endl;
}
Brain::Brain(Brain const &src)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    int i = 0;
    while(!src.ideas[i].empty() && i < 100)
    {
        this->ideas[i] = src.ideas[i];
        i++;
    }
    *this = src;
}
Brain::~Brain(void)
{
    std::cout << "Brain Destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const & rhs)
{
    std::cout << "Brain Assignment operator called" << std::endl;
    int i = 0;
    while(!rhs.ideas[i].empty() && i < 100)
    {
        this->ideas[i] = rhs.ideas[i];
        i++;
    }
    return (*this);
}
void Brain::addIdea( std::string idea )
{
    int i = 0;
    while(!this->ideas[i].empty() && i < 100)
    {
        i++;
    }
    if (i == 99)
        this->ideas[0] = idea;
    else
        this->ideas[i] = idea;

}

void Brain::printOutIdeas(void) const
{
    int i = 0;
    if (this->ideas[i].empty())
    {
        std::cout << "no idea~" << std::endl;
        return ;
    }
    while(!this->ideas[i].empty() && i < 100)
    {
        std::cout << i << ":" << this->ideas[i] << std::endl;
        i++;
    }
}
