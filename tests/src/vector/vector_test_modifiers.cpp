/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_modifiers.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/12/10 19:03:30 by mboivin          ###   ########.fr       */
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

		explain_test("Assigns new contents to the vector using a range of iterators.");

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

		display_vec_infos(vec2, "before");

		clock_t	time_start = clock();
		vec2.assign(first, last);
		clock_t	time_end = clock();

		display_vec_infos(vec2, "after");
		display_elapsed_time(time_start, time_end);
	}

	void	test_vec_assign_val(void)
	{
		std::cout << "TEST: Modifiers: assign(n, val) \n\n";

		explain_test("Assigns new contents to the vector using a fill value.");

		// create vectors
		vector<int>	vec;

		// fill them
		for ( int i = 0; i < 60; ++i )
			vec.push_back(i);

		display_vec_infos(vec, "before");

		clock_t	time_start = clock();
		vec.assign(42, 42);
		clock_t	time_end = clock();

		display_vec_infos(vec, "after");
		display_elapsed_time(time_start, time_end);
	}

	void	test_vec_push_back(void)
	{
		std::cout << "TEST: Modifiers: push_back() \n\n";

		explain_test("Add a new elements at the end of the vector.");

		// create a vector
		vector<int>	vec;

		clock_t	time_start = clock();

		// call push_back()
		for ( int i = 0; i < 1000000; ++i )
			vec.push_back(i);

		display_elapsed_time(time_start, clock());
	}

	void	test_vec_pop_back(void)
	{
		std::cout << "TEST: Modifiers: pop_back() \n\n";

		explain_test("Removes (destroys) the last element in the vector.");

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
		display_elapsed_time(time_start, time_end);
	}

	void	test_vec_insert_val(void)
	{
		std::cout << "TEST: Modifiers: insert(pos, val) \n\n";

		explain_test("Insert an element at the position pos.");

		// create vectors
		vector<int>	vec;
		vector<int>	result;

		// fill it
		for ( int i = 0; i < 10; ++i )
			vec.push_back(i);

		for ( int i = 0; i < 2; ++i )
			result.push_back(i);

		result.push_back(100);

		for ( int i = 2; i < 10; ++i )
			result.push_back(i);

		vector<int>::iterator	it;

		display_vec_infos(vec, "before");

		clock_t	time_start = clock();
		it = vec.insert(vec.begin() + 2, 100);
		clock_t	time_end = clock();

		display_vec_infos(vec, "after");
		std::cout << "*it = " << *it << "\n\n";
		display_elapsed_time(time_start, time_end);

		assert(*it == 100);
		assert(vec == result);
	}

	void	test_vec_insert_nval(void)
	{
		std::cout << "TEST: Modifiers: insert(pos, n, val) \n\n";

		explain_test("Insert n elements at the position pos.");

		// create vectors
		vector<int>	vec;
		vector<int>	result;

		// fill it
		for ( int i = 0; i < 10; ++i )
			vec.push_back(i);

		for ( int i = 0; i < 2; ++i )
			result.push_back(i);

		result.push_back(500);
		result.push_back(500);
		result.push_back(300);
		result.push_back(100);
		result.push_back(100);
		result.push_back(100);

		for ( int i = 2; i < 10; ++i )
			result.push_back(i);

		display_vec_infos(vec, "before");

		clock_t	time_start = clock();
		vec.insert(vec.begin() + 2, 3, 100);
		vec.insert(vec.begin() + 2, 1, 300);
		vec.insert(vec.begin() + 2, 2, 500);
		clock_t	time_end = clock();

		display_vec_infos(vec, "after");
		display_elapsed_time(time_start, time_end);

		assert(vec == result);
	}

	void	test_vec_insert_it(void)
	{
		std::cout << "TEST: Modifiers: insert(pos, first, last) \n\n";

		explain_test("Insert a range of elements at the position pos.");

		// create vectors
		vector<int>	vec;
		vector<int>	vec2;
		vector<int>	result;

		// fill them
		for ( int i = 0; i < 10; ++i )
			vec.push_back(i);

		for ( int i = 250; i < 300; i += 10 )
			vec2.push_back(i);

		for ( int i = 0; i < 5; ++i )
			result.push_back(i);
		for ( int i = 250; i < 300; i += 10 )
			result.push_back(i);
		for ( int i = 5; i < 10; ++i )
			result.push_back(i);
		for ( int i = 250; i < 300; i += 10 )
			result.push_back(i);

		display_vec_infos(vec, "before");

		clock_t	time_start = clock();
		vec.insert(vec.begin() + 5, vec2.begin(), vec2.end());
		vec.insert(vec.end(), vec2.begin(), vec2.end());
		clock_t	time_end = clock();

		display_vec_infos(vec, "after");
		display_elapsed_time(time_start, time_end);

		assert(vec == result);
	}

	void	test_vec_erase_pos(void)
	{
		std::cout << "TEST: Modifiers: erase(pos) \n\n";

		explain_test("Removes from the vector the element at the given position.");

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

		display_elapsed_time(time_start, time_end);

		assert(*it == 51);
	}

	void	test_vec_erase_it(void)
	{
		std::cout << "TEST: Modifiers: erase(first, last) \n\n";

		explain_test("Removes from the vector a range of elements.");

		// create vectors
		vector<int>	vec;
		vector<int>	original;

		// fill them
		for ( int i = 0; i < 1000; ++i )
			vec.push_back(i);

		for ( int i = 0; i < 10; ++i )
			original.push_back(i);
		for ( int i = 50; i < 1000; ++i )
			original.push_back(i);

		vector<int>::iterator	first = vec.begin();
		vector<int>::iterator	last = vec.begin();
		first += 10;
		last += 50;

		//display_vec_infos(vec, "before");

		vector<int>::iterator	it;
		clock_t	time_start = clock();
		it = vec.erase(first, last);
		clock_t	time_end = clock();

		//display_vec_infos(vec, "after");
		display_elapsed_time(time_start, time_end);

		assert(vec == original);
	}

	void	test_vec_swap(void)
	{
		std::cout << "TEST: Modifiers: swap() \n\n";

		explain_test("Exchanges the content of the current instance by the content "
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

		display_vec_infos(vec1, "vector 1");
		display_vec_infos(vec2, "vector 2");

		std::cout << "vector.swap();\n\n";

		clock_t	time_start = clock();
		vec1.swap(vec2);
		clock_t	time_end = clock();

		display_vec_infos(vec1, "vector 1");
		display_vec_infos(vec2, "vector 2");

		display_elapsed_time(time_start, time_end);

		std::cout << "vector.swap();\n\n";

		time_start = clock();
		vec1.swap(vec3);
		display_elapsed_time(time_start, clock());
	}

	void	test_vec_clear(void)
	{
		std::cout << "TEST: Modifiers: clear() \n\n";

		explain_test("Destroys all elements from the vector, leaving the container with a size of 0.");

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
		display_elapsed_time(time_start, time_end);
	}
}
