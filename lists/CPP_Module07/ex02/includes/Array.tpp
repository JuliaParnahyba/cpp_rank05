/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:08:42 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:08:43 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
char const	*Array<T>::OutOfBoundsException::what(void) const throw()
{
	return ("Array index out of bounds");
}

template <typename T>
Array<T>::Array(void) : _items(NULL), _count(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _items(NULL), _count(n)
{
	if (_count > 0)
		_items = new T[_count]();
}

template <typename T>
Array<T>::Array(Array const &other) : _items(NULL), _count(0)
{
	*this = other;
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] _items;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &other)
{
	T			*copy;
	unsigned int	index;

	if (this == &other)
		return (*this);
	copy = NULL;
	if (other._count > 0)
	{
		copy = new T[other._count]();
		index = 0;
		try
		{
			while (index < other._count)
			{
				copy[index] = other._items[index];
				index++;
			}
		}
		catch (...)
		{
			delete [] copy;
			throw ;
		}
	}
	delete [] _items;
	_items = copy;
	_count = other._count;
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _count)
		throw OutOfBoundsException();
	return (_items[index]);
}

template <typename T>
T const	&Array<T>::operator[](unsigned int index) const
{
	if (index >= _count)
		throw OutOfBoundsException();
	return (_items[index]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_count);
}

#endif
