/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_assignment_op.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:49:17 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/12 17:07:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "test_utils.hpp"
#include "vector.hpp"
#include "vector_tests.hpp"

/*
 * Compare Copy assignment operator
 */

void	cmpVecAssignmentOperator( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ Copy assignment operator\n\n"
			  << COL_RESET;

	showTestInfos("operator=");

	std::cout << COL_BLUE_B << "______ std::vector\n\n" << COL_RESET;

	// Create 3 different vectors
	std::vector<int>	vec1(14, 1);
	std::vector<int>	vec2(42, 2);
	std::vector<int>	vec3(4,  3);

	// Display their informations
	displayVecInfos(vec1, "std::vector 1");
	displayVecInfos(vec2, "std::vector 2");
	displayVecInfos(vec3, "std::vector 3");

	// vec2 and vec3 become both copies of vec1
	vec2 = vec1;
	vec3 = vec1;

	std::cout << COL_BLUE_B << "AFTER COPY\n\n" << COL_RESET;

	// Display vec2 and vec3 informations after copy
	displayVecInfos(vec2, "std::vector 2");
	displayVecInfos(vec3, "std::vector 3");

	std::cout << COL_BLUE_B << "______ ft::vector\n\n" << COL_RESET;

	// Create 3 different vectors
	ft::vector<int>	ft_vec1(14, 1);
	ft::vector<int>	ft_vec2(42, 2);
	ft::vector<int>	ft_vec3(4,  3);

	std::cout << std::endl;

	// Display their informations
	displayVecInfos(ft_vec1, "ft::vector 1");
	displayVecInfos(ft_vec2, "ft::vector 2");
	displayVecInfos(ft_vec3, "ft::vector 3");

	std::cout << COL_BLUE_B << "Creating copies:\n" << COL_RESET;

	// vec2 and vec3 become both copies of vec1
	ft_vec2 = ft_vec1;
	ft_vec3 = ft_vec1;

	std::cout << COL_BLUE_B << "\nAFTER COPY\n\n" << COL_RESET;

	// Display vec2 and vec3 informations after copy
	displayVecInfos(ft_vec2, "ft::vector 2");
	displayVecInfos(ft_vec3, "ft::vector 3");

	std::cout << std::endl;
}
