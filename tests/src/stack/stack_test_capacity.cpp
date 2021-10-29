/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_capacity.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:57:18 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/30 00:00:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
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

		explainTest("Test whether container is empty.");

		// create vectors
		vector<int>	vec1;

		vec1.push_back(12);
		vec1.push_back(5);
		vec1.push_back(42);

		vector<int>	vec2;

		stack<int>	stack1(vec1);
		stack<int>	stack2(vec2);

		assert(!stack1.empty());
		assert(stack2.empty());
	}

	void	test_stack_size(void)
	{
		std::cout << "TEST: Capacity: size() \n\n";

		explainTest("Returns the number of elements in the stack.");

		// create a vector
		vector<int>	vec(42);

		stack<int>	stack1(vec);

		std::cout << "stack.size() = " << stack1.size() << std::endl;

		assert(stack1.size() == 42);

		for (int i = 0; i < 8; ++i)
			vec.push_back(i);

		std::cout << "stack.size() = " << stack1.size() << std::endl;
		assert(stack1.size() == 50);
	}
}
