#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), 
      energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap " << this->name << " is copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't attack because it has no hit points left!" << std::endl;
        return;
    }
    if (this->energyPoints == 0) 
    {
        std::cout << "ClapTrap " << this->name << " can't attack because it has no energy points left!" << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ClapTrap " << this->name << " attacks " << target 
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " is already destroyed and can't take more damage!" << std::endl;
        return;
    }
    if (amount >= this->hitPoints)
    {
        this->hitPoints = 0;
        std::cout << "ClapTrap " << this->name << " takes " << amount 
                  << " points of damage and is destroyed!" << std::endl;
    }
    else
    {
        this->hitPoints -= amount;
        std::cout << "ClapTrap " << this->name << " takes " << amount 
                  << " points of damage! Hit points remaining: " << this->hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't be repaired because it's destroyed!" << std::endl;
        return;
    }
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't be repaired because it has no energy points left!" << std::endl;
        return;
    }
    this->energyPoints--;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->name << " is repaired for " << amount 
              << " hit points! Current hit points: " << this->hitPoints << std::endl;
}

std::string ClapTrap::getName() const
{
    return this->name;
}

unsigned int ClapTrap::getHitPoints() const
{
    return this->hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return this->energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return this->attackDamage;
}