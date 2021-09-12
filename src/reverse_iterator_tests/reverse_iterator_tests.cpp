/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator_tests.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:33:44 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/12 15:41:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iterator>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"


/*
 * Compare relational operators
 */

void	cmpRevItRelationalOps( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ Relational operators\n\n"
			  << COL_RESET;
	
	showTestInfos("Operators to make comparison between two reverse iterators.");

	std::cout << COL_BLUE_B << "______ Test array created: \n\n" << COL_RESET;

	int	arr[4];

	for ( int i = 0; i < 4; i++ ) {

		arr[i] = i;
		std::cout << arr[i] << ' ';
	}

	std::cout << COL_BLUE_B << "\n\n______ 4 reverse iterators created\n"
							   "       (2 originals + 2 ft::reverse_iterator)\n\n" << COL_RESET;

	// Original
	std::reverse_iterator<int*>	std_it(arr + 1);
	std::reverse_iterator<int*>	std_ite(arr + 4);

	// ft
	ft::reverse_iterator<int*>	ft_it(arr + 1);
	ft::reverse_iterator<int*>	ft_ite(arr + 4);

	std::cout << std::endl;

	std::cout << "std::it:  " << *std_it << "\tft::it:  " << *ft_it
			  << "\nstd::ite: " << *std_ite << "\tft::ite: " << *ft_ite << std::endl;

	std::cout << COL_BLUE_B << "\n______ Tests\n\n" << COL_RESET;

	bool	std_res = (std_it == std_ite);
	bool	ft_res = (ft_it == ft_ite);

	std::cout << std::boolalpha
			  << COL_BLUE << "std::it == std::ite ? " << COL_RESET << std_res
			  << COL_BLUE << " \nft::it == ft::ite ?   " << COL_RESET << ft_res << "\n\n";
	
	if ( cmpResults(std_res == ft_res) )
		return ;
}


/*
 * Run all reverse iterator tests
 */

int	testReverseIterator( void ) {

	std::cout << COL_BLUE_B
			  << "\n::::::::::::::::::::::::::::::::::::::::::::\n"
				 "::::::::::::: REVERSE ITERATOR :::::::::::::\n"
				 "::::::::::::::::::::::::::::::::::::::::::::\n"
			  << COL_RESET << std::endl;

	cmpRevItRelationalOps();

	return (0);
}
