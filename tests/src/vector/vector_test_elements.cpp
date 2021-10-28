/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_elements.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 17:02:20 by mboivin          ###   ########.fr       */
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
	void	test_vec_subscript_op(void)
	{
		std::cout << "TEST: Element access: operator[] \n\n";

		explainTest("Access an element of the vector.");

		int	n = 2;
		int	out = 30;

		// create vector
		vector<int>	vec;

		vec.push_back(12);
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(100);
		vec.push_back(25);

		clock_t	start = clock();
		std::cout << "vector[" << n << "] " << vec[n] << "\n\n";
		displayElapsedTime(start, clock());

		// If the container size is greater than n, the function never throws exceptions.
		// Otherwise, the behavior is undefined.
		std::cout << "vector[" << out << "] " << vec[out] << "\n\n";
	}

	void	test_vec_at(void)
	{
		std::cout << "TEST: Element access: at() \n\n";

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

	void	test_vec_front(void)
	{
		std::cout << "TEST: Element access: front() \n\n";

		explainTest("Access the first element in the vector.");

		// create vector
		vector<int>	vec;

		vec.push_back(12);
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(100);
		vec.push_back(25);

		clock_t	start = clock();
		std::cout << "vector.front(): " << vec.front() << "\n\n";
		displayElapsedTime(start, clock());

		assert(vec.front() == 12);
	}

	void	test_vec_back(void)
	{
		std::cout << "TEST: Element access: back() \n\n";

		explainTest("Access the last element in the vector.");

		// create vector
		vector<int>	vec;

		vec.push_back(12);
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(100);
		vec.push_back(25);

		clock_t	start = clock();
		std::cout << "vector.back(): " << vec.back() << "\n\n";
		displayElapsedTime(start, clock());

		assert(vec.back() == 25);
	}
}
