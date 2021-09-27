/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_element_access.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:10:37 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/27 14:55:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <iostream>
#include <vector>
#include "tests.hpp"
#include "vector.hpp"
#include "vector_tests.hpp"

/*
 * List of element access methods:
 *
 * operator[]
 * at
 * front
 * back
 */

/*
 * Compare at
 *
 * This member function accesses the element at the specified position in the container
 */

int	cmpVecAt( void ) {

	std::cout << COL_BLUE_B
			  << "\n_________ Element access method: at ________\n\n"
			  << COL_RESET;

	explainUnit("This member function accesses the element at\n"
				"the specified position in the container.");

	int	n = 2;
	int	out = 15;

	// create vector
	std::vector<int>	vec;

	vec.push_back(12);
	vec.push_back(5);
	vec.push_back(42);
	vec.push_back(100);
	vec.push_back(25);

	displayVecInfos(vec, "std::vector");

	// create ft::vector
	ft::vector<int>	ft_vec;
	std::cout << std::endl;

	ft_vec.push_back(12);
	ft_vec.push_back(5);
	ft_vec.push_back(42);
	ft_vec.push_back(100);
	ft_vec.push_back(25);

	displayVecInfos(ft_vec, "ft::vector");

	try {
		std::cout << "std::vector.at(" << n << ") "
				  << COL_WHITE_B << vec.at(n) << COL_RESET << std::endl;
	} catch (std::out_of_range& oor) {
		std::cout << "\nCatched 'out_of_range': " << oor.what() << std::endl;
	}

	try {
		std::cout << "ft::vector.at(" << n << ")  "
				  << COL_WHITE_B << ft_vec.at(n) << COL_RESET << "\n\n";
	} catch (std::out_of_range& oor) {
		std::cout << "\nCatched 'out_of_range': " << oor.what() << std::endl;
	}

	try {
		std::cout << "std::vector.at(" << out << ") "
				  << COL_WHITE_B << vec.at(out) << COL_RESET << std::endl;
	} catch (std::out_of_range& oor) {
		std::cout << "Catched 'out_of_range':\n" << COL_RESET << oor.what() << "\n\n";
	}

	try {
		std::cout << "ft::vector.at(" << out << ")  "
				  << COL_WHITE_B << ft_vec.at(out) << COL_RESET << "\n\n";
	} catch (std::out_of_range& oor) {
		std::cout << "Catched 'out_of_range':\n" << COL_RESET << oor.what() << "\n\n";
	}

	// Check if the results are the same or not between original and ft
	return ( displayTestResult(vec.at(n) == ft_vec.at(n)) );
}
