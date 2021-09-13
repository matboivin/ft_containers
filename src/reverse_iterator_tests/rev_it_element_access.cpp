/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_element_access.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:49:32 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/13 17:53:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * element access
 *
 * operator*
 * operator->
 * operator[]
 */

/*
 * Compare operator* (indirection operator)
 */

int	cmpRevItIndirectionOp( void ) {

	std::cout << COL_BLUE_B
			  << "\n_____ operator* (indirection operator) _____\n\n"
			  << COL_RESET;

	explainUnit("Dereference iterator.\n"
				"Internally, the function decreases a copy of its base\n"
				"iterator and returns the result of dereferencing it.");
	
	bool	succeeded = true;
	int		len = 10;

	// iterator type pointing on vector of int
	typedef std::vector<int>::iterator	iter_type;

	// create test vector
	std::vector<int>	vec;

	for ( int i = 0; i < len; i++ )
		vec.push_back(i);

	iter_type	it = vec.begin();
	iter_type	ite = vec.end();

	// Original
	std::reverse_iterator<iter_type>	rev_end(it);
	std::reverse_iterator<iter_type>	rev_start(ite);

	// ft::reverse_iterator
	ft::reverse_iterator<iter_type>		ft_rev_end(it);
	ft::reverse_iterator<iter_type>		ft_rev_start(ite);
	std::cout << std::endl;

	std::cout << "Original: [ ";
	while ( rev_start != rev_end )
		std::cout << *rev_start++ << ' ';
	std::cout << "]\n\n";

	// restore
	rev_start -= len;

	std::cout << "ft:       [ ";
	while ( ft_rev_start != ft_rev_end ) {

		if ( *rev_start != *ft_rev_start )
			succeeded = false;
		std::cout << *ft_rev_start << ' ';
		rev_start++;
		ft_rev_start++;
	}
	std::cout << "]\n\n";

	return ( displayTestResult(succeeded) );
}

/*
 * Compare operator-> (member of pointer)
 */

int	cmpRevItPointerOp( void ) {

	std::cout << COL_BLUE_B
			  << "\n______ operator-> (member of pointer) ______\n\n"
			  << COL_RESET;

	explainUnit("Dereference iterator.\n"
				"Internally, the function calls operator* and returns its address.");
	
	bool	succeeded = true;

	// iterator type pointing on map of int, string
	typedef std::map<int,std::string>::iterator	map_iter;

	// create test map
	std::map<int,std::string>	numbers;

	numbers.insert( std::make_pair(1,"one") );
	numbers.insert( std::make_pair(2,"two") );
	numbers.insert( std::make_pair(3,"three") );

	map_iter	it = numbers.begin();
	map_iter	ite = numbers.end();

	// Original
	std::reverse_iterator<map_iter>	rev_end(it);
	std::reverse_iterator<map_iter>	rev_start(ite);
	std::reverse_iterator<map_iter>	rev_start_copy(ite);

	// ft::reverse_iterator
	ft::reverse_iterator<map_iter>	ft_rev_end(it);
	ft::reverse_iterator<map_iter>	ft_rev_start(ite);
	std::cout << std::endl;

	std::cout << "Original:\n";
	while ( rev_start != rev_end ) {

		std::cout << rev_start->first << ' ' << rev_start->second << '\n';
		rev_start++;
	}

	std::cout << "\nft:\n";
	while ( ft_rev_start != ft_rev_end ) {

		if ( (ft_rev_start->first != rev_start_copy->first)
			 || (ft_rev_start->second != rev_start_copy->second) ) {

			succeeded = false;
		}

		std::cout << ft_rev_start->first << ' ' << ft_rev_start->second << '\n';
		rev_start_copy++;
		ft_rev_start++;
	}
	std::cout << std::endl;

	return ( displayTestResult(succeeded) );
}

/*
 * Compare operator[] (subscripting operator)
 */

int	cmpRevItSubscriptingOp( void ) {

	std::cout << COL_BLUE_B
			  << "\n____ operator[] (subscripting operator) ____\n\n"
			  << COL_RESET;

	explainUnit("Accesses the element located n positions away\n"
				"from the element currently pointed to by the iterator.");

	// create test array
	int	arr[10];
	int	len = 10;

	for ( int i = 0; i < len; i++ )
		arr[i] = i;

	// Original
	std::cout << COL_BLUE_B << "_ std::reverse_iterator\n\n" << COL_RESET;

	// create a reverse iterator pointing on array's elements
	std::reverse_iterator<int*>	std_rev_it(arr + 10);

	std::cout << "std::rev_it    = " << *std_rev_it << "\n\n";

	for ( int i = 0; i < len; i++ )
		std::cout << "std::rev_it[" << i << "] = " << std_rev_it[i] << '\n';

	std::cout << "\nstd::rev_it    = " << *std_rev_it << std::endl;

	// ft::reverse_iterator
	std::cout << COL_BLUE_B << "\n_ ft::reverse_iterator\n\n" << COL_RESET;

	// create a reverse iterator pointing on array's elements
	ft::reverse_iterator<int*>	ft_rev_it(arr + 10);
	std::cout << std::endl;

	std::cout << "ft::rev_it    = " << *ft_rev_it << "\n\n";

	for ( int i = 0; i < len; i++ )
		std::cout << "ft::rev_it[" << i << "] = " << ft_rev_it[i] << '\n';

	std::cout << "\nft::rev_it    = " << *ft_rev_it << std::endl;

	return (0);
}
