#include "Fixed.hpp"

const int Fixed::_num_fb = 8;

Fixed::Fixed(void):_fp_num(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    //std::cout << "Copy constructor called"<< std::endl;
    *this = obj;
}

Fixed::Fixed(const int value)
{
    //std::cout << "Int constructor called" << std::endl;
    this->_fp_num = value << Fixed::_num_fb;
}
Fixed::Fixed(const float value)
{
    //std::cout << "Float constructor called" << std::endl;
    this->_fp_num = roundf(value * (1 << Fixed::_num_fb));
}

Fixed &Fixed::operator=(const Fixed &right)
{
    //std::cout << "Copy assignment operator called"<< std::endl;
    this->_fp_num = right.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &right) const
{
    return (this->getRawBits() > right.getRawBits());
}
bool Fixed::operator<(const Fixed &right) const
{
    return (this->getRawBits() < right.getRawBits());
}
bool Fixed::operator>=(const Fixed &right) const
{
    return (this->getRawBits() >= right.getRawBits());
}
bool Fixed::operator<=(const Fixed &right) const
{
    return (this->getRawBits() <= right.getRawBits());
}
bool Fixed::operator==(const Fixed &right) const
{
    return (this->getRawBits() == right.getRawBits());
}
bool Fixed::operator!=(const Fixed &right) const
{
    return (this->getRawBits() != right.getRawBits());
}

Fixed Fixed::operator+(const Fixed &right)
{
    return Fixed((this->getRawBits() + right.getRawBits()) >> Fixed::_num_fb);
}
Fixed Fixed::operator-(const Fixed &right)
{
    return Fixed((this->getRawBits() - right.getRawBits()) >> Fixed::_num_fb);
}
Fixed Fixed::operator*(const Fixed &right)
{
    return Fixed(this->toFloat() * right.toFloat());
}
Fixed Fixed::operator/(const Fixed &right)
{
    return Fixed(this->toFloat() / right.toFloat());
}

// prefix increment ++x
Fixed &Fixed::operator++(void)
{
    this->_fp_num += 1;
    return *this; 
}
// postfix increment x++
Fixed Fixed::operator++(int)
{
    Fixed old(*this);
    this->_fp_num += 1;
    return old;
}
// prefix increment --x
Fixed &Fixed::operator--(void)
{
    this->_fp_num -= 1;
    return *this; 
}
// postfix increment x--
Fixed Fixed::operator--(int)
{
    Fixed old(*this);
    this->_fp_num -= 1;
    return old;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a <= b ? (a) : (b));
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a <= b ? (a) : (b));
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a >= b ? (a) : (b));
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a >= b ? (a) : (b));
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
int Fixed::toInt( void ) const
{
    //std::cout << "toInt called"<< std::endl;
    return (this->_fp_num / (1 << Fixed::_num_fb)); 
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return (o);
}
