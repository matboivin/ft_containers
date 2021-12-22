/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests_elements.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/12/21 00:02:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include <string>
#include <map>
#include "tests.hpp"
#include "map_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_map_subscript_op(void)
	{
		std::cout << "TEST: Element access: operator[] \n\n";

		explain_test("Insert a new element. Returns a reference to the data.");

		int_map				m;
		std::map<int, int>	cmp_m;

		// check m[2] is overridden
		m[1] = 1;
		m[2] = 2;
		m[3] = m[2];
		m[2] = 0; // now m[2] value is set to 0

		std::cout << "m[1] = " << m[1] << '\n'
				  << "m[2] = " << m[2] << '\n'
				  << "m[3] = " << m[3] << '\n'
				  << "m[1] = " << m[1] << "\n\n";

		m.clear();

		clock_t	start = clock();

		// insert a lot of elements with subscript operator
		for (int i = 0; i < COUNT; ++i)
			m[rand()] = rand();

		display_elapsed_time(start, clock());

		m.clear();

		int	random_key;
		int	random_val;

		for (int i = 0; i < COUNT; ++i)
		{
			random_key = rand();
			random_val = rand();
			m[random_key] = random_val;
			cmp_m[random_key] = random_val;
		}

		std::size_t	len = m.size();

		std::cout << "Map has " << len << " elements\n\n";

		// compare elements are stored in the same order
		int_map::iterator				it = m.begin();
		std::map<int, int>::iterator	cmp_it = cmp_m.begin();

		int	diff_count = 0;

		for ( ; it != m.end() && cmp_it != cmp_m.end(); ++it, ++cmp_it)
		{
			if ((it->first != cmp_it->first) || (it->second != cmp_it->second))
			{
				std::cout << cmp_it->first << " => " << cmp_it->second << '\n'
						  << it->first << " => " << it->second << '\n';
				++diff_count;
			}
		}

		std::cout << "Differences: " << diff_count << "\n\n";

		diff_count = 0;

		// compare speeds accessing random keys
		for (std::size_t i = 0; i <= len; ++i)
		{
			random_key = rand();
			if (m[random_key] != cmp_m[random_key])
				++diff_count;
		}
		std::cout << "Differences: " << diff_count << "\n\n";
	}
}
