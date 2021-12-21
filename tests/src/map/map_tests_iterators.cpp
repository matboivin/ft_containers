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
		map_type	m;

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
				  << "begin(): " << m.begin()->second << '\n'
				  << "end(): " << (--m.end())->second << '\n';

		std::cout << "map size: " << m.size() << '\n';

		for (map_type::iterator it = m.begin();
			 it != m.end();
			 ++it)
		{
			std::cout << it->first << " => " << it->second << '\n';
		}

		map_type::iterator	end = m.end();
		--end;

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
		map_type	m;

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
				  << "begin(): " << m.begin()->second << '\n'
				  << "end(): " << (--m.end())->second << '\n';

		std::cout << "map size: " << m.size() << "\n\n";

		std::cout << "Print the map content using reverse iterator:" << "\n\n";

		for (map_type::reverse_iterator rev_it = m.rbegin();
			 rev_it != m.rend();
			 ++rev_it)
		{
			std::cout << rev_it->first << " => " << rev_it->second << '\n';
		}
		std::cout << "\n\n";
	}
}
