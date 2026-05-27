/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:08:26 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:08:27 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void	printValue(T const &value)
{
	std::cout << value << std::endl;
}

template <typename T>
void	incrementValue(T &value)
{
	value++;
}

static void	testMutableArray(void)
{
	int	numbers[5];

	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;
	numbers[4] = 5;
	std::cout << "[numbers before]" << std::endl;
	::iter(numbers, 5, printValue<int>);
	::iter(numbers, 5, incrementValue<int>);
	std::cout << "[numbers after increment]" << std::endl;
	::iter(numbers, 5, printValue<int>);
}

static void	testConstArray(void)
{
	std::string const	words[3] = {"templates", "are", "strict"};

	std::cout << "[const strings]" << std::endl;
	::iter(words, 3, printValue<std::string>);
}

int	main(void)
{
	testMutableArray();
	std::cout << std::endl;
	testConstArray();
	std::cout << std::endl;
	std::cout << "[empty array call]" << std::endl;
	::iter(static_cast<int *>(NULL), 0, printValue<int>);
	std::cout << "done" << std::endl;
	return (0);
}
