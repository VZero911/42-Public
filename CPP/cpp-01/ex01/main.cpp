#include "Zombie.hpp"

int main()
{
    int hordeSize = 5;
    std::string zombieName = "HordeMember";
    
    std::cout << "=== Creating a horde of " << hordeSize << " zombies ===" << std::endl;
    
    Zombie* horde = zombieHorde(hordeSize, zombieName);
    
    if (horde == NULL)
    {
        std::cout << "Failed to create zombie horde!" << std::endl;
        return 1;
    }
    
    std::cout << "\n=== Making the horde announce themselves ===" << std::endl;
    
    for (int i = 0; i < hordeSize; i++)
    {
        std::cout << "Zombie " << i << ": ";
        horde[i].announce();
    }
    
    std::cout << "\n=== Testing with different names ===" << std::endl;
    
    horde[0].setName("Leader");
    horde[1].setName("Follower");
    
    std::cout << "After renaming first two zombies:" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Zombie " << i << ": ";
        horde[i].announce();
    }
    
    std::cout << "\n=== Destroying the horde ===" << std::endl;
    
    delete[] horde;
    
    std::cout << "\n=== Testing edge cases ===" << std::endl;
    
    Zombie* singleZombie = zombieHorde(1, "Loner");
    if (singleZombie)
    {
        singleZombie->announce();
        delete[] singleZombie;
    }
    
    Zombie* noZombies = zombieHorde(0, "None");
    if (noZombies == NULL)
    {
        std::cout << "Correctly handled zero zombie request" << std::endl;
    }
    
    std::cout << "\n=== Program ending ===" << std::endl;
    
    return 0;
}