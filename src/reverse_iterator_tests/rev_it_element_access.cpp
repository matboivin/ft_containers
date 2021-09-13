/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_element_access.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:49:32 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/13 17:05:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
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
 * Compare operator[] (subscripting operator)
 */

int	cmpRevItSubscriptingOp( void ) {

	std::cout << COL_BLUE_B
			  << "\n____ operator[] (subscripting operator) ____\n\n"
			  << COL_RESET;

	explainUnit("Constructs a reverse iterator from some other reverse iterator.");

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
	std::cout << COL_BLUE_B << "_ ft::reverse_iterator\n\n" << COL_RESET;

	// create a reverse iterator pointing on array's elements
	ft::reverse_iterator<int*>	ft_rev_it(arr + 10);
	std::cout << std::endl;

	std::cout << "ft::rev_it    = " << *ft_rev_it << "\n\n";

	for ( int i = 0; i < len; i++ )
		std::cout << "ft::rev_it[" << i << "] = " << ft_rev_it[i] << '\n';

	std::cout << "\nft::rev_it    = " << *ft_rev_it << std::endl;

	return (0);
}
