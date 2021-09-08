/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:49:17 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 18:24:45 by mboivin          ###   ########.fr       */
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
			  << "\n______________ Default Constructor\n\nstd::vector\n\n"
			  << COL_RESET;

	std::vector<int>	vec;

	displayInfos(vec, "std::vector");

	std::cout << COL_BLUE_B << "______________\n\nft::vector\n\n" << COL_RESET;

	ft::vector<int>		ft_vec;

	std::cout << std::endl;

	displayInfos(ft_vec, "ft::vector");
}

/*
 * Compare fill constructor
 */

void	cmpVecFillConstructor( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ Fill Constructor\n\nstd::vector\n\n"
			  << COL_RESET;

	std::vector<int>	vec1(14, 1);
	std::vector<int>	vec2(42, 2);
	std::vector<int>	vec3(4,  3);

	displayInfos(vec1, "std::vector 1");
	displayInfos(vec2, "std::vector 2");
	displayInfos(vec3, "std::vector 3");

	std::cout << COL_BLUE_B << "______________\n\nft::vector\n\n" << COL_RESET;

	ft::vector<int>	ft_vec1(14, 1);
	ft::vector<int>	ft_vec2(42, 2);
	ft::vector<int>	ft_vec3(4,  3);

	std::cout << std::endl;

	displayInfos(ft_vec1, "ft::vector 1");
	displayInfos(ft_vec2, "ft::vector 2");
	displayInfos(ft_vec3, "ft::vector 3");

	std::cout << std::endl;
}

/*
 * Compare copy constructor
 */

void	cmpVecCopyConstructor( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ Copy constructor\n\nstd::vector\n\n"
			  << COL_RESET;

	std::vector<int>	vec1(14, 1);

	displayInfos(vec1, "std::vector 1");

	std::vector<int>	vec2(vec1);

	displayInfos(vec2, "std::vector 2");

	std::cout << COL_BLUE_B << "______________\n\nft::vector\n\n" << COL_RESET;

	ft::vector<int>	ft_vec1(14, 1);

	std::cout << std::endl;

	displayInfos(ft_vec1, "ft::vector 1");

	ft::vector<int>	ft_vec2(ft_vec1);

	std::cout << std::endl;

	displayInfos(ft_vec2, "ft::vector 2");

	std::cout << std::endl;
}
