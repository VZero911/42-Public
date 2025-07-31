#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{    
    std::cout << "\n=================================" << std::endl;
    std::cout << "=== ScavTrap Testing ===" << std::endl;
    
    std::cout << "\n--- Creating ScavTraps (Constructor Chaining) ---" << std::endl;
    ScavTrap scav1("Guardian");
    ScavTrap scav2("Sentinel");
    
    std::cout << "\n--- Testing ScavTrap Attack ---" << std::endl;
    scav1.attack("Bandit");
    scav2.attack("Raider");
    
    std::cout << "\n--- Testing ScavTrap Special Ability ---" << std::endl;
    scav1.guardGate();
    scav2.guardGate();
    
    std::cout << "\n--- Testing ScavTrap Inherited Functions ---" << std::endl;
    scav1.takeDamage(30);
    scav1.beRepaired(15);
    
    std::cout << "\n--- Testing ScavTrap Enhanced Stats ---" << std::endl;
    std::cout << "ScavTrap " << scav1.getName() << " stats:" << std::endl;
    std::cout << "HP: " << scav1.getHitPoints() << ", Energy: " << scav1.getEnergyPoints() 
              << ", Attack: " << scav1.getAttackDamage() << std::endl;
    
    std::cout << "\n--- Testing ScavTrap Copy Constructor ---" << std::endl;
    ScavTrap scav3(scav1);
    scav3.attack("Test Target");
    scav3.guardGate();
    
    std::cout << "\n--- Testing ScavTrap Assignment Operator ---" << std::endl;
    ScavTrap scav4("Temporary");
    scav4 = scav1;
    scav4.attack("Assigned Target");
    
    std::cout << "\n--- Testing ScavTrap Energy Management ---" << std::endl;
    ScavTrap energyTest("EnergyTester");
    
    for (int i = 0; i < 5; i++) {
        energyTest.attack("Training Dummy");
    }
    
    std::cout << "Energy remaining: " << energyTest.getEnergyPoints() << std::endl;
    
    std::cout << "\n--- Destructors will be called automatically (Destruction Chaining) ---" << std::endl;
    
    return 0;
}