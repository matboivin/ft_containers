/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_comp_ops.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:50:10 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/30 16:25:29 by mboivin          ###   ########.fr       */
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
	void	test_stack_non_mb_comp_ops(void)
	{
		std::cout << "TEST: Non-member comparison operators \n\n";

		explainTest("Operators to make comparison between two stacks.");

		// create vectors
		vector<int>	vec1;

		vec1.push_back(12);
		vec1.push_back(5);
		vec1.push_back(42);

		vector<int>	vec2(vec1);

		vec1.push_back(100);
		vec1.push_back(25);
		vec1.push_back(120);

		stack<int, vector<int> >	stack1(vec1);
		stack<int, vector<int> >	stack2(vec2);
		stack<int, vector<int> >	stack3(vec2);

		assert(stack1 > stack2);
		assert(stack3 < stack1);
		assert(stack1 != stack2);
		assert(stack2 == stack3);
		assert(stack2 >= stack3);
		assert(stack2 <= stack3);
	}
}
