#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " is assembled!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << this->name << " is copied!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " is disassembled!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->name << " can't attack because it has no hit points left!" << std::endl;
        return;
    }
    if (this->energyPoints == 0)
    {
        std::cout << "ScavTrap " << this->name << " can't attack because it has no energy points left!" << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ScavTrap " << this->name << " fiercely attacks " << target 
              << ", dealing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}