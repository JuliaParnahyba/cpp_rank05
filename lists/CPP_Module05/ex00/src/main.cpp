/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:20:56 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/24 20:38:11 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void	tryCreate(std::string const &name, int grade)
{
	try
	{
		Bureaucrat	bureaucrat(name, grade);

		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception const &exception)
	{
		std::cout << name << " failed: " << exception.what() << std::endl;
	}
}

int	main(void)
{
	Bureaucrat	arthur("Arthur Dent", 42);
	Bureaucrat	top("Top Clerk", 1);
	Bureaucrat	trainee("Trainee", 150);

	std::cout << arthur << std::endl;
	arthur.incrementGrade();
	std::cout << "After increment: " << arthur << std::endl;
	arthur.decrementGrade();
	std::cout << "After decrement: " << arthur << std::endl;

	tryCreate("Too High", 0);
	tryCreate("Too Low", 151);

	try
	{
		top.incrementGrade();
	}
	catch (std::exception const &exception)
	{
		std::cout << top.getName() << " failed: ";
		std::cout << exception.what() << std::endl;
	}
	try
	{
		trainee.decrementGrade();
	}
	catch (std::exception const &exception)
	{
		std::cout << trainee.getName() << " failed: ";
		std::cout << exception.what() << std::endl;
	}
	return (0);
}
