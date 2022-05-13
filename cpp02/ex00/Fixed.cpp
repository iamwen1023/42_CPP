#include "Fixed.hpp"
#include <iostream>

const int Fixed::_num_fb = 8;

Fixed::Fixed(void):_fp_num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &toCopy ) {
	std::cout << "Copy constructor called\n";
	*this = toCopy;
};

// Fixed::Fixed(const Fixed &obj)
// {
//     std::cout << "Copy constructor called"<< std::endl;
//     *this = obj;
// }

Fixed::~Fixed(void)
{
    std::cout << "Deconstructor called" << std::endl;
}


Fixed &Fixed::operator=(const Fixed other)
{
    std::cout << "Copy assignment operator called"<< std::endl;
    this->_fp_num = other.getRawBits();
    return *this;
}
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called"<< std::endl;
    return this->_fp_num;
}
void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called"<< std::endl;
    this->_fp_num = raw;
}