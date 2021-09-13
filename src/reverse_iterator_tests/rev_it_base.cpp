/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_base.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:19:10 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/13 18:44:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <vector>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * Compare member function base()
 */

int	cmpRevItBase( void ) {

	std::cout << COL_BLUE_B
			  << "\n__________ member function: base ___________\n\n"
			  << COL_RESET;

	explainUnit("Returns a copy of the base iterator.");

	int	errors = 0;
	int	len = 10;

	// iterator type pointing on vector of int
	typedef std::vector<int>::iterator	iter_type;

	// create test vector
	std::vector<int>	vec;

	for ( int i = 0; i < len; i++ )
		vec.push_back(i);

	iter_type	it = vec.begin();
	iter_type	ite = vec.end();

	// Original
	std::cout << COL_BLUE_B << "_ std::reverse_iterator\n\n" << COL_RESET;

	std::reverse_iterator<iter_type>	rev_end(it);
	std::reverse_iterator<iter_type>	rev_start(ite);

	std::cout << COL_WHITE_B << "Display base iterator:\n" << COL_RESET;

	for ( iter_type it_base = rev_end.base();
		  it_base != rev_start.base();
		  ++it_base ) {

		std::cout << *it_base << ' ';
	}
	std::cout << "\n\n";

	std::cout << COL_WHITE_B << "Display reverse iterator:\n" << COL_RESET;

	for ( std::reverse_iterator<iter_type> rev_it = rev_start;
		  rev_it != rev_end; ++rev_it ) {

		std::cout << *rev_it << ' ';
	}
	std::cout << "\n\n";

	// ft::reverse_iterator
	std::cout << COL_BLUE_B << "_ ft::reverse_iterator\n\n" << COL_RESET;

	ft::reverse_iterator<iter_type>	ft_rev_end(it);
	ft::reverse_iterator<iter_type>	ft_rev_start(ite);
	std::cout << std::endl;

	std::cout << COL_WHITE_B << "Display base iterator:\n" << COL_RESET;

	// for comparison
	iter_type	it_cmp = rev_end.base();

	for ( iter_type it_base = ft_rev_end.base();
		  it_base != ft_rev_start.base();
		  ++it_base ) {

		if ( *it_base != *it_cmp )
			errors++;
		std::cout << *it_base << ' ';
		it_cmp++;
	}
	std::cout << "\n\n";

	std::cout << COL_WHITE_B << "Display reverse iterator:\n" << COL_RESET;

	// for comparison
	std::reverse_iterator<iter_type>	rev_cmp = rev_start;

	for ( ft::reverse_iterator<iter_type> rev_it = ft_rev_start;
		  rev_it != ft_rev_end;
		  ++rev_it ) {

		if ( *rev_it != *rev_cmp )
			errors++;
		std::cout << *rev_it << ' ';
		rev_cmp++;
	}
	std::cout << "\n\n";

	return ( displayTestResult(!errors) );
}
