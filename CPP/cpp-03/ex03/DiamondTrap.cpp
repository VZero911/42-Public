#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    this->hitPoints = FragTrap::getEnergyPoints();
    this->energyPoints = ScavTrap::getEnergyPoints();
    this->attackDamage = FragTrap::getAttackDamage();
    
    std::cout << "DiamondTrap " << this->name << " is forged from the finest materials!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    std::cout << "DiamondTrap " << this->name << " is replicated!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->name = other.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " is shattered into pieces!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << this->name 
              << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

std::string DiamondTrap::getDiamondName() const
{
    return this->name;
}