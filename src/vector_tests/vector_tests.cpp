/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:49:17 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 18:26:15 by mboivin          ###   ########.fr       */
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

	has_failed = cmpVecEmpty();

	return (has_failed);
}
