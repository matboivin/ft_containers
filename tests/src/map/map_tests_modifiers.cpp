/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests_modifiers.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/23 13:14:12 by mboivin          ###   ########.fr       */
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
	void	test_map_insert_val(void)
	{
		std::cout << "TEST: Modifiers: insert(val) \n\n";

		explain_test("Insert an element.");

		// create a map
		int_map	m;

		// fill it
		for (int i = 0; i < 10000; ++i)
			m[rand()] = rand();

		clock_t	time_start = clock();

		// insert a random element
		m.insert(make_pair(rand(), rand()));
		m.insert(make_pair(1, rand()));

		display_elapsed_time(time_start, clock());
	}

	void	test_map_insert_pos(void)
	{
		std::cout << "TEST: Modifiers: insert(pos, val) \n\n";

		explain_test("Insert an element giving a hint pos.");

		// create a map
		int_map	m;

		// fill it
		for (int i = 0; i < 10000; ++i)
			m[rand()] = rand();

		clock_t	time_start = clock();

		// insert a random element
		m.insert(m.end(), make_pair(rand(), rand()));
		m.insert(m.end(), make_pair(1, rand()));

		display_elapsed_time(time_start, clock());
	}

	void	test_map_insert_range(void)
	{
		std::cout << "TEST: Modifiers: insert(first, last) \n\n";

		explain_test("Insert a range of elements.");

		// create maps
		int_map	m1;
		int_map	m2;

		for (int i = 0; i < 10; ++i)
			m2[rand()] = rand();

		display_map_infos(m1, "before");

		m1.insert(m2.begin(), m2.end());

		display_map_infos(m1, "after");

		for (int i = 0; i < COUNT; ++i)
			m2[rand()] = rand();

		clock_t	start = clock();

		m1.insert(m2.begin(), m2.end());

		display_elapsed_time(start, clock());
	}


	void	test_map_swap(void)
	{
		std::cout << "TEST: Modifiers: swap() \n\n";

		explain_test("Exchanges the content of the map and the other map.");

		// create maps
		int_map	m1;
		int_map	m2;
		int_map	m3;

		// fill them
		for (int i = 0; i < 5; ++i)
			m1[rand()] = rand();

		for (int i = 0; i < 500; ++i)
			m2[rand()] = rand();

		std::cout << "map.swap();\n\n";

		clock_t	time_start = clock();
		m1.swap(m2);
		clock_t	time_end = clock();

		display_elapsed_time(time_start, time_end);

		std::cout << "map.swap();\n\n";

		time_start = clock();
		m1.swap(m3);
		display_elapsed_time(time_start, clock());
	}

	void	test_map_clear(void)
	{
		std::cout << "TEST: Modifiers: clear() \n\n";

		explain_test("Destroys all elements from the container, leaving it with a size of 0.");

		// create a map
		int_map	m;

		// fill it
		for (int i = 0; i < COUNT; ++i)
			m[rand()] = rand();

		std::cout << "map size: " << m.size()
				  << "\nmap.clear();" << std::endl;

		clock_t	time_start = clock();
		m.clear();
		clock_t	time_end = clock();

		std::cout << "map size: " << m.size() << "\n\n";
		display_elapsed_time(time_start, time_end);
	}
}
