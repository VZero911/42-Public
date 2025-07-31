#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    std::cout << "=== Testing HumanA (with reference to weapon) ===" << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    
    std::cout << "\n=== Testing HumanB (with pointer to weapon) ===" << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    
    std::cout << "\n=== Testing HumanB without weapon ===" << std::endl;
    {
        HumanB unarmed("John");
        unarmed.attack();
    }
    
    return 0;
}