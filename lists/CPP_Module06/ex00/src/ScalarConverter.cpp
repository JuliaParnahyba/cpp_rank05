/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:12:38 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 20:48:58 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cerrno>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

namespace
{
	enum SpecialKind
	{
		SPECIAL_NONE,
		SPECIAL_NAN,
		SPECIAL_POS_INF,
		SPECIAL_NEG_INF
	};

	struct ParsedLiteral
	{
		bool		valid;
		double		value;
		SpecialKind	special;
	};

	bool	isDigit(char c)
	{
		return (std::isdigit(static_cast<unsigned char>(c)) != 0);
	}

	bool	isPrintable(int c)
	{
		return (std::isprint(static_cast<unsigned char>(c)) != 0);
	}

	bool	parseSpecial(std::string const &literal, ParsedLiteral &parsed)
	{
		if (literal == "nan" || literal == "nanf")
			parsed.special = SPECIAL_NAN;
		else if (literal == "+inf" || literal == "+inff"
			|| literal == "inf" || literal == "inff")
			parsed.special = SPECIAL_POS_INF;
		else if (literal == "-inf" || literal == "-inff")
			parsed.special = SPECIAL_NEG_INF;
		else
			return (false);
		parsed.valid = true;
		if (parsed.special == SPECIAL_NAN)
			parsed.value = std::numeric_limits<double>::quiet_NaN();
		else if (parsed.special == SPECIAL_POS_INF)
			parsed.value = std::numeric_limits<double>::infinity();
		else
			parsed.value = -std::numeric_limits<double>::infinity();
		return (true);
	}

	bool	isNumberFormat(std::string const &literal)
	{
		std::string::size_type	i;
		bool					hasDigit;
		bool					hasDot;
		bool					hasSuffix;

		i = 0;
		hasDigit = false;
		hasDot = false;
		hasSuffix = false;
		if (literal.empty())
			return (false);
		if (literal[i] == '+' || literal[i] == '-')
			++i;
		while (i < literal.length())
		{
			if (isDigit(literal[i]))
				hasDigit = true;
			else if (literal[i] == '.' && !hasDot && !hasSuffix)
				hasDot = true;
			else if (literal[i] == 'f' && i + 1 == literal.length())
				hasSuffix = true;
			else
				return (false);
			++i;
		}
		if (!hasDigit)
			return (false);
		if (hasSuffix && !hasDot)
			return (false);
		return (true);
	}

	bool	parseNumber(std::string literal, ParsedLiteral &parsed)
	{
		char	*end;
		double	value;

		if (!isNumberFormat(literal))
			return (false);
		if (literal[literal.length() - 1] == 'f')
			literal.erase(literal.length() - 1);
		errno = 0;
		value = std::strtod(literal.c_str(), &end);
		if (*end != '\0')
			return (false);
		if (errno == ERANGE
			&& (value > std::numeric_limits<double>::max()
				|| value < -std::numeric_limits<double>::max()))
			return (false);
		parsed.valid = true;
		parsed.value = value;
		parsed.special = SPECIAL_NONE;
		return (true);
	}

	bool	parseChar(std::string const &literal, ParsedLiteral &parsed)
	{
		if (literal.length() == 3 && literal[0] == '\''
			&& literal[2] == '\'')
			parsed.value = static_cast<double>(literal[1]);
		else if (literal.length() == 1 && !isDigit(literal[0]))
			parsed.value = static_cast<double>(literal[0]);
		else
			return (false);
		parsed.valid = true;
		parsed.special = SPECIAL_NONE;
		return (true);
	}

	ParsedLiteral	parseLiteral(std::string const &literal)
	{
		ParsedLiteral	parsed;

		parsed.valid = false;
		parsed.value = 0.0;
		parsed.special = SPECIAL_NONE;
		if (parseSpecial(literal, parsed))
			return (parsed);
		if (parseChar(literal, parsed))
			return (parsed);
		parseNumber(literal, parsed);
		return (parsed);
	}

	std::string	formatFinite(double value, int precision)
	{
		std::ostringstream	out;
		double				integerPart;

		if (std::modf(value, &integerPart) == 0.0)
			out << std::fixed << std::setprecision(1) << value;
		else
			out << std::setprecision(precision) << value;
		return (out.str());
	}

	void	printChar(ParsedLiteral const &parsed)
	{
		char	c;

		std::cout << "char: ";
		if (!parsed.valid || parsed.special != SPECIAL_NONE
			|| parsed.value < 0.0 || parsed.value > 127.0)
		{
			std::cout << "impossible" << std::endl;
			return ;
		}
		c = static_cast<char>(parsed.value);
		if (!isPrintable(c))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;
	}

	void	printInt(ParsedLiteral const &parsed)
	{
		std::cout << "int: ";
		if (!parsed.valid || parsed.special != SPECIAL_NONE
			|| parsed.value < static_cast<double>(INT_MIN)
			|| parsed.value > static_cast<double>(INT_MAX))
		{
			std::cout << "impossible" << std::endl;
			return ;
		}
		std::cout << static_cast<int>(parsed.value) << std::endl;
	}

	void	printFloat(ParsedLiteral const &parsed)
	{
		float	value;

		std::cout << "float: ";
		if (!parsed.valid)
			std::cout << "impossible" << std::endl;
		else if (parsed.special == SPECIAL_NAN)
			std::cout << "nanf" << std::endl;
		else if (parsed.special == SPECIAL_POS_INF)
			std::cout << "+inff" << std::endl;
		else if (parsed.special == SPECIAL_NEG_INF)
			std::cout << "-inff" << std::endl;
		else if (parsed.value > std::numeric_limits<float>::max()
			|| parsed.value < -std::numeric_limits<float>::max())
			std::cout << "impossible" << std::endl;
		else
		{
			value = static_cast<float>(parsed.value);
			std::cout << formatFinite(value, 7) << "f" << std::endl;
		}
	}

	void	printDouble(ParsedLiteral const &parsed)
	{
		std::cout << "double: ";
		if (!parsed.valid)
			std::cout << "impossible" << std::endl;
		else if (parsed.special == SPECIAL_NAN)
			std::cout << "nan" << std::endl;
		else if (parsed.special == SPECIAL_POS_INF)
			std::cout << "+inf" << std::endl;
		else if (parsed.special == SPECIAL_NEG_INF)
			std::cout << "-inf" << std::endl;
		else
			std::cout << formatFinite(parsed.value, 15) << std::endl;
	}
}

ScalarConverter::ScalarConverter(void) { }

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) { }

void	ScalarConverter::convert(std::string const &literal)
{
	ParsedLiteral	parsed;

	parsed = parseLiteral(literal);
	printChar(parsed);
	printInt(parsed);
	printFloat(parsed);
	printDouble(parsed);
}
