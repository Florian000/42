#include "../include/Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat(): _name("Unknown"), _grade(150) {}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if(grade < 1)
	{
		throw GradeTooHighException();
		_grade = 1;
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
		_grade = 150;
	}
	else
		_grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name), _grade(copy._grade) {}

// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
		_grade = copy._grade;
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getter for name
std::string Bureaucrat::getName()const
{
	return (_name);
}

// Getter for grade
int Bureaucrat::getGrade()const
{
	return (_grade);
}

// Increment grade
void Bureaucrat::incGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	else
		_grade--;
}

// Decrement grade
void Bureaucrat::decGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	else
		_grade++;
}

// Exception message for GradeTooHighException
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

// Exception message for GradeTooLowException
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

// Overload of the << operator
std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (os);
}
