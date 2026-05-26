#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(void):
	_name("Untitled"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
}

Form::Form(std::string const &name, int signGrade, int executeGrade):
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_executeGrade(executeGrade)
{
	validateGrade(_signGrade);
	validateGrade(_executeGrade);
}

Form::Form(Form const &other):
	_name(other._name),
	_isSigned(other._isSigned),
	_signGrade(other._signGrade),
	_executeGrade(other._executeGrade)
{
}

Form	&Form::operator=(Form const &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

Form::~Form(void)
{
}

std::string const	&Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_isSigned);
}

int	Form::getSignGrade(void) const
{
	return (_signGrade);
}

int	Form::getExecuteGrade(void) const
{
	return (_executeGrade);
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw (Form::GradeTooLowException());
	_isSigned = true;
}

void	Form::validateGrade(int grade)
{
	if (grade < 1)
		throw (Form::GradeTooHighException());
	if (grade > 150)
		throw (Form::GradeTooLowException());
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("grade too high");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("grade too low");
}

std::ostream	&operator<<(std::ostream &out, Form const &form)
{
	out << form.getName() << ", signed: ";
	if (form.getIsSigned())
		out << "yes";
	else
		out << "no";
	out << ", sign grade: " << form.getSignGrade();
	out << ", execute grade: " << form.getExecuteGrade() << ".";
	return (out);
}
