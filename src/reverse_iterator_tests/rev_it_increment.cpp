/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_increment.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:34:12 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/12 17:02:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * Compare incrementation
 */

int	cmpRevItIncrement( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ operator++ (increment)\n\n" << COL_RESET;

	showTestInfos("Decrease iterator position.");

	int	arr[5];

	// fill test array
	for ( int i = 0; i < 5; i++ )
		arr[i] = i;

	// iterators
	std::reverse_iterator<int*>	std_it(arr + 1);
	ft::reverse_iterator<int*>	ft_it(arr + 1);

	std::cout << COL_BLUE_B << "\n______ pre-decrement version\n\n" << COL_RESET;

	std::cout << "std::it:   " << *std_it
			  << "\n++std::it: " << *(++std_it)
			  << "\nstd::it:   " << *std_it << "\n\n";

	std::cout << "ft::it:    " << *ft_it
			  << "\n++ft::it:  " << *(++ft_it)
			  << "\nft::it:    " << *ft_it << "\n\n";
	
	if ( cmpResults(*std_it == *ft_it) )
		return (1);

	// restore
	std_it--;
	ft_it--;

	std::cout << COL_BLUE_B << "______ post-decrement version\n\n" << COL_RESET;

	std::cout << "std::it:   " << *std_it
			  << "\nstd::it++: " << *(std_it++)
			  << "\nstd::it:   " << *std_it << "\n\n";

	std::cout << "ft::it:    " << *ft_it
			  << "\nft::it++:  " << *(ft_it++)
			  << "\nft::it:    " << *ft_it << "\n\n";

	return ( cmpResults(*std_it == *ft_it) );
}
