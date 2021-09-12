/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:33:44 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/12 16:27:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * Run all reverse iterator tests
 */

int	testReverseIterator( void ) {

	std::cout << COL_BLUE_B
			  << "\n::::::::::::::::::::::::::::::::::::::::::::\n"
				 "::::::::::::: REVERSE ITERATOR :::::::::::::\n"
				 "::::::::::::::::::::::::::::::::::::::::::::\n"
			  << COL_RESET << std::endl;

	int	arr[10];

	std::cout << "Test array of 10 elements: ";
	for ( int i = 0; i < 10; i++ ) {

		arr[i] = i;
		std::cout << arr[i] << ' ';
	}

	std::cout << COL_BLUE_B << "\n\nCreate 4 reverse iterators:\n"
			  << COL_BLUE << "(2 originals + 2 ft::reverse_iterator)\n" << COL_RESET;

	// Original
	std::reverse_iterator<int*>	std_it(arr + 1);
	std::reverse_iterator<int*>	std_ite(arr + 10);

	// ft
	ft::reverse_iterator<int*>	ft_it(arr + 1);
	ft::reverse_iterator<int*>	ft_ite(arr + 10);

	std::cout << std::endl;

	// operator=
	cmpRevItAssignmentOperator(std_it, std_ite, ft_it, ft_ite);

	// Relational operators
	//cmpRevItRelationalOps(std_it, std_ite, ft_it, ft_ite);

	return (0);
}
