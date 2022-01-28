/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests_swap.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:53:42 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/28 15:56:02 by mboivin          ###   ########.fr       */
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
	void	test_set_non_mb_swap(void)
	{
		std::cout << "TEST: Non-member swap() \n\n";

		explain_test("Exchange contents of 2 sets.");

		// create sets
		int_set	s1;
		int_set	s2;
		int_set	s3;

		// fill them
		for (int i = 0; i < 10000; ++i)
			s3.insert(rand());

		for (int i = 0; i < 20; ++i)
			s1.insert(rand());

		for (int i = 0; i < 10; ++i)
			s2.insert(rand());

		// create backup
		int_set	backup1(s1);
		int_set	backup2(s2);
		int_set	backup3(s3);

		// first test
		display_set_infos(s1, "before: set 1");
		display_set_infos(s2, "before: set 2");

		std::cout << "swap(s1, s2);\n\n";

		clock_t	time_start = clock();
		swap(s1, s2);
		clock_t	time_end = clock();

		display_set_infos(s1, "after: set 1");
		display_set_infos(s2, "after: set 2");
		display_elapsed_time(time_start, time_end);

		// assert using backup sets
		assert(s1 == backup2);
		assert(s2 == backup1);

		// second test
		std::cout << "swap(s1, s3);\n\n";

		time_start = clock();
		swap(s1, s3);
		display_elapsed_time(time_start, clock());

		// assert using backup sets
		assert(s1 == backup3);
		assert(s3 == backup2);
	}
}
