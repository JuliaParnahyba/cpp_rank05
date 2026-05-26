/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:03:01 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 20:48:33 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>

static void	testLiteral(std::string const &literal)
{
	std::cout << "./convert " << literal << std::endl;
	ScalarConverter::convert(literal);
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return (0);
	}
	if (argc == 1)
	{
		testLiteral("0");
		testLiteral("nan");
		testLiteral("42.0f");
		testLiteral("'a'");
		testLiteral("hello");
		return (0);
	}
	std::cout << "Usage: ./convert <literal>" << std::endl;
	return (1);
}
