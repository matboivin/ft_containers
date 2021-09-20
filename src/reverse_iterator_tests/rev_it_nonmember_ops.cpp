/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_nonmember_ops.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:58:21 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/20 14:13:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <vector>
#include "iterator.hpp"
#include "tests.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * non-member operators
 *
 * operator+
 * operator-
 */

/*
 * Compare operator+ (addition)
 */

static int	cmpRevItAdditionOp2( void ) {

	std::cout << COL_BLUE_B
			  << "\n_____ non-member operator+ (addition) ______\n\n"
			  << COL_RESET;

	explainUnit("Returns a reverse iterator pointing to the element located\n"
				"n positions away from the element pointed to by rev_it.");

	int	n = 3;

	// iterator type pointing on vector of int
	typedef std::vector<int>::iterator	iter_type;

	// create test vector
	std::vector<int>	vec;

	for ( int i = 0; i < 10; i++ )
		vec.push_back(i);

	// create iterators
	std::reverse_iterator<iter_type>	ite(vec.end());
	std::reverse_iterator<iter_type>	std_rev_it;

	ft::reverse_iterator<iter_type>		ft_ite(vec.end());
	ft::reverse_iterator<iter_type>		ft_rev_it;

	std_rev_it = n + ite;
	ft_rev_it = n + ft_ite;

	std::cout << "*std::rev_it = " << *std_rev_it
			  << "\n*ft::rev_it  = " << *ft_rev_it << "\n\n";

	return ( displayTestResult(*std_rev_it == *ft_rev_it) );
}

/*
 * Compare operator- (subtraction)
 */

static int	cmpRevItSubtractOp2( void ) {

	std::cout << COL_BLUE_B
			  << "\n____ non-member operator- (subtraction) ____\n\n"
			  << COL_RESET;

	explainUnit("Computes the distance between two reverse iterators.\n"
				"Returns the same as subtracting lhs's base iterator\n"
				"from rhs's base iterator");

	// iterator type pointing on vector of int
	typedef std::vector<int>::iterator	iter_type;

	// create test vector
	std::vector<int>	vec;

	for ( int i = 0; i < 10; i++ )
		vec.push_back(i);

	iter_type	it = vec.begin();
	iter_type	ite = vec.end();

	// Original
	std::cout << COL_BLUE_B << "_ std::reverse_iterator\n\n" << COL_RESET;

	std::reverse_iterator<iter_type>	rev_end(it);
	std::reverse_iterator<iter_type>	rev_start(ite);

	std::size_t	std_res = rev_end - rev_start;

	std::cout << "vector has " << std_res << " elements.\n";

	// ft::reverse_iterator
	std::cout << COL_BLUE_B << "\n_ ft::reverse_iterator\n\n" << COL_RESET;

	ft::reverse_iterator<iter_type>		ft_rev_end(it);
	ft::reverse_iterator<iter_type>		ft_rev_start(ite);

	std::size_t	ft_res = ft_rev_end - ft_rev_start;

	std::cout << "vector has " << ft_res << " elements.\n\n";

	return ( displayTestResult(std_res == ft_res) );
}

/*
 * Compare non-member operators + and -
 */

int	cmpRevItNonMemberOps( void ) {

	// Test operator+
	if ( cmpRevItAdditionOp2() )
		return ( exitFailedTest("reverse_iterator: non-member operator+") );

	// Test operator-
	if ( cmpRevItSubtractOp2() )
		return ( exitFailedTest("reverse_iterator: non-member operator-") );

	return (0);
}
