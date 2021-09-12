/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_subtraction_op.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:36:40 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/12 17:56:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * Compare subtraction operator
 */

int	cmpRevItSubtractOp( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ operator- (subtraction)\n\n" << COL_RESET;

	showTestInfos("Returns an iterator pointing to the element n positions before the currently pointed one.");

	int	arr[10];

	// fill test array
	for ( int i = 0; i < 10; i++ )
		arr[i] = i;

	// set iterators
	std::reverse_iterator<int*>	std_it(arr + 1);
	ft::reverse_iterator<int*>	ft_it(arr + 1);

	std::cout << "std::it = " << *std_it
			  << "\nft::it  = " << *ft_it << "\n\n";

	// storing results
	std::reverse_iterator<int*>	std_res = (std_it - 5);
	ft::reverse_iterator<int*>	ft_res = (ft_it - 5);

	std::cout << "\nstd::it - 5 = " << *std_res
			  << "\nft::it - 5  = " << *ft_res << "\n\n";

	return ( cmpResults(*std_res == *ft_res) );
}
