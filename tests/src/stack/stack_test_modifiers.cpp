/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test_modifiers.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 00:00:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/30 00:04:38 by mboivin          ###   ########.fr       */
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
	void	test_stack_push(void)
	{
		std::cout << "TEST: Modifiers: push() \n\n";

		explainTest("Inserts a new element at the top of the stack.");
	}

	void	test_stack_pop(void)
	{
		std::cout << "TEST: Modifiers: pop() \n\n";

		explainTest("Remove top element.");
	}
}
