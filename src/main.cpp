/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:23:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 18:24:07 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "test_utils.hpp"
#include "vector_tests.hpp"

int	main( void ) {

	// const char*	default_prompt = "Enter the name of the container to test "
	// 							 "('vector', 'map', 'stack') or 'exit'.";
	// std::string	user_input = "";

	// while (1) {

	// 	std::cout << COL_BLUE_B << default_prompt << COL_RESET << "\n> ";
	// 	getline(std::cin, user_input);

	// 	if ( strToLower(user_input) == "exit" )
	// 		break ;

	// 	if ( strToLower(user_input) == "vector" )
	// 		testVector();
	// 	else if ( strToLower(user_input) == "map" )
	// 		testMap();
	// 	else if ( strToLower(user_input) == "stack" )
	// 		testStack();
	// 	else
	// 		std::cout << COL_RED_B << "Error:"
	// 				  << COL_RED << " invalid input.\n\n" << COL_RESET;
	// }

	testVector();

	return (0);
}
