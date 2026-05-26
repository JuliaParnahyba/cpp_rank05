#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void):
	_name("Untitled"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
}

AForm::AForm(std::string const &name, int signGrade, int executeGrade):
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_executeGrade(executeGrade)
{
	validateGrade(_signGrade);
	validateGrade(_executeGrade);
}

AForm::AForm(AForm const &other):
	_name(other._name),
	_isSigned(other._isSigned),
	_signGrade(other._signGrade),
	_executeGrade(other._executeGrade)
{
}

AForm	&AForm::operator=(AForm const &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm(void)
{
}

std::string const	&AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getIsSigned(void) const
{
	return (_isSigned);
}

int	AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int	AForm::getExecuteGrade(void) const
{
	return (_executeGrade);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw (AForm::GradeTooLowException());
	_isSigned = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw (AForm::FormNotSignedException());
	if (executor.getGrade() > _executeGrade)
		throw (AForm::GradeTooLowException());
	executeAction();
}

void	AForm::validateGrade(int grade)
{
	if (grade < 1)
		throw (AForm::GradeTooHighException());
	if (grade > 150)
		throw (AForm::GradeTooLowException());
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("grade too high");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("grade too low");
}

const char	*AForm::FormNotSignedException::what(void) const throw()
{
	return ("form is not signed");
}

std::ostream	&operator<<(std::ostream &out, AForm const &form)
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
