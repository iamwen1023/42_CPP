#include "Fixed.hpp"

const int Fixed::_num_fb = 8;

Fixed::Fixed(void):_fp_num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called"<< std::endl;
    *this = obj;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fp_num = value << Fixed::_num_fb;
}
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fp_num = roundf(value * (1 << Fixed::_num_fb));
}
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called"<< std::endl;
    this->_fp_num = other.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
    //std::cout << "getRawBits member function called"<< std::endl;
    return this->_fp_num;
}

void Fixed::setRawBits( int const raw )
{
    //std::cout << "setRawBits member function called"<< std::endl;
    this->_fp_num = raw;
}

float Fixed::toFloat( void ) const
{
    //std::cout << "toFloat called"<< std::endl;
    return ((float)this->_fp_num / (1 << Fixed::_num_fb)); 
}

// int Fixed::toInt( void ) const
// {
//     //std::cout << "toInt called"<< std::endl;
//     return (this->_fp_num / (1 << Fixed::_num_fb)); 
// }
int Fixed::toInt(void) const 
{
	return (this->_fp_num >> Fixed::_num_fb);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return (o);
}
