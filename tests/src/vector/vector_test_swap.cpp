/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_swap.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:27:40 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 18:28:59 by mboivin          ###   ########.fr       */
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

		explainTest("Exchange contents of 2 vectors.");

		// create vectors
		vector<int>	vec1;
		vector<int>	vec2;
		vector<int>	vec3(1000000, 1);

		// fill them
		for ( int i = 0; i < 20; ++i )
			vec1.push_back(i);

		for ( int i = 0; i < 10; ++i )
			vec2.push_back(35 - i);

		displayVecInfos(vec1, "vector 1");
		displayVecInfos(vec2, "vector 2");

		std::cout << "swap(vec1, vec2);\n\n";

		clock_t	time_start = clock();
		swap(vec1, vec2);
		clock_t	time_end = clock();

		displayVecInfos(vec1, "vector 1");
		displayVecInfos(vec2, "vector 2");

		displayElapsedTime(time_start, time_end);

		std::cout << "swap(vec1, vec3);\n\n";

		time_start = clock();
		swap(vec1, vec3);
		displayElapsedTime(time_start, clock());
	}
}
