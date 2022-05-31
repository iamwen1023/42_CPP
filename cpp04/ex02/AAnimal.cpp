#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    this->type = "Default";
    std::cout << "AAnimal Default constructor called" << std::endl;
}
AAnimal::AAnimal(AAnimal const &src)
{
    std::cout << "AAnimal Copy constructor called" << std::endl;
    *this = src;
}
AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const & rhs)
{
    std::cout << "AAnimal Assignment operator called" << std::endl;
    this->type = rhs.getType();
    return (*this);
}
std::string AAnimal::getType(void) const
{
    return (this->type);
}
void AAnimal::makeSound(void) const
{
    std::cout << "AAnimal make a noise!" << std::endl;
}
void	AAnimal::printOutIdeas( void ) const
{
    return ;
}
void	AAnimal::addIdea(std::string idea)
{
    (void)idea;
    return ;
}