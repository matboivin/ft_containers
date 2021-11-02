/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_modifiers.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 00:00:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/02 14:33:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <deque>
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

		// Test vector
		std::cout << "1. With vector" << std::endl;

		stack<int, vector<int> >	stack_vec;

		std::cout << "stack_vec.size() = " << stack_vec.size() << std::endl;

		clock_t	time_start = clock();
		for (int i = 0; i < 1000; ++i)
			stack_vec.push(i);
		clock_t	time_end = clock();

		std::cout << "stack_vec.size() = " << stack_vec.size() << std::endl;

		assert(stack_vec.size() == 1000);
		displayElapsedTime(time_start, time_end);

		// Test deque
		std::cout << "2. With deque" << std::endl;

		stack<int, std::deque<int> >	stack_deque;

		std::cout << "stack_deque.size() = " << stack_deque.size() << std::endl;

		time_start = clock();
		for (int i = 0; i < 1000; ++i)
			stack_deque.push(i);
		time_end = clock();

		std::cout << "stack_deque.size() = " << stack_deque.size() << std::endl;

		assert(stack_deque.size() == 1000);
		displayElapsedTime(time_start, time_end);

		// Test list
		std::cout << "3. With list" << std::endl;

		stack<int, std::list<int> >	stack_lst;

		std::cout << "stack_lst.size() = " << stack_lst.size() << std::endl;

		time_start = clock();
		for (int i = 0; i < 1000; ++i)
			stack_lst.push(i);
		time_end = clock();

		std::cout << "stack_lst.size() = " << stack_lst.size() << std::endl;

		assert(stack_lst.size() == 1000);
		displayElapsedTime(time_start, time_end);
	}

	void	test_stack_pop(void)
	{
		std::cout << "TEST: Modifiers: pop() \n\n";

		explainTest("Remove top element.");

		// Test vector
		std::cout << "1. With vector" << std::endl;

		stack<int, vector<int> >	stack_vec;

		stack_vec.push(42);
		stack_vec.push(500);
		stack_vec.push(10);
		stack_vec.push(1);
		stack_vec.push(13);
		stack_vec.push(12);
		stack_vec.push(21);

		std::cout << "stack.size() = " << stack_vec.size() << std::endl;

		clock_t	time_start = clock();
		stack_vec.pop();
		clock_t	time_end = clock();

		std::cout << "stack.size() = " << stack_vec.size() << std::endl;

		assert(stack_vec.size() == 6);
		displayElapsedTime(time_start, time_end);

		// Test deque
		std::cout << "2. With deque" << std::endl;

		stack<int, std::deque<int> >	stack_deque;

		stack_deque.push(42);
		stack_deque.push(500);
		stack_deque.push(10);
		stack_deque.push(1);
		stack_deque.push(13);
		stack_deque.push(12);
		stack_deque.push(21);

		std::cout << "stack_deque.size() = " << stack_deque.size() << std::endl;

		time_start = clock();
		stack_deque.pop();
		time_end = clock();

		std::cout << "stack_deque.size() = " << stack_deque.size() << std::endl;

		assert(stack_deque.size() == 6);
		displayElapsedTime(time_start, time_end);

		// Test list
		std::cout << "3. With list" << std::endl;

		stack<int, std::list<int> >	stack_lst;

		stack_lst.push(42);
		stack_lst.push(500);
		stack_lst.push(10);
		stack_lst.push(1);
		stack_lst.push(13);
		stack_lst.push(12);
		stack_lst.push(21);

		std::cout << "stack_lst.size() = " << stack_lst.size() << std::endl;

		time_start = clock();
		stack_lst.pop();
		time_end = clock();

		std::cout << "stack_lst.size() = " << stack_lst.size() << std::endl;

		assert(stack_lst.size() == 6);
		displayElapsedTime(time_start, time_end);
	}
}
