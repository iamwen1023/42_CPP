#include "Animal.hpp"

Animal::Animal(void)
{
    this->type = "Default";
    std::cout << "Animal Default constructor called" << std::endl;
}
Animal::Animal(Animal const &src)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = src;
}
Animal::~Animal(void)
{
    std::cout << "Animal Destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const & rhs)
{
    std::cout << "Animal Assignment operator called" << std::endl;
    this->type = rhs.getType();
    return (*this);
}
std::string Animal::getType(void) const
{
    return (this->type);
}
void Animal::makeSound(void) const
{
    std::cout << "Animal make a noise!" << std::endl;
}