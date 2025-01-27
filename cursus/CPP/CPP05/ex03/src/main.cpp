#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main()
{
    Intern someRandomIntern;
    AForm* form;

    std::cout << GREEN << "=== Test 1: Robotomy Request Form ===" << RESET << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        Bureaucrat bureaucrat("John", 1);
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    }
    std::cout << std::endl;

    std::cout << GREEN << "=== Test 2: Shrubbery Creation Form ===" << RESET << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form)
    {
        Bureaucrat bureaucrat("Jane", 50);
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    }
    std::cout << std::endl;

    std::cout << GREEN << "=== Test 3: Presidential Pardon Form ===" << RESET << std::endl;
    form = someRandomIntern.makeForm("presidential pardon", "Alice");
    if (form)
    {
        Bureaucrat bureaucrat("Alice", 5);
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    }
    std::cout << std::endl;

    std::cout << RED<< "=== Test 4: Unknown Form ===" << RESET << std::endl;
    form = someRandomIntern.makeForm("unknown form", "Target");
    if (form)
    {
        delete form;
    }
    std::cout << std::endl;

    return 0;
}