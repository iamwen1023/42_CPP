#include "Dog.hpp"

Dog::Dog(void):Animal()
{
    std::cout << "Dog Default constructor called" << std::endl;
    this->type = "Dog";
    this->dogBrain = new Brain();  
}
Dog::Dog(Dog const &src):Animal()
{
    std::cout << "Dog Copy constructor called" << std::endl;
    this->type = src.getType();
    this->dogBrain = new Brain(*(src.dogBrain));
    // int i = 0;
    // while(!src.dogBrain->ideas[i].empty() && i < 100)
    // {
    //     this->dogBrain->ideas[i] = src.dogBrain->ideas[i];
    //     i++;
    // }
    // *this = src;
}
Dog::~Dog(void)
{
    delete this->dogBrain;
    std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const & rhs)
{
    std::cout << "Dog Assignment operator called" << std::endl;
    this->type = rhs.getType();
    if (this->dogBrain)
        delete this->dogBrain;
    this->dogBrain = new Brain(*(rhs.dogBrain));
    // int i = 0;
    // while(!rhs.dogBrain->ideas[i].empty() && i < 100)
    // {
    //     this->dogBrain->ideas[i] = rhs.dogBrain->ideas[i];
    //     i++;
    // }
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "woof!!" << std::endl;
}

void Dog::addIdea( std::string idea )
{
    int i = 0;
    while(!this->dogBrain->ideas[i].empty() && i < 100)
    {
        i++;
    }
    if (i == 99)
        this->dogBrain->ideas[0] = idea;
    else
        this->dogBrain->ideas[i] = idea;
}
void Dog::printOutIdeas(void) const
{
    int i = 0;
    if (this->dogBrain->ideas[i].empty())
    {
        std::cout << "no idea~" << std::endl;
        return ;
    }
    while(!this->dogBrain->ideas[i].empty() && i < 100)
    {
        std::cout << i << ":" << this->dogBrain->ideas[i] << std::endl;
        i++;
    }
}