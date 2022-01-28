/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests_observers.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:11:14 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/28 16:22:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "utility.hpp"
#include "tests.hpp"
#include "set_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	typedef set<std::string,size_compare<std::string> >	strlen_set;

	void	test_set_key_comp(void)
	{
		std::cout << "TEST: Non-member key_comp() \n\n";

		explain_test("Returns a copy of the comparison object used by the container"
					 "to compare keys.");

		// create set
		int_set	s1;
		int_set	expected1;
		// get key comparison object
		int_set::key_compare	less_comp = s1.key_comp();

		std::cout << "set<std::string>\n\n";

		// insert elements
		s1.insert(200);
		s1.insert(100);
		s1.insert(100);
		s1.insert(400);
		s1.insert(300);
		s1.insert(300);
		s1.insert(100);
		s1.insert(100);
		// expected result
		expected1.insert(100);
		expected1.insert(200);
		expected1.insert(300);
		expected1.insert(400);

		int					highest1 = *s1.rbegin();
		int_set::iterator	it1 = s1.begin();

		do
		{
			std::cout << *it1 << '\n';
		} while (less_comp((*it1++), highest1));

		std::cout << '\n';

		// assert set meets expected result
		assert(s1 == expected1);

		// create set
		strlen_set	s2;
		strlen_set	expected2;
		// get key comparison object
		strlen_set::key_compare	strlen_comp = s2.key_comp();

		std::cout << "set<std::string>\n\n";

		// insert elements
		s2.insert("foo");
		s2.insert("qwerty");
		s2.insert("qwerty");
		s2.insert("qwerty");
		s2.insert("qwerty");
		s2.insert("foo");
		s2.insert("foo");
		s2.insert("bar");
		s2.insert("42");
		s2.insert("bar");
		s2.insert("bar");
		s2.insert("bar");
		// expected result
		expected2.insert("42");
		expected2.insert("foo");
		expected2.insert("qwerty");

		std::string				highest2 = *s2.rbegin();
		strlen_set::iterator	it2 = s2.begin();

		do
		{
			std::cout << *it2 << '\n';
		} while (strlen_comp((*it2++), highest2));

		std::cout << '\n';

		// assert set meets expected result
		assert(s2 == expected2);
	}

	void	test_set_value_comp(void)
	{
		std::cout << "TEST: Non-member value_comp() \n\n";

		explain_test("Returns a copy of the comparison object used by the container"
					 "to compare elements.");

		// create set
		int_set	s1;
		int_set	expected1;

		std::cout << "set<int>\n\n";

		// insert elements
		s1.insert(200);
		s1.insert(100);
		s1.insert(100);
		s1.insert(400);
		s1.insert(300);
		s1.insert(300);
		s1.insert(100);
		s1.insert(100);
		// expected result
		expected1.insert(100);
		expected1.insert(200);
		expected1.insert(300);
		expected1.insert(400);

		int					highest1 = *s1.rbegin();
		int_set::iterator	it1 = s1.begin();

		do
		{
			std::cout << *it1 << '\n';
		} while (s1.value_comp()(*(it1++), highest1));

		std::cout << '\n';

		// assert set meets expected result
		assert(s1 == expected1);

		// create set
		strlen_set	s2;
		strlen_set	expected2;

		std::cout << "set<std::string>\n\n";

		// insert elements
		s2.insert("foo");
		s2.insert("qwerty");
		s2.insert("qwerty");
		s2.insert("qwerty");
		s2.insert("qwerty");
		s2.insert("foo");
		s2.insert("foo");
		s2.insert("bar");
		s2.insert("42");
		s2.insert("bar");
		s2.insert("bar");
		s2.insert("bar");
		// expected result
		expected2.insert("42");
		expected2.insert("foo");
		expected2.insert("qwerty");

		std::string				highest2 = *s2.rbegin();
		strlen_set::iterator	it2 = s2.begin();

		do
		{
			std::cout << *it2 << '\n';
		} while (s2.value_comp()(*(it2++), highest2));

		std::cout << '\n';

		// assert set meets expected result
		assert(s2 == expected2);
	}
}
