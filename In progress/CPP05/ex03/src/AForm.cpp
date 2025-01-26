#include "../include/AForm.hpp"

// Default constructor
AForm::AForm(): _name("Unknown"), _is_signed(false), _req_grade_sign(100), _req_grade_exec(50) {}

// Parameterized constructor
AForm::AForm(std::string name, int req_grade_sign, int req_grade_exec): _name(name), _is_signed(false), _req_grade_sign(req_grade_sign), _req_grade_exec(req_grade_exec)
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
AForm::AForm(const AForm& copy): _name(copy._name), _is_signed(copy._is_signed), _req_grade_sign(copy._req_grade_sign), _req_grade_exec(copy._req_grade_exec) {}

// Assignment operator
AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
		_is_signed = copy._is_signed;
	return *this;
}

// Destructor
AForm::~AForm() {}

// Getter for name
std::string AForm::getName() const { return (_name);}

// Getter for signed status
bool AForm::getSigned() const { return (_is_signed);}

// Getter for required grade to sign
int AForm::getSignedGrade() const { return (_req_grade_sign);}

// Getter for required grade to execute
int AForm::getExecGRade() const { return (_req_grade_exec);}

// Method to sign the form
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _req_grade_sign)
		throw GradeTooLowException();
	else
		_is_signed = true;
}

// Exception for grade too high
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

// Exception for grade too low
const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

// Method to execute the form
void AForm::execute(Bureaucrat const &executor) const
{
    if (!_is_signed)
        throw FormNotSignedException();
    else if (executor.getGrade() > _req_grade_exec)
        throw GradeTooLowException();
    else
        executeAction();
}

// Exception for form not signed
const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form not signed!");
}

// Overload of the << operator for Form
std::ostream &operator<<(std::ostream &os, AForm const &form)
{
	os << "Form : " << form.getName()
	<< std::endl << "Form is signed : " << form.getSigned() << std::endl
	<< "sign grade required :" << form.getSignedGrade() << std::endl
	<< "Exec grade required :" << form.getExecGRade() << std::endl;
	return (os);
}
