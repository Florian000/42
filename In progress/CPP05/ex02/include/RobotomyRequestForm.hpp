#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        // Constructor
        RobotomyRequestForm(std::string target);
        // Copy constructor
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        // Assignment operator
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
        // Destructor
        ~RobotomyRequestForm();
        // Method to execute the form's action
        void executeAction() const;
};
