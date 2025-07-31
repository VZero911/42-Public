#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm &operator=(const AForm &other);
        ~AForm();

        const std::string& getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat& bureaucrat);
    
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);


#endif