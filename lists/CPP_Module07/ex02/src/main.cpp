/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:08:54 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:08:55 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750

static void	testIntegerArray(void)
{
	Array<int>		numbers(MAX_VAL);
	int				*mirror;
	unsigned int	index;
	int				value;
	bool			matches;

	mirror = new int[MAX_VAL];
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	index = 0;
	while (index < MAX_VAL)
	{
		value = std::rand();
		numbers[index] = value;
		mirror[index] = value;
		index++;
	}
	{
		Array<int>	tmp(numbers);
		Array<int>	test;

		test = tmp;
		tmp[0] = -1;
		test[1] = -2;
	}
	index = 0;
	matches = true;
	while (index < MAX_VAL)
	{
		if (mirror[index] != numbers[index])
			matches = false;
		index++;
	}
	delete [] mirror;
	std::cout << "integer copy keeps original intact: " << matches << std::endl;
}

static void	testStringArray(void)
{
	Array<std::string>	words(2);
	Array<std::string>	copy;

	words[0] = "alpha";
	words[1] = "beta";
	copy = words;
	copy[0] = "changed";
	words[1] = "updated";
	std::cout << "words size: " << words.size() << std::endl;
	std::cout << "original[0]: " << words[0] << std::endl;
	std::cout << "copy[0]: " << copy[0] << std::endl;
	std::cout << "copy[1]: " << copy[1] << std::endl;
}

static void	testErrors(void)
{
	Array<int>	empty;
	Array<int>	values(3);

	std::cout << "empty size: " << empty.size() << std::endl;
	try
	{
		empty[0] = 42;
	}
	catch (std::exception const &error)
	{
		std::cout << "empty[0]: " << error.what() << std::endl;
	}
	try
	{
		values[-1] = 42;
	}
	catch (std::exception const &error)
	{
		std::cout << "values[-1]: " << error.what() << std::endl;
	}
	try
	{
		values[values.size()] = 42;
	}
	catch (std::exception const &error)
	{
		std::cout << "values[size]: " << error.what() << std::endl;
	}
}

int	main(void)
{
	testIntegerArray();
	std::cout << std::endl;
	testStringArray();
	std::cout << std::endl;
	testErrors();
	return (0);
}
