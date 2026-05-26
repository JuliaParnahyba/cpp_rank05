/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:13:04 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 20:54:50 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

static void	testGeneratedObjects(void)
{
	Base	*object;
	int		i;

	i = 0;
	while (i < 5)
	{
		object = generate();
		std::cout << "Generated pointer: ";
		identify(object);
		std::cout << "Generated reference: ";
		identify(*object);
		delete object;
		++i;
	}
}

static void	testKnownObjects(void)
{
	A		a;
	B		b;
	C		c;
	Base	base;

	std::cout << "Known A pointer/reference: ";
	identify(&a);
	identify(a);
	std::cout << "Known B pointer/reference: ";
	identify(&b);
	identify(b);
	std::cout << "Known C pointer/reference: ";
	identify(&c);
	identify(c);
	std::cout << "Base object reference: ";
	identify(base);
	std::cout << "Null pointer: ";
	identify(0);
}

int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	testKnownObjects();
	testGeneratedObjects();
	return (0);
}
