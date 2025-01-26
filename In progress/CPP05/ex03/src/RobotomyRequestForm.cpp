#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

// Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::srand(std::time(NULL));
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy), _target(copy._target) {}

// Assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    if (this != &copy)
        _target = copy._target;
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Method to execute the form's action
void RobotomyRequestForm::executeAction() const
{
    std::cout << "Drilling noises..." << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy failed." << std::endl;
}
