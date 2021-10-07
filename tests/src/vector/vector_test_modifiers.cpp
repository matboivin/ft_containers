/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_modifiers.cpp                          :+:      :+:    :+:   */
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
	void	test_vec_push_back(void)
	{
		std::cout << "TEST: Modifiers: push_back() \n\n";

		explainTest("Add a new elements at the end of the vector.");

		clock_t	start = clock();

		// create a vector
		vector<int>	vec;

		// call push_back()
		for ( int i = 0; i < 1000000; ++i )
			vec.push_back(i);

		displayElapsedTime(start, clock());

		// displayVecInfos(vec);
	}
}
