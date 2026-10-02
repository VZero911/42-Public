#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target);

        class UnknownFormException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:
        struct FormInfo
        {
            std::string name;
            AForm* (*creator)(const std::string& target);
        };

        static const FormInfo _formTypes[3];
        static AForm* createShrubberyForm(const std::string& target);
        static AForm* createRobotomyForm(const std::string& target);
        static AForm* createPresidentialForm(const std::string& target);
};

#endif