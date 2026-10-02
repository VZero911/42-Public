#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Form validForm("Tax Form", 50, 25);
        std::cout << validForm << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try {
        Form invalidForm2("Invalid Form", 50, 200);
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat highRank("Alice", 20);
        Bureaucrat lowRank("Bob", 100);
        Form importantForm("Important Document", 50, 25);
        Form veryImportantForm("Very Important Document", 10, 5);
        
        std::cout << highRank << std::endl;
        std::cout << lowRank << std::endl;
        std::cout << importantForm << std::endl;
        std::cout << veryImportantForm << std::endl;
        
        std::cout << "\n--- Signing Tests ---" << std::endl;
        
        highRank.signForm(importantForm);
        highRank.signForm(veryImportantForm);
        
        std::cout << importantForm << std::endl;
        std::cout << veryImportantForm << std::endl;
        
        Form anotherForm("Another Form", 50, 25);
        Form restrictedForm("Restricted Form", 10, 5);
        
        lowRank.signForm(anotherForm);
        lowRank.signForm(restrictedForm);
        
        std::cout << anotherForm << std::endl;
        std::cout << restrictedForm << std::endl;
        
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}