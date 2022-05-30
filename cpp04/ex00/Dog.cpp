#include "Dog.hpp"

Dog::Dog(void):Animal()
{
    this->type = "Dog";
    std::cout << "Dog Default constructor called" << std::endl;
}
Dog::Dog(Dog const &src):Animal()
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = src;
}
Dog::~Dog(void)
{
    std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const & rhs)
{
    std::cout << "Dog Assignment operator called" << std::endl;
    this->type = rhs.getType();
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Woof!" << std::endl;
}