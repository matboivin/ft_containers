/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/12/21 00:27:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
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

		// elements access
		test_map_subscript_op();

		// lookup
		test_map_lookup();
	}
}
