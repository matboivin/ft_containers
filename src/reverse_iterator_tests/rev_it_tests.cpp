/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:33:44 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/13 16:30:14 by mboivin          ###   ########.fr       */
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
	cmpRevItInitConstructor();
	cmpRevItCopyConstructor();

	if ( !continueTests("advance/decrease operators") )
		return (0);

	// advance/decrease
	has_failed = cmpRevItAdvDecr();
	if ( has_failed )
		return (1);
	
	if ( !continueTests("relational operators") )
		return (0);

	// Relational operators
	has_failed = cmpRevItRelationalOps();
	if ( has_failed )
		return (1);

	return (0);
}
