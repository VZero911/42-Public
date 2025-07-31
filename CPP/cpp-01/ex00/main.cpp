#include "Zombie.hpp"

int main()
{
    std::cout << "=== Testing newZombie (heap allocation) ===" << std::endl;
    
    Zombie* heapZombie = newZombie("HeapWalker");
    heapZombie->announce();
    
    std::cout << "\n=== Testing randomChump (stack allocation) ===" << std::endl;
    
    randomChump("StackBiter");
    
    std::cout << "\n=== Main function continues ===" << std::endl;
    std::cout << "HeapWalker is still alive and can announce:" << std::endl;
    heapZombie->announce();
    
    std::cout << "\n=== Cleaning up heap zombie ===" << std::endl;
    std::cout << "About to delete HeapWalker..." << std::endl;
    delete heapZombie;
    std::cout << "Delete operation completed" << std::endl;
    
    std::cout << "\n=== Program ending ===" << std::endl;
    
    return 0;
}