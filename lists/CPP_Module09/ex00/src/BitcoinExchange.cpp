/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:00:00 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:41:45 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace
{
	int	toInt(std::string const &text)
	{
		int					value;
		std::istringstream	stream(text);

		stream >> value;
		return (value);
	}

	bool	isLeapYear(int year)
	{
		if (year % 400 == 0)
			return (true);
		if (year % 100 == 0)
			return (false);
		return (year % 4 == 0);
	}

	bool	readDouble(std::string const &text, double &value)
	{
		char				extra;
		std::istringstream	stream(text);

		stream >> value;
		if (stream.fail())
			return (false);
		if (stream >> extra)
			return (false);
		return (true);
	}
}

BitcoinExchange::BitcoinExchange(void)
{
	loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
	: _rates(other._rates)
{
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
		_rates = other._rates;
	return (*this);
}

void	BitcoinExchange::loadDatabase(std::string const &fileName)
{
	std::ifstream	file(fileName.c_str());
	std::string		line;
	std::string		date;
	std::string		rateText;
	double			rate;
	std::size_t		comma;

	if (!file.is_open())
		throw (std::runtime_error("Error: could not open database."));
	std::getline(file, line);
	while (std::getline(file, line))
	{
		comma = line.find(',');
		if (comma == std::string::npos)
			continue ;
		date = trim(line.substr(0, comma));
		rateText = trim(line.substr(comma + 1));
		if (isValidDate(date) && readDouble(rateText, rate))
			_rates[date] = rate;
	}
	if (_rates.empty())
		throw (std::runtime_error("Error: empty database."));
}

void	BitcoinExchange::processInputFile(std::string const &fileName) const
{
	std::ifstream	file(fileName.c_str());
	std::string		line;

	if (!file.is_open())
		throw (std::runtime_error("Error: could not open file."));
	if (std::getline(file, line) && trim(line) != "date | value")
		processLine(line);
	while (std::getline(file, line))
		processLine(line);
}

void	BitcoinExchange::processLine(std::string const &line) const
{
	std::string		date;
	std::string		valueText;
	ValueStatus	status;
	double			value;
	double			rate;
	std::size_t		separator;

	separator = line.find(" | ");
	if (separator == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	date = trim(line.substr(0, separator));
	valueText = trim(line.substr(separator + 3));
	if (!isValidDate(date))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	status = parseValue(valueText, value);
	if (status == VALUE_NEGATIVE)
		std::cout << "Error: not a positive number." << std::endl;
	else if (status == VALUE_TOO_LARGE)
		std::cout << "Error: too large a number." << std::endl;
	else if (status == VALUE_BAD)
		std::cout << "Error: bad input => " << line << std::endl;
	else
	{
		try
		{
			rate = getRateForDate(date);
		}
		catch (std::exception const &error)
		{
			std::cout << error.what() << std::endl;
			return ;
		}
		std::cout << date << " => " << valueText << " = "
			<< value * rate << std::endl;
	}
}

double	BitcoinExchange::getRateForDate(std::string const &date) const
{
	std::map<std::string, double>::const_iterator	it;

	it = _rates.lower_bound(date);
	if (it != _rates.end() && it->first == date)
		return (it->second);
	if (it == _rates.begin())
		throw (std::runtime_error("Error: no exchange rate available."));
	--it;
	return (it->second);
}

bool	BitcoinExchange::isValidDate(std::string const &date)
{
	int			year;
	int			month;
	int			day;
	int const	daysInMonth[] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (std::size_t i = 0; i < date.length(); ++i)
	{
		if (i != 4 && i != 7
			&& !std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}
	year = toInt(date.substr(0, 4));
	month = toInt(date.substr(5, 2));
	day = toInt(date.substr(8, 2));
	if (year < 0 || month < 1 || month > 12 || day < 1)
		return (false);
	if (month == 2 && isLeapYear(year))
		return (day <= 29);
	return (day <= daysInMonth[month - 1]);
}

std::string	BitcoinExchange::trim(std::string const &text)
{
	std::size_t	begin;
	std::size_t	end;

	begin = 0;
	while (begin < text.length()
		&& std::isspace(static_cast<unsigned char>(text[begin])))
		++begin;
	end = text.length();
	while (end > begin
		&& std::isspace(static_cast<unsigned char>(text[end - 1])))
		--end;
	return (text.substr(begin, end - begin));
}

BitcoinExchange::ValueStatus	BitcoinExchange::parseValue(
	std::string const &text, double &value)
{
	std::string	clean;

	clean = trim(text);
	if (clean.empty())
		return (VALUE_BAD);
	if (clean[0] == '-')
		return (VALUE_NEGATIVE);
	if (!readDouble(clean, value))
		return (VALUE_BAD);
	if (value < 0)
		return (VALUE_NEGATIVE);
	if (value > 1000)
		return (VALUE_TOO_LARGE);
	return (VALUE_OK);
}
