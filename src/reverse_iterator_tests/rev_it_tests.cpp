/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:33:44 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/13 18:17:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"

int	testReverseIterator( void ) {

	std::cout << COL_BLUE_B
			  << "\n::::::::::::::::::::::::::::::::::::::::::::\n"
				 "::::::::::::: REVERSE ITERATOR :::::::::::::\n"
				 "::::::::::::::::::::::::::::::::::::::::::::\n"
			  << COL_RESET << std::endl;

	int	has_failed = 0;

	// constructors
	cmpRevItDefaultConstructor();

	if ( !continueTests("Initialization constructor") )
		return (0);

	cmpRevItInitConstructor();

	if ( !continueTests("Copy constructor") )
		return (0);

	cmpRevItCopyConstructor();

	if ( !continueTests("operator*") )
		return (0);

	// element access
	has_failed = cmpRevItIndirectionOp();
	if ( has_failed )
		return ( exitFailedTest("reverse_iterator: operator*") );
	
	if ( !continueTests("operator->") )
		return (0);

	has_failed = cmpRevItPointerOp();
	if ( has_failed )
		return ( exitFailedTest("reverse_iterator: operator->") );

	if ( !continueTests("operator[]") )
		return (0);

	has_failed = cmpRevItSubscriptingOp();
	if ( has_failed )
		return ( exitFailedTest("reverse_iterator: operator[]") );

	if ( !continueTests("advance/decrease operators") )
		return (0);

	// advance/decrease
	has_failed = cmpRevItAdvDecr();
	if ( has_failed )
		return (1);
	
	if ( !continueTests("non-member functions") )
		return (0);

	// Relational operators
	has_failed = cmpRevItRelationalOps();
	if ( has_failed )
		return (1);

	has_failed = cmpRevItNonMemberOps();
	if ( has_failed )
		return (1);

	return (0);
}
