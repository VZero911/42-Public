#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :_name(name), _gradeToSign(gradeToSign) , _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form&other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

Form::~Form()
{}

const std::string& Form::getName() const
{
    return this->_name;
}

bool Form::getSigned() const
{
    return this->_signed;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

void Form::beSigned(Bureaucrat & bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Grade is too High !";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Grade is too Low !";
}

std::ostream& operator<<(std::ostream & out, const Form& Form)
{
    out << "Form " << Form.getName()
        << ", signed: " << (Form.getSigned() ? "Yes" : "No")
        << ", garde required to sign: " << Form.getGradeToSign()
        << ", grade required to execute: " << Form.getGradeToExecute();
    return out;
}