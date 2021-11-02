/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_construct.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:51:27 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/02 12:15:28 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <deque>
#include <list>
#include "vector.hpp"
#include "tests.hpp"
#include "stack_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_stack_default_ctor(void)
	{
		std::cout << "TEST: Default Constructor \n\n";

		explainTest("Constructs a stack container adaptor object.");

		// Test default container
		std::cout << "1. With default container" << std::endl;

		clock_t	start = clock();
		stack<int>	stack_default;
		displayElapsedTime(start, clock());

		// Test std::vector and vector
		std::cout << "2. With vector" << std::endl;

		start = clock();
		stack<int, vector<int> >	stack_vec;
		displayElapsedTime(start, clock());

		// Test std::deque
		std::cout << "3. With deque" << std::endl;

		start = clock();
		stack<int, std::deque<int> >	stack_deque;
		displayElapsedTime(start, clock());

		// Test std::list
		std::cout << "4. With list" << std::endl;

		start = clock();
		stack<int, std::list<int> >	stack_lst;
		displayElapsedTime(start, clock());
	}

	void	test_stack_copy_ctor(void)
	{
		std::cout << "TEST: Copy Constructor \n\n";

		explainTest("Creates a new object from existing one passed as parameter.");

		// Test vector
		vector<int>					vec(1000000, 1);
		stack<int, vector<int> >	stack_vec(vec);

		clock_t	start = clock();
		stack<int, vector<int> >	copy_stack_vec(stack_vec);
		displayElapsedTime(start, clock());

		// assert they're identical
		assert(stack_vec == copy_stack_vec);

		// Test deque
		std::list<int>				de_que(1000000, 1);
		stack<int, std::list<int> >	stack_deque(de_que);

		start = clock();
		stack<int, std::list<int> > copy_stack_deque(stack_deque);
		displayElapsedTime(start, clock());

		// assert they're identical
		assert(stack_deque == copy_stack_deque);

		// Test list
		std::list<int>				lst(1000000, 1);
		stack<int, std::list<int> >	stack_lst(lst);

		start = clock();
		stack<int, std::list<int> > copy_stack_lst(stack_lst);
		displayElapsedTime(start, clock());

		// assert they're identical
		assert(stack_lst == copy_stack_lst);
	}

	void	test_stack_copy_assign(void)
	{
		std::cout << "TEST: Copy assignment operator \n\n";

		explainTest("Replaces the contents with a copy of the contents of other.");

		// Test std::list
		stack<int, std::list<int> >	stack1;
		stack<int, std::list<int> >	stack2;

		for (int i = 0; i < 1000; ++i)
			stack1.push(i);

		assert(stack1 != stack2);

		clock_t	start = clock();
		stack2 = stack1;
		displayElapsedTime(start, clock());

		assert(stack1 == stack2);

		// Test std::vector and vector
		vector<int>	vec(1000, 1);

		stack<int, vector<int> >	stack3(vec);
		stack<int, vector<int> >	stack4;

		assert(stack3 != stack4);

		start = clock();
		stack3 = stack4;
		displayElapsedTime(start, clock());

		assert(stack3 == stack4);
	}
}
