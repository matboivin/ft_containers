/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_construct.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:51:27 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/30 00:15:17 by mboivin          ###   ########.fr       */
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
	void	test_stack_default_ctor(void)
	{
		std::cout << "TEST: Default Constructor \n\n";

		explainTest("Constructs a stack container adaptor object.");

		clock_t	start = clock();
		stack<int>	stack1;
		displayElapsedTime(start, clock());

		start = clock();
		stack<int, std::list<int> >	stack2;
		displayElapsedTime(start, clock());
	}

	void	test_stack_copy_assign(void)
	{
		std::cout << "TEST: Copy assignment operator \n\n";

		explainTest("Replaces the contents with a copy of the contents of other.");
	}
}
