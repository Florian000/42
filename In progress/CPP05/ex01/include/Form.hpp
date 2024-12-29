#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _req_grade_sign;
		const int _req_grade_exec;
	public:
		//Constructor
		Form();
		Form(std::string name, int req_grade_sign, int req_grade_exec);
		Form(const Form& copy);
		//Operators
		Form& operator=(const Form& copy);
		//Destructor
		~Form();
		//Member function
		void beSigned(const Bureaucrat &bureaucrat);
		//Getter
		std::string getName() const;
		bool getSigned() const;
		int getSignedGrade() const;
		int getExecGRade() const;

		//Setter
		//Exception
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

std::ostream& operator<<(std::ostream& os, const Form& form);