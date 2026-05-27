/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:05:49 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:05:50 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

static void	testIntegers(void)
{
	int	first;
	int	second;
	int	equal_first;
	int	equal_second;

	first = 2;
	second = 3;
	::swap(first, second);
	std::cout << "first = " << first << ", second = " << second << std::endl;
	std::cout << "min(first, second) = " << ::min(first, second) << std::endl;
	std::cout << "max(first, second) = " << ::max(first, second) << std::endl;
	equal_first = 7;
	equal_second = 7;
	std::cout << "min returns second on equality: "
		<< (&::min(equal_first, equal_second) == &equal_second) << std::endl;
	std::cout << "max returns second on equality: "
		<< (&::max(equal_first, equal_second) == &equal_second) << std::endl;
}

static void	testStrings(void)
{
	std::string	first;
	std::string	second;

	first = "chaine1";
	second = "chaine2";
	::swap(first, second);
	std::cout << "first = " << first << ", second = " << second << std::endl;
	std::cout << "min(first, second) = " << ::min(first, second) << std::endl;
	std::cout << "max(first, second) = " << ::max(first, second) << std::endl;
}

int	main(void)
{
	std::cout << "[int]" << std::endl;
	testIntegers();
	std::cout << std::endl;
	std::cout << "[string]" << std::endl;
	testStrings();
	return (0);
}
