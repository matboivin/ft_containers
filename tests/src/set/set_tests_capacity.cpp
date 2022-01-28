/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests_capacity.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/28 15:54:02 by mboivin          ###   ########.fr       */
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
	void	test_set_empty(void)
	{
		std::cout << "TEST: Capacity: empty() \n\n";

		explain_test("Returns true if the set is empty.");

		// create an empty set
		int_set	s;

		bool	is_empty = s.empty();

		std::cout << std::boolalpha << "set.empty()? " << is_empty << std::endl;
		assert(is_empty == true);

		// add elements
		for (int i = 0; i < 42; ++i)
			s.insert(rand());

		is_empty = s.empty();
		std::cout << std::boolalpha << "set.empty()? " << is_empty << std::endl;
		assert(is_empty == false);
	}

	void	test_set_size(void)
	{
		std::cout << "TEST: Capacity: size() \n\n";

		explain_test("Returns the number of element in the set.");

		// create an empty set
		int_set	s;

		std::size_t	set_size = s.size();

		std::cout << "set.size() = " << set_size << std::endl;
		assert(set_size == 0);

		// add elements
		for (int i = 0; i < 42; ++i)
			s.insert(rand());

		set_size = s.size();

		std::cout << "set.size() = " << set_size << std::endl;
		assert(set_size == 42);
	}

	void	test_set_max_size(void)
	{
		std::cout << "TEST: Capacity: max_size() \n\n";

		explain_test("Returns the maximum number of elements that the set can hold.");

		// Create two sets
		int_set	s1;
		str_set	s2;

		// Display capacity
		std::cout << "set<int>:    " << s1.max_size()
				  << "\nset<string>: " << s2.max_size() << std::endl;
	}
}
