/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_construct.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:49:17 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/13 15:03:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "test_utils.hpp"
#include "vector.hpp"
#include "vector_tests.hpp"

/*
 * Compare default constructor
 */

void	cmpVecDefaultConstructor( void ) {

	std::cout << COL_BLUE_B
			  << "\n___________ Default Constructor ____________\n\n"
			  << COL_RESET;

	explainUnit("Constructs an empty container, with no elements.");

	// Original
	std::cout << COL_BLUE_B << "_ std::vector\n\n" << COL_RESET;

	std::vector<int>	vec;

	displayVecInfos(vec, "std::vector");

	// ft::vector
	std::cout << COL_BLUE_B << "_ ft::vector\n\n" << COL_RESET;

	ft::vector<int>		ft_vec;

	std::cout << std::endl;

	displayVecInfos(ft_vec, "ft::vector");
}

/*
 * Compare fill constructor
 */

void	cmpVecFillConstructor( void ) {

	std::cout << COL_BLUE_B
			  << "\n_____________ Fill Constructor _____________\n\n"
			  << COL_RESET;
	
	explainUnit("Constructs a container with n elements. Each element is a copy of value passed as parameter.");

	// Original
	std::cout << COL_BLUE_B << "_ std::vector\n\n" << COL_RESET;

	std::vector<int>	vec1(14, 1);
	std::vector<int>	vec2(5,  2);

	displayVecInfos(vec1, "std::vector 1 (14, 1)");
	displayVecInfos(vec2, "std::vector 2 (5,  2)");

	// ft::vector
	std::cout << COL_BLUE_B << "_ ft::vector\n\n" << COL_RESET;

	ft::vector<int>	ft_vec1(14, 1);
	ft::vector<int>	ft_vec2(5,  2);
	std::cout << std::endl;

	displayVecInfos(ft_vec1, "ft::vector 1 (14, 1)");
	displayVecInfos(ft_vec2, "ft::vector 2 (5,  2)");

	std::cout << std::endl;
}

/*
 * Compare copy constructor
 */

void	cmpVecCopyConstructor( void ) {

	std::cout << COL_BLUE_B
			  << "\n_____________ Copy constructor _____________\n\n"
			  << COL_RESET;
	
	explainUnit("Creates a new object from existing one passed as parameter.");

	// Original
	std::cout << COL_BLUE_B << "_ std::vector\n\n" << COL_RESET;

	// create a vector
	std::vector<int>	vec1(5);
	// add some numbers to it
	vec1.push_back(12);
	vec1.push_back(5);
	vec1.push_back(42);
	vec1.push_back(100);
	vec1.push_back(25);

	// display vec1
	displayVecInfos(vec1, "std::vector 1");

	// create a copy from vec1
	std::vector<int>	vec2(vec1);
	// display copy
	displayVecInfos(vec2, "std::vector 2");

	// ft::vector
	std::cout << COL_BLUE_B << "_ ft::vector\n\n" << COL_RESET;

	// create a vector
	ft::vector<int>	ft_vec1(5);
	std::cout << std::endl;
	// add some numbers to it
	ft_vec1.push_back(12);
	ft_vec1.push_back(5);
	ft_vec1.push_back(42);
	ft_vec1.push_back(100);
	ft_vec1.push_back(25);

	// display ft_vec1
	displayVecInfos(ft_vec1, "ft::vector 1");

	// create a copy from ft_vec1
	ft::vector<int>	ft_vec2(ft_vec1);
	std::cout << std::endl;
	// display copy
	displayVecInfos(ft_vec2, "ft::vector 2");

	std::cout << std::endl;
}
