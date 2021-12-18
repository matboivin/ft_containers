/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_construct.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 18:22:57 by mboivin          ###   ########.fr       */
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
	void	test_vec_default_ctor(void)
	{
		std::cout << "TEST: Default Constructor \n\n";

		explain_test("Constructs an empty vector.");

		clock_t	start = clock();

		vector<int>	vec;

		display_elapsed_time(start, clock());
	}

	void	test_vec_fill_ctor(void)
	{
		std::cout << "TEST: Fill Constructor \n\n";

		explain_test("Constructs a vector with n elements. "
					"Each element is a copy of value passed as parameter.");

		clock_t	start = clock();

		vector<int>	vec1(1000000, 1);

		display_elapsed_time(start, clock());
	}

	void	test_vec_copy_ctor(void)
	{
		std::cout << "TEST: Copy constructor \n\n";

		explain_test("Creates a new object from existing one passed as parameter.");

		// create a vector
		vector<int>	vec1(1000000, 1);

		clock_t	start = clock();

		// create a copy from vec1
		vector<int>	vec2(vec1);

		display_elapsed_time(start, clock());

		// assert they're identical
		assert(vec1 == vec2);
	}

	void	test_vec_range_ctor(void)
	{
		std::cout << "TEST: Range constructor \n\n";

		explain_test("Creates a new object using a range of elements.");

		// create a vector
		vector<int>	test;

		// call push_back()
		for ( int i = 0; i < 30; ++i )
			test.push_back(i);

		vector<int>::iterator	it = test.begin();
		it += 10;

		clock_t	start = clock();

		// create vectors using ranges of elements
		vector<int>	vec1(test.begin(), test.end());

		display_elapsed_time(start, clock());

		start = clock();

		vector<int>	vec2(test.begin(), it);

		display_elapsed_time(start, clock());

		display_vec_infos(vec1, "vector 1");
		display_vec_infos(vec2, "vector 2");
	}

	void	test_vec_copy_assign(void)
	{
		std::cout << "TEST: Copy assignment operator \n\n";

		explain_test("Copies a vector from an existing one.");

		// create two vectors
		vector<int>	vec1(1000000, 1);
		vector<int>	vec2(5);

		clock_t	start = clock();

		// create a copy from vec1
		vec2 = vec1;

		display_elapsed_time(start, clock());

		// assert they're identical
		assert(vec1 == vec2);
	}
}
