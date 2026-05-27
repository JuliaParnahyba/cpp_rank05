/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:08:36 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:08:37 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

template <typename T>
class Array
{
	public:
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};

		Array(void);
		Array(unsigned int n);
		Array(Array const &other);
		~Array(void);

		Array		&operator=(Array const &other);
		T			&operator[](unsigned int index);
		T const		&operator[](unsigned int index) const;
		unsigned int	size(void) const;

	private:
		T			*_items;
		unsigned int	_count;
};

# include "Array.tpp"

#endif
