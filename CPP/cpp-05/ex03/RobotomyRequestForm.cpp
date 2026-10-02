#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), _target(target) 
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) 
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) 
{
    if (this != &other) 
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
}

const std::string& RobotomyRequestForm::getTarget() const 
{
    return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const 
{
    checkExecution(executor);
    
    std::cout << "* DRILLING NOISES * BZZZZZZ * WHIRRRRR * CLANK CLANK *" << std::endl;
    
    static bool seeded = false;
    if (!seeded) 
    {
        srand(time(NULL));
        seeded = true;
    }
    
    if (rand() % 2 == 0) 
    {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else 
    {
        std::cout << "Robotomy of " << _target << " failed!" << std::endl;
    }
}