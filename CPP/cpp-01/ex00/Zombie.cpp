#include "Zombie.hpp"

Zombie::Zombie(void) : name("")
{
}

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie(void)
{
    std::cout << name << " has been destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}