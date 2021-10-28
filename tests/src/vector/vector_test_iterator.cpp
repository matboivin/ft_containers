/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_iterator.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 18:38:21 by mboivin          ###   ########.fr       */
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
	void	test_vec_iterator(void)
	{
		std::cout << "TEST: Iterator \n\n";

		explainTest("Move through the elements of the container like pointers do.");

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
}
