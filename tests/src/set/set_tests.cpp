/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:21:25 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/28 16:05:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "tests.hpp"
#include "set_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_set(void)
	{
		#if defined(TEST_FT)
		std::cout << std::setw(42) << " MY SET \n\n";
		#else
		std::cout << std::setw(42) << " ORIGINAL SET \n\n";
		#endif

		// construct/assign
		test_set_default_ctor();
		test_set_range_ctor();
		test_set_copy_ctor();
		test_set_copy_assign();

		// iterators
		test_set_iterator();
		test_set_rev_iterator();

		// capacity
		test_set_empty();
		test_set_size();
		test_set_max_size();

		// modifiers
		test_set_insert_val();
		test_set_insert_pos();
		test_set_insert_range();
		test_set_swap();
		test_set_clear();

		// lookup
		test_set_lookup();

		// observers
		test_set_key_comp();
		test_set_value_comp();

		// non-member functions
		test_set_non_mb_comp_ops();
		test_set_non_mb_swap();
	}
}
