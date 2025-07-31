#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
    private:
        int rawBits;
        static int const fractBits = 8;

    public:
        Fixed(void);
        Fixed(const Fixed& other);
        ~Fixed(void);
        Fixed& operator=(const Fixed& other);
        int getRawBits(void) const;
        void setRawBits( int const raw );
};

#endif