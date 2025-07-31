#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits (0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->rawBits = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->rawBits;
}
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->rawBits = raw;
}