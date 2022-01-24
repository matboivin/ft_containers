/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests_comp_ops.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:54:38 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 16:58:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "tests.hpp"
#include "map_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_map_non_mb_comp_ops(void)
	{
		std::cout << "TEST: Non-member comparison operators \n\n";

		explain_test("Operators to make comparison between two trees.");

		// create trees
		int_s_map	m1;
		int_s_map	m2;
		int_s_map	m3;

		m1.insert( make_pair(12,  "twelve"));
		m1.insert( make_pair(5,   "five"));
		m1.insert( make_pair(42,  "fourty-two"));
		m1.insert( make_pair(100, "one-hundred"));
		m1.insert( make_pair(25,  "twenty-five"));

		m3.insert( make_pair(120,  "one-hundred twenty"));

		// copy of m3
		int_s_map	m4(m3);

		std::cout << std::boolalpha
				  << "(m1 > m2 && m1 < m3) ? " << (m1 > m2 && m1 < m3)
				  << "\n(m1 < m2)   ? " << (m1 < m2)
				  << "\n(m3 != m2)  ? " << (m3 != m2)
				  << "\n(m3 == m4)  ? " << (m3 == m4)
				  << "\n(m3 != m4)  ? " << (m3 != m4)
				  << "\n(m1 != m4)  ? " << (m1 != m4)
				  << "\n(m3 >= m4)  ? " << (m3 >= m4)
				  << "\n(m3 <= m4)  ? " << (m3 <= m4)
				  << "\n\n";

		assert(m1 > m2 && m1 < m3);
		assert((m1 < m2) == false);
		assert(m3 != m2);
		assert(m3 == m4);
		assert((m3 != m4) == false);
		assert(m1 != m4);
		assert(m3 >= m4);
		assert(m3 <= m4);
	}
}
