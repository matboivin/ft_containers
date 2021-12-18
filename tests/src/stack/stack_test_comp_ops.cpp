/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_comp_ops.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:50:10 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/02 14:25:44 by mboivin          ###   ########.fr       */
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
	void	test_stack_non_mb_comp_ops(void)
	{
		std::cout << "TEST: Non-member comparison operators \n\n";

		explain_test("Operators to make comparison between two stacks.");

		// Test vector
		std::cout << "1. With vector" << std::endl;

		vector<int>	vec1;

		vec1.push_back(12);
		vec1.push_back(5);
		vec1.push_back(42);

		vector<int>	vec2(vec1);

		vec1.push_back(100);
		vec1.push_back(25);
		vec1.push_back(120);

		stack<int, vector<int> >	stack_vec1(vec1);
		stack<int, vector<int> >	stack_vec2(vec2);
		stack<int, vector<int> >	stack_vec3(vec2);

		std::cout << std::boolalpha
				  << "(stack_vec1 > stack_vec2)  ? " << (stack_vec1 > stack_vec2)
				  << "\n(stack_vec1 < stack_vec2)  ? " << (stack_vec1 < stack_vec2)
				  << "\n(stack_vec3 < stack_vec1)  ? " << (stack_vec3 < stack_vec1)
				  << "\n(stack_vec1 != stack_vec2) ? " << (stack_vec1 != stack_vec2)
				  << "\n(stack_vec2 == stack_vec3) ? " << (stack_vec2 == stack_vec3)
				  << "\n(stack_vec2 != stack_vec3) ? " << (stack_vec2 != stack_vec3)
				  << "\n(stack_vec2 >= stack_vec3) ? " << (stack_vec2 >= stack_vec3)
				  << "\n(stack_vec2 <= stack_vec3) ? " << (stack_vec2 <= stack_vec3)
				  << "\n\n";

		assert(stack_vec1 > stack_vec2);
		assert((stack_vec1 < stack_vec2) == false);
		assert(stack_vec3 < stack_vec1);
		assert(stack_vec1 != stack_vec2);
		assert(stack_vec2 == stack_vec3);
		assert((stack_vec2 != stack_vec3) == false);
		assert(stack_vec2 >= stack_vec3);
		assert(stack_vec2 <= stack_vec3);

		// Test deque
		std::cout << "2. With deque" << std::endl;

		std::deque<int>	deque1;

		deque1.push_back(12);
		deque1.push_back(5);
		deque1.push_back(42);

		std::deque<int>	deque2(deque1);

		deque1.push_back(100);
		deque1.push_back(25);
		deque1.push_back(120);

		stack<int, std::deque<int> >	stack_deque1(deque1);
		stack<int, std::deque<int> >	stack_deque2(deque2);
		stack<int, std::deque<int> >	stack_deque3(deque2);

		std::cout << std::boolalpha
				  << "stack_deque1 > stack_deque2)   ? " << (stack_deque1 > stack_deque2)
				  << "\n(stack_deque1 < stack_deque2)  ? " << (stack_deque1 < stack_deque2)
				  << "\n(stack_deque3 < stack_deque1)  ? " << (stack_deque3 < stack_deque1)
				  << "\n(stack_deque1 != stack_deque2) ? " << (stack_deque1 != stack_deque2)
				  << "\n(stack_deque2 == stack_deque3) ? " << (stack_deque2 == stack_deque3)
				  << "\n(stack_deque2 != stack_deque3) ? " << (stack_deque2 != stack_deque3)
				  << "\n(stack_deque2 >= stack_deque3) ? " << (stack_deque2 >= stack_deque3)
				  << "\n(stack_deque2 <= stack_deque3) ? " << (stack_deque2 <= stack_deque3)
				  << "\n\n";

		assert(stack_deque1 > stack_deque2);
		assert((stack_deque1 < stack_deque2) == false);
		assert(stack_deque3 < stack_deque1);
		assert(stack_deque1 != stack_deque2);
		assert(stack_deque2 == stack_deque3);
		assert((stack_deque2 != stack_deque3) == false);
		assert(stack_deque2 >= stack_deque3);
		assert(stack_deque2 <= stack_deque3);

		// Test list
		std::cout << "3. With list" << std::endl;

		std::list<int>	lst1;

		lst1.push_back(12);
		lst1.push_back(5);
		lst1.push_back(42);

		std::list<int>	lst2(lst1);

		lst1.push_back(100);
		lst1.push_back(25);
		lst1.push_back(120);

		stack<int, std::list<int> >	stack_lst1(lst1);
		stack<int, std::list<int> >	stack_lst2(lst2);
		stack<int, std::list<int> >	stack_lst3(lst2);

		std::cout << std::boolalpha
				  << "(stack_lst1 > stack_lst2)   ? " << (stack_lst1 > stack_lst2)
				  << "\n(stack_lst1 < stack_lst2)   ? " << (stack_lst1 < stack_lst2)
				  << "\n(stack_lst3 < stack_lst1)   ? " << (stack_lst3 < stack_lst1)
				  << "\n(stack_lst1 != stack_lst2)  ? " << (stack_lst1 != stack_lst2)
				  << "\n(stack_lst2 == stack_lst3)  ? " << (stack_lst2 == stack_lst3)
				  << "\n(stack_lst2 != stack_lst3)  ? " << !(stack_lst2 != stack_lst3)
				  << "\n(stack_lst2 >= stack_lst3)  ? " << (stack_lst2 >= stack_lst3)
				  << "\n(stack_lst2 <= stack_lst3)  ? " << (stack_lst2 <= stack_lst3)
				  << "\n\n";

		assert(stack_lst1 > stack_lst2);
		assert((stack_lst1 < stack_lst2) == false);
		assert(stack_lst3 < stack_lst1);
		assert(stack_lst1 != stack_lst2);
		assert(stack_lst2 == stack_lst3);
		assert((stack_lst2 != stack_lst3) == false);
		assert(stack_lst2 >= stack_lst3);
		assert(stack_lst2 <= stack_lst3);
	}
}
