#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat(void);
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat(void);

        const std::string& getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

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
        static const int HIGHEST_GRADE = 1;
        static const int LOWEST_GRADE = 150;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif