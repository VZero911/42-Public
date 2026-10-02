#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon Form", 25, 5), _target(target) 
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) 
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) 
{
    if (this != &other) 
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
}

const std::string& PresidentialPardonForm::getTarget() const 
{
    return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const 
{
    checkExecution(executor);
    
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}