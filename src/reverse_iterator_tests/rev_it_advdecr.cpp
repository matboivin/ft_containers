/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_advdecr.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:05:43 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/20 00:01:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "tests.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * Compare advance/decrease operators
 */

int	cmpRevItAdvDecr( void ) {

	std::cout << COL_BLUE_B
			  << "\n________ Advance/decrease operators ________\n\n"
			  << COL_RESET;

	// operator++
	if ( cmpRevItIncrement() )
		return ( exitFailedTest("reverse_iterator: operator++") );

	// operator--
	if ( cmpRevItDecrement() )
		return ( exitFailedTest("reverse_iterator: operator--") );

	// operator+=
	if ( cmpRevItAdvanceOp() )
		return ( exitFailedTest("reverse_iterator: operator+=") );

	// operator-=
	if ( cmpRevItRetrocedeOp() )
		return ( exitFailedTest("reverse_iterator: operator-=") );

	// operator+
	if ( cmpRevItAdditionOp() )
		return ( exitFailedTest("reverse_iterator: operator+") );

	// operator-
	if ( cmpRevItSubtractOp() )
		return ( exitFailedTest("reverse_iterator: operator-") );

	return (0);
}
