/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revit_test_elem_access.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:51:13 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 16:13:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "tests.hpp"
#include "revit_tests.hpp"
#include <vector>
#include <map>

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_revit_indirection(void) // operator*
	{
		std::cout << "TEST: Indirection operator * \n\n";

		explainTest("Dereference iterator. "
					"Internally, the function decreases a copy of its base "
					"iterator and returns the result of dereferencing it.");

		typedef std::vector<int>::iterator	iter_type;

		// create test vector
		std::vector<int>	vec;

		for ( int i = 0; i < 10; i++ )
			vec.push_back(i);

		iter_type	it = vec.begin();
		iter_type	ite = vec.end();

		reverse_iterator<iter_type>	rev_end(it);
		reverse_iterator<iter_type>	rev_start(ite);

		std::cout << "[ ";
		while ( rev_start != rev_end )
			std::cout << *rev_start++ << ' ';
		std::cout << "]\n\n";
	}

	void	test_revit_pointer(void) // operator->
	{
		std::cout << "TEST: Pointer operator -> \n\n";

		explainTest("Dereference iterator. "
					"Internally, the function calls operator* and returns its address.");

		// iterator type pointing on map of int, string
		typedef std::map<int,std::string>::iterator	map_iter;

		// create test map
		std::map<int,std::string>	numbers;

		numbers.insert( std::make_pair(1,"one") );
		numbers.insert( std::make_pair(2,"two") );
		numbers.insert( std::make_pair(3,"three") );

		map_iter	it = numbers.begin();

		// Original
		reverse_iterator<map_iter>	rev_it(it);

		assert(rev_it->first == 3);
	}

	void	test_revit_subcript(void) // operator[]
	{
		std::cout << "TEST:  Subscripting operator [] \n\n";

		explainTest("Accesses the element located n positions away "
					"from the element currently pointed to by the iterator.");

		typedef std::vector<int>::iterator	iter_type;

		// create test vector
		std::vector<int>	vec;

		for ( int i = 1; i < 20; i++ )
			vec.push_back(i);

		iter_type	it = vec.begin();
		it += 8;

		reverse_iterator<iter_type>	rev_it(it);

		assert(*rev_it == 8);
	}
}
