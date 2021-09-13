/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_construct.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:10:51 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/13 18:33:28 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <vector>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * Compare default constructor
 */

void	cmpRevItDefaultConstructor( void ) {

	std::cout << COL_BLUE_B
			  << "\n___________ Default Constructor ____________\n\n"
			  << COL_RESET;

	explainUnit("Constructs a reverse iterator that points to no object.");

	// Original
	std::reverse_iterator<int*>	std_rev_it;

	// ft
	ft::reverse_iterator<int*>	ft_rev_it;
	std::cout << std::endl;
}

/*
 * Compare initialization constructor
 */

void	cmpRevItInitConstructor( void ) {

	std::cout << COL_BLUE_B
			  << "\n________ Initialization Constructor ________\n\n"
			  << COL_RESET;

	explainUnit("Constructs a reverse iterator from some original iterator it.");

	// iterator type pointing on vector of int
	typedef std::vector<int>::iterator	iter_type;

	// create test vector
	std::vector<int>	vec;

	for ( int i = 0; i < 10; i++ )
		vec.push_back(i);

	// create an iterator at position 5
	iter_type	it = vec.begin();
	it += 5;

	// Original
	std::cout << COL_BLUE_B << "_ std::reverse_iterator\n\n" << COL_RESET;

	// create a copy of it
	std::reverse_iterator<iter_type>	rev_it(it);

	std::cout << "*std::it       = " << *it
			  << "\n*std::rev_it   = " << *rev_it << "\n\n";

	// Ensure the copy sense of iteration is inverted
	it--;
	rev_it--;

	std::cout << "*std::it--     = " << *it
			  << "\n*std::rev_it-- = " << *rev_it << "\n\n";

	// restore
	it++;

	// ft::reverse_iterator
	std::cout << COL_BLUE_B << "_ ft::reverse_iterator\n\n" << COL_RESET;

	// create a copy of it
	ft::reverse_iterator<iter_type>	ft_rev_it(it);
	std::cout << std::endl;

	std::cout << "*std::it      = " << *it
			  << "\n*ft::rev_it   = " << *ft_rev_it << "\n";

	// Ensure the copy sense of iteration is inverted
	it--;
	ft_rev_it--;

	std::cout << "\n*std::it--    = " << *it
			  << "\n*ft::rev_it-- = " << *ft_rev_it << std::endl;
}

/*
 * Compare copy constructor
 */

void	cmpRevItCopyConstructor( void ) {

	std::cout << COL_BLUE_B
			  << "\n_____________ Copy constructor _____________\n\n"
			  << COL_RESET;

	explainUnit("Constructs a reverse iterator from some other reverse iterator.");

	// iterator type pointing on vector of int
	typedef std::vector<int>::iterator	iter_type;

	// create test array
	int	arr[10];

	for ( int i = 0; i < 10; i++ )
		arr[i] = i;

	// Original
	std::cout << COL_BLUE_B << "_ std::reverse_iterator\n\n" << COL_RESET;

	// create a reverse iterator pointing on array's elements
	std::reverse_iterator<int*>	std_rev_it(arr + 5);
	// create copy
	std::reverse_iterator<iter_type>	std_rev_it_copy(std_rev_it);

	std::cout << "*std::rev_it      = " << *std_rev_it
			  << "\n*std::rev_it copy = " << *std_rev_it_copy << "\n\n";

	// ft::reverse_iterator
	std::cout << COL_BLUE_B << "_ ft::reverse_iterator\n\n" << COL_RESET;

	// create a reverse iterator pointing on array's elements
	ft::reverse_iterator<int*>	ft_rev_it(arr + 5);
	// create copy
	ft::reverse_iterator<iter_type>		ft_rev_it_copy(ft_rev_it);
	std::cout << std::endl;

	std::cout << "*ft::rev_it       = " << *ft_rev_it
			  << "\n*ft::rev_it copy  = " << *ft_rev_it_copy << "\n\n";
}
