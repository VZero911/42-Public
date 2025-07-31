#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"

#include <iostream>

int main()
{
    std::cout << "=== Basic test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << "\n=== Additional tests ===" << std::endl;
    
    IMateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());
    
    ICharacter* alice = new Character("alice");
    
    for (int i = 0; i < 5; i++)
    {
        AMateria* materia = src2->createMateria("ice");
        alice->equip(materia);
        std::cout << "Equipped materia " << i + 1 << std::endl;
    }
    
    ICharacter* target = new Character("target");
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Using slot " << i << ": ";
        alice->use(i, *target);
    }
    
    alice->unequip(0);
    std::cout << "After unequipping slot 0: ";
    alice->use(0, *target);
    
    Character* alice_copy = new Character(*((Character*)alice));
    std::cout << "Copy using slot 1: ";
    alice_copy->use(1, *target);
    
    AMateria* unknown = src2->createMateria("fire");
    if (!unknown)
        std::cout << "Unknown materia type correctly returned null" << std::endl;
    
    delete target;
    delete alice;
    delete alice_copy;
    delete src2;
    
    Character::cleanFloor();

    return 0;
}