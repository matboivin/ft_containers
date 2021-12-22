/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests_lookup.cpp                               :+:      :+:    :+:   */
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
#include "tests.hpp"
#include "map_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_map_lookup(void)
	{
		// create a map
		int_map		m;

		// fill it
		for (int i = 0; i < COUNT; ++i)
			m[rand()] = rand();

		int_map::iterator	it = m.begin();
		int_map::iterator	ite = m.end();
		--ite;

		std::cout << "TEST: Lookup: count() \n\n";

		explain_test("Returns the number of elements matching key k.");

		clock_t	start = clock();

		std::cout << "m.count(" << ite->first << ") = " << std::boolalpha << m.count(ite->first) << "\n\n";

		display_elapsed_time(start, clock());

		std::cout << "TEST: Lookup: find() \n\n";

		explain_test("Returns the element with the key k, else return end.");

		start = clock();

		std::cout << "m.find(" << ite->first << ") = "
				  << m.find(ite->first)->first << " => " << m.find(ite->first)->second << "\n\n";

		display_elapsed_time(start, clock());

		std::cout << "TEST: Lookup: lower_bound() \n\n";

		explain_test("Gets the first element that is equivalent or after k.");

		start = clock();

		std::cout << "m.lower_bound(" << ite->first << ") = "
				  << m.lower_bound(ite->first)->first << " => " << m.lower_bound(ite->first)->second << "\n\n";

		display_elapsed_time(start, clock());

		std::cout << "TEST: Lookup: upper_bound() \n\n";

		explain_test("Gets the first element that is after k.");

		start = clock();

		std::cout << "m.upper_bound(" << it->first << ") = "
				  << m.upper_bound(it->first)->first << " => " << m.lower_bound(it->first)->second << "\n\n";

		display_elapsed_time(start, clock());

		std::cout << "TEST: Lookup: equal_range() \n\n";

		explain_test("Returns the bounds of a range that have a key equivalent to k.");

		start = clock();

		pair<int_map::iterator,int_map::iterator>	it_pair = m.equal_range(682694293);
		int_map::iterator							first = it_pair.first;
		int_map::iterator							last = it_pair.second;

		std::cout << "m.equal_range(682694293) = "
				  << first->first << " => " << first->second << '\n'
				  << last->first << " => " << last->second << "\n\n";

		display_elapsed_time(start, clock());
	}
}
