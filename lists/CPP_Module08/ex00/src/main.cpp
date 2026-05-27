/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:00:00 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:45:11 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

static void	testVector(void)
{
	std::vector<int>			values;
	std::vector<int>::iterator	found;

	values.push_back(4);
	values.push_back(8);
	values.push_back(15);
	values.push_back(16);
	values.push_back(23);
	values.push_back(42);
	found = easyfind(values, 15);
	*found = 150;
	std::cout << "vector found and changed: " << values[2] << std::endl;
}

static void	testList(void)
{
	std::list<int>			values;
	std::list<int>::iterator	found;

	values.push_back(-7);
	values.push_back(0);
	values.push_back(7);
	found = easyfind(values, 7);
	std::cout << "list found: " << *found << std::endl;
}

static void	testConstDeque(void)
{
	std::deque<int> const				values(3, 9);
	std::deque<int>::const_iterator		found;

	found = easyfind(values, 9);
	std::cout << "const deque found: " << *found << std::endl;
}

static void	testMissingValue(void)
{
	std::vector<int>	values;

	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	try
	{
		easyfind(values, 99);
	}
	catch (std::exception const &error)
	{
		std::cout << "missing value: " << error.what() << std::endl;
	}
}

int	main(void)
{
	testVector();
	testList();
	testConstDeque();
	testMissingValue();
	return (0);
}
