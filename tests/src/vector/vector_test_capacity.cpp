/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_capacity.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/07 18:54:30 by mboivin          ###   ########.fr       */
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
	// void	test_vec_empty(void)
	// {
	// 	std::cout << "TEST: Capacity: empty() \n\n";

	// 	explainTest("Creates a new object from existing one passed as parameter.");

	// 	// create a vector
	// 	vector<int>	vec1(1000000, 1);

	// 	clock_t	start = clock();

	// 	// create a copy from vec1
	// 	vector<int>	vec2(vec1);

	// 	displayElapsedTime(start, clock());

	// 	// assert they're identical
	// 	assert(vec1 == vec2);
	// }

	// void	test_vec_size(void)

	// void	test_vec_resize(void)

	// void	test_vec_max_ize(void)

	// void	test_vec_capacity(void)

	// void	test_vec_reserve(void)
}
