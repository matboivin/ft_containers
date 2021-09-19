/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:46:05 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/20 00:03:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests.hpp"
#include "utils.hpp"

int	otherTests( void ) {

	std::cout << COL_BLUE_B
			  << "\n::::::::::::::::::::::::::::::::::::::::::::\n"
			  << COL_RESET << std::endl;

	int	has_failed = 0;

	has_failed = equalTests();
	if ( has_failed )
		return ( exitFailedTest("equal()") );

	has_failed = lexCmpTests();
	if ( has_failed )
		return ( exitFailedTest("lexicographical_compare()") );

	return (0);
}
