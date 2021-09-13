/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_advance.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:30:49 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/13 18:33:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * advance operators
 *
 * operator++
 * operator+=
 * operator+
 */

/*
 * Compare operator++ (increment)
 */

int	cmpRevItIncrement( void ) {

	std::cout << COL_BLUE_B
			  << "\n__________ operator++ (increment) __________\n\n"
			  << COL_RESET;

	explainUnit("Increments iterator position.");

	int	arr[5];

	// fill test array
	for ( int i = 0; i < 5; i++ )
		arr[i] = i;

	// iterators
	std::reverse_iterator<int*>	std_rev_it(arr + 1);
	ft::reverse_iterator<int*>	ft_rev_it(arr + 1);

	std::cout << COL_BLUE_B << "\n_ pre-decrement version\n\n" << COL_RESET;

	std::cout << "*std::rev_it   = " << *std_rev_it
			  << "\t*ft::rev_it   = " << *ft_rev_it
			  << "\n*++std::rev_it = " << *(++std_rev_it)
			  << "\t*++ft::rev_it = " << *(++ft_rev_it)
			  << "\n*std::rev_it   = " << *std_rev_it
			  << "\t*ft::rev_it   = " << *ft_rev_it << "\n\n";

	if ( displayTestResult(*std_rev_it == *ft_rev_it) )
		return (1);

	// restore
	std_rev_it--;
	ft_rev_it--;

	std::cout << COL_BLUE_B << "_ post-decrement version\n\n" << COL_RESET;

	std::cout << "*std::rev_it   = " << *std_rev_it
			  << "\t*ft::rev_it   = " << *ft_rev_it
			  << "\n*std::rev_it++ = " << *(std_rev_it++)
			  << "\t*ft::rev_it++ = " << *(ft_rev_it++)
			  << "\n*std::rev_it   = " << *std_rev_it
			  << "\t*ft::rev_it   = " << *ft_rev_it << "\n\n";

	return ( displayTestResult(*std_rev_it == *ft_rev_it) );
}

/*
 * Compare operator+= (avance)
 */

int	cmpRevItAdvanceOp( void ) {

	std::cout << COL_BLUE_B
			  << "\n____________ operator+= (avance) ___________\n\n"
			  << COL_RESET;

	explainUnit("Advances the reverse_iterator by n element positions.");

	int	n = 7;
	int	arr[10];

	// fill test array
	for ( int i = 0; i < 10; i++ )
		arr[i] = i;

	// set iterators
	std::reverse_iterator<int*>	std_rev_it(arr + 10);
	ft::reverse_iterator<int*>	ft_rev_it(arr + 10);
	std::cout << std::endl;

	std::cout << "*std::rev_it =  " << *std_rev_it
			  << "\t*ft::rev_it  =  " << *ft_rev_it << std::endl;

	std_rev_it += n;
	ft_rev_it += n;

	std::cout << "*std::rev_it += 7;\t*ft::rev_it  += 7;"
			  << "\n*std::rev_it  = " << *std_rev_it
			  << "\t*ft::rev_it   = " <<  *ft_rev_it << "\n\n";

	return ( displayTestResult(*std_rev_it == *ft_rev_it) );
}

/*
 * Compare operator+ (addition)
 */

int	cmpRevItAdditionOp( void ) {

	std::cout << COL_BLUE_B
			  << "\n___________ operator+ (addition) ___________\n\n"
			  << COL_RESET;

	explainUnit("Returns an iterator pointing to the element n positions away.");

	int	arr[10];

	// fill test array
	for ( int i = 0; i < 10; i++ )
		arr[i] = i;

	// set iterators
	std::reverse_iterator<int*>	std_rev_it(arr + 10);
	ft::reverse_iterator<int*>	ft_rev_it(arr + 10);
	std::cout << std::endl;

	std::cout << "*std::rev_it = " << *std_rev_it
			  << "\n*ft::rev_it  = " << *ft_rev_it << "\n\n";

	// storing results
	std::reverse_iterator<int*>	std_res = (std_rev_it + 5);
	ft::reverse_iterator<int*>	ft_res = (ft_rev_it + 5);

	std::cout << "\n*(std::rev_it + 5) = " << *std_res
			  << "\n*(ft::rev_it + 5)  = " << *ft_res << "\n\n";

	return ( displayTestResult(*std_res == *ft_res) );
}
