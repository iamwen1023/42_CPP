#include "Cat.hpp"

Cat::Cat(void):Animal()
{
    this->type = "Cat";
    std::cout << "Cat Default constructor called" << std::endl;
}
Cat::Cat(Cat const &src):Animal()
{
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = src;
}
Cat::~Cat(void)
{
    std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const & rhs)
{
    std::cout << "Cat Assignment operator called" << std::endl;
    this->type = rhs.getType();
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow~~" << std::endl;
}