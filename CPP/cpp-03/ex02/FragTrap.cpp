#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << this->name << " is manufactured!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap " << this->name << " is replicated!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " is recycled!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " requests a positive high-five from everyone! ✋" << std::endl;
}