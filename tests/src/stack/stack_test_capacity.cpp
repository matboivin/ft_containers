/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_capacity.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:57:18 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/02 12:57:43 by mboivin          ###   ########.fr       */
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
	void	test_stack_empty(void)
	{
		std::cout << "TEST: Capacity: size() \n\n";

		explain_test("Test whether container is empty.");

		// Test vector
		std::cout << "1. With vector" << std::endl;

		stack<int, vector<int> >	stack_vec1;
		stack<int, vector<int> >	stack_vec2;

		for (int i = 0; i < 42; ++i)
			stack_vec1.push(i);

		std::cout << std::boolalpha
				  << "stack_vec1.empty()? " << stack_vec1.empty()
				  << "\nstack_vec2.empty()? " << stack_vec2.empty() << "\n\n";

		assert(!stack_vec1.empty());
		assert(stack_vec2.empty());

		// Test deque
		std::cout << "2. With deque" << std::endl;

		stack<int, std::deque<int> >	stack_deque1;
		stack<int, std::deque<int> >	stack_deque2;

		for (int i = 0; i < 42; ++i)
			stack_deque1.push(i);

		std::cout << std::boolalpha
				  << "stack_deque1.empty()? " << stack_deque1.empty()
				  << "\nstack_deque2.empty()? " << stack_deque2.empty() << "\n\n";

		assert(!stack_deque1.empty());
		assert(stack_deque2.empty());

		// Test list
		std::cout << "3. With list" << std::endl;

		stack<int, std::list<int> >	stack_lst1;
		stack<int, std::list<int> >	stack_lst2;

		for (int i = 0; i < 42; ++i)
			stack_lst1.push(i);

		std::cout << std::boolalpha
				  << "stack_lst1.empty()? " << stack_lst1.empty()
				  << "\nstack_lst2.empty()? " << stack_lst2.empty() << "\n\n";

		assert(!stack_lst1.empty());
		assert(stack_lst2.empty());
	}

	void	test_stack_size(void)
	{
		std::cout << "TEST: Capacity: size() \n\n";

		explain_test("Returns the number of elements in the stack.");

		// Test vector
		std::cout << "1. With vector" << std::endl;

		vector<int>					vec(42);
		stack<int, vector<int> >	stack_vec(vec);

		std::cout << "stack_vec.size() = " << stack_vec.size() << std::endl;
		assert(stack_vec.size() == 42);

		for (int i = 0; i < 8; ++i)
			stack_vec.push(i);

		std::cout << "stack_vec.size() = " << stack_vec.size() << "\n\n";
		assert(stack_vec.size() == 50);

		// Test deque
		std::cout << "2. With deque" << std::endl;

		std::deque<int>					de_que(42);
		stack<int, std::deque<int> >	stack_deque(de_que);

		std::cout << "stack_deque.size() = " << stack_deque.size() << std::endl;
		assert(stack_deque.size() == 42);

		for (int i = 0; i < 8; ++i)
			stack_deque.push(i);

		std::cout << "stack_deque.size() = " << stack_deque.size() << "\n\n";
		assert(stack_deque.size() == 50);

		// Test list
		std::cout << "3. With list" << std::endl;

		std::list<int>				lst(42);
		stack<int, std::list<int> >	stack_lst(lst);

		std::cout << "stack_lst.size() = " << stack_lst.size() << std::endl;
		assert(stack_lst.size() == 42);

		for (int i = 0; i < 8; ++i)
			stack_lst.push(i);

		std::cout << "stack_lst.size() = " << stack_lst.size() << "\n\n";
		assert(stack_lst.size() == 50);
	}
}
