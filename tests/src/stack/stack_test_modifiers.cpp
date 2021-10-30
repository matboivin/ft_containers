/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_modifiers.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 00:00:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/30 16:52:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <list>
#include "tests.hpp"
#include "stack_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_stack_push(void)
	{
		std::cout << "TEST: Modifiers: push() \n\n";

		explainTest("Inserts a new element at the top of the stack.");

		// with std::list
		stack<int, std::list<int> >	stack1;

		std::cout << "stack.size() = " << stack1.size() << std::endl;

		clock_t	time_start = clock();
		for (int i = 0; i < 1000; ++i)
			stack1.push(i);
		clock_t	time_end = clock();

		std::cout << "stack.size() = " << stack1.size() << std::endl;

		assert(stack1.size() == 1000);
		displayElapsedTime(time_start, time_end);

		// with default container
		stack<int>	stack2;

		std::cout << "stack.size() = " << stack2.size() << std::endl;

		time_start = clock();
		for (int i = 0; i < 1000; ++i)
			stack2.push(i);
		time_end = clock();

		std::cout << "stack.size() = " << stack2.size() << std::endl;

		assert(stack2.size() == 1000);
		displayElapsedTime(time_start, time_end);
	}

	void	test_stack_pop(void)
	{
		std::cout << "TEST: Modifiers: pop() \n\n";

		explainTest("Remove top element.");

		// with std::list
		stack<int, std::list<int> >	stack1;

		stack1.push(42);
		stack1.push(500);
		stack1.push(10);
		stack1.push(1);
		stack1.push(13);
		stack1.push(12);
		stack1.push(21);

		std::cout << "stack.size() = " << stack1.size() << std::endl;

		clock_t	time_start = clock();
		stack1.pop();
		clock_t	time_end = clock();

		std::cout << "stack.size() = " << stack1.size() << std::endl;

		assert(stack1.size() == 6);
		displayElapsedTime(time_start, time_end);

		// with default container
		stack<int>	stack2;

		stack2.push(42);
		stack2.push(500);
		stack2.push(10);
		stack2.push(1);
		stack2.push(13);
		stack2.push(12);
		stack2.push(21);

		std::cout << "stack.size() = " << stack2.size() << std::endl;

		time_start = clock();
		stack2.pop();
		time_end = clock();

		std::cout << "stack.size() = " << stack2.size() << std::endl;

		assert(stack2.size() == 6);
		displayElapsedTime(time_start, time_end);
	}
}
