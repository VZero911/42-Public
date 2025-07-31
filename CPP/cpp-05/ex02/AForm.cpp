#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) :_name(name), _gradeToSign(gradeToSign) , _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm&other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

AForm::~AForm()
{}

const std::string& AForm::getName() const
{
    return this->_name;
}

bool AForm::getSigned() const
{
    return this->_signed;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

int AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

void AForm::beSigned(Bureaucrat & bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm Grade is too High !";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm Grade is too Low !";
}

std::ostream& operator<<(std::ostream & out, const AForm& AForm)
{
    out << "AForm " << AForm.getName()
        << ", signed: " << (AForm.getSigned() ? "Yes" : "No")
        << ", garde required to sign: " << AForm.getGradeToSign()
        << ", grade required to execute: " << AForm.getGradeToExecute();
    return out;
}