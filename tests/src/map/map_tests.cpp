/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/28 15:45:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include "tests.hpp"
#include "map_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_map(void)
	{
		#if defined(TEST_FT)
		std::cout << std::setw(42) << " MY MAP \n\n";
		#else
		std::cout << std::setw(42) << " ORIGINAL MAP \n\n";
		#endif

		srand(42);

		// construct/assign
		test_map_default_ctor();
		test_map_range_ctor();
		test_map_copy_ctor();
		test_map_copy_assign();

		// iterators
		test_map_iterator();
		test_map_rev_iterator();

		// capacity
		test_map_empty();
		test_map_size();
		test_map_max_size();

		// elements access
		test_map_subscript_op();

		// modifiers
		test_map_insert_val();
		test_map_insert_pos();
		test_map_insert_range();
		test_map_swap();
		test_map_clear();

		// lookup
		test_map_lookup();

		// observers
		test_map_key_comp();
		test_map_value_comp();

		// non-member functions
		test_map_non_mb_comp_ops();
		test_map_non_mb_swap();
	}
}
