#include "../include/Bureaucrat.hpp"

int main()
{
	std::cout << "Creating default form, testing getters and printing with <<" << std::endl;
	try {
	Form unknown;
	std::cout << unknown;
	std::cout << unknown.getName() << std::endl;
	std::cout << unknown.getSigned() << std::endl;
	std::cout << unknown.getSignedGrade() << std::endl;
	std::cout << unknown.getExecGRade() << std::endl;
	} catch(const std::exception &e) {
		std::cerr << "Exception raised : " << e.what() << std::endl;
	}

	std::cout << std::endl <<"Creating too high grade form" << std::endl;
	try {
		Form bob("form1", 0, 100);
	} catch(const std::exception &e) {
		std::cerr << "Exception raised : " << e.what() << std::endl;
	}
	try {
		Form bob("form1", 100, 0);
	} catch(const std::exception &e) {
		std::cerr << "Exception raised : " << e.what() << std::endl;
	}

	std::cout << std::endl << "Creating form with parameters and signing it using be signed" << std::endl;
	try {
		Form form1("form1", 100, 100);
		Bureaucrat bob("bob", 10);
		std::cout << form1;
		form1.beSigned(bob);
		std::cout << form1;
		
	} catch(const std::exception &e) {
		std::cerr << "Exception raised : " << e.what() << std::endl;
	}

	std::cout << std::endl << "Creating form with parameters and signing it using signform" << std::endl;
	try {
		Form form1("form1", 100, 100);
		Bureaucrat bob("bob", 10);
		std::cout << form1;
		bob.signForm(form1);
		std::cout << form1;
		
	} catch(const std::exception &e) {
		std::cerr << "Exception raised : " << e.what() << std::endl;
	}

	std::cout << std::endl << "Creating form with parameters and trying to sign it with grade too low" << std::endl;
	try {
		Form form1("form1", 100, 100);
		Bureaucrat bob("bob", 120);
		std::cout << form1;
		bob.signForm(form1);
		std::cout << form1;
		
	} catch(const std::exception &e) {
		std::cerr << "Exception raised : " << e.what() << std::endl;
	}
	return (0);
}