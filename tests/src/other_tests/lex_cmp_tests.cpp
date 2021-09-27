/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_cmp_tests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 00:02:57 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/20 00:11:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>
#include <algorithm>
#include "algorithm.hpp"
#include "tests.hpp"
#include "utils.hpp"

static bool	compare( char a, char b ) {

	return ( std::tolower(a) < std::tolower(b) );
}

int	lexCmpTests( void ) {

	std::cout << COL_BLUE_B
			  << "\n__________ lexicographical_compare _________\n\n"
			  << COL_RESET;

	explainUnit("Test whether the elements in two ranges are equal.");

	bool	std_res;
	bool	ft_res;

	char	s1[] = "Fourty two";
	char	s2[] = "fourth";

	size_t	len1 = std::strlen(s1);
	size_t	len2 = std::strlen(s2);

	std::cout << COL_BLUE_B << "\n_ TEST1: default\n\n" << COL_RESET;

	std_res = std::lexicographical_compare( s1, s1 + len1, s2, s2 + len2 );
	ft_res = ft::lexicographical_compare( s1, s1 + len1, s2, s2 + len2 );

	if ( displayTestResult(std_res == ft_res) )
		return (1);

	std::cout << COL_BLUE_B << "\n_ TEST2: custom\n\n" << COL_RESET;

	std_res = std::lexicographical_compare( s1, s1 + len1, s2, s2 + len2, compare );
	ft_res = ft::lexicographical_compare( s1, s1 + len1, s2, s2 + len2, compare );

	return ( displayTestResult(std_res == ft_res) );
}
