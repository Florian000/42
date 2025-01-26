#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

// Forward declaration of Bureaucrat class
class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _is_signed;
        const int _req_grade_sign;
        const int _req_grade_exec;
    public:
        // Constructors
        AForm();
        AForm(std::string name, int req_grade_sign, int req_grade_exec);
        AForm(const AForm& copy);
        // Assignment operator
        AForm& operator=(const AForm& copy);
        // Destructor
        virtual ~AForm();
        // Member functions
        void beSigned(const Bureaucrat &bureaucrat);
        void execute(Bureaucrat const &executor) const;
        virtual void executeAction() const = 0;
        // Getters
        std::string getName() const;
        bool getSigned() const;
        int getSignedGrade() const;
        int getExecGRade() const;

        // Exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class FormNotSignedException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

// Overload of the << operator for AForm
std::ostream& operator<<(std::ostream& os, const AForm& form);
