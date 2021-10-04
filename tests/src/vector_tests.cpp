/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/04 18:59:33 by mboivin          ###   ########.fr       */
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

		vector<int>	vec1(1000000, 1);

		displayElapsedTime(start, clock());
	}

	void	test_vec_copy_ctor(void)
	{
		std::cout << "_____________ Copy constructor _____________\n\n";

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
		std::cout << "_________ Copy assignment operator _________\n\n";

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
		std::cout << "_______ capacity method: push_back() _______\n\n";

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
		std::cout << "_________________ Iterator _________________\n\n";

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
		std::cout << "_________ Element access method: at ________\n\n";

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
			std::cout << "vector.at(" << n << ") " << vec.at(n) << std::endl;
			displayElapsedTime(start, clock());
		}
		catch (std::out_of_range& oor)
		{
			std::cout << "\nCatched 'out_of_range': " << oor.what() << std::endl;
		}

		try
		{
			std::cout << "vector.at(" << out << ") " << vec.at(out) << std::endl;
		}
		catch (std::out_of_range& oor)
		{
			std::cout << "Catched 'out_of_range':\n" << COL_RESET << oor.what() << "\n\n";
		}
	}

	void	test_vector(void)
	{
		std::cout << ":::::::::::::::::: VECTOR ::::::::::::::::::\n\n";

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
