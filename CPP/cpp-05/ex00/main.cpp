#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Testing Bureaucrat Class ===" << std::endl;

    std::cout << "\n--- Test 1: Grade Too High Exception ---" << std::endl;
    try 
    {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Grade Too Low Exception ---" << std::endl;
    try 
    {
        Bureaucrat invalid("Invalid", 151);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Grade Increment/Decrement ---" << std::endl;
    try 
    {
        Bureaucrat john("John", 75);
        std::cout << "Initial: " << john << std::endl;
        
        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;
        
        john.decrementGrade();
        std::cout << "After decrement: " << john << std::endl;
        
        john.decrementGrade();
        std::cout << "After another decrement: " << john << std::endl;
    } catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Increment Beyond Highest Grade ---" << std::endl;
    try 
    {
        Bureaucrat topBureaucrat("TopGuy", 1);
        std::cout << "Before increment: " << topBureaucrat << std::endl;
        topBureaucrat.incrementGrade();
    } catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 5: Decrement Beyond Lowest Grade ---" << std::endl;
    try 
    {
        Bureaucrat bottomBureaucrat("BottomGuy", 150);
        std::cout << "Before decrement: " << bottomBureaucrat << std::endl;
        bottomBureaucrat.decrementGrade();
    } catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}