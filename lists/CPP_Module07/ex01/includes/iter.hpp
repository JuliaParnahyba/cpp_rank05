/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:08:19 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:08:20 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename F>
void	iter(T *array, unsigned int const length, F function)
{
	unsigned int	index;

	if (array == NULL)
		return ;
	index = 0;
	while (index < length)
	{
		function(array[index]);
		index++;
	}
}

#endif
