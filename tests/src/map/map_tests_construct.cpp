/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests_construct.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/12/20 23:56:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include <string>
#include "tests.hpp"
#include "map_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_map_default_ctor(void)
	{
		std::cout << "TEST: Default Constructor \n\n";

		explain_test("Constructs an empty map.");

		clock_t	start = clock();

		int_map	map;

		display_elapsed_time(start, clock());
	}

	void	test_map_range_ctor(void)
	{
		std::cout << "TEST: range Constructor \n\n";

		explain_test("Constructs a map with a range of elements.");

		// create a map
		int_map	m;

		for (int i = 0; i < 10000; ++i)
			m[rand()] = rand();

		clock_t	start = clock();

		int_map	m_range(m.begin(), m.end());

		display_elapsed_time(start, clock());
	}

	void	test_map_copy_ctor(void)
	{
		std::cout << "TEST: Copy constructor \n\n";

		explain_test("Creates a new object from existing one passed as parameter.");

		// create a map
		int_map	m;

		for (int i = 0; i < 10000; ++i)
			m[rand()] = rand();

		clock_t	start = clock();

		// create a copy from m
		int_map	cpy_m(m);

		display_elapsed_time(start, clock());

		// check they're identical
		int_map::iterator	it = m.begin();
		int_map::iterator	cpy_it = cpy_m.begin();

		for ( ; it != m.end() && cpy_it != cpy_m.end(); ++it, ++cpy_it)
			assert((it->first == cpy_it->first) && (it->second == cpy_it->second));

		int	random_key = rand();

		std::cout << "m[" << random_key << "]     = " << m[random_key] << '\n'
				  << "cpy_m[" << random_key << "] = " << cpy_m[random_key] << "\n\n";

		m[random_key] = rand();

		std::cout << "m[" << random_key << "]     = " << m[random_key] << '\n'
				  << "cpy_m[" << random_key << "] = " << cpy_m[random_key] << "\n\n";

		// check the copy didn't change
		assert(m[random_key] != cpy_m[random_key]);
	}

	void	test_map_copy_assign(void)
	{
		std::cout << "TEST: Copy assignment operator \n\n";

		explain_test("Copies a map from an existing one.");

		// create maps
		int_map	m;
		int_map	cpy_m;

		for (int i = 0; i < 10000; ++i)
			m[rand()] = rand();

		clock_t	start = clock();

		// create a copy from m
		cpy_m = m;

		display_elapsed_time(start, clock());

		// check they're identical
		int_map::iterator	it = m.begin();
		int_map::iterator	cpy_it = cpy_m.begin();

		for ( ; it != m.end() && cpy_it != cpy_m.end(); ++it, ++cpy_it)
			assert((it->first == cpy_it->first) && (it->second == cpy_it->second));

		int	random_key = rand();

		std::cout << "before:\nm[" << random_key << "]     = " << m[random_key] << '\n'
				  << "cpy_m[" << random_key << "] = " << cpy_m[random_key] << "\n\n";

		m[random_key] = rand();

		std::cout << "after:\nm[" << random_key << "]     = " << m[random_key] << '\n'
				  << "cpy_m[" << random_key << "] = " << cpy_m[random_key] << "\n\n";

		// check the copy didn't change
		assert(m[random_key] != cpy_m[random_key]);
	}
}
