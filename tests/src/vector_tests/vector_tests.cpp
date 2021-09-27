/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:49:17 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/27 14:19:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "tests.hpp"
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

	// // constructors
	// cmpVecDefaultConstructor();

	// if ( !continueTests("Fill constructor") )
	// 	return (0);

	// cmpVecFillConstructor();

	// if ( !continueTests("Copy constructor") )
	// 	return (0);

	// cmpVecCopyConstructor();

	// if ( !continueTests("Assignment operator") )
	// 	return (0);

	// // assignment operator
	// cmpVecAssignmentOperator();

	// // capacity member functions
	// if ( !continueTests("Capacity member function: empty()") )
	// 	return (0);

	// has_failed = cmpVecEmpty();
	// if ( has_failed )
	// 	return ( exitFailedTest("vector: capacity: empty()") );

	// if ( !continueTests("Capacity member function: size()") )
	// 	return (0);

	// has_failed = cmpVecSize();
	// if ( has_failed )
	// 	return ( exitFailedTest("vector: capacity: size(") );

	// if ( !continueTests("Capacity member function: resize()") )
	// 	return (0);

	// has_failed = cmpVecResize();
	// if ( has_failed )
	// 	return ( exitFailedTest("vector: capacity: resize(") );

	// if ( !continueTests("Capacity member function: max_size()") )
	// 	return (0);

	// has_failed = cmpVecMaxSize();
	// if ( has_failed )
	// 	return ( exitFailedTest("vector: capacity: max_size()") );

	// if ( !continueTests("Capacity member function: capacity()") )
	// 	return (0);

	// has_failed = cmpVecCapacity();
	// if ( has_failed )
	// 	return ( exitFailedTest("vector: capacity: capacity()") );

	// if ( !continueTests("Capacity member function: reserve()") )
	// 	return (0);

	// has_failed = cmpVecReserve();
	// if ( has_failed )
	// 	return ( exitFailedTest("vector: capacity: reserve()") );

	// // element access
	// if ( !continueTests("Element access member function: at()") )
	// 	return (0);

	has_failed = cmpVecAt();
	if ( has_failed )
		return ( exitFailedTest("vector: element access: at()") );

	// // iterator
	// if ( !continueTests("iterators") )
	// 	return (0);

	// has_failed = cmpVecIterator();
	// if ( has_failed )
	// 	return ( exitFailedTest("vector: iterator") );

	// // relational operators
	// if ( !continueTests("relational operators") )
	// 	return (0);

	// has_failed = cmpVecRelationalOps();
	// if ( has_failed )
	// 	return ( exitFailedTest("vector: relational operators") );

	return (0);
}
