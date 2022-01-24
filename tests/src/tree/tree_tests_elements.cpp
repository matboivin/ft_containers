/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests_elements.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 20:32:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include "tests.hpp"
#include "tree_tests.hpp"

namespace ft
{
	void	test_tree_count(void)
	{
		std::cout << "TEST: Element access: count() \n\n";

		explain_test("Returns 1 if the tree contains an element matching key k.");

		std::map<int, std::string>	m;
		int_s_tree					tree;

		m[8]  = "eight";
		m[18] = "eighteen";
		m[5]  = "five";
		m[15] = "fifteen";
		m[17] = "seventeen";
		m[25] = "twenty-five";
		m[40] = "fourty";
		m[80] = "eigthy";
		m[11] = "eleven";
		m[20] = "twenty";

		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(5,  "five") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(17, "seventeen") );
		tree.insert( pair<int, std::string>(25, "twenty-five") );
		tree.insert( pair<int, std::string>(40, "fourty") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(11, "eleven") );
		tree.insert( pair<int, std::string>(20, "twenty") );

		std::cout << "m.count(5):                     " << m.count(5) << '\n'
				  << "tree.count(5):                  " << tree.count(5) << '\n'
				  << "m.count(40):                    " << m.count(40) << '\n'
				  << "tree.count(40):                 " << tree.count(40) << "\n\n"
				  << "m.count(99):                    " << m.count(99) << '\n'
				  << "tree.count(99):                 " << tree.count(99)
				  << "\n\n";
	}

	void	test_tree_find(void)
	{
		std::cout << "TEST: Element access: find() \n\n";

		explain_test("Returns the element with the key k, else return end.");

		std::map<int, std::string>	m;
		int_s_tree					tree;

		m[8]  = "eight";
		m[18] = "eighteen";
		m[5]  = "five";
		m[15] = "fifteen";
		m[17] = "seventeen";
		m[25] = "twenty-five";
		m[40] = "fourty";
		m[80] = "eigthy";
		m[11] = "eleven";
		m[20] = "twenty";

		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(5,  "five") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(17, "seventeen") );
		tree.insert( pair<int, std::string>(25, "twenty-five") );
		tree.insert( pair<int, std::string>(40, "fourty") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(11, "eleven") );
		tree.insert( pair<int, std::string>(20, "twenty") );

		std::cout << "m.find(5):                     " << m.find(5)->first << '\n'
				  << "tree.find(5):                  " << tree.find(5)->first << '\n'
				  << "m.find(40):                    " << m.find(40)->first << '\n'
				  << "tree.find(40):                 " << tree.find(40)->first << "\n\n"
				  << "(m.find(99) == m.end())?       " << (m.find(99) == m.end()) << '\n'
				  << "(tree.find(99) == tree.end())? " << (tree.find(99) == tree.end())
				  << "\n\n";
	}

	void	test_tree_lower_bound(void)
	{
		std::cout << "TEST: Element access: lower_bound() \n\n";

		explain_test("Returns the first element that is equivalent or after k.");

		std::map<int, std::string>	m;
		int_s_tree					tree;

		m[8]  = "eight";
		m[18] = "eighteen";
		m[5]  = "five";
		m[15] = "fifteen";
		m[17] = "seventeen";
		m[25] = "twenty-five";
		m[40] = "fourty";
		m[80] = "eigthy";
		m[11] = "eleven";
		m[20] = "twenty";

		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(5,  "five") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(17, "seventeen") );
		tree.insert( pair<int, std::string>(25, "twenty-five") );
		tree.insert( pair<int, std::string>(40, "fourty") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(11, "eleven") );
		tree.insert( pair<int, std::string>(20, "twenty") );

		std::cout << "m.lower_bound(5):                     " << m.lower_bound(5)->first << '\n'
				  << "tree.lower_bound(5):                  " << tree.lower_bound(5)->first << '\n'
				  << "m.lower_bound(24):                    " << m.lower_bound(24)->first << '\n'
				  << "tree.lower_bound(24):                 " << tree.lower_bound(24)->first << "\n\n"
				  << "(m.lower_bound(99) == m.end())?       " << (m.lower_bound(99) == m.end()) << '\n'
				  << "(tree.lower_bound(99) == tree.end())? " << (tree.lower_bound(99) == tree.end())
				  << "\n\n";
	}

	void	test_tree_upper_bound(void)
	{
		std::cout << "TEST: Element access: upper_bound() \n\n";

		explain_test("Returns the first element that is after k.");

		std::map<int, std::string>	m;
		int_s_tree					tree;

		m[8]  = "eight";
		m[18] = "eighteen";
		m[5]  = "five";
		m[15] = "fifteen";
		m[17] = "seventeen";
		m[25] = "twenty-five";
		m[40] = "fourty";
		m[80] = "eigthy";
		m[11] = "eleven";
		m[20] = "twenty";

		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(5,  "five") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(17, "seventeen") );
		tree.insert( pair<int, std::string>(25, "twenty-five") );
		tree.insert( pair<int, std::string>(40, "fourty") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(11, "eleven") );
		tree.insert( pair<int, std::string>(20, "twenty") );

		std::cout << "m.upper_bound(5):                     " << m.upper_bound(5)->first << '\n'
				  << "tree.upper_bound(5):                  " << tree.upper_bound(5)->first << '\n'
				  << "m.upper_bound(24):                    " << m.upper_bound(24)->first << '\n'
				  << "tree.upper_bound(24):                 " << tree.upper_bound(24)->first << "\n\n"
				  << "(m.upper_bound(99) == m.end())?       " << (m.upper_bound(99) == m.end()) << '\n'
				  << "(tree.upper_bound(99) == tree.end())? " << (tree.upper_bound(99) == tree.end())
				  << "\n\n";
	}

	void	test_tree_equal_range(void)
	{
		std::cout << "TEST: Element access: equal_range() \n\n";

		explain_test("Returns the bounds of a range that have a key equivalent to k.");

		std::map<int, std::string>	m;
		int_s_tree					tree;

		m[8]  = "eight";
		m[18] = "eighteen";
		m[5]  = "five";
		m[15] = "fifteen";
		m[17] = "seventeen";
		m[25] = "twenty-five";
		m[40] = "fourty";
		m[80] = "eigthy";
		m[11] = "eleven";
		m[20] = "twenty";

		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(5,  "five") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(17, "seventeen") );
		tree.insert( pair<int, std::string>(25, "twenty-five") );
		tree.insert( pair<int, std::string>(40, "fourty") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(11, "eleven") );
		tree.insert( pair<int, std::string>(20, "twenty") );

		std::cout << "m.equal_range(5):                     " << m.equal_range(5).first->first << '\n'
				  << "tree.equal_range(5):                  " << tree.equal_range(5).first->first << '\n'
				  << "m.equal_range(24):                    " << m.equal_range(24).first->first << '\n'
				  << "tree.equal_range(24):                 " << tree.equal_range(24).first->first << "\n\n"
				  << "(m.equal_range(99) == m.end())?       " << (m.equal_range(99).first == m.end()) << '\n'
				  << "(tree.equal_range(99) == tree.end())? " << (tree.equal_range(99).first == tree.end())
				  << "\n\n";
	}
}
