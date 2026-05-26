/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:13:44 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/24 20:37:23 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Unnamed"), _grade(150) { }

Bureaucrat::Bureaucrat(std::string const &name, int grade):
	_name(name), _grade(grade)
{
	validateGrade(_grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &other):
	_name(other._name), _grade(other._grade) { }

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) { }

std::string const	&Bureaucrat::getName(void) const { return (_name); }

int	Bureaucrat::getGrade(void) const { return (_grade); }

void	Bureaucrat::incrementGrade(void)
{
	validateGrade(_grade - 1);
	--_grade;
}

void	Bureaucrat::decrementGrade(void)
{
	validateGrade(_grade + 1);
	++_grade;
}

void	Bureaucrat::validateGrade(int grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw() { return ("grade too high"); }

const char	*Bureaucrat::GradeTooLowException::what(void) const throw() { return ("grade too low"); }

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade ";
	out << bureaucrat.getGrade() << ".";
	return (out);
}
