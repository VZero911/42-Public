#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int rawBits;
        static int const fractBits = 8;

    public:
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed(const int value);
        Fixed(const float value);
        Fixed& operator=(const Fixed& other);
        ~Fixed(void);

        int getRawBits(void) const;
        void setRawBits( int const raw );
        float toFloat(void) const;
        int  toInt(void) const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif