#include "Harl.hpp"
#include <iostream>

int main()
{
    Harl harl;
    
    std::cout << "Testing Harl's complaints:" << std::endl;
    std::cout << "=========================" << std::endl;
    
    std::cout << "\nDEBUG level:" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "\nINFO level:" << std::endl;
    harl.complain("INFO");
    
    std::cout << "\nWARNING level:" << std::endl;
    harl.complain("WARNING");
    
    std::cout << "\nERROR level:" << std::endl;
    harl.complain("ERROR");
    
    std::cout << "\nTesting invalid level:" << std::endl;
    harl.complain("INVALID");
    
    std::cout << "\nTesting case sensitivity:" << std::endl;
    harl.complain("debug");
    
    return 0;
}