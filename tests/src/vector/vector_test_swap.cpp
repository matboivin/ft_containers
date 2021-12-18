/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_swap.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:27:40 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/02 12:16:26 by mboivin          ###   ########.fr       */
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
	void	test_vec_non_mb_swap(void)
	{
		std::cout << "TEST: Non-member swap() \n\n";

		explain_test("Exchange contents of 2 vectors.");

		// create vectors
		vector<int>	vec1;
		vector<int>	vec2;
		vector<int>	vec3(1000000, 1);

		// fill them
		for ( int i = 0; i < 20; ++i )
			vec1.push_back(i);

		for ( int i = 0; i < 10; ++i )
			vec2.push_back(35 - i);

		// create backup
		vector<int>	backup1(vec1);
		vector<int>	backup2(vec2);
		vector<int>	backup3(vec3);

		// first test
		display_vec_infos(vec1, "before: vector 1");
		display_vec_infos(vec2, "before: vector 2");

		std::cout << "swap(vec1, vec2);\n\n";

		clock_t	time_start = clock();
		swap(vec1, vec2);
		clock_t	time_end = clock();

		display_vec_infos(vec1, "after: vector 1");
		display_vec_infos(vec2, "after: vector 2");
		display_elapsed_time(time_start, time_end);

		// assert using backup vectors
		assert(vec1 == backup2);
		assert(vec2 == backup1);

		// second test
		std::cout << "swap(vec1, vec3);\n\n";

		time_start = clock();
		swap(vec1, vec3);
		display_elapsed_time(time_start, clock());

		// assert using backup vectors
		assert(vec1 == backup3);
		assert(vec3 == backup2);
	}
}
