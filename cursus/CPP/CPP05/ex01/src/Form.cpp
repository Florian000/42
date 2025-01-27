#include "../include/Form.hpp"

// Default constructor
Form::Form(): _name("Unknown"), _is_signed(false), _req_grade_sign(100), _req_grade_exec(50) {}

// Parameterized constructor
Form::Form(std::string name, int req_grade_sign, int req_grade_exec): _name(name), _is_signed(false), _req_grade_sign(req_grade_sign), _req_grade_exec(req_grade_exec)
{
	if(req_grade_exec < 1 || req_grade_sign < 1)
	{
		throw GradeTooHighException();
		req_grade_exec = req_grade_exec < 1 ? 1 : req_grade_exec;
		req_grade_sign = req_grade_sign < 1 ? 1 : req_grade_sign;
	}
	else if (req_grade_exec > 150 || req_grade_sign > 150)
	{
		throw GradeTooLowException();
		req_grade_exec = req_grade_exec > 150 ? 150 : req_grade_exec;
		req_grade_sign = req_grade_sign > 150 ? 150 : req_grade_sign;
	}
}

// Copy constructor
Form::Form(const Form& copy): _name(copy._name), _is_signed(copy._is_signed), _req_grade_sign(copy._req_grade_sign), _req_grade_exec(copy._req_grade_exec) {}

// Assignment operator
Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
		_is_signed = copy._is_signed;
	return *this;
}

// Destructor
Form::~Form() {}

// Getter for name
std::string Form::getName() const { return (_name);}

// Getter for signed status
bool Form::getSigned() const { return (_is_signed);}

// Getter for required grade to sign
int Form::getSignedGrade() const { return (_req_grade_sign);}

// Getter for required grade to execute
int Form::getExecGRade() const { return (_req_grade_exec);}

// Method to sign the form
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _req_grade_sign)
		throw GradeTooLowException();
	else
		_is_signed = true;
}

// Exception for grade too high
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

// Exception for grade too low
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

// Overload of the << operator for Form
std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << "Form : " << form.getName()
	<< std::endl << "Form is signed : " << form.getSigned() << std::endl
	<< "sign grade required :" << form.getSignedGrade() << std::endl
	<< "Exec grade required :" << form.getExecGRade() << std::endl;
	return (os);
}