/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:56:25 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 20:56:26 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void	tryCreateForm(std::string const &name, int sign, int execute)
{
	try
	{
		Form	form(name, sign, execute);

		std::cout << form << std::endl;
	}
	catch (std::exception const &exception)
	{
		std::cout << name << " failed: " << exception.what() << std::endl;
	}
}

int	main(void)
{
	Bureaucrat	manager("Ford Prefect", 40);
	Bureaucrat	assistant("Arthur Dent", 120);
	Form		permit("Intergalactic Travel Permit", 75, 50);

	std::cout << manager << std::endl;
	std::cout << assistant << std::endl;
	std::cout << permit << std::endl;

	assistant.signForm(permit);
	manager.signForm(permit);
	std::cout << permit << std::endl;

	tryCreateForm("Impossible High", 0, 50);
	tryCreateForm("Impossible Low", 42, 151);
	return (0);
}
