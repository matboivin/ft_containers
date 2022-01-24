/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests_observers.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:11:14 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 18:27:13 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "utility.hpp"
#include "tests.hpp"
#include "map_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	typedef map<std::string,int,size_compare<std::string> >	s_int_map;

	void	test_map_key_comp(void)
	{
		std::cout << "TEST: Non-member key_comp() \n\n";

		explain_test("Returns a copy of the comparison object used by the container"
					 "to compare keys.");

		// create map
		int_s_map	m1;
		int_s_map	expected1;
		// get key comparison object
		int_s_map::key_compare	less_comp = m1.key_comp();

		std::cout << "map<int, std::string>\n\n";

		// insert elements
		m1.insert(make_pair(200, "foo"));
		m1.insert(make_pair(100, "qwerty"));
		m1.insert(make_pair(100, "qwerty"));
		m1.insert(make_pair(400, "42"));
		m1.insert(make_pair(300, "bar"));
		m1.insert(make_pair(300, "bar"));
		m1.insert(make_pair(100, "qwerty"));
		m1.insert(make_pair(100, "qwerty"));
		// expected result
		expected1.insert(make_pair(100, "qwerty"));
		expected1.insert(make_pair(200, "foo"));
		expected1.insert(make_pair(300, "bar"));
		expected1.insert(make_pair(400, "42"));

		int					highest1 = m1.rbegin()->first;
		int_s_map::iterator	it1 = m1.begin();

		do
		{
			std::cout << it1->first << " => " << it1->second << '\n';
		} while (less_comp((*it1++).first, highest1));

		std::cout << '\n';

		// assert map meets expected result
		assert(m1 == expected1);

		// create map
		s_int_map	m2;
		s_int_map	expected2;
		// get key comparison object
		s_int_map::key_compare	strlen_comp = m2.key_comp();

		std::cout << "map<std::string, int>\n\n";

		// insert elements
		m2.insert(make_pair("foo",    200));
		m2.insert(make_pair("qwerty", 100));
		m2.insert(make_pair("qwerty", 100));
		m2.insert(make_pair("qwerty", 100));
		m2.insert(make_pair("qwerty", 100));
		m2.insert(make_pair("foo",    200));
		m2.insert(make_pair("foo",    200));
		m2.insert(make_pair("bar",    300));
		m2.insert(make_pair("42",     400));
		m2.insert(make_pair("bar",    300));
		m2.insert(make_pair("bar",    300));
		m2.insert(make_pair("bar",    300));
		// expected result
		expected2.insert(make_pair("42",     400));
		expected2.insert(make_pair("foo",    200));
		expected2.insert(make_pair("qwerty", 100));

		std::string			highest2 = m2.rbegin()->first;
		s_int_map::iterator	it2 = m2.begin();

		do
		{
			std::cout << it2->first << " => " << it2->second << '\n';
		} while (strlen_comp((*it2++).first, highest2));

		std::cout << '\n';

		// assert map meets expected result
		assert(m2 == expected2);
	}

	void	test_map_value_comp(void)
	{
		std::cout << "TEST: Non-member value_comp() \n\n";

		explain_test("Returns a copy of the comparison object used by the container"
					 "to compare elements.");

		// create map
		int_s_map	m1;
		int_s_map	expected1;

		std::cout << "map<int, std::string>\n\n";

		// insert elements
		m1.insert(make_pair(200, "foo"));
		m1.insert(make_pair(100, "qwerty"));
		m1.insert(make_pair(100, "qwerty"));
		m1.insert(make_pair(400, "42"));
		m1.insert(make_pair(300, "bar"));
		m1.insert(make_pair(300, "bar"));
		m1.insert(make_pair(100, "qwerty"));
		m1.insert(make_pair(100, "qwerty"));
		// expected result
		expected1.insert(make_pair(100, "qwerty"));
		expected1.insert(make_pair(200, "foo"));
		expected1.insert(make_pair(300, "bar"));
		expected1.insert(make_pair(400, "42"));

		pair<int,std::string>	highest1 = *m1.rbegin();
		int_s_map::iterator		it1 = m1.begin();

		do
		{
			std::cout << it1->first << " => " << it1->second << '\n';
		} while (m1.value_comp()(*it1++, highest1));

		std::cout << '\n';

		// assert map meets expected result
		assert(m1 == expected1);

		// create map
		s_int_map	m2;
		s_int_map	expected2;

		std::cout << "map<std::string, int>\n\n";

		// insert elements
		m2.insert(make_pair("foo",    200));
		m2.insert(make_pair("qwerty", 100));
		m2.insert(make_pair("qwerty", 100));
		m2.insert(make_pair("qwerty", 100));
		m2.insert(make_pair("qwerty", 100));
		m2.insert(make_pair("foo",    200));
		m2.insert(make_pair("foo",    200));
		m2.insert(make_pair("bar",    300));
		m2.insert(make_pair("42",     400));
		m2.insert(make_pair("bar",    300));
		m2.insert(make_pair("bar",    300));
		m2.insert(make_pair("bar",    300));
		// expected result
		expected2.insert(make_pair("42",     400));
		expected2.insert(make_pair("foo",    200));
		expected2.insert(make_pair("qwerty", 100));

		pair<std::string,int>	highest2 = *m2.rbegin();
		s_int_map::iterator		it2 = m2.begin();

		do
		{
			std::cout << it2->first << " => " << it2->second << '\n';
		} while (m2.value_comp()(*it2++, highest2));

		std::cout << '\n';

		// assert map meets expected result
		assert(m2 == expected2);
	}
}
