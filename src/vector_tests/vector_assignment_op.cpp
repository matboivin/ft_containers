/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_assignment_op.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:49:17 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 18:33:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "test_utils.hpp"
#include "vector.hpp"
#include "vector_tests.hpp"

/*
 * Compare assignment operator
 */

void	cmpVecAssignmentOperator( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ Assignment Operator\n\nstd::vector\n\n"
			  << COL_RESET;

	// Create 3 different vectors
	std::vector<int>	vec1(14, 1);
	std::vector<int>	vec2(42, 2);
	std::vector<int>	vec3(4,  3);

	// Display their informations
	displayInfos(vec1, "std::vector 1");
	displayInfos(vec2, "std::vector 2");
	displayInfos(vec3, "std::vector 3");

	// vec2 and vec3 become both copies of vec1
	vec2 = vec1;
	vec3 = vec1;

	std::cout << COL_BLUE_B << "AFTER\n\n" << COL_RESET;

	// Display vec2 and vec3 informations after copy
	displayInfos(vec2, "std::vector 2");
	displayInfos(vec3, "std::vector 3");

	std::cout << COL_BLUE_B << "______________\n\nft::vector\n\n" << COL_RESET;

	// Create 3 different vectors
	ft::vector<int>	ft_vec1(14, 1);
	ft::vector<int>	ft_vec2(42, 2);
	ft::vector<int>	ft_vec3(4,  3);

	std::cout << std::endl;

	// Display their informations
	displayInfos(ft_vec1, "ft::vector 1");
	displayInfos(ft_vec2, "ft::vector 2");
	displayInfos(ft_vec3, "ft::vector 3");

	std::cout << COL_BLUE_B << "Creating copies:\n" << COL_RESET;

	// vec2 and vec3 become both copies of vec1
	ft_vec2 = ft_vec1;
	ft_vec3 = ft_vec1;

	std::cout << COL_BLUE_B << "\nAFTER\n\n" << COL_RESET;

	// Display vec2 and vec3 informations after copy
	displayInfos(ft_vec2, "ft::vector 2");
	displayInfos(ft_vec3, "ft::vector 3");

	std::cout << std::endl;
}
