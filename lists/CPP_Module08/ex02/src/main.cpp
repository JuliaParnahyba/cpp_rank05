/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:00:00 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:24:31 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <stack>
#include <string>
#include "MutantStack.hpp"

static void	printMutantStack(MutantStack<int> &mstack)
{
	MutantStack<int>::iterator	it;
	MutantStack<int>::iterator	ite;

	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

static void	testSubjectExample(void)
{
	MutantStack<int>				mstack;
	MutantStack<int>::iterator	probe;
	std::stack<int>				regular_stack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "top before pop: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size after pop: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	probe = mstack.begin();
	++probe;
	--probe;
	printMutantStack(mstack);
	regular_stack = std::stack<int>(mstack);
	std::cout << "copied stack size: " << regular_stack.size() << std::endl;
}

static void	testListComparison(void)
{
	std::list<int>				values;
	std::list<int>::iterator	it;
	std::list<int>::iterator	ite;

	values.push_back(5);
	values.push_back(3);
	values.push_back(5);
	values.push_back(737);
	values.push_back(0);
	it = values.begin();
	ite = values.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

static void	testConstAndReverseIterators(void)
{
	MutantStack<std::string>				words;
	MutantStack<std::string> const		copy;
	MutantStack<std::string>::iterator	it;

	words.push("first");
	words.push("second");
	words.push("third");
	it = words.begin();
	*it = "changed";
	std::cout << "begin after change: " << *words.begin() << std::endl;
	std::cout << "reverse begin: " << *words.rbegin() << std::endl;
	std::cout << "const empty: " << (copy.begin() == copy.end()) << std::endl;
}

int	main(void)
{
	std::cout << "[mutant stack]" << std::endl;
	testSubjectExample();
	std::cout << std::endl;
	std::cout << "[list comparison]" << std::endl;
	testListComparison();
	std::cout << std::endl;
	std::cout << "[const and reverse]" << std::endl;
	testConstAndReverseIterators();
	return (0);
}
