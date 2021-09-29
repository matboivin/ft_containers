/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/29 15:44:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <fstream>
#include <iostream>
#include "tests.hpp"
#include "vector_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_vec_fill_ctor(void)
	{
		std::cout << "_____________ Fill Constructor _____________\n\n";

		clock_t	start = clock();

		vector<int>	vec1(1000, 1);

		displayElapsedTime(start, clock());
	}

	void	test_vec_copy_ctor(void)
	{
		std::cout << "_____________ Copy constructor _____________\n\n";

		// create a vector
		vector<int>	vec1(1000, 1);

		clock_t	start = clock();

		// create a copy from vec1
		vector<int>	vec2(vec1);

		displayElapsedTime(start, clock());

		// assert they're identical
		assert(vec1 == vec2);

		// displayVecInfos(vec1, "vector 1");
		// displayVecInfos(vec2, "vector 2");
	}

	void	test_vec_copy_assign(void)
	{
		std::cout << "_________ Copy assignment operator _________\n\n";

		// create two vectors
		vector<int>	vec1(1000, 1);
		vector<int>	vec2;

		clock_t	start = clock();

		// create a copy from vec1
		vec2 = vec1;

		displayElapsedTime(start, clock());

		// assert they're identical
		assert(vec1 == vec2);

		// displayVecInfos(vec1, "vector 1");
		// displayVecInfos(vec2, "vector 2");
	}

	void	test_vec_push_back(void)
	{
		std::cout << "_______ capacity method: push_back() _______\n\n";

		clock_t	start = clock();

		// create a vector
		vector<int>	vec;

		// call push_back()
		vec.push_back(12);
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(100);
		vec.push_back(25);
		vec.push_back(9);
		vec.push_back(13);
		vec.push_back(12);
		vec.push_back(500);
		vec.push_back(4);
		vec.push_back(95);
		vec.push_back(5);

		displayElapsedTime(start, clock());

		displayVecInfos(vec);
	}

	void	test_vector(void)
	{
		std::cout << ":::::::::::::::::: VECTOR ::::::::::::::::::\n\n";

		test_vec_fill_ctor();
		test_vec_copy_ctor();
		test_vec_copy_assign();
		test_vec_push_back();
	}
}
