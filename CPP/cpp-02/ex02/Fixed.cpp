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

bool Fixed::operator>(const Fixed& other) const
{
    return this->rawBits > other.rawBits;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->rawBits < other.rawBits;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->rawBits >= other.rawBits;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->rawBits <= other.rawBits;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->rawBits == other.rawBits;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->rawBits != other.rawBits;
}

Fixed Fixed::operator+(const Fixed& other) const

{
    Fixed result;
    result.rawBits = (this->rawBits + other.rawBits);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const

{
    Fixed result;
    result.rawBits = (this->rawBits - other.rawBits);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const

{
    Fixed result;
    result.rawBits = ((this->rawBits * other.rawBits) >> fractBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const

{
    Fixed result;
    result.rawBits = ((this->rawBits << fractBits) / other.rawBits);
    return result;
}

Fixed& Fixed::operator++(void)
{
    this->rawBits++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->rawBits++;
    return temp;
}

Fixed& Fixed::operator--(void)
{
    this->rawBits--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->rawBits--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}