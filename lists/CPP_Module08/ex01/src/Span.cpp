/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:00:00 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:24:03 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <climits>
#include "Span.hpp"

char const	*Span::FullSpanException::what(void) const throw()
{
	return ("Span is full");
}

char const	*Span::TooFewNumbersException::what(void) const throw()
{
	return ("Span needs at least two numbers");
}

Span::Span(void) : _capacity(0), _numbers()
{
}

Span::Span(unsigned int n) : _capacity(n), _numbers()
{
	_numbers.reserve(n);
}

Span::Span(Span const &other) : _capacity(0), _numbers()
{
	*this = other;
}

Span::~Span(void)
{
}

Span	&Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_capacity = other._capacity;
		_numbers = other._numbers;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= static_cast<std::vector<int>::size_type>(_capacity))
		throw FullSpanException();
	_numbers.push_back(number);
}

unsigned int	Span::shortestSpan(void) const
{
	std::vector<int>				sorted;
	std::vector<int>::size_type	index;
	unsigned long				shortest;
	unsigned long				current;

	if (_numbers.size() < 2)
		throw TooFewNumbersException();
	sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	shortest = ULONG_MAX;
	index = 1;
	while (index < sorted.size())
	{
		current = static_cast<unsigned long>(
				static_cast<long>(sorted[index])
				- static_cast<long>(sorted[index - 1]));
		if (current < shortest)
			shortest = current;
		index++;
	}
	return (static_cast<unsigned int>(shortest));
}

unsigned int	Span::longestSpan(void) const
{
	std::vector<int>::const_iterator	lowest;
	std::vector<int>::const_iterator	highest;
	unsigned long					span;

	if (_numbers.size() < 2)
		throw TooFewNumbersException();
	lowest = std::min_element(_numbers.begin(), _numbers.end());
	highest = std::max_element(_numbers.begin(), _numbers.end());
	span = static_cast<unsigned long>(
			static_cast<long>(*highest) - static_cast<long>(*lowest));
	return (static_cast<unsigned int>(span));
}
