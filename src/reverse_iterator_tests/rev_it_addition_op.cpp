/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_addition_op.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:30:49 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/12 17:56:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * Compare addition operator
 */

int	cmpRevItAdditionOp( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ operator+ (addition)\n\n" << COL_RESET;

	showTestInfos("Returns an iterator pointing to the element n positions away.");

	int	arr[10];

	// fill test array
	for ( int i = 0; i < 10; i++ )
		arr[i] = i;

	// set iterators
	std::reverse_iterator<int*>	std_it(arr + 10);
	ft::reverse_iterator<int*>	ft_it(arr + 10);

	std::cout << "std::it = " << *std_it
			  << "\tft::it  = " << *ft_it << "\n\n";

	// storing results
	std::reverse_iterator<int*>	std_res = (std_it + 5);
	ft::reverse_iterator<int*>	ft_res = (ft_it + 5);

	std::cout << "\nstd::it + 5 = " << *std_res
			  << "\nft::it + 5  = " << *ft_res << "\n\n";

	return ( cmpResults(*std_res == *ft_res) );
}
