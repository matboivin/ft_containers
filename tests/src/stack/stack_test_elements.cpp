/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_elements.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:56:34 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/30 17:02:08 by mboivin          ###   ########.fr       */
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
	void	test_stack_top(void)
	{
		std::cout << "TEST: Element access: top() \n\n";

		explainTest("Return the top element.");

		// with std::list
		stack<int, std::list<int> >	stack1;

		stack1.push(42);
		stack1.push(500);
		stack1.push(10);
		stack1.push(1);
		stack1.push(13);
		stack1.push(12);
		stack1.push(21);

		clock_t	time_start = clock();
		int	top_elem = stack1.top();
		clock_t	time_end = clock();

		stack1.pop();
		assert(top_elem == 21);
		top_elem = stack1.top();
		assert(top_elem == 12);

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

		time_start = clock();
		top_elem = stack2.top();
		time_end = clock();

		stack2.pop();
		assert(top_elem == 21);
		top_elem = stack2.top();
		assert(top_elem == 12);

		displayElapsedTime(time_start, time_end);
	}
}
