/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:00:00 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:23:53 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>

class Span
{
	public:
		class FullSpanException : public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};

		class TooFewNumbersException : public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};

		Span(void);
		Span(unsigned int n);
		Span(Span const &other);
		~Span(void);

		Span			&operator=(Span const &other);
		void			addNumber(int number);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		template <typename Iterator>
		void			addNumber(Iterator first, Iterator last);

		template <typename Iterator>
		void			addNumbers(Iterator first, Iterator last);

	private:
		unsigned int		_capacity;
		std::vector<int>	_numbers;
};

template <typename Iterator>
void	Span::addNumber(Iterator first, Iterator last)
{
	addNumbers(first, last);
}

template <typename Iterator>
void	Span::addNumbers(Iterator first, Iterator last)
{
	std::vector<int>				incoming(first, last);
	std::vector<int>::size_type	available;

	available = static_cast<std::vector<int>::size_type>(_capacity);
	available -= _numbers.size();
	if (incoming.size() > available)
		throw FullSpanException();
	_numbers.insert(_numbers.end(), incoming.begin(), incoming.end());
}

#endif
