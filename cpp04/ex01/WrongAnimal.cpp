#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    this->type = "Default";
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    *this = src;
}
WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const & rhs)
{
    std::cout << "WrongAnimal Assignment operator called" << std::endl;
    this->type = rhs.getType();
    return (*this);
}
std::string WrongAnimal::getType(void) const
{
    return (this->type);
}
void WrongAnimal::makeSound(void) const
{
    std::cout << "Animal make a noise!" << std::endl;
}