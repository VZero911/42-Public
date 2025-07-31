#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
}

Weapon::~Weapon(void)
{
}

const std::string& Weapon::getType() const
{
    return type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}