/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_assignment_op.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:16:53 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/13 15:03:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * Compare Copy assignment operator
 */

int	cmpRevItAssignmentOperator( void ) {

	std::cout << COL_BLUE_B
			  << "\n_________ Copy assignment operator _________\n\n"
			  << COL_RESET;

	explainUnit("operator=");

	int	arr[10];

	// fill test array
	for ( int i = 0; i < 10; i++ )
		arr[i] = i;

	// Original
	std::reverse_iterator<int*>	std_it(arr + 1);
	std::reverse_iterator<int*>	std_ite(arr + 10);

	// ft
	ft::reverse_iterator<int*>	ft_it(arr + 1);
	ft::reverse_iterator<int*>	ft_ite(arr + 10);
	std::cout << std::endl;

	std::cout << COL_BLUE_B << "_ std::reverse_iterator\n\n" << COL_RESET;

	// Create a new reverse iterator
	std::reverse_iterator<int*>	std_copy(std_ite);

	std::cout << "std::it:      " << *std_it
			  << "\nstd::it_copy: " << *std_copy;

	// copy
	std_copy = std_it;

	std::cout << COL_BLUE_B << "\n\nAFTER COPY (must be the same)\n" << COL_RESET
			  << "\nstd::it:      " << *std_it
			  << "\nstd::it_copy: " << *std_copy << "\n\n";

	if ( displayTestResult(*std_it == *std_copy) )
		return (1);

	std::cout << COL_BLUE_B << "_ ft::reverse_iterator\n" << COL_RESET;

	// Create a new reverse iterator
	ft::reverse_iterator<int*>	ft_copy(ft_ite);

	std::cout << "\nft::it:      " << *ft_it
			  << "\nft::it_copy: " << *ft_copy << "\n\n";

	// copy
	ft_copy = ft_it;

	std::cout << COL_BLUE_B << "\nAFTER COPY (must be the same)\n" << COL_RESET
			  << "\nft::it:      " << *ft_it
			  << "\nft::it_copy: " << *ft_copy << std::endl;

	return ( displayTestResult(*ft_it == *ft_copy) );
}
