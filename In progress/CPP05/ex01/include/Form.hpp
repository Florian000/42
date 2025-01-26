#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

// Forward declaration of Bureaucrat class
class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _req_grade_sign;
		const int _req_grade_exec;
	public:
		 // Constructors
		Form();
		Form(std::string name, int req_grade_sign, int req_grade_exec);
		Form(const Form& copy);
		// Assignment operator
		Form& operator=(const Form& copy);
		// Destructor
		~Form();
		// Member function
		void beSigned(const Bureaucrat &bureaucrat);
		// Getters
		std::string getName() const;
		bool getSigned() const;
		int getSignedGrade() const;
		int getExecGRade() const;

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

// Overload of the << operator for Form
std::ostream& operator<<(std::ostream& os, const Form& form);