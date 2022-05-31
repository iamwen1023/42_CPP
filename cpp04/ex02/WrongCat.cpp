#include "WrongCat.hpp"

WrongCat::WrongCat(void):WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat Default constructor called" << std::endl;
}
WrongCat::WrongCat(WrongCat const &src):WrongAnimal()
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = src;
}
WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const & rhs)
{
    std::cout << "WrongCat Assignment operator called" << std::endl;
    this->type = rhs.getType();
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "yoyoyo~" << std::endl;
}