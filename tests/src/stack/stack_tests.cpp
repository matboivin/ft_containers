/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/30 00:01:18 by mboivin          ###   ########.fr       */
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
	void	test_stack(void)
	{
		#if defined(TEST_FT)
		std::cout << std::setw(42) << " MY STACK \n\n";
		#else
		std::cout << std::setw(42) << " ORIGINAL STACK \n\n";
		#endif

		// construct/assign
		test_stack_default_ctor();
		test_stack_copy_assign();

		// capacity
		test_stack_empty();
		test_stack_size();

		// modifiers
		test_stack_push();
		test_stack_pop();

		// non-member functions
		test_stack_non_mb_comp_ops();
	}
}
