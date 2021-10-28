/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 16:46:08 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "tests.hpp"
#include "vector_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_vector(void)
	{
		#if defined(TEST_FT)
		std::cout << std::setw(42) << " MY VECTOR \n\n";
		#else
		std::cout << std::setw(42) << " ORIGINAL VECTOR \n\n";
		#endif

		// construct/assign
		test_vec_default_ctor();
		test_vec_fill_ctor();
		test_vec_copy_ctor();
		test_vec_range_ctor();
		test_vec_copy_assign();

		// iterator
		test_vec_iterator();

		// capacity
		test_vec_empty();
		test_vec_size();
		test_vec_resize();
		test_vec_max_size();
		test_vec_capacity();
		test_vec_reserve();

		// elements access
		test_vec_at();

		// modifiers
		test_vec_push_back();

		// non-member functions
		test_vec_comp_ops();
	}
}
