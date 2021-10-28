/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:33:23 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 16:36:23 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "tests.hpp"

void	displayElapsedTime(clock_t start, clock_t end)
{
	double	elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << std::fixed << elapsed << " seconds\n\n";
}

void	explainTest(const std::string& msg) {

	std::cout << "Test description: " << msg << "\n\n";
}

std::string	str_to_lower(std::string str)
{
	for ( std::string::iterator it = str.begin();
		  it != str.end();
		  ++it )
	{
		*it = std::tolower(*it);
	}
	return (str);
}

int	continue_tests(const std::string& next_test)
{
	const char*	default_prompt = "\nPress enter to continue or 'exit'.";
	std::string	user_input = "";

	std::cout << "\nNext test is: "
			  << COL_WHITE_B << next_test << COL_RESET;

	while (1)
	{
		std::cout << COL_WHITE_B << default_prompt << COL_RESET << "\n> ";
		getline(std::cin, user_input);

		if (str_to_lower(user_input) == "exit")
			break ;
		if (user_input.empty())
		{
			std::cout << COL_WHITE_B << "-> Next test\n\n" << COL_RESET;
			return (1);
		}
	}
	return (0);
}
