/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:00:00 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:43:21 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <cctype>
#include <climits>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <sys/time.h>

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	parseArguments(argc, argv);
}

PmergeMe::PmergeMe(PmergeMe const &other)
	: _input(other._input)
{
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other)
		_input = other._input;
	return (*this);
}

void	PmergeMe::run(void) const
{
	std::vector<int>	vectorValues;
	std::deque<int>		dequeValues;
	double				start;
	double				vectorTime;
	double				dequeTime;

	printVector("Before: ", _input);
	start = getMicroseconds();
	vectorValues = _input;
	sortVector(vectorValues);
	vectorTime = getMicroseconds() - start;
	start = getMicroseconds();
	for (std::vector<int>::const_iterator it = _input.begin();
		it != _input.end(); ++it)
		dequeValues.push_back(*it);
	sortDeque(dequeValues);
	dequeTime = getMicroseconds() - start;
	if (!isSorted(vectorValues, dequeValues))
		throw (std::runtime_error("Error"));
	printVector("After: ", vectorValues);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _input.size()
		<< " elements with std::vector : " << vectorTime << " us"
		<< std::endl;
	std::cout << "Time to process a range of " << _input.size()
		<< " elements with std::deque : " << dequeTime << " us"
		<< std::endl;
}

void	PmergeMe::parseArguments(int argc, char **argv)
{
	int	value;

	if (argc < 2)
		throw (std::runtime_error("Error"));
	for (int i = 1; i < argc; ++i)
	{
		value = parsePositiveInteger(argv[i]);
		if (containsValue(value))
			throw (std::runtime_error("Error"));
		_input.push_back(value);
	}
}

bool	PmergeMe::containsValue(int value) const
{
	for (std::vector<int>::const_iterator it = _input.begin();
		it != _input.end(); ++it)
	{
		if (*it == value)
			return (true);
	}
	return (false);
}

void	PmergeMe::sortVector(std::vector<int> &values) const
{
	std::vector<VectorPair>		pairs;
	std::vector<VectorPending>	pending;
	std::vector<int>			mainChain;
	VectorPair					pair;
	VectorPending				next;
	bool						hasOdd;
	int							odd;

	if (values.size() < 2)
		return ;
	hasOdd = (values.size() % 2 != 0);
	odd = values[values.size() - 1];
	for (std::size_t i = 0; i + 1 < values.size(); i += 2)
	{
		if (values[i] < values[i + 1])
		{
			pair.high = values[i + 1];
			pair.low = values[i];
		}
		else
		{
			pair.high = values[i];
			pair.low = values[i + 1];
		}
		pairs.push_back(pair);
		mainChain.push_back(pair.high);
	}
	sortVector(mainChain);
	for (std::size_t i = 0; i < mainChain.size(); ++i)
	{
		next.value = findVectorLow(pairs, mainChain[i]);
		next.high = mainChain[i];
		next.hasHigh = true;
		pending.push_back(next);
	}
	if (hasOdd)
	{
		next.value = odd;
		next.high = 0;
		next.hasHigh = false;
		pending.push_back(next);
	}
	values = mainChain;
	insertVectorPendings(values, pending);
}

void	PmergeMe::insertVectorPendings(std::vector<int> &values,
	std::vector<VectorPending> const &pending) const
{
	std::size_t	previousJacobsthal;
	std::size_t	currentJacobsthal;
	std::size_t	insertedLimit;
	std::size_t	groupLimit;
	std::size_t	index;

	if (pending.empty())
		return ;
	insertVectorPending(values, pending[0]);
	previousJacobsthal = 1;
	currentJacobsthal = 3;
	insertedLimit = 1;
	while (insertedLimit < pending.size())
	{
		groupLimit = currentJacobsthal;
		if (groupLimit > pending.size())
			groupLimit = pending.size();
		index = groupLimit;
		while (index > insertedLimit)
		{
			insertVectorPending(values, pending[index - 1]);
			--index;
		}
		index = currentJacobsthal + 2 * previousJacobsthal;
		previousJacobsthal = currentJacobsthal;
		currentJacobsthal = index;
		insertedLimit = groupLimit;
	}
}

void	PmergeMe::insertVectorPending(std::vector<int> &values,
	VectorPending const &pending) const
{
	std::size_t	end;
	std::size_t	position;

	end = values.size();
	if (pending.hasHigh)
		end = findVectorBound(values, pending.high);
	position = lowerBoundVector(values, pending.value, end);
	values.insert(values.begin() + position, pending.value);
}

