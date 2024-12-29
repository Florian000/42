#include "../include/Form.hpp"

Form::Form(): _name("Unknown"), _is_signed(false), _req_grade_sign(100), _req_grade_exec(50) {}

Form::Form(std::string name, int req_grade_sign, int req_grade_exec): _name(name), _is_signed(false), _req_grade_sign(req_grade_sign), _req_grade_exec(req_grade_exec)
{
	if(req_grade_exec < 1 || req_grade_sign < 1)
		throw GradeTooHighException();
	else if (req_grade_exec > 150 || req_grade_sign > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& copy): _name(copy._name), _is_signed(copy._is_signed), _req_grade_sign(copy._req_grade_sign), _req_grade_exec(copy._req_grade_exec) {}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
		_is_signed = copy._is_signed;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const { return (_name);}
bool Form::getSigned() const { return (_is_signed);}
int Form::getSignedGrade() const { return (_req_grade_sign);}
int Form::getExecGRade() const { return (_req_grade_exec);}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _req_grade_sign)
		throw GradeTooLowException();
	else
		_is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << "Form : " << form.getName()
	<< std::endl << "Form is signed : " << form.getSigned() << std::endl
	<< "sign grade required :" << form.getSignedGrade() << std::endl
	<< "Exec grade required :" << form.getExecGRade() << std::endl;
	return (os);
}