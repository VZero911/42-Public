#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(LOWEST_GRADE) 
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) 
{
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    if (grade < HIGHEST_GRADE) 
        throw GradeTooHighException();
    if (grade > LOWEST_GRADE) 
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) 
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &other) 
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() 
{
    std::cout << "Bureaucrat destructor called for " << _name << std::endl;
}

const std::string& Bureaucrat::getName() const 
{
    return this->_name;
}

int Bureaucrat::getGrade() const 
{
    return this->_grade;
}

void Bureaucrat::incrementGrade() 
{
    if (_grade <= HIGHEST_GRADE) 
        throw GradeTooHighException();
    _grade--;
    std::cout << _name << "'s grade incremented to " << _grade << std::endl;
}

void Bureaucrat::decrementGrade() 
{
    if (_grade >= LOWEST_GRADE) 
        throw GradeTooLowException();
    _grade++;
    std::cout << _name << "'s grade decremented to " << _grade << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Grade is too high! (Minimum grade is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Grade is too low! (Maximum grade is 150)";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) 
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
    
}