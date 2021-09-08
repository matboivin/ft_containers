/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:49:17 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 19:06:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "test_utils.hpp"
#include "vector.hpp"
#include "vector_tests.hpp"

/*
 * Run all vector tests
*/

int	testVector( void ) {

	std::cout << COL_BLUE_B
			  << "\n::::::::::::::::::::::::::::::::::::::::::::\n"
				 ":::::::::::::::::: VECTOR ::::::::::::::::::\n"
				 "::::::::::::::::::::::::::::::::::::::::::::\n"
			  << COL_RESET << std::endl;

	int	has_failed = 0;

	// cmpVecDefaultConstructor();

	// if ( !continueTests("Fill constructor") )
	// 	return (0);

	// cmpVecFillConstructor();

	// if ( !continueTests("Copy constructor") )
	// 	return (0);

	// cmpVecCopyConstructor();

	// if ( !continueTests("Assignment operator") )
	// 	return (0);

	// cmpVecAssignmentOperator();

	// if ( !continueTests("Capacity member function: empty") )
	// 	return (0);

	// has_failed = cmpVecEmpty();
	// if ( has_failed )
	// 	return (1);

	// if ( !continueTests("Capacity member function: size") )
	// 	return (0);

	// has_failed = cmpVecSize();
	// if ( has_failed )
	// 	return (1);
	
	has_failed = cmpVecMaxSize();
	if ( has_failed )
		return (1);

	return (0);
}
