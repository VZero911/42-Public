#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try 
    {
        Bureaucrat invalid("Invalid", 151);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try 
    {
        Bureaucrat john("John", 75);
        john.incrementGrade();
        john.decrementGrade();
        john.decrementGrade();
    } catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try 
    {
        Bureaucrat topBureaucrat("TopGuy", 1);
        topBureaucrat.incrementGrade();
    } catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try 
    {
        Bureaucrat bottomBureaucrat("BottomGuy", 150);
        bottomBureaucrat.decrementGrade();
    } catch (std::exception& e) 
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}