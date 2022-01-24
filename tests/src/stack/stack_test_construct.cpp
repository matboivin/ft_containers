/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_construct.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:51:27 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 18:37:49 by mboivin          ###   ########.fr       */
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

		explain_test("Constructs a stack container adaptor object.");

		// Test default container
		std::cout << "1. With default container" << std::endl;

		clock_t	start = clock();
		stack<int>	stack_default;
		display_elapsed_time(start, clock());

		// Test vector
		std::cout << "2. With vector" << std::endl;

		start = clock();
		stack<int, vector<int> >	stack_vec;
		display_elapsed_time(start, clock());

		// Test std::deque
		std::cout << "3. With deque" << std::endl;

		start = clock();
		stack<int, std::deque<int> >	stack_deque;
		display_elapsed_time(start, clock());

		// Test std::list
		std::cout << "4. With list" << std::endl;

		start = clock();
		stack<int, std::list<int> >	stack_lst;
		display_elapsed_time(start, clock());
	}

	void	test_stack_copy_ctor(void)
	{
		std::cout << "TEST: Copy Constructor \n\n";

		explain_test("Creates a new object from existing one passed as parameter.");

		// Test vector
		std::cout << "1. With vector" << std::endl;

		vector<int>					vec(1000000, 1);
		stack<int, vector<int> >	stack_vec(vec);

		clock_t	start = clock();
		stack<int, vector<int> >	copy_stack_vec(stack_vec);
		display_elapsed_time(start, clock());

		// assert they're identical
		assert(stack_vec == copy_stack_vec);
		// another assert test
		copy_is_identical(stack_vec, stack_vec);

		// Test deque
		std::cout << "2. With deque" << std::endl;

		std::list<int>				de_que(1000000, 1);
		stack<int, std::list<int> >	stack_deque(de_que);

		start = clock();
		stack<int, std::list<int> > copy_stack_deque(stack_deque);
		display_elapsed_time(start, clock());

		// assert they're identical
		assert(stack_deque == copy_stack_deque);
		// another assert test
		copy_is_identical(stack_deque, stack_deque);

		// Test list
		std::cout << "3. With list" << std::endl;

		std::list<int>				lst(1000000, 1);
		stack<int, std::list<int> >	stack_lst(lst);

		start = clock();
		stack<int, std::list<int> > copy_stack_lst(stack_lst);
		display_elapsed_time(start, clock());

		// assert they're identical
		assert(stack_lst == copy_stack_lst);
		// another assert test
		copy_is_identical(stack_lst, stack_lst);
	}

	void	test_stack_copy_assign(void)
	{
		std::cout << "TEST: Copy assignment operator \n\n";

		explain_test("Replaces the contents with a copy of the contents of other.");

		// Test vector
		std::cout << "1. With vector" << std::endl;

		vector<int>					vec(1000, 1);

		stack<int, vector<int> >	stack_vec(vec);
		stack<int, vector<int> >	copy_stack_vec;

		assert(stack_vec != copy_stack_vec);

		clock_t	start = clock();
		stack_vec = copy_stack_vec;
		display_elapsed_time(start, clock());

		assert(stack_vec == copy_stack_vec);

		// Test std::deque
		std::cout << "2. With deque" << std::endl;

		std::deque<int>					de_que(1000, 1);
		stack<int, std::deque<int> >	stack_deque(de_que);
		stack<int, std::deque<int> >	copy_stack_deque;

		assert(stack_deque != copy_stack_deque);

		start = clock();
		stack_deque = copy_stack_deque;
		display_elapsed_time(start, clock());

		assert(stack_deque == copy_stack_deque);

		// Test std::list
		std::cout << "3. With list" << std::endl;

		std::list<int>				lst(1000, 1);
		stack<int, std::list<int> >	stack_lst(lst);
		stack<int, std::list<int> >	copy_stack_lst;

		assert(stack_lst != copy_stack_lst);

		start = clock();
		stack_lst = copy_stack_lst;
		display_elapsed_time(start, clock());

		assert(stack_lst == copy_stack_lst);
	}
}
