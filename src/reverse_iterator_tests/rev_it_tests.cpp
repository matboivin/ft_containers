/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:33:44 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/12 17:44:36 by mboivin          ###   ########.fr       */
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

	int	has_failed = 0;

	// // operator=
	// has_failed = cmpRevItAssignmentOperator();
	// if ( has_failed )
	// 	return ( exitFailedTest("reverse_iterator: assignement operator") );

	// advance/decrease
	has_failed = cmpRevItIncrement();
	if ( has_failed )
		return ( exitFailedTest("reverse_iterator: operator++") );

	has_failed = cmpRevItDecrement();
	if ( has_failed )
		return ( exitFailedTest("reverse_iterator: operator--") );

	has_failed = cmpRevItAdvanceOp();
	if ( has_failed )
		return ( exitFailedTest("reverse_iterator: operator+=") );
	
	has_failed = cmpRevItAdditionOp();
	if ( has_failed )
		return ( exitFailedTest("reverse_iterator: operator+") );
	
	has_failed = cmpRevItRetrocedeOp();
	if ( has_failed )
		return ( exitFailedTest("reverse_iterator: operator-=") );
	
	has_failed = cmpRevItSubtractOp();
	if ( has_failed )
		return ( exitFailedTest("reverse_iterator: operator-") );

	// // Relational operators
	// has_failed = cmpRevItRelationalOps();
	// if ( has_failed )
	// 	return ( exitFailedTest("reverse_iterator: relational operators") );

	return (0);
}
