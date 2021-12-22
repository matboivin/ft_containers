/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests_capacity.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/12/21 00:02:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include <string>
#include <map>
#include "tests.hpp"
#include "map_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_map_empty(void)
	{
		std::cout << "TEST: Capacity: empty() \n\n";

		explain_test("Returns true if the map is empty.");

		// create an empty map
		int_map	m;

		bool	is_empty = m.empty();

		std::cout << std::boolalpha << "map.empty()? " << is_empty << std::endl;
		assert(is_empty == true);

		// add elements
		for (int i = 0; i < 42; ++i)
			m[rand()] = rand();

		is_empty = m.empty();
		std::cout << std::boolalpha << "map.empty()? " << is_empty << std::endl;
		assert(is_empty == false);
	}

	void	test_map_size(void)
	{
		std::cout << "TEST: Capacity: size() \n\n";

		explain_test("Returns the number of element in the map.");

		// create an empty map
		int_map	m;

		std::size_t	map_size = m.size();

		std::cout << "map.size() = " << map_size << std::endl;
		assert(map_size == 0);

		// add elements
		for (int i = 0; i < 42; ++i)
			m[rand()] = rand();

		map_size = m.size();

		std::cout << "map.size() = " << map_size << std::endl;
		assert(map_size == 42);
	}

	void	test_map_max_size(void)
	{
		std::cout << "TEST: Capacity: max_size() \n\n";

		explain_test("Returns the maximum number of elements that the map can hold.");

		// Create two maps
		int_map		m1;
		int_s_map	m2;

		// Display capacity
		std::cout << "map<int,int>:    " << m1.max_size()
				  << "\nmap<int,string>: " << m2.max_size() << std::endl;
	}
}
