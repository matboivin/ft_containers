/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests_iterators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/28 16:14:02 by mboivin          ###   ########.fr       */
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
	void	test_set_iterator(void)
	{
		std::cout << "TEST: Iterator \n\n";

		explain_test("Move through the elements of the container like pointers do.");

		// create set
		int_set	s;

		std::cout << std::boolalpha << "(s.begin() == s.end())? "
				  << (s.begin() == s.end()) << '\n';

		assert(s.begin() == s.end());

		for (int i = 0; i < 10; ++i)
			s.insert(rand());

		std::cout << std::boolalpha << "(s.begin() == s.end())? "
				  << (s.begin() == s.end()) << '\n'
				  << "begin() = " << *s.begin() << '\n'
				  << "end()   = " << *(--s.end()) << "\n\n";

		std::cout << "Print the set content using iterator:" << "\n\n";

		for (int_set::iterator it = s.begin(); it != s.end(); ++it)
			std::cout << *it << '\n';

		int_set::iterator	end = s.end();
		--end;

		std::cout << "\nPrint the set content from the end, decrementing iterator:" << "\n\n";

		for ( ; end != s.begin(); --end)
			std::cout << *end << '\n';
		std::cout << *end << "\n\n";
	}

	void	test_set_rev_iterator(void)
	{
		std::cout << "TEST: Reverse iterator \n\n";

		explain_test("Move through the elements of the container backwards.");

		// create set
		int_set	s;

		for (int i = 0; i < 10; ++i)
			s.insert(rand());

		std::cout << std::boolalpha << "(s.begin() == s.end())? "
				  << (s.begin() == s.end()) << '\n'
				  << "begin() = " << *s.begin() << '\n'
				  << "end()   = " << *(--s.end()) << '\n';

		std::cout << "set size: " << s.size() << "\n\n";

		std::cout << "Print the set content using reverse iterator:" << "\n\n";

		for (int_set::reverse_iterator rev_it = s.rbegin(); rev_it != s.rend(); ++rev_it)
			std::cout << *rev_it << '\n';
		std::cout << "\n\n";
	}
}
