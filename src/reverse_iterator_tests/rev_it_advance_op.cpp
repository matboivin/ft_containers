/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_advance_op.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:39:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/12 17:55:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * Compare advance operator
 */

int	cmpRevItAdvanceOp( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ operator+= (avance)\n\n" << COL_RESET;

	showTestInfos("Advances the reverse_iterator by n element positions.");

	int	arr[10];

	// fill test array
	for ( int i = 0; i < 10; i++ )
		arr[i] = i;

	// set iterators
	std::reverse_iterator<int*>	std_it(arr + 10);
	ft::reverse_iterator<int*>	ft_it(arr + 10);

	std::cout << "std::it = " << *std_it
			  << "\nft::it  = " << *ft_it << "\n\n";

	std_it += 7;
	ft_it += 7;

	std::cout << "std::it += 7 = " << *std_it
			  << "\nft::it  += 7 = " << *ft_it << "\n\n";

	return ( cmpResults(*std_it == *ft_it) );
}
