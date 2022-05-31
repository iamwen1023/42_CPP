#include "Cat.hpp"

Cat::Cat(void):AAnimal()
{
    std::cout << "Cat Default constructor called" << std::endl;
    this->type = "Cat";
    this->CatBrain = new Brain();  
}
Cat::Cat(Cat const &src):AAnimal()
{
    std::cout << "Cat Copy constructor called" << std::endl;
    this->type = src.getType();
    this->CatBrain = new Brain();
    int i = 0;
    while(!src.CatBrain->ideas[i].empty() && i < 100)
    {
        this->CatBrain->ideas[i] = src.CatBrain->ideas[i];
        i++;
    }
    *this = src;
}
Cat::~Cat(void)
{
    delete this->CatBrain;
    std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const & rhs)
{
    std::cout << "Cat Assignment operator called" << std::endl;
    this->type = rhs.getType();
    this->CatBrain = new Brain();
    int i = 0;
    while(!rhs.CatBrain->ideas[i].empty() && i < 100)
    {
        this->CatBrain->ideas[i] = rhs.CatBrain->ideas[i];
        i++;
    }
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow~~" << std::endl;
}

void Cat::addIdea( std::string idea )
{
    int i = 0;
    while(!this->CatBrain->ideas[i].empty() && i < 100)
    {
        i++;
    }
    if (i == 99)
        this->CatBrain->ideas[0] = idea;
    else
        this->CatBrain->ideas[i] = idea;
}
void Cat::printOutIdeas(void) const
{
    int i = 0;
    if (this->CatBrain->ideas[i].empty())
    {
        std::cout << "no idea~" << std::endl;
        return ;
    }
    while(!this->CatBrain->ideas[i].empty() && i < 100)
    {
        std::cout << i << ":" << this->CatBrain->ideas[i] << std::endl;
        i++;
    }
}
