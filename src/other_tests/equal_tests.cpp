/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:43:32 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/20 00:12:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include "algorithm.hpp"
#include "tests.hpp"
#include "utils.hpp"

static bool	predicate( int a, int b ) {

	return ( a == b );
}

int	equalTests( void ) {

	std::cout << COL_BLUE_B
			  << "\n___________________ equal __________________\n\n"
			  << COL_RESET;

	explainUnit("Test whether the elements in two ranges are equal.");

	bool	std_res;
	bool	ft_res;
	int		arr[] = { 20, 40, 60, 80, 100 };
	std::vector<int>vec (arr, arr+5);

	std::cout << COL_BLUE_B << "\n_ TEST1: equality\n\n" << COL_RESET;

	std_res = std::equal( vec.begin(), vec.end(), arr );
	ft_res = ft::equal( vec.begin(), vec.end(), arr );

	if ( displayTestResult(std_res == ft_res) )
		return (1);

	std::cout << COL_BLUE_B << "\n_ TEST2: predicate\n\n" << COL_RESET;

	std_res = std::equal( vec.begin(), vec.end(), arr, predicate );
	ft_res = ft::equal( vec.begin(), vec.end(), arr, predicate );

	return ( displayTestResult(std_res == ft_res) );
}
