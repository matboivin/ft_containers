/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:49:17 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 17:15:13 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"
#include "vector_tests.hpp"

/*
 * Compare default constructor
 */

void	cmpDefaultConstructor( void ) {

	std::cout << COL_BLUE_B << "\n______________ Default Constructor\n\n" << COL_RESET;

	std::vector<int>	vec;

	displayInfos(vec, "vec");

	std::cout << COL_BLUE_B << "______________\n\n" << COL_RESET;

	ft::vector<int>		ft_vec;

	std::cout << std::endl;

	displayInfos(ft_vec, "ft_vec");
}

/*
 * Compare fill constructor
 */

void	cmpFillConstructor( void ) {

	std::cout << COL_BLUE_B << "\n______________ Fill Constructor\n\n" << COL_RESET;

	std::vector<int>	vec1(14, 1);
	std::vector<int>	vec2(42, 2);
	std::vector<int>	vec3(4,  3);

	displayInfos(vec1, "vec1");
	displayInfos(vec2, "vec2");
	displayInfos(vec3, "vec3");

	std::cout << COL_BLUE_B << "______________\n\n" << COL_RESET;

	ft::vector<int>	ft_vec1(14, 1);
	ft::vector<int>	ft_vec2(42, 2);
	ft::vector<int>	ft_vec3(4,  3);

	std::cout << std::endl;

	displayInfos(ft_vec1, "ft_vec1");
	displayInfos(ft_vec2, "ft_vec2");
	displayInfos(ft_vec3, "ft_vec3");

	std::cout << std::endl;
}

/*
 * Compare copy constructor
 */

void	cmpCopyConstructor( void ) {

	std::cout << COL_BLUE_B << "\n______________ Copy constructor\n\n" << COL_RESET;

	std::vector<int>	vec1(14, 1);

	displayInfos(vec1, "vec1");

	std::vector<int>	vec2(vec1);

	displayInfos(vec2, "vec2");

	std::cout << COL_BLUE_B << "______________\n\n" << COL_RESET;

	ft::vector<int>	ft_vec1(14, 1);

	std::cout << std::endl;

	displayInfos(ft_vec1, "ft_vec1");

	ft::vector<int>	ft_vec2(ft_vec1);

	std::cout << std::endl;

	displayInfos(ft_vec2, "ft_vec2");

	std::cout << std::endl;
}
