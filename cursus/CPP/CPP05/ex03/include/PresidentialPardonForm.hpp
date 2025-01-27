#pragma once

#include "AForm.hpp"
#include <string>
#include <iostream>

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        // Constructor
        PresidentialPardonForm(std::string target);
        // Copy constructor
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        // Assignment operator
        PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
        // Destructor
        ~PresidentialPardonForm();

        // Method to execute the form's action
        void executeAction() const;
};

