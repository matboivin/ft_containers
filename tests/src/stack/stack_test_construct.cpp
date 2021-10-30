/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_construct.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:51:27 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/30 16:44:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
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

		// with default container
		clock_t	start = clock();
		stack<int>	stack1;
		displayElapsedTime(start, clock());

		// with std::list
		start = clock();
		stack<int, std::list<int> >	stack2;
		displayElapsedTime(start, clock());
	}

	void	test_stack_copy_assign(void)
	{
		std::cout << "TEST: Copy assignment operator \n\n";

		explainTest("Replaces the contents with a copy of the contents of other.");

		// with std::list
		stack<int, std::list<int> >	stack1;
		stack<int, std::list<int> >	stack2;

		for (int i = 0; i < 1000; ++i)
			stack1.push(i);

		assert(stack1 != stack2);

		clock_t	start = clock();
		stack2 = stack1;
		displayElapsedTime(start, clock());

		assert(stack1 == stack2);

		// with std::vector and vector
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
