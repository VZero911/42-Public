#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <level>" << std::endl;
        std::cout << "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }
    
    Harl harl;
    harl.filter(argv[1]);
    
    return 0;
}