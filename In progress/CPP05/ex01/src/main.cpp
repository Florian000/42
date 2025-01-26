#include "../include/Bureaucrat.hpp"

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
    // Test 1: Default constructor for Form
    std::cout << BLUE << "Test 1: Default constructor for Form" << RESET << std::endl;
    Form f1;
    std::cout << f1;
    std::cout << "-------------------------" << std::endl << std::endl;

    // Test 2: Form instantiation with grade too high
    std::cout << BLUE << "Test 2: Form instantiation with grade too high" << RESET << std::endl;
    try {
        Form f2("Form2", 0, 50);
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    try {
        Form f3("Form3", 50, 0);
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "-------------------------" << std::endl << std::endl;

    // Test 3: Form instantiation with grade too low
    std::cout << BLUE << "Test 3: Form instantiation with grade too low" << RESET << std::endl;
    try {
        Form f4("Form4", 151, 50);
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    try {
        Form f5("Form5", 50, 151);
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "-------------------------" << std::endl << std::endl;

    // Test 4: Form signing with valid grade
    std::cout << BLUE << "Test 4: Form signing with valid grade" << RESET << std::endl;
    Bureaucrat b7("Frank", 50);
    Form f6("Form6", 75, 50);
    std::cout << f6;
    b7.signForm(f6);
    std::cout << (f6.getSigned() ? GREEN : RED) << f6 << RESET;
    std::cout << "-------------------------" << std::endl << std::endl;

    // Test 5: Form signing with grade too low
	try {
    std::cout << BLUE << "Test 5: Form signing with grade too low" << RESET << std::endl;
    Bureaucrat b8("Grace", 100);
    Form f7("Form7", 50, 25);
    std::cout << f7;
    b8.signForm(f7);
    std::cout << (f7.getSigned() ? GREEN : RED) << f7 << RESET;
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
    std::cout << "-------------------------" << std::endl << std::endl;

    // Test 6: Form beSigned method with valid grade
    std::cout << BLUE << "Test 6: Form beSigned method with valid grade" << RESET << std::endl;
    Bureaucrat b9("Hank", 30);
    Form f8("Form8", 50, 25);
    std::cout << f8;
    try {
        f8.beSigned(b9);
        std::cout << GREEN << "Form successfully signed by " << b9.getName() << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << (f8.getSigned() ? GREEN : RED) << f8 << RESET;
    std::cout << "-------------------------" << std::endl << std::endl;

    // Test 7: Form beSigned method with grade too low
    std::cout << BLUE << "Test 7: Form beSigned method with grade too low" << RESET << std::endl;
    Bureaucrat b10("Ivy", 100);
    Form f9("Form9", 50, 25);
    std::cout << f9;
    try {
        f9.beSigned(b10);
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << (f9.getSigned() ? GREEN : RED) << f9 << RESET;
    std::cout << "-------------------------" << std::endl << std::endl;

    return 0;
}