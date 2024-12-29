#include "../include/Bureaucrat.hpp"

int main()
{
	std::cout << "Creating default bureaucrat, testing getters and printing with <<" << std::endl;
	try {
	Bureaucrat unknown;
	std::cout << unknown;
	std::cout << unknown.getGrade() << std::endl;
	std::cout << unknown.getName() << std::endl;
	} catch(const std::exception &e) {
		std::cerr << "Exception raised : " << e.what() << std::endl;
	}

	std::cout << std::endl <<"Creating too high bureaucrat" << std::endl;
	try {
		Bureaucrat bob("bob", 151);
	} catch(const std::exception &e) {
		std::cerr << "Exception raised : " << e.what() << std::endl;
	}

	std::cout << std::endl << "Creating too low bureaucrat" << std::endl;
	try {
		Bureaucrat bob("bob", 0);
	} catch(const std::exception &e) {
		std::cerr << "Exception raised : " << e.what() << std::endl;
	}

	std::cout << std::endl << "Incrementing too high bureaucrat" << std::endl;
	try {
		Bureaucrat bob("bob", 1);
		bob.incGrade();
	} catch(const std::exception &e) {
		std::cerr << "Exception raised : " << e.what() << std::endl;
	}

	std::cout << std::endl << "Decrementing too low bureaucrat" << std::endl;
	try {
		Bureaucrat bob("bob", 150);
		bob.decGrade();
	} catch(const std::exception &e) {
		std::cerr << "Exception raised : " << e.what() << std::endl;
	}

	std::cout << std::endl << "Testing nomal inc and dec" << std::endl;
	try {
		Bureaucrat bob("bob", 120);
		std::cout << bob;
		bob.incGrade();
		std::cout << bob;
		bob.decGrade();
		std::cout << bob;
	} catch(const std::exception &e) {
		std::cerr << "Exception raised : " << e.what() << std::endl;
	}
	return (0);
}