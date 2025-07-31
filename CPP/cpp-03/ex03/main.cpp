#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n=================================" << std::endl;
    std::cout << "=== DiamondTrap Testing ===" << std::endl;
    
    std::cout << "\n--- Creating DiamondTraps (Virtual Inheritance) ---" << std::endl;
    DiamondTrap diamond1("Precious");
    DiamondTrap diamond2("Gemstone");
    
    std::cout << "\n--- Testing DiamondTrap Attack (ScavTrap's version) ---" << std::endl;
    diamond1.attack("Test Subject");
    diamond2.attack("Training Dummy");
    
    std::cout << "\n--- Testing DiamondTrap Special Ability ---" << std::endl;
    diamond1.whoAmI();
    diamond2.whoAmI();
    
    std::cout << "\n--- Testing Inherited Special Abilities ---" << std::endl;
    diamond1.guardGate();
    diamond1.highFivesGuys();
    diamond2.guardGate();
    diamond2.highFivesGuys();
    
    std::cout << "\n--- Testing DiamondTrap Mixed Attributes ---" << std::endl;
    std::cout << "DiamondTrap " << diamond1.getDiamondName() << " stats:" << std::endl;
    std::cout << "HP: " << diamond1.getHitPoints() << " (from FragTrap)" << std::endl;
    std::cout << "Energy: " << diamond1.getEnergyPoints() << " (from ScavTrap)" << std::endl;
    std::cout << "Attack: " << diamond1.getAttackDamage() << " (from FragTrap)" << std::endl;
    std::cout << "ClapTrap name: " << diamond1.getName() << std::endl;
    
    std::cout << "\n--- Testing DiamondTrap Damage and Repair ---" << std::endl;
    diamond1.takeDamage(25);
    diamond1.beRepaired(10);
    diamond1.whoAmI();
    
    std::cout << "\n--- Testing DiamondTrap Copy Constructor ---" << std::endl;
    DiamondTrap diamond3(diamond1);
    diamond3.whoAmI();
    diamond3.attack("Copy Target");
    
    std::cout << "\n--- Testing DiamondTrap Assignment Operator ---" << std::endl;
    DiamondTrap diamond4("Temporary");
    diamond4 = diamond1;
    diamond4.whoAmI();
    diamond4.attack("Assigned Target");
    
    std::cout << "\n--- Complete Class Hierarchy Comparison ---" << std::endl;
    ClapTrap basic2("BasicBot");
    ScavTrap guardian2("GuardBot");
    FragTrap demolisher2("BombBot");
    DiamondTrap ultimate("UltimateBot");
    
    std::cout << "\nClass Stats Summary:" << std::endl;
    std::cout << "ClapTrap   - HP: " << basic2.getHitPoints() 
              << ", Energy: " << basic2.getEnergyPoints() 
              << ", Attack: " << basic2.getAttackDamage() << std::endl;
    
    std::cout << "ScavTrap   - HP: " << guardian2.getHitPoints() 
              << ", Energy: " << guardian2.getEnergyPoints() 
              << ", Attack: " << guardian2.getAttackDamage() << std::endl;
    
    std::cout << "FragTrap   - HP: " << demolisher2.getHitPoints() 
              << ", Energy: " << demolisher2.getEnergyPoints() 
              << ", Attack: " << demolisher2.getAttackDamage() << std::endl;
    
    std::cout << "DiamondTrap - HP: " << ultimate.getHitPoints() 
              << ", Energy: " << ultimate.getEnergyPoints() 
              << ", Attack: " << ultimate.getAttackDamage() << std::endl;
    
    std::cout << "\nSpecial Abilities Demo:" << std::endl;
    basic2.attack("Target");
    guardian2.guardGate();
    demolisher2.highFivesGuys();
    ultimate.whoAmI();
    
    std::cout << "\n--- Destructors will be called automatically (Complex Destruction Chain) ---" << std::endl;
    
    return 0;
}