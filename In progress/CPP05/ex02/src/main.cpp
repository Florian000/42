#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

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
    try {
        Bureaucrat john("John", 1);
        Bureaucrat jane("Jane", 150);

        ShrubberyCreationForm shrubbery1("home");
        ShrubberyCreationForm shrubbery2("garden");
        RobotomyRequestForm robotomy("office");
        PresidentialPardonForm pardon("criminal");

        std::cout << GREEN << "Testing ShrubberyCreationForm (home):" << RESET << std::endl;
        john.signForm(shrubbery1);
        john.executeForm(shrubbery1);
        std::cout << "----------------------------------------" << std::endl << std::endl;

        std::cout << GREEN << "Testing ShrubberyCreationForm (garden):" << RESET << std::endl;
        john.signForm(shrubbery2);
        john.executeForm(shrubbery2);
        std::cout << "----------------------------------------" << std::endl << std::endl;

        std::cout << GREEN << "Testing RobotomyRequestForm:" << RESET << std::endl;
        john.signForm(robotomy);
        john.executeForm(robotomy);
        std::cout << "----------------------------------------" << std::endl << std::endl;

        std::cout << GREEN << "Testing PresidentialPardonForm:" << RESET << std::endl;
        john.signForm(pardon);
        john.executeForm(pardon);
        std::cout << "----------------------------------------" << std::endl << std::endl;

        std::cout << RED << "Testing with low-grade bureaucrat:" << RESET << std::endl;
        jane.executeForm(shrubbery1);
        std::cout << "----------------------------------------" << std::endl << std::endl;

        std::cout << RED << "Testing execution without signing:" << RESET << std::endl;
        RobotomyRequestForm unsignedForm("unsigned");
        john.executeForm(unsignedForm);
        std::cout << "----------------------------------------" << std::endl << std::endl;

        std::cout << GREEN << "Testing RobotomyRequestForm failing half the time" << RESET << std::endl;
        for (int i = 0; i < 10; ++i) {
            john.executeForm(robotomy);
            std::cout << std::endl; 
        }
        std::cout << "----------------------------------------" << std::endl << std::endl;

    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    return 0;
}