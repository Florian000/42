#pragma once
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		//Constructor
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		//Operators
		Bureaucrat& operator=(const Bureaucrat& copy);
		//Destructor
		~Bureaucrat();
		//Member function
		void incGrade();
		void decGrade();
		void signForm(Form &form);
		//Getter
		std::string getName()const;
		int getGrade()const;

		//Exeptions
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);