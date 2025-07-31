#include "Character.hpp"

AMateria* Character::floor[100];
int Character::floor_count = 0;

Character::Character(std::string const & name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

Character::Character(Character const & other) : name(other.name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = 0;
    }
}

Character& Character::operator=(Character const & other)
{
    if (this != &other)
    {
        name = other.name;
        
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
            {
                delete inventory[i];
                inventory[i] = 0;
            }
        }
        
        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = 0;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
        
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        if (floor_count < 1000)
        {
            floor[floor_count] = inventory[idx];
            floor_count++;
        }
        inventory[idx] = 0;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        inventory[idx]->use(target);
    }
}

void Character::cleanFloor()
{
    for (int i = 0; i < floor_count; i++)
    {
        delete floor[i];
        floor[i] = 0;
    }
    floor_count = 0;
}
