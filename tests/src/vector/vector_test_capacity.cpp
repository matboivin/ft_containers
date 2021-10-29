/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_capacity.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/29 17:23:00 by mboivin          ###   ########.fr       */
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
	void	test_vec_empty(void)
	{
		std::cout << "TEST: Capacity: empty() \n\n";

		explainTest("Returns true if the vector is empty.");

		// create an empty vector
		vector<int>	vec1;

		bool	is_empty = vec1.empty();

		std::cout << std::boolalpha << "vec.empty()? " << is_empty << std::endl;
		assert(is_empty == true);

		// create a vector of size 10
		vector<int>	vec2(10);

		is_empty = vec2.empty();
		std::cout << std::boolalpha << "vec.empty()? " << is_empty << std::endl;
		assert(is_empty == false);
	}

	void	test_vec_size(void)
	{
		std::cout << "TEST: Capacity: size() \n\n";

		explainTest("Returns true the number of element in the vector.");

		// create a vector
		vector<int>	vec(42);

		std::size_t	vec_size = vec.size();

		std::cout << "vec.size() = " << vec_size << std::endl;
		assert(vec_size == 42);

		for (int i = 0; i < 8; ++i)
			vec.push_back(i);

		vec_size = vec.size();

		std::cout << "vec.size() = " << vec_size << std::endl;
		assert(vec_size == 50);
	}

	void	test_vec_resize(void)
	{
		std::cout << "TEST: Capacity: resize() \n\n";

		explainTest("Resizes the container so that it contains n elements.");

		// create expected results
		vector<int>	res1;

		for ( int i = 1; i < 6; ++i )
			res1.push_back(i);

		vector<int>	res2(res1);

		for ( int i = 0; i < 3; ++i )
			res2.push_back(100);

		vector<int>	res3(res2);

		for ( int i = 0; i < 4; ++i )
			res3.push_back(0);

		// create a vector
		vector<int>	vec;

		for ( int i = 1; i < 10 ; ++i )
			vec.push_back(i);

		std::cout << "vec.resize(5);\n\n";
		vec.resize(5); // [ 1, 2, 3, 4, 5 ]
		assert(vec == res1);
		displayVecInfos(vec);

		std::cout << "\nvec.resize(8,100);\n\n";
		vec.resize(8,100); // [ 1, 2, 3, 4, 5, 100, 100, 100 ]
		assert(vec == res2);
		displayVecInfos(vec);

		std::cout << "\nvec.resize(12);\n\n";
		vec.resize(12); // [ 1, 2, 3, 4, 5, 100, 100, 100, 0, 0, 0, 0 ]
		assert(vec == res3);
		displayVecInfos(vec);
	}

	void	test_vec_max_size(void)
	{
		std::cout << "TEST: Capacity: max_size() \n\n";

		explainTest("Returns the maximum number of elements that the vector can hold.");

		// Create two vectors of size 42
		vector<int>		vec1(42);
		vector<char>	vec2(42);

		// Display capacity
		std::cout << "vector of int:  " << vec1.max_size()
				  << "\nvector of char: " << vec2.max_size() << std::endl;
	}

	void	test_vec_capacity(void)
	{
		std::cout << "TEST: Capacity: capacity() \n\n";

		explainTest("Returns the size of allocated storage capacity.");

		// Create two vectors of size 42
		vector<int>		vec1(42);
		vector<char>	vec2(42);

		// Display capacity
		std::cout << "vector of int:  " << vec1.capacity()
				  << "\nvector of char: " << vec2.capacity() << std::endl;
	}

	void	test_vec_reserve(void)
	{
		std::cout << "TEST: Capacity: reserve() \n\n";

		explainTest("Requests that the vector capacity be at least enough to contain n elements.");

		// Create two vectors of size 42
		vector<int>		vec1(1);
		vector<char>	vec2(1);

		// Display capacity
		std::cout << "vector of int:  " << vec1.capacity()
				  << "\nvector of char: " << vec2.capacity() << std::endl;

		std::cout << "\nvector.reserve(42);\n\n";

		// reserve
		vec1.reserve(42);
		vec2.reserve(42);

		// Display capacity
		std::cout << "vector of int:  " << vec1.capacity()
				  << "\nvector of char: " << vec2.capacity() << std::endl;
	}
}
