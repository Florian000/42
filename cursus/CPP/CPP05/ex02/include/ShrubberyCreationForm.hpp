#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        // Constructor
        ShrubberyCreationForm(std::string target);
        // Copy constructor
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        // Assignment operator
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
        // Destructor
        ~ShrubberyCreationForm();
        // Method to execute the form's action
        void executeAction() const;
};
