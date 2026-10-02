#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    
    try {
        Bureaucrat president("President", 1);
        Bureaucrat manager("Manager", 50);
        Bureaucrat intern("Intern", 150);
        
        ShrubberyCreationForm shrubForm("garden");
        RobotomyRequestForm robotForm("C-3PO");
        PresidentialPardonForm pardonForm("Ford Prefect");
        
        intern.signForm(shrubForm);
        intern.executeForm(shrubForm);
        
        manager.executeForm(shrubForm);

        manager.signForm(shrubForm);

        manager.executeForm(shrubForm);        
        manager.signForm(robotForm);
        manager.executeForm(robotForm);
        manager.executeForm(robotForm);
        
        manager.signForm(pardonForm);
        
        president.signForm(pardonForm);
        president.executeForm(pardonForm);
        
        RobotomyRequestForm unsignedForm("R2-D2");
        president.executeForm(unsignedForm);
        
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}