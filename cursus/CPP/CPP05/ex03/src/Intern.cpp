#include "../include/Intern.hpp"

// Constructor
Intern::Intern() {}

// Copy constructor
Intern::Intern(const Intern& copy)
{
    *this = copy;
}

// Assignment operator
Intern& Intern::operator=(const Intern& copy)
{
    (void)copy;
    return *this;
}

// Destructor
Intern::~Intern() {}

// Form creators
AForm* Intern::createShrubberyCreationForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

// Method to create a form
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string _formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*_formCreators[3])(const std::string&) = {createShrubberyCreationForm, createRobotomyRequestForm, createPresidentialPardonForm};
    for (int i = 0; i < 3; ++i)
    {
        if (_formNames[i] == formName)
            return _formCreators[i](target);
    }
    std::cerr << "Error: Form name " << formName << " does not exist." << std::endl;
    return NULL;
}
