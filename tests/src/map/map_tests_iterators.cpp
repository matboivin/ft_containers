/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests_iterators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/12/21 00:53:10 by mboivin          ###   ########.fr       */
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
	void	test_map_iterator(void)
	{
		std::cout << "TEST: Iterator \n\n";

		explain_test("Move through the elements of the container like pointers do.");

		// create map
		int_s_map	m;

		std::cout << std::boolalpha << "(m.begin() == m.end())? "
				  << (m.begin() == m.end()) << '\n';

		assert(m.begin() == m.end());

		m.insert( pair<int, std::string>(8,  "eight") );
		m.insert( pair<int, std::string>(18, "eighteen") );
		m.insert( pair<int, std::string>(5,  "five") );
		m.insert( pair<int, std::string>(15, "fifteen") );
		m.insert( pair<int, std::string>(17, "seventeen") );
		m.insert( pair<int, std::string>(25, "twenty-five") );
		m.insert( pair<int, std::string>(40, "fourty") );
		m.insert( pair<int, std::string>(80, "eighty") );
		m.insert( pair<int, std::string>(11, "eleven") );
		m.insert( pair<int, std::string>(20, "twenty") );

		std::cout << std::boolalpha << "(m.begin() == m.end())? "
				  << (m.begin() == m.end()) << '\n'
				  << "begin() = " << m.begin()->first << '\n'
				  << "end()   = " << (--m.end())->first << "\n\n";

		std::cout << "Print the map content using iterator:" << "\n\n";

		for (int_s_map::iterator it = m.begin();
			 it != m.end();
			 ++it)
		{
			std::cout << it->first << " => " << it->second << '\n';
		}

		int_s_map::iterator	end = m.end();
		--end;

		std::cout << "\nPrint the map content from the end, decrementing iterator:" << "\n\n";

		for ( ; end != m.begin(); --end)
		{
			std::cout << end->first << " => " << end->second << '\n';
		}
		std::cout << end->first << " => " << end->second << "\n\n";
	}

	void	test_map_rev_iterator(void)
	{
		std::cout << "TEST: Reverse iterator \n\n";

		explain_test("Move through the elements of the container backwards.");

		// create map
		int_s_map	m;

		m.insert( pair<int, std::string>(8,  "eight") );
		m.insert( pair<int, std::string>(18, "eighteen") );
		m.insert( pair<int, std::string>(5,  "five") );
		m.insert( pair<int, std::string>(15, "fifteen") );
		m.insert( pair<int, std::string>(17, "seventeen") );
		m.insert( pair<int, std::string>(25, "twenty-five") );
		m.insert( pair<int, std::string>(40, "fourty") );
		m.insert( pair<int, std::string>(80, "eighty") );
		m.insert( pair<int, std::string>(11, "eleven") );
		m.insert( pair<int, std::string>(20, "twenty") );

		std::cout << std::boolalpha << "(m.begin() == m.end())? "
				  << (m.begin() == m.end()) << '\n'
				  << "begin()->second = " << m.begin()->second << '\n'
				  << "end()->second   = " << (--m.end())->second << '\n';

		std::cout << "map size: " << m.size() << "\n\n";

		std::cout << "Print the map content using reverse iterator:" << "\n\n";

		for (int_s_map::reverse_iterator rev_it = m.rbegin();
			 rev_it != m.rend();
			 ++rev_it)
		{
			std::cout << rev_it->first << " => " << rev_it->second << '\n';
		}
		std::cout << "\n\n";
	}
}
