/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_relational_ops.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:33:44 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/20 14:12:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "tests.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * Compare relational operators
 */

int	cmpRevItRelationalOps( void ) {

	std::cout << COL_BLUE_B
			  << "\n___________ Relational operators ___________\n\n"
			  << COL_RESET;

	explainUnit("Operators to make comparison between two reverse iterators.");

	int	arr[10];

	// fill test array
	for ( int i = 0; i < 10; i++ )
		arr[i] = i;

	// Original
	std::reverse_iterator<int*>	std_rev_it(arr + 1);
	std::reverse_iterator<int*>	std_rev_ite(arr + 10);

	// ft
	ft::reverse_iterator<int*>	ft_rev_it(arr + 1);
	ft::reverse_iterator<int*>	ft_rev_ite(arr + 10);

	assert( (std_rev_it == std_rev_ite) == (ft_rev_it == ft_rev_ite) );
	assert( (std_rev_it != std_rev_ite) == (ft_rev_it != ft_rev_ite) );
	assert( (std_rev_it < std_rev_ite) == (ft_rev_it < ft_rev_ite) );
	assert( (std_rev_it > std_rev_ite) == (ft_rev_it > ft_rev_ite) );
	assert( (std_rev_it <= std_rev_ite) == (ft_rev_it <= ft_rev_ite) );
	assert( (std_rev_it >= std_rev_ite) == (ft_rev_it >= ft_rev_ite) );

	std::cout << "std::rev_it:  " << *std_rev_it << "\tft::rev_it:  " << *ft_rev_it
			  << "\nstd::rev_ite: " << *std_rev_ite << "\tft::rev_ite: " << *ft_rev_ite
			  << "\n\n";

	return ( displayTestResult(1) );
}
