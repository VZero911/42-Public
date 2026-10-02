#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        
        delete rrf;
        
        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur");
        
        boss.signForm(*shrub);
        boss.signForm(*pardon);
        boss.executeForm(*shrub);
        boss.executeForm(*pardon);
        
        delete shrub;
        delete pardon;
        
        AForm* unknown = someRandomIntern.makeForm("coffee making", "office");
        delete unknown;
        
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}