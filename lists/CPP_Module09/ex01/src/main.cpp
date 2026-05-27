/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:00:00 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:42:44 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <exception>
#include <iostream>
#include <stdexcept>

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (std::runtime_error("Error"));
		RPN	calculator;

		std::cout << calculator.evaluate(argv[1]) << std::endl;
	}
	catch (std::exception const &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	return (0);
}
