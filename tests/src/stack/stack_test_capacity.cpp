/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_capacity.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:57:18 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/30 16:42:45 by mboivin          ###   ########.fr       */
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

		// create stacks
		stack<int, vector<int> >	stack1;
		stack<int, vector<int> >	stack2;

		for (int i = 0; i < 42; ++i)
			stack1.push(i);

		std::cout << std::boolalpha
				  << "stack1.empty()? " << stack1.empty()
				  << "\nstack2.empty()? " << stack2.empty() << "\n\n";

		assert(!stack1.empty());
		assert(stack2.empty());
	}

	void	test_stack_size(void)
	{
		std::cout << "TEST: Capacity: size() \n\n";

		explainTest("Returns the number of elements in the stack.");

		// create a vector
		vector<int>	vec(42);

		stack<int, vector<int> >	stack1(vec);

		std::cout << "stack.size() = " << stack1.size() << std::endl;
		assert(stack1.size() == 42);

		for (int i = 0; i < 8; ++i)
			stack1.push(i);

		std::cout << "stack.size() = " << stack1.size() << "\n\n";
		assert(stack1.size() == 50);
	}
}
