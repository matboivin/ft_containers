/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/07 18:22:13 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <fstream>
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
	void	test_vec_fill_ctor(void)
	{
		std::cout << std::setfill('.') << std::setw(42) << " Fill Constructor \n\n";

		explainTest("Constructs a container with n elements. "
					"Each element is a copy of value passed as parameter.");

		clock_t	start = clock();

		vector<int>	vec1(1000000, 1);

		displayElapsedTime(start, clock());
	}

	void	test_vec_copy_ctor(void)
	{
		std::cout << std::setfill('.') << std::setw(42) << " Copy constructor \n\n";

		explainTest("Creates a new object from existing one passed as parameter.");

		// create a vector
		vector<int>	vec1(1000000, 1);

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
		std::cout << std::setfill('.') << std::setw(42) << " Copy assignment operator \n\n";

		explainTest("Copies a vector from an existing one.");

		// create two vectors
		vector<int>	vec1(1000000, 1);
		vector<int>	vec2(5);

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
		std::cout << std::setfill('.') << std::setw(42) << " capacity method: push_back() \n\n";

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

	void	test_vec_iterator(void)
	{
		std::cout << std::setfill('.') << std::setw(42) << " Iterator \n\n";

		explainTest("Move through the elements of the container like pointers do.");

		vector<int>::iterator	iter_type;

		// create vector
		vector<int>	vec;

		vec.push_back(12);
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(100);
		vec.push_back(25);

		clock_t	start = clock();

		// create iterators
		vector<int>::iterator	it = vec.begin();
		vector<int>::iterator	ite = vec.end();

		std::cout << "*it      = " << *it
				<< "\n*(--ite) = " << *(--ite)
				<< "\n\n";

		displayElapsedTime(start, clock());

		assert(*it == 12);
		assert(*ite == 25);
	}

	// elements access
	void	test_vec_at(void)
	{
		std::cout << std::setfill('.') << std::setw(42) << " Element access: at \n\n";

		explainTest("This member function accesses the element at "
					"the specified position in the container.");

		int	n = 2;
		int	out = 15;

		// create vector
		vector<int>	vec;

		vec.push_back(12);
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(100);
		vec.push_back(25);

		try
		{
			clock_t	start = clock();
			std::cout << "vector.at(" << n << ") " << vec.at(n) << "\n\n";
			displayElapsedTime(start, clock());
		}
		catch (std::out_of_range& oor)
		{
			std::cout << "Catched 'out_of_range':\n" << oor.what() << "\n\n";
		}

		try
		{
			std::cout << "vector.at(" << out << ") " << vec.at(out) << "\n\n";
		}
		catch (std::out_of_range& oor)
		{
			std::cout << "Catched 'out_of_range':\n" << oor.what() << "\n\n";
		}
	}

	void	test_vector(void)
	{
		#if defined(TEST_FT)
		std::cout << std::setfill('_') << std::setw(42) << " MY VECTOR \n\n";
		#else
		std::cout << std::setfill('_') << std::setw(42) << " ORIGINAL VECTOR \n\n";
		#endif

		// construct/assign/destroy
		test_vec_fill_ctor();
		test_vec_copy_ctor();
		test_vec_copy_assign();
		test_vec_push_back();

		// iterator
		test_vec_iterator();

		// elements access
		test_vec_at();
	}
}
