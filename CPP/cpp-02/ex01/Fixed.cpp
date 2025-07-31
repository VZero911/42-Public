#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits (0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed (const int value) : rawBits(value << fractBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float value) : rawBits(roundf(value * (1 << fractBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
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

int Fixed::toInt (void) const
{
    return this->rawBits >> fractBits;
}

float Fixed::toFloat (void) const
{
    return float(this->rawBits) / (1 << fractBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}