#include "Point.hpp"
#include <iostream>

Point::Point(void) : x(0), y(0)
{
    // std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
    // std::cout << "Point float constructor called" << std::endl;
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
    // std::cout << "Point copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& other)
{
    // std::cout << "Point assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Point::~Point(void)
{
    // std::cout << "Point destructor called" << std::endl;
}

Fixed Point::getX(void) const
{
    return this->x;
}

Fixed Point::getY(void) const
{
    return this->y;
}