/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_construct.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:10:51 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/13 15:44:29 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
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
	std::reverse_iterator<int*>	std_it;

	// ft
	ft::reverse_iterator<int*>	ft_it;
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

	int	arr[10];

	// fill test array
	for ( int i = 0; i < 10; i++ )
		arr[i] = i;

	// Original
	std::reverse_iterator<int*>	std_it1(arr + 5);
	std::reverse_iterator<int*>	std_it2(std_it1);

	std::cout << "std::it1 = " << *std_it1
			  << "\nstd::it2 = " << *std_it2 << "\n\n";

	// ft
	ft::reverse_iterator<int*>	ft_it1(arr + 5);
	ft::reverse_iterator<int*>	ft_it2(ft_it1);
	std::cout << std::endl;

	std::cout << "ft::it1 = " << *ft_it1
			  << "\nft::it2 = " << *ft_it2 << "\n";
}
