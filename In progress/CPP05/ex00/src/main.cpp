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
    // Test 1: Default constructor
    std::cout << BLUE << "Test 1: Default constructor" << RESET << std::endl;
    Bureaucrat b1;
    std::cout << b1;
    std::cout << "-------------------------" << std::endl << std::endl;

    // Test 2: Parameterized constructor with valid grade
    std::cout << BLUE << "Test 2: Parameterized constructor with valid grade" << RESET << std::endl;
    Bureaucrat b2("Alice", 75);
    std::cout << b2;
    std::cout << "-------------------------" << std::endl << std::endl;

    // Test 3: Parameterized constructor with grade too high
    std::cout << BLUE << "Test 3: Parameterized constructor with grade too high" << RESET << std::endl;
    try {
        Bureaucrat b3("Bob", 0);
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "-------------------------" << std::endl << std::endl;

    // Test 4: Parameterized constructor with grade too low
    std::cout << BLUE << "Test 4: Parameterized constructor with grade too low" << RESET << std::endl;
    try {
        Bureaucrat b4("Charlie", 151);
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "-------------------------" << std::endl << std::endl;

    // Test 5: Increment grade
    std::cout << BLUE << "Test 5: Increment grade" << RESET << std::endl;
    Bureaucrat b5("Dave", 2);
    std::cout << b5;
    b5.incGrade();
    std::cout << b5;
    try {
        b5.incGrade();
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "-------------------------" << std::endl << std::endl;

    // Test 6: Decrement grade
    std::cout << BLUE << "Test 6: Decrement grade" << RESET << std::endl;
    Bureaucrat b6("Eve", 149);
    std::cout << b6;
    b6.decGrade();
    std::cout << b6;
    try {
        b6.decGrade();
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "-------------------------" << std::endl << std::endl;

    return 0;
}