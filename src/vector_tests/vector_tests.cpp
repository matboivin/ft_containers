/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:49:17 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 18:02:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vector_tests.hpp"
/*
 * Run all vector tests
*/

static int	continueTests( const std::string& next_test ) {

	const char*	default_prompt = "\nPress enter to continue or 'exit' "
								 "to return to menu.";
	std::string	user_input = "";

	std::cout << COL_BLUE << "\nNext test is: "
			  << COL_BLUE_B << next_test << COL_RESET;

	while (1) {

		std::cout << COL_BLUE_B << default_prompt << COL_RESET << "\n> ";
		getline(std::cin, user_input);

		if ( strToLower(user_input) == "exit" ) {

			std::cout << COL_GREEN << "Back to menu.\n\n" << COL_RESET;
			break ;
		}

		if ( user_input.empty() ) {

			std::cout << COL_GREEN << "-> Next test\n\n" << COL_RESET;
			return (1);

		} else {

			std::cout << COL_RED_B << "Error:"
					  << COL_RED << " invalid input.\n" << COL_RESET;;
		}
	}

	return (0);
}

int	testVector( void ) {

	std::cout << COL_BLUE_B
			  << "\n::::::::::::::::::::::::::::::::::::::::::::\n"
				 ":::::::::::::::::: VECTOR ::::::::::::::::::\n"
				 "::::::::::::::::::::::::::::::::::::::::::::\n"
			  << COL_RESET << std::endl;

	cmpDefaultConstructor();

	if ( !continueTests("Fill constructor") )
		return (0);

	cmpFillConstructor();

	if ( !continueTests("Copy constructor") )
		return (0);

	cmpCopyConstructor();

	if ( !continueTests("Assignment operator") )
		return (0);

	cmpAssignmentOperator();

	return (0);
}
