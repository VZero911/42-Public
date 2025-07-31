#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") 
{
}

Ice::~Ice() 
{
}

Ice* Ice::clone() const 
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target) 
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}