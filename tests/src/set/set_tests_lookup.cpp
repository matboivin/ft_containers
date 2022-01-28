/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests_lookup.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/28 16:20:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include "tests.hpp"
#include "set_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_set_lookup(void)
	{
		// create a set
		int_set		s;

		// fill it
		for (int i = 0; i < COUNT; ++i)
			s.insert(rand());

		int_set::iterator	it = s.begin();
		int_set::iterator	ite = s.end();
		--ite;

		std::cout << "TEST: Lookup: count() \n\n";

		explain_test("Returns the number of elements matching key k.");

		clock_t	start = clock();

		std::cout << "s.count(" << *ite << ") = " << std::boolalpha << s.count(*ite) << "\n\n";

		display_elapsed_time(start, clock());

		std::cout << "TEST: Lookup: find() \n\n";

		explain_test("Returns the element with the key k, else return end.");

		start = clock();

		std::cout << "s.find(" << *ite << ") = " << *s.find(*ite) << "\n\n";

		display_elapsed_time(start, clock());

		std::cout << "TEST: Lookup: lower_bound() \n\n";

		explain_test("Gets the first element that is equivalent or after k.");

		start = clock();

		std::cout << "s.lower_bound(" << *ite << ") = " << *s.lower_bound(*ite) << "\n\n";

		display_elapsed_time(start, clock());

		std::cout << "TEST: Lookup: upper_bound() \n\n";

		explain_test("Gets the first element that is after k.");

		start = clock();

		std::cout << "s.upper_bound(" << *it << ") = " << *s.upper_bound(*it) << "\n\n";

		display_elapsed_time(start, clock());

		std::cout << "TEST: Lookup: equal_range() \n\n";

		explain_test("Returns the bounds of a range that have a key equivalent to k.");

		start = clock();

		pair<int_set::iterator,int_set::iterator>	it_pair = s.equal_range(682694293);
		int_set::iterator							first = it_pair.first;
		int_set::iterator							last = it_pair.second;

		std::cout << "s.equal_range(682694293) = "
				  << *first << '\n'
				  << *last << "\n\n";

		display_elapsed_time(start, clock());
	}
}
