#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n=================================" << std::endl;
    std::cout << "=== FragTrap Testing ===" << std::endl;
    
    std::cout << "\n--- Creating FragTraps (Constructor Chaining) ---" << std::endl;
    FragTrap frag1("Bomber");
    FragTrap frag2("Exploder");
    
    std::cout << "\n--- Testing FragTrap Attack ---" << std::endl;
    frag1.attack("Target Dummy");
    frag2.attack("Practice Bot");
    
    std::cout << "\n--- Testing FragTrap Special Ability ---" << std::endl;
    frag1.highFivesGuys();
    frag2.highFivesGuys();
    
    std::cout << "\n--- Testing FragTrap Inherited Functions ---" << std::endl;
    frag1.takeDamage(40);
    frag1.beRepaired(20);
    
    std::cout << "\n--- Testing FragTrap Enhanced Stats ---" << std::endl;
    std::cout << "FragTrap " << frag1.getName() << " stats:" << std::endl;
    std::cout << "HP: " << frag1.getHitPoints() << ", Energy: " << frag1.getEnergyPoints() 
              << ", Attack: " << frag1.getAttackDamage() << std::endl;
    
    std::cout << "\n--- Testing FragTrap Copy Constructor ---" << std::endl;
    FragTrap frag3(frag1);
    frag3.attack("Copy Target");
    frag3.highFivesGuys();
    
    std::cout << "\n--- Testing FragTrap Assignment Operator ---" << std::endl;
    FragTrap frag4("TempFrag");
    frag4 = frag1;
    frag4.attack("Assigned Target");
    frag4.highFivesGuys();
    
    std::cout << "\n--- Class Comparison ---" << std::endl;
    ClapTrap basic("Basic");
    ScavTrap guardian("Guardian");
    FragTrap demolisher("Demolisher");
    
    std::cout << "ClapTrap stats - HP: " << basic.getHitPoints() 
              << ", Energy: " << basic.getEnergyPoints() 
              << ", Attack: " << basic.getAttackDamage() << std::endl;
    
    std::cout << "ScavTrap stats - HP: " << guardian.getHitPoints() 
              << ", Energy: " << guardian.getEnergyPoints() 
              << ", Attack: " << guardian.getAttackDamage() << std::endl;
    
    std::cout << "FragTrap stats - HP: " << demolisher.getHitPoints() 
              << ", Energy: " << demolisher.getEnergyPoints() 
              << ", Attack: " << demolisher.getAttackDamage() << std::endl;
    
    std::cout << "\n--- Special Abilities Showcase ---" << std::endl;
    basic.attack("Common Enemy");
    guardian.guardGate();
    demolisher.highFivesGuys();
    
    std::cout << "\n--- Destructors will be called automatically (Destruction Chaining) ---" << std::endl;
    
    return 0;
}