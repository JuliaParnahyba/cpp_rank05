/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:00:00 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:23:35 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator	found;

	found = std::find(container.begin(), container.end(), value);
	if (found == container.end())
		throw std::out_of_range("easyfind: value not found");
	return (found);
}

template <typename T>
typename T::const_iterator	easyfind(T const &container, int value)
{
	typename T::const_iterator	found;

	found = std::find(container.begin(), container.end(), value);
	if (found == container.end())
		throw std::out_of_range("easyfind: value not found");
	return (found);
}

#endif
