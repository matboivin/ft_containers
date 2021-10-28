/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_modifiers.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 19:35:25 by mboivin          ###   ########.fr       */
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
	void	test_vec_assign_it(void)
	{
		std::cout << "TEST: Modifiers: assign(first, last) \n\n";

		explainTest("Assigns new contents to the vector using a range of iterators.");

		// create vectors
		vector<int>	vec1;
		vector<int>	vec2;

		// fill them
		for ( int i = 0; i < 60; ++i )
			vec1.push_back(i);

		vector<int>::iterator	first = vec1.begin();
		vector<int>::iterator	last = vec1.begin();
		first += 2;
		last += 42;

		displayVecInfos(vec2, "before");

		clock_t	time_start = clock();
		vec2.assign(first, last);
		clock_t	time_end = clock();

		displayVecInfos(vec2, "after");
		displayElapsedTime(time_start, time_end);
	}

	void	test_vec_assign_val(void)
	{
		std::cout << "TEST: Modifiers: assign(n, val) \n\n";

		explainTest("Assigns new contents to the vector using a fill value.");

		// create vectors
		vector<int>	vec;

		// fill them
		for ( int i = 0; i < 60; ++i )
			vec.push_back(i);

		displayVecInfos(vec, "before");

		clock_t	time_start = clock();
		vec.assign(42, 42);
		clock_t	time_end = clock();

		displayVecInfos(vec, "after");
		displayElapsedTime(time_start, time_end);
	}

	void	test_vec_push_back(void)
	{
		std::cout << "TEST: Modifiers: push_back() \n\n";

		explainTest("Add a new elements at the end of the vector.");

		// create a vector
		vector<int>	vec;

		clock_t	time_start = clock();

		// call push_back()
		for ( int i = 0; i < 1000000; ++i )
			vec.push_back(i);

		displayElapsedTime(time_start, clock());
	}

	void	test_vec_pop_back(void)
	{
		std::cout << "TEST: Modifiers: pop_back() \n\n";

		explainTest("Removes (destroys) the last element in the vector.");

		// create a vector
		vector<int>	vec;

		// fill it
		for ( int i = 0; i < 1000; ++i )
			vec.push_back(i);

		std::cout << "vector size: " << vec.size()
				  << "\nvector.pop_back();" << std::endl;
		
		clock_t	time_start = clock();
		vec.pop_back();
		clock_t	time_end = clock();

		std::cout << "vector size: " << vec.size() << "\n\n";
		displayElapsedTime(time_start, time_end);
	}

	void	test_vec_erase_pos(void)
	{
		std::cout << "TEST: Modifiers: erase(pos) \n\n";

		explainTest("Removes from the vector the element at the given position.");

		// create a vector
		vector<int>	vec;

		// fill it
		for ( int i = 0; i < 1000; ++i )
			vec.push_back(i);

		vector<int>::iterator	pos = vec.begin();
		pos += 50;

		std::cout << "vector size:      " << vec.size()
				  << "\nvector.at(50)   = " << vec.at(50)
				  << "\n\nit = vector.erase(50);\n\n";

		vector<int>::iterator	it;
		clock_t	time_start = clock();
		it = vec.erase(pos);
		clock_t	time_end = clock();

		std::cout << "vector size:      " << vec.size()
				  << "\nvector.at(50)   = " << vec.at(50)
				  << "\n*it             = " << *it << "\n\n";

		displayElapsedTime(time_start, time_end);

		assert(*it == 51);
	}

	void	test_vec_erase_it(void)
	{
		std::cout << "TEST: Modifiers: erase(first, last) \n\n";

		explainTest("Removes from the vector a range of elements.");

		// create vectors
		vector<int>	vec;
		vector<int>	original;

		// fill them
		for ( int i = 0; i < 60; ++i )
			vec.push_back(i);

		for ( int i = 0; i < 10; ++i )
			original.push_back(i);
		for ( int i = 50; i < 60; ++i )
			original.push_back(i);

		vector<int>::iterator	first = vec.begin();
		vector<int>::iterator	last = vec.begin();
		first += 10;
		last += 50;

		displayVecInfos(vec, "before");

		vector<int>::iterator	it;
		clock_t	time_start = clock();
		it = vec.erase(first, last);
		clock_t	time_end = clock();

		displayVecInfos(vec, "after");
		displayElapsedTime(time_start, time_end);

		assert(vec == original);
	}

	void	test_vec_swap(void)
	{
		std::cout << "TEST: Modifiers: swap() \n\n";

		explainTest("Exchanges the content of the current instance by the content "
					"of the vector parameter.");

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

		std::cout << "vector.swap();\n\n";

		clock_t	time_start = clock();
		vec1.swap(vec2);
		clock_t	time_end = clock();

		displayVecInfos(vec1, "vector 1");
		displayVecInfos(vec2, "vector 2");

		displayElapsedTime(time_start, time_end);

		std::cout << "vector.swap();\n\n";

		time_start = clock();
		vec1.swap(vec3);
		displayElapsedTime(time_start, clock());
	}

	void	test_vec_clear(void)
	{
		std::cout << "TEST: Modifiers: clear() \n\n";

		explainTest("Add a new elements at the end of the vector.");

		// create a vector
		vector<int>	vec;

		// fill it
		for ( int i = 0; i < 1000; ++i )
			vec.push_back(i);

		std::cout << "vector size: " << vec.size()
				  << "\nvector.clear();" << std::endl;

		clock_t	time_start = clock();
		vec.clear();
		clock_t	time_end = clock();

		std::cout << "vector size: " << vec.size() << "\n\n";
		displayElapsedTime(time_start, time_end);
	}
}
