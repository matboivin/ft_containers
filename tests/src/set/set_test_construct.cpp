/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test_construct.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:37:19 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 18:57:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "tests.hpp"
#include "set_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_set_default_ctor(void)
	{
		std::cout << "TEST: Default Constructor \n\n";

		explain_test("Constructs an empty set.");

		clock_t	start = clock();

		int_set	s;

		display_elapsed_time(start, clock());
	}

	void	test_set_range_ctor(void)
	{
		std::cout << "TEST: range Constructor \n\n";

		explain_test("Constructs a set with a range of elements.");

		// create a set
		int_set	s;

		for (int i = 0; i < 10000; ++i)
			s.insert(rand());

		clock_t	start = clock();

		// create a set from a range
		int_set	s_range(s.begin(), s.end());

		display_elapsed_time(start, clock());
	}

	void	test_set_copy_ctor(void)
	{
		std::cout << "TEST: Copy constructor \n\n";

		explain_test("Creates a new object from existing one passed as parameter.");

		// create a set
		int_set	s;

		for (int i = 0; i < 10000; ++i)
			s.find(rand());

		clock_t	start = clock();

		// create a copy from m
		int_set	cpy_s(s);

		display_elapsed_time(start, clock());

		// another assert test
		copy_is_identical(s, s);
	}

	void	test_set_copy_assign(void)
	{
		std::cout << "TEST: Copy assignment operator \n\n";

		explain_test("Copies a set from an existing one.");

		// create sets
		int_set	s;
		int_set	cpy_s;

		for (int i = 0; i < 10000; ++i)
			s.insert(rand());

		clock_t	start = clock();

		// create a copy from m
		cpy_s = s;

		display_elapsed_time(start, clock());

		// check they're identical
		int_set::iterator	it = s.begin();
		int_set::iterator	cpy_it = cpy_s.begin();

		for (; it != s.end() && cpy_it != cpy_s.end(); ++it, ++cpy_it)
			assert(*it == *cpy_it);

		int	random_key = rand();

		std::cout << "before:\ns.find(" << random_key << ")     = " << *s.find(random_key) << '\n'
				  << "cpy_s.find(" << random_key << ") = " << *cpy_s.find(random_key) << "\n\n";

		random_key = rand();

		std::cout << "after:\ns.find(" << random_key << ")     = " << *s.find(random_key) << '\n'
				  << "cpy_s.find(" << random_key << ") = " << *cpy_s.find(random_key) << "\n\n";

		// check the copy didn't change
		assert(s.find(random_key) != cpy_s.find(random_key));
	}
}
