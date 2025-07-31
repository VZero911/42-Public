#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : type(type) 
{
}

AMateria::~AMateria() 
{
}

std::string const & AMateria::getType() const 
{
    return type;
}

void AMateria::use(ICharacter& target) 
{
    (void)target;
}