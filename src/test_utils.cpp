/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:22:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 18:47:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "test_utils.hpp"

std::string	strToLower( std::string str ) {

	for ( std::string::iterator it = str.begin();
		  it != str.end();
		  ++it ) {

		*it = std::tolower(*it);
	}

	return (str);
}

void	showTestInfos( const std::string& msg ) {

	std::cout << COL_BLUE_B << "Test description:\n"
			  << COL_BLUE << msg << '\n'
			  << COL_RESET << std::endl;
}

int	continueTests( const std::string& next_test ) {

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
