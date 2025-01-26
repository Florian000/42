#pragma once

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        static AForm* createShrubberyCreationForm(const std::string &target);
        static AForm* createRobotomyRequestForm(const std::string &target);
        static AForm* createPresidentialPardonForm(const std::string &target);
    public:
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& copy);
        ~Intern();
        AForm* makeForm(const std::string& formName, const std::string& target);

        class FormNotFoundException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};
