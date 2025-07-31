#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== ClapTrap Testing ===" << std::endl;
    
    std::cout << "\n--- Creating ClapTraps ---" << std::endl;
    ClapTrap robot1("R2-D2");
    ClapTrap robot2("C-3PO");
    
    std::cout << "\n--- Testing Attack ---" << std::endl;
    robot1.attack("Enemy Bot");
    robot2.attack("Another Enemy");
    
    std::cout << "\n--- Testing Take Damage ---" << std::endl;
    robot1.takeDamage(3);
    robot2.takeDamage(15);
    
    std::cout << "\n--- Testing Repair ---" << std::endl;
    robot1.beRepaired(5);
    robot2.beRepaired(2);
    
    std::cout << "\n--- Testing Energy Depletion ---" << std::endl;
    ClapTrap robot3("Wall-E");
    
    for (int i = 0; i < 10; i++) {
        robot3.attack("Target");
    }
    
    robot3.attack("Can't attack this");
    
    robot3.beRepaired(1);
    
    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    ClapTrap robot4(robot1);
    
    std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
    ClapTrap robot5("Temp");
    robot5 = robot1;
    
    std::cout << "\n--- Final Status ---" << std::endl;
    std::cout << robot1.getName() << " - HP: " << robot1.getHitPoints() 
              << ", Energy: " << robot1.getEnergyPoints() 
              << ", Attack: " << robot1.getAttackDamage() << std::endl;
    
    std::cout << robot3.getName() << " - HP: " << robot3.getHitPoints() 
              << ", Energy: " << robot3.getEnergyPoints() 
              << ", Attack: " << robot3.getAttackDamage() << std::endl;
    
    std::cout << "\n--- Destructors will be called automatically ---" << std::endl;
    
    return 0;
}