/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_elements.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:56:34 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/02 14:35:34 by mboivin          ###   ########.fr       */
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
	void	test_stack_top(void)
	{
		std::cout << "TEST: Element access: top() \n\n";

		explainTest("Return the top element.");

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

		clock_t	time_start = clock();
		int		top_elem = stack_vec.top();
		clock_t	time_end = clock();

		stack_vec.pop();
		assert(top_elem == 21);
		top_elem = stack_vec.top();
		assert(top_elem == 12);

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

		time_start = clock();
		top_elem = stack_deque.top();
		time_end = clock();

		stack_deque.pop();
		assert(top_elem == 21);
		top_elem = stack_deque.top();
		assert(top_elem == 12);

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

		time_start = clock();
		top_elem = stack_lst.top();
		time_end = clock();

		stack_lst.pop();
		assert(top_elem == 21);
		top_elem = stack_lst.top();
		assert(top_elem == 12);

		displayElapsedTime(time_start, time_end);
	}
}
