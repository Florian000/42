#include "../include/PresidentialPardonForm.hpp"

// Constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target) {}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm(copy), _target(copy._target) {}

// Assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    if (this != &copy)
        _target = copy._target;
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Method to execute the form's action
void PresidentialPardonForm::executeAction() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
