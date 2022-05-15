#ifndef _FIXED_HPP_
# define _FIXED_HPP_
#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &obj);
        Fixed &operator=(const Fixed &other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
    private:
        int _fp_num;
        static const int _num_fb;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
# endif