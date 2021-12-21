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

		map_type	m;

		clock_t	start = clock();

		m[1] = "first element";
		m[2] = "second element";
		m[3] = m[2];
		m[2] = "overriden second element";

		std::cout << "m[1] is " << m[1] << '\n'
				  << "m[2] is " << m[2] << '\n'
				  << "m[3] is " << m[3] << '\n'
				  << "m[4] is " << m[4] << '\n';

		display_elapsed_time(start, clock());

		m.clear();

		start = clock();

		m[8]  = "eight";
		m[18] = "eighteen";
		m[5]  = "five";
		m[15] = "fifteen";
		m[17] = "seventeen";
		m[25] = "twenty-five";
		m[40] = "fourty";
		m[80] = "eigthy";
		m[11] = "eleven";
		m[20] = "twenty";
		m[2]  = "two";
		m[987] = "nine-hundred eighty-seven";
		m[100] = "one-hundred";
		m[16] = "sixteen";

		display_elapsed_time(start, clock());

	#if defined(TEST_FT)
		m.write_tree_dot("ast");
	#endif
	}
}