void	PmergeMe::sortDeque(std::deque<int> &values) const
{
	std::deque<DequePair>		pairs;
	std::deque<DequePending>		pending;
	std::deque<int>				mainChain;
	DequePair					pair;
	DequePending				next;
	bool						hasOdd;
	int							odd;

	if (values.size() < 2)
		return ;
	hasOdd = (values.size() % 2 != 0);
	odd = values[values.size() - 1];
	for (std::size_t i = 0; i + 1 < values.size(); i += 2)
	{
		if (values[i] < values[i + 1])
		{
			pair.high = values[i + 1];
			pair.low = values[i];
		}
		else
		{
			pair.high = values[i];
			pair.low = values[i + 1];
		}
		pairs.push_back(pair);
		mainChain.push_back(pair.high);
	}
	sortDeque(mainChain);
	for (std::size_t i = 0; i < mainChain.size(); ++i)
	{
		next.value = findDequeLow(pairs, mainChain[i]);
		next.high = mainChain[i];
		next.hasHigh = true;
		pending.push_back(next);
	}
	if (hasOdd)
	{
		next.value = odd;
		next.high = 0;
		next.hasHigh = false;
		pending.push_back(next);
	}
	values = mainChain;
	insertDequePendings(values, pending);
}

void	PmergeMe::insertDequePendings(std::deque<int> &values,
	std::deque<DequePending> const &pending) const
{
	std::size_t	previousJacobsthal;
	std::size_t	currentJacobsthal;
	std::size_t	insertedLimit;
	std::size_t	groupLimit;
	std::size_t	index;

	if (pending.empty())
		return ;
	insertDequePending(values, pending[0]);
	previousJacobsthal = 1;
	currentJacobsthal = 3;
	insertedLimit = 1;
	while (insertedLimit < pending.size())
	{
		groupLimit = currentJacobsthal;
		if (groupLimit > pending.size())
			groupLimit = pending.size();
		index = groupLimit;
		while (index > insertedLimit)
		{
			insertDequePending(values, pending[index - 1]);
			--index;
		}
		index = currentJacobsthal + 2 * previousJacobsthal;
		previousJacobsthal = currentJacobsthal;
		currentJacobsthal = index;
		insertedLimit = groupLimit;
	}
}

void	PmergeMe::insertDequePending(std::deque<int> &values,
	DequePending const &pending) const
{
	std::size_t	end;
	std::size_t	position;

	end = values.size();
	if (pending.hasHigh)
		end = findDequeBound(values, pending.high);
	position = lowerBoundDeque(values, pending.value, end);
	values.insert(values.begin() + position, pending.value);
}

int	PmergeMe::parsePositiveInteger(std::string const &token)
{
	long	value;

	if (token.empty())
		throw (std::runtime_error("Error"));
	value = 0;
	for (std::size_t i = 0; i < token.length(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(token[i])))
			throw (std::runtime_error("Error"));
		value = value * 10 + (token[i] - '0');
		if (value > INT_MAX)
			throw (std::runtime_error("Error"));
	}
	if (value <= 0)
		throw (std::runtime_error("Error"));
	return (static_cast<int>(value));
}

int	PmergeMe::findVectorLow(std::vector<VectorPair> const &pairs, int high)
{
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].high == high)
			return (pairs[i].low);
	}
	throw (std::runtime_error("Error"));
}

std::size_t	PmergeMe::findVectorBound(std::vector<int> const &values, int high)
{
	for (std::size_t i = 0; i < values.size(); ++i)
	{
		if (values[i] == high)
			return (i);
	}
	throw (std::runtime_error("Error"));
}

std::size_t	PmergeMe::lowerBoundVector(std::vector<int> const &values,
	int value, std::size_t end)
{
	std::size_t	begin;
	std::size_t	middle;

	begin = 0;
	while (begin < end)
	{
		middle = begin + (end - begin) / 2;
		if (values[middle] < value)
			begin = middle + 1;
		else
			end = middle;
	}
	return (begin);
}

int	PmergeMe::findDequeLow(std::deque<DequePair> const &pairs, int high)
{
	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].high == high)
			return (pairs[i].low);
	}
	throw (std::runtime_error("Error"));
}

std::size_t	PmergeMe::findDequeBound(std::deque<int> const &values, int high)
{
	for (std::size_t i = 0; i < values.size(); ++i)
	{
		if (values[i] == high)
			return (i);
	}
	throw (std::runtime_error("Error"));
}

std::size_t	PmergeMe::lowerBoundDeque(std::deque<int> const &values,
	int value, std::size_t end)
{
	std::size_t	begin;
	std::size_t	middle;

	begin = 0;
	while (begin < end)
	{
		middle = begin + (end - begin) / 2;
		if (values[middle] < value)
			begin = middle + 1;
		else
			end = middle;
	}
	return (begin);
}

double	PmergeMe::getMicroseconds(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		throw (std::runtime_error("Error"));
	return (static_cast<double>(time.tv_sec) * 1000000.0
		+ static_cast<double>(time.tv_usec));
}

void	PmergeMe::printVector(char const *label,
	std::vector<int> const &values)
{
	std::cout << label;
	for (std::size_t i = 0; i < values.size(); ++i)
	{
		if (i != 0)
			std::cout << ' ';
		std::cout << values[i];
	}
	std::cout << std::endl;
}

bool	PmergeMe::isSorted(std::vector<int> const &values,
	std::deque<int> const &other)
{
	if (values.size() != other.size())
		return (false);
	for (std::size_t i = 0; i < values.size(); ++i)
	{
		if (values[i] != other[i])
			return (false);
		if (i > 0 && values[i - 1] > values[i])
			return (false);
	}
	return (true);
}
