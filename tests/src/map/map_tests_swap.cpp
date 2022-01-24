/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests_swap.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:53:42 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 16:59:01 by mboivin          ###   ########.fr       */
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
	void	test_map_non_mb_swap(void)
	{
		std::cout << "TEST: Non-member swap() \n\n";

		explain_test("Exchange contents of 2 maps.");

		// create maps
		int_s_map	m1;
		int_s_map	m2;
		int_s_map	m3;

		// fill them
		for (int i = 0; i < 10000; ++i)
			m3.insert(make_pair(rand(), "three"));

		for (int i = 0; i < 20; ++i)
			m1.insert(make_pair(rand(), "one"));

		for (int i = 0; i < 10; ++i)
			m2.insert(make_pair(rand(), "two"));

		// create backup
		int_s_map	backup1(m1);
		int_s_map	backup2(m2);
		int_s_map	backup3(m3);

		// first test
		display_map_infos(m1, "before: map 1");
		display_map_infos(m2, "before: map 2");

		std::cout << "swap(m1, m2);\n\n";

		clock_t	time_start = clock();
		swap(m1, m2);
		clock_t	time_end = clock();

		display_map_infos(m1, "after: map 1");
		display_map_infos(m2, "after: map 2");
		display_elapsed_time(time_start, time_end);

		// assert using backup maps
		assert(m1 == backup2);
		assert(m2 == backup1);

		// second test
		std::cout << "swap(m1, m3);\n\n";

		time_start = clock();
		swap(m1, m3);
		display_elapsed_time(time_start, clock());

		// assert using backup maps
		assert(m1 == backup3);
		assert(m3 == backup2);
	}
}
