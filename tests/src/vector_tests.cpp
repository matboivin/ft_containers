/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/28 17:06:50 by mboivin          ###   ########.fr       */
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
	void	test_vec_fill_ctor( void )
	{
		std::cout << "_____________ Fill Constructor _____________\n\n";

		clock_t	start = clock();

		vector<int>	vec1(1000, 1);

		displayElapsedTime(start, clock());

		//displayVecInfos(vec1, "vector 1 (14, 1)");
	}

	void	test_vec_copy_ctor( void )
	{
		std::cout << "_____________ Copy constructor _____________\n\n";

		clock_t	start = clock();

		// create a vector
		vector<int>	vec1;
		// add some numbers to it
		vec1.push_back(12);
		vec1.push_back(5);
		vec1.push_back(42);
		vec1.push_back(100);
		vec1.push_back(25);

		// create a copy from vec1
		vector<int>	vec2(vec1);

		displayElapsedTime(start, clock());

		// assert they're identical
		assert(vec1 == vec2);

		// display
		displayVecInfos(vec1, "vector 1");
		displayVecInfos(vec2, "vector 2");
	}

	void	test_vec_copy_assign( void )
	{
		std::cout << "_________ Copy assignment operator _________\n\n";

		clock_t	start = clock();

		// create two vectors
		vector<int>	vec1;
		vector<int>	vec2;

		// add some numbers to vec1
		vec1.push_back(12);
		vec1.push_back(5);
		vec1.push_back(42);
		vec1.push_back(100);
		vec1.push_back(25);

		// create a copy from vec1
		vec2 = vec1;

		displayElapsedTime(start, clock());

		// assert they're identical
		assert(vec1 == vec2);

		// display
		displayVecInfos(vec1, "vector 1");
		displayVecInfos(vec2, "vector 2");
	}

	void	test_vector( void )
	{
		std::cout << ":::::::::::::::::: VECTOR ::::::::::::::::::\n\n";

		test_vec_fill_ctor();
		test_vec_copy_ctor();
		test_vec_copy_assign();
	}
}
