#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack(void)
{
    if (weapon == NULL) {
        std::cout << name << " has no weapon to attack with!" << std::endl;
    } else {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    }
}