#pragma once
#include <iostream>

class Bureaucrat
{
	private:
		const std::string _name; // Name of the bureaucrat
		int _grade; // Grade of the bureaucrat
	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		// Assignment operator
		Bureaucrat& operator=(const Bureaucrat& copy);
		// Destructor
		~Bureaucrat();
		// Member functions
		void incGrade();
		void decGrade();
		// Getters
		std::string getName()const;
		int getGrade()const;

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

// Overload of the << operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);