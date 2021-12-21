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
			m[i] = rand();

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
			m[i] = rand();

		clock_t	start = clock();

		// create a copy from m
		int_map	m_cpy(m);

		display_elapsed_time(start, clock());

		// assert they're identical
		//assert(map == map_cpy);
	}

	void	test_map_copy_assign(void)
	{
		std::cout << "TEST: Copy assignment operator \n\n";

		explain_test("Copies a map from an existing one.");

		// create maps
		int_map	m;
		int_map	m_cpy;

		for (int i = 0; i < 10000; ++i)
			m[i] = rand();

		clock_t	start = clock();

		// create a copy from m
		m_cpy = m;

		display_elapsed_time(start, clock());
	}
}
