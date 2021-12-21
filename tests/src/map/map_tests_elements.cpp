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

		clock_t	start = clock();

		m[1] = 1;
		m[2] = 2;
		m[3] = m[2];
		m[2] = 0;

		std::cout << "m[1] = " << m[1] << '\n'
				  << "m[2] = " << m[2] << '\n'
				  << "m[3] = " << m[3] << '\n'
				  << "m[4] = " << m[4] << "\n\n";

		display_elapsed_time(start, clock());

		m.clear();

		start = clock();

		for (int i = 0; i < 10000; ++i)
			m[i] = rand();

		display_elapsed_time(start, clock());

		m.clear();

		int	random_n;

		for (int i = 0; i < 10000; ++i)
		{
			random_n = rand();
			m[i] = random_n;
			cmp_m[i] = random_n;
		}

		std::size_t	len = m.size();

		std::cout << "Map has " << len << " elements\n\n";

		for (std::size_t i = 0; i <= len; ++i)
		{
			assert(m[i] == cmp_m[i]);
		}

	#if defined(TEST_FT)
		m.write_tree_dot("ast");
	#endif
	}
}
