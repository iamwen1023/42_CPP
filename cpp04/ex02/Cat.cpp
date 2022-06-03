#include "Cat.hpp"

Cat::Cat(void):AAnimal()
{
    std::cout << "Cat Default constructor called" << std::endl;
    this->type = "Cat";
    this->catBrain = new Brain();  
}
Cat::Cat(Cat const &src):AAnimal()
{
    std::cout << "Cat Copy constructor called" << std::endl;
    this->type = src.getType();
    this->catBrain = new Brain(*(src.catBrain));
}
Cat::~Cat(void)
{
    delete this->catBrain;
    std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const & rhs)
{
    std::cout << "Cat Assignment operator called" << std::endl;
    this->type = rhs.getType();
    if (this->catBrain)
        delete this->catBrain;
    this->catBrain = new Brain(*(rhs.catBrain));
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow~~" << std::endl;
}

void Cat::addIdea( std::string idea )
{
    int i = 0;
    while(!this->catBrain->ideas[i].empty() && i < 100)
    {
        i++;
    }
    if (i == 99)
        this->catBrain->ideas[0] = idea;
    else
        this->catBrain->ideas[i] = idea;
}
void Cat::printOutIdeas(void) const
{
    int i = 0;
    if (this->catBrain->ideas[i].empty())
    {
        std::cout << "no idea~" << std::endl;
        return ;
    }
    while(!this->catBrain->ideas[i].empty() && i < 100)
    {
        std::cout << i << ":" << this->catBrain->ideas[i] << std::endl;
        i++;
    }
}
