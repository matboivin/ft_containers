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
		std::cout << "TEST: Lookup: count() \n\n";

		explain_test("Returns the number of elements matching key k.");

		int_map		m;

		for (int i = 0; i < COUNT; ++i)
			m[rand()] = rand();

		int_map::iterator	it = m.begin();
		int_map::iterator	ite = m.end();
		--ite;

		clock_t	start = clock();

		std::cout << "m.count(" << ite->first << "):       " << m.count(ite->first) << "\n\n";

		display_elapsed_time(start, clock());

		start = clock();

		std::cout << "m.lower_bound(" << ite->first << "): "
				  << m.lower_bound(ite->first)->first << " => " << m.lower_bound(ite->first)->second << "\n\n";

		display_elapsed_time(start, clock());

		start = clock();

		std::cout << "m.upper_bound(" << it->first << "):  "
				  << m.upper_bound(it->first)->first << " => " << m.lower_bound(it->first)->second << "\n\n";

		display_elapsed_time(start, clock());
	}
}
