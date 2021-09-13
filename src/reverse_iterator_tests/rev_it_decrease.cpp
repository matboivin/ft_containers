/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_decrease.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:30:49 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/13 15:27:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * decrease operators
 *
 * operator--
 * operator-=
 * operator-
 */

/*
 * Compare operator-- (decrement) 
 */

int	cmpRevItDecrement( void ) {

	std::cout << COL_BLUE_B
			  << "\n__________ operator-- (decrement) __________\n\n"
			  << COL_RESET;

	explainUnit("Decreases iterator position.");

	int	arr[5];

	// fill test array
	for ( int i = 0; i < 5; i++ )
		arr[i] = i;

	// iterators
	std::reverse_iterator<int*>	std_it(arr + 1);
	ft::reverse_iterator<int*>	ft_it(arr + 1);

	std::cout << COL_BLUE_B << "\n_ pre-decrement version\n\n" << COL_RESET;

	std::cout << "std::it   = " << *std_it << "\tft::it   = " << *ft_it
			  << "\n--std::it = " << *(--std_it) << "\t--ft::it = " << *(--ft_it)
			  << "\nstd::it   = " << *std_it << "\tft::it   = " << *ft_it << "\n\n";

	if ( displayTestResult(*std_it == *ft_it) )
		return (1);

	// restore
	std_it++;
	ft_it++;

	std::cout << COL_BLUE_B << "_ post-decrement version\n\n" << COL_RESET;

	std::cout << "std::it   = " << *std_it << "\tft::it   = " << *ft_it
			  << "\nstd::it-- = " << *(std_it--) << "\tft::it-- = " << *(ft_it--)
			  << "\nstd::it   = " << *std_it << "\tft::it   = " << *ft_it << "\n\n";

	return ( displayTestResult(*std_it == *ft_it) );
}

/*
 * Compare operator-= (retrocede)
 */

int	cmpRevItRetrocedeOp( void ) {

	std::cout << COL_BLUE_B
			  << "\n__________ operator-= (retrocede) __________\n\n"
			  << COL_RESET;

	explainUnit("Decreases the reverse_iterator by n element positions.");

	int	n = 4;
	int	arr[10];

	// fill test array
	for ( int i = 0; i < 10; i++ )
		arr[i] = i;

	// set iterators
	std::reverse_iterator<int*>	std_it(arr + 1);
	ft::reverse_iterator<int*>	ft_it(arr + 1);
	std::cout << std::endl;

	std::cout << "std::it  = " << *std_it << "\tft::it   = " << *ft_it;

	std_it -= n;
	ft_it -= n;

	std::cout << "\nstd::it -= 4;\tft::it  -= 4;\n"
			  << "std::it  = " << *std_it
			  << "\tft::it   = " << *ft_it << "\n\n";

	return ( displayTestResult(*std_it == *ft_it) );
}

/*
 * Compare operator- (subtraction)
 */

int	cmpRevItSubtractOp( void ) {

	std::cout << COL_BLUE_B
			  << "\n__________ operator- (subtraction) _________\n\n"
			  << COL_RESET;

	explainUnit("Returns an iterator pointing to the element n positions before the currently pointed one.");

	int	arr[10];

	// fill test array
	for ( int i = 0; i < 10; i++ )
		arr[i] = i;

	// set iterators
	std::reverse_iterator<int*>	std_it(arr + 1);
	ft::reverse_iterator<int*>	ft_it(arr + 1);
	std::cout << std::endl;

	std::cout << "std::it = " << *std_it
			  << "\nft::it  = " << *ft_it << "\n\n";

	// storing results
	std::reverse_iterator<int*>	std_res = (std_it - 5);
	ft::reverse_iterator<int*>	ft_res = (ft_it - 5);
	std::cout << std::endl;

	std::cout << "(std::it - 5) = " << *std_res
			  << "\n(ft::it - 5)  = " << *ft_res << "\n\n";

	return ( displayTestResult(*std_res == *ft_res) );
}
