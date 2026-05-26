/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:15:40 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 20:50:41 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <iostream>

static void	printData(Data const &data)
{
	std::cout << "Data{id=" << data.id;
	std::cout << ", name=" << data.name;
	std::cout << ", score=" << data.score << "}" << std::endl;
}

int	main(void)
{
	Data		data;
	uintptr_t	raw;
	Data		*restored;

	data.id = 42;
	data.name = "Scalar sample";
	data.score = 98.5;
	raw = Serializer::serialize(&data);
	restored = Serializer::deserialize(raw);
	std::cout << "Original pointer: " << &data << std::endl;
	std::cout << "Serialized raw: " << raw << std::endl;
	std::cout << "Restored pointer: " << restored << std::endl;
	if (restored == &data)
		std::cout << "Pointers match: yes" << std::endl;
	else
		std::cout << "Pointers match: no" << std::endl;
	printData(*restored);
	restored->score = 100.0;
	printData(data);
	return (0);
}
