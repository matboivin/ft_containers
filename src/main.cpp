/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:23:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 18:02:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector_tests.hpp>

std::string	strToLower( std::string str ) {

	for ( std::string::iterator it = str.begin();
		  it != str.end();
		  ++it ) {

		*it = std::tolower(*it);
	}

	return (str);
}

int	main( void ) {

	const char*	default_prompt = "Enter the name of the container to test "
								 "('vector', 'map', 'stack') or 'exit'.";
	std::string	user_input = "";

	while (1) {

		std::cout << COL_BLUE_B << default_prompt << COL_RESET << "\n> ";
		getline(std::cin, user_input);

		if ( strToLower(user_input) == "exit" )
			break ;

		if ( strToLower(user_input) == "vector" )
			testVector();
		else
			std::cout << COL_RED_B << "Error:"
					  << COL_RED << " invalid input.\n\n" << COL_RESET;
	}

	return (0);
}
