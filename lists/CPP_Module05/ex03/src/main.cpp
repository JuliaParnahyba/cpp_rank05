/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:58:35 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 20:58:36 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

static void	processForm(Bureaucrat const &bureaucrat, AForm *form)
{
	if (!form)
		return ;
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	delete form;
}

int	main(void)
{
	Intern		intern;
	Bureaucrat	boss("Zaphod", 1);
	AForm		*robotomy;
	AForm		*shrubbery;
	AForm		*pardon;
	AForm		*unknown;

	robotomy = intern.makeForm("pedido de robotomia", "Bender");
	shrubbery = intern.makeForm("shrubbery creation", "office");
	pardon = intern.makeForm("presidential pardon", "Marvin");
	unknown = intern.makeForm("coffee request", "Arthur");

	processForm(boss, robotomy);
	processForm(boss, shrubbery);
	processForm(boss, pardon);
	delete unknown;
	return (0);
}
