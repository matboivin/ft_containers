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

#define MAX_RAM 4294967295
#define BUFFER_SIZE 4096

struct Buffer
{
	int		idx;
	char	buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

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

		// int_map				m;
		// std::map<int, int>	cmp_m;

		// clock_t	start = clock();

		// m[1] = 1;
		// m[2] = 2;
		// m[3] = m[2];
		// m[2] = 0;

		// std::cout << "m[1] = " << m[1] << '\n'
		// 		  << "m[2] = " << m[2] << '\n'
		// 		  << "m[3] = " << m[3] << '\n'
		// 		  << "m[1] = " << m[1] << "\n\n";

		// display_elapsed_time(start, clock());

	// 	m.clear();

	// 	// tmp test

		int_s_map					m2;
		std::map<int, std::string>	cmp_m2;

		m2[8]  = "eight";
		m2[18] = "eighteen";
		m2[5]  = "five";
		m2[15] = "fifteen";
		m2[17] = "seventeen";
		m2[25] = "twenty-five";
		m2[40] = "fourty";
		m2[80] = "eigthy";
		m2[11] = "eleven";
		m2[20] = "twenty";
		m2[2]  = "two";
		m2[987] = "nine-hundred eighty-seven";
		m2[100] = "one-hundred";
		m2[16] = "sixteen";

		cmp_m2[8]  = "eight";
		cmp_m2[18] = "eighteen";
		cmp_m2[5]  = "five";
		cmp_m2[15] = "fifteen";
		cmp_m2[17] = "seventeen";
		cmp_m2[25] = "twenty-five";
		cmp_m2[40] = "fourty";
		cmp_m2[80] = "eigthy";
		cmp_m2[11] = "eleven";
		cmp_m2[20] = "twenty";
		cmp_m2[2]  = "two";
		cmp_m2[987] = "nine-hundred eighty-seven";
		cmp_m2[100] = "one-hundred";
		cmp_m2[16] = "sixteen";

		std::size_t	len = m2.size();

		std::cout << "Map has " << len << " elements\n\n";

		for (std::size_t i = 0; i <= len; ++i)
		{
			assert(m2[i] == cmp_m2[i]);
		}

	#if defined(TEST_FT)
		m2.write_tree_dot("ast");
	#endif

	// // !tmp test

	// 	m.clear();

	// 	start = clock();

	// 	for (int i = 0; i < 10000; ++i)
	// 		m[i] = rand();

	// 	display_elapsed_time(start, clock());

	// 	m.clear();

		// int	random_key;
		// int	random_val;
		// int	steps = 105;

		// std::cout << "Count: " << COUNT << '\n';

		// for (int i = 0; i < 10000; ++i)
		// {
		// 	random_key = rand();
		// 	random_val = rand();
		// 	m[random_key] = random_val;
		// 	cmp_m[random_key] = random_val;
			// if (i % 10000 == 0)
			// {
			// 	--steps;
			// 	std::cout << steps << " steps remaining\n";
			// }
	// 	}

	// 	std::cout << "Map has " << m.size() << " elements\n\n";

	// 	int_map::iterator				it = m.begin();
	// 	std::map<int, int>::iterator	cmp_it = cmp_m.begin();

	// 	for ( ; it != m.end() && cmp_it != cmp_m.end(); ++it, ++cmp_it)
	// 	{
	// 		if ((it->first != cmp_it->first) || (it->second != cmp_it->second))
	// 		{
	// 			std::cout << cmp_it->first << " => " << cmp_it->second << '\n'
	// 					  << it->first << " => " << it->second << '\n';
	// 			break ;
	// 		}
	// 	}

	// #if defined(TEST_FT)
	// 	m.write_tree_dot("ast2");
	// #endif

		// len = m.size();

		// std::cout << "Map has " << len << " elements\n\n";

	// 	int	count = 0;

		// for (std::size_t i = 0; i <= len; ++i)
		// {
		// 	random_key = rand();
		// 	if (m[random_key] != cmp_m[random_key])
		// 	{
		// 		++count;
		// 		break ;
		// 	}
		// }
	// 	std::cout << "Differences: " << count << "\n\n";
	}
}
