#include "Dog.hpp"

Dog::Dog(void):Animal()
{
    std::cout << "Dog Default constructor called" << std::endl;
    this->type = "Dog";
    this->DogBrain = new Brain();
}
Dog::Dog(Dog const &src):Animal()
{
    std::cout << "Dog Copy constructor called" << std::endl;
    this->type = src.getType();
    this->DogBrain = new Brain();
    int i = 0;
    while(!src.DogBrain->ideas[i].empty() && i < 100)
    {
        this->DogBrain->ideas[i] = src.DogBrain->ideas[i];
        i++;
    }
}
Dog::~Dog(void)
{
    delete this->DogBrain;
    std::cout << "Dog Destructor called" << std::endl;
    
}

Dog &Dog::operator=(Dog const & rhs)
{
    std::cout << "Dog Assignment operator called" << std::endl;
    this->type = rhs.getType();
    this->DogBrain = new Brain();
    int i = 0;
    while(!rhs.DogBrain->ideas[i].empty() && i < 100)
    {
        this->DogBrain->ideas[i] = rhs.DogBrain->ideas[i];
        i++;
    }
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Woof!" << std::endl;
}

void Dog::addIdea( std::string idea )
{
    int i = 0;
    while(!this->DogBrain->ideas[i].empty() && i < 100)
    {
        i++;
    }
    if (i == 99)
        this->DogBrain->ideas[0] = idea;
    else
        this->DogBrain->ideas[i] = idea;
}
void Dog::printOutIdeas(void) const
{
    int i = 0;
    if (this->DogBrain->ideas[i].empty())
    {
        std::cout << "no idea~" << std::endl;
        return ;
    }
    while(!this->DogBrain->ideas[i].empty() && i < 100)
    {
        std::cout << i << ":" << this->DogBrain->ideas[i] << std::endl;
        i++;
    }
}
