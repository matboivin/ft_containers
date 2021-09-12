/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_retrocede_op.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:42:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/12 17:55:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * Compare retrocede operator
 */

int	cmpRevItRetrocedeOp( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ operator-= (retrocede)\n\n" << COL_RESET;

	showTestInfos("Decreases the reverse_iterator by n element positions.");

	int	arr[10];

	// fill test array
	for ( int i = 0; i < 10; i++ )
		arr[i] = i;

	// set iterators
	std::reverse_iterator<int*>	std_it(arr + 1);
	ft::reverse_iterator<int*>	ft_it(arr + 1);

	std::cout << "std::it = " << *std_it
			  << "\nft::it  = " << *ft_it << "\n\n";

	std_it -= 4;
	ft_it -= 4;

	std::cout << "\nstd::it -= 4 = " << *std_it
			  << "\nft::it -= 4  = " << *ft_it << "\n\n";

	return ( cmpResults(*std_it == *ft_it) );
}
