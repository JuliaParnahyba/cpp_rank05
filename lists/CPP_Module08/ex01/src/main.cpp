/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:00:00 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:23:59 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"

static void	testSubjectExample(void)
{
	Span	sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "subject shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "subject longest: " << sp.longestSpan() << std::endl;
}

static void	testExceptions(void)
{
	Span	empty(1);

	try
	{
		empty.shortestSpan();
	}
	catch (std::exception const &error)
	{
		std::cout << "too few numbers: " << error.what() << std::endl;
	}
	try
	{
		empty.addNumber(1);
		empty.addNumber(2);
	}
	catch (std::exception const &error)
	{
		std::cout << "full span: " << error.what() << std::endl;
	}
}

static void	testIteratorRange(void)
{
	Span				large(10000);
	std::vector<int>	values;
	int					index;

	index = 0;
	while (index < 10000)
	{
		values.push_back(index * 2);
		index++;
	}
	large.addNumbers(values.begin(), values.end());
	std::cout << "large shortest: " << large.shortestSpan() << std::endl;
	std::cout << "large longest: " << large.longestSpan() << std::endl;
}

static void	testRangeOverflow(void)
{
	Span				small(2);
	std::vector<int>	values;

	values.push_back(10);
	values.push_back(20);
	values.push_back(30);
	try
	{
		small.addNumber(values.begin(), values.end());
	}
	catch (std::exception const &error)
	{
		std::cout << "range overflow: " << error.what() << std::endl;
	}
}

int	main(void)
{
	testSubjectExample();
	std::cout << std::endl;
	testExceptions();
	std::cout << std::endl;
	testIteratorRange();
	std::cout << std::endl;
	testRangeOverflow();
	return (0);
}
