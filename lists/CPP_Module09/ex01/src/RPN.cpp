/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:00:00 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:42:49 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <cctype>
#include <sstream>
#include <stdexcept>

RPN::RPN(void)
{
}

RPN::RPN(RPN const &other)
{
	(void)other;
}

RPN::~RPN(void)
{
}

RPN	&RPN::operator=(RPN const &other)
{
	(void)other;
	return (*this);
}

long	RPN::evaluate(std::string const &expression) const
{
	std::istringstream	stream(expression);
	std::stack<long>	operands;
	std::string			token;
	long				left;
	long				right;

	while (stream >> token)
	{
		if (token.length() == 1
			&& std::isdigit(static_cast<unsigned char>(token[0])))
			operands.push(token[0] - '0');
		else if (isOperator(token))
		{
			if (operands.size() < 2)
				throw (std::runtime_error("Error"));
			right = operands.top();
			operands.pop();
			left = operands.top();
			operands.pop();
			operands.push(applyOperator(left, right, token[0]));
		}
		else
			throw (std::runtime_error("Error"));
	}
	if (operands.size() != 1)
		throw (std::runtime_error("Error"));
	return (operands.top());
}

bool	RPN::isOperator(std::string const &token)
{
	if (token.length() != 1)
		return (false);
	return (token[0] == '+' || token[0] == '-'
		|| token[0] == '*' || token[0] == '/');
}

long	RPN::applyOperator(long left, long right, char operation)
{
	if (operation == '+')
		return (left + right);
	if (operation == '-')
		return (left - right);
	if (operation == '*')
		return (left * right);
	if (right == 0)
		throw (std::runtime_error("Error"));
	return (left / right);
}
