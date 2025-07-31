#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    WrongAnimal::operator=(other);
    std::cout << "WrongCat assignment operator called" << std::endl;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound!" << std::endl;
}