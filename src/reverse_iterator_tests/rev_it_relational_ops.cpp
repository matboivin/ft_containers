/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_relational_ops.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:33:44 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/20 00:01:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "tests.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * Compare operator== (equal to)
 */

static int	cmpRevItEqualTo( std::reverse_iterator<int*> std_rev_it,
							 std::reverse_iterator<int*> std_rev_ite,
							 ft::reverse_iterator<int*> ft_rev_it,
							 ft::reverse_iterator<int*> ft_rev_ite ) {

	std::cout << COL_BLUE_B
			  << "\n_ TEST: operator== (equal to)\n\n" << COL_RESET;

	bool	std_res = (std_rev_it == std_rev_ite);
	bool	ft_res = (ft_rev_it == ft_rev_ite);

	std::cout << std::boolalpha
			  << "std::rev_it == std::rev_it ? " << COL_WHITE_B << std_res << COL_RESET
			  << " \nft::rev_it == ft::rev_it ?   " << COL_WHITE_B << ft_res << COL_RESET
			  << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(std_res == ft_res) )
		return (1);

	std_res = (std_rev_it == std_rev_it);
	ft_res = (ft_rev_it == ft_rev_it);

	std::cout << std::boolalpha
			  << "std::rev_it == std::rev_it ? " << COL_WHITE_B << std_res << COL_RESET
			  << " \nft::rev_it == ft::rev_it ?   " << COL_WHITE_B << ft_res << COL_RESET
			  << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(std_res == ft_res) )
		return (1);

	return (0);
}

/*
 * Compare operator!= (not equal to)
 */

static int	cmpRevItNotEqualTo( std::reverse_iterator<int*> std_rev_it,
								std::reverse_iterator<int*> std_rev_ite,
								ft::reverse_iterator<int*> ft_rev_it,
								ft::reverse_iterator<int*> ft_rev_ite ) {

	std::cout << COL_BLUE_B
			  << "\n_ TEST: operator!= (not equal to)\n\n" << COL_RESET;

	bool	std_res = (std_rev_it != std_rev_ite);
	bool	ft_res = (ft_rev_it != ft_rev_ite);

	std::cout << std::boolalpha
			  << "std::rev_it != std::rev_it ? " << COL_WHITE_B << std_res << COL_RESET
			  << " \nft::rev_it != ft::rev_it ?   " << COL_WHITE_B << ft_res << COL_RESET
			  << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(std_res == ft_res) )
		return (1);

	std_res = (std_rev_it != std_rev_it);
	ft_res = (ft_rev_it != ft_rev_it);

	std::cout << std::boolalpha
			  << "std::rev_it != std::rev_it ? " << COL_WHITE_B << std_res << COL_RESET
			  << " \nft::rev_it != ft::rev_it ?   " << COL_WHITE_B << ft_res << COL_RESET
			  << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(std_res == ft_res) )
		return (1);

	return (0);
}

/*
 * Compare operator< (less than)
 */

static int	cmpRevItLessThan( std::reverse_iterator<int*> std_rev_it,
							  std::reverse_iterator<int*> std_rev_ite,
							  ft::reverse_iterator<int*> ft_rev_it,
							  ft::reverse_iterator<int*> ft_rev_ite ) {

	std::cout << COL_BLUE_B
			  << "\n_ TEST: operator< (less than)\n\n" << COL_RESET;

	bool	std_res = (std_rev_it < std_rev_ite);
	bool	ft_res = (ft_rev_it < ft_rev_ite);

	std::cout << std::boolalpha
			  << "std::rev_it < std::rev_it ? " << COL_WHITE_B << std_res << COL_RESET
			  << " \nft::rev_it < ft::rev_it ?   " << COL_WHITE_B << ft_res << COL_RESET
			  << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(std_res == ft_res) )
		return (1);

	std_res = (std_rev_it < std_rev_it);
	ft_res = (ft_rev_it < ft_rev_it);

	std::cout << std::boolalpha
			  << "std::rev_it < std::rev_it ? " << COL_WHITE_B << std_res << COL_RESET
			  << " \nft::rev_it < ft::rev_it ?   " << COL_WHITE_B << ft_res << COL_RESET
			  << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(std_res == ft_res) )
		return (1);

	return (0);
}

/*
 * Compare operator> (greater than)
 */

static int	cmpRevItGreaterThan( std::reverse_iterator<int*> std_rev_it,
								 std::reverse_iterator<int*> std_rev_ite,
								 ft::reverse_iterator<int*> ft_rev_it,
								 ft::reverse_iterator<int*> ft_rev_ite ) {

	std::cout << COL_BLUE_B
			  << "\n_ TEST: operator> (greater than)\n\n" << COL_RESET;

	bool	std_res = (std_rev_it > std_rev_ite);
	bool	ft_res = (ft_rev_it > ft_rev_ite);

	std::cout << std::boolalpha
			  << "std::rev_it > std::rev_it ? " << COL_WHITE_B << std_res << COL_RESET
			  << " \nft::rev_it > ft::rev_it ?   " << COL_WHITE_B << ft_res << COL_RESET
			  << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(std_res == ft_res) )
		return (1);

	std_res = (std_rev_it > std_rev_it);
	ft_res = (ft_rev_it > ft_rev_it);

	std::cout << std::boolalpha
			  << "std::rev_it > std::rev_it ? " << COL_WHITE_B << std_res << COL_RESET
			  << " \nft::rev_it > ft::rev_it ?   " << COL_WHITE_B << ft_res << COL_RESET
			  << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(std_res == ft_res) )
		return (1);

	return (0);
}

/*
 * Compare operator<= (less than or equal to)
 */

static int	cmpRevItLessEqual( std::reverse_iterator<int*> std_rev_it,
							   std::reverse_iterator<int*> std_rev_ite,
							   ft::reverse_iterator<int*> ft_rev_it,
							   ft::reverse_iterator<int*> ft_rev_ite ) {

	std::cout << COL_BLUE_B
			  << "\n_ TEST: operator<= (less than or equal to)\n\n" << COL_RESET;

	bool	std_res = (std_rev_it <= std_rev_ite);
	bool	ft_res = (ft_rev_it <= ft_rev_ite);

	std::cout << std::boolalpha
			  << "std::rev_it <= std::rev_it ? " << COL_WHITE_B << std_res << COL_RESET
			  << " \nft::rev_it <= ft::rev_it ?   " << COL_WHITE_B << ft_res << COL_RESET
			  << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(std_res == ft_res) )
		return (1);

	std_res = (std_rev_it <= std_rev_it);
	ft_res = (ft_rev_it <= ft_rev_it);

	std::cout << std::boolalpha
			  << "std::rev_it <= std::rev_it ? " << COL_WHITE_B << std_res << COL_RESET
			  << " \nft::rev_it <= ft::rev_it ?   " << COL_WHITE_B << ft_res << COL_RESET
			  << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(std_res == ft_res) )
		return (1);

	return (0);
}

/*
 * Compare operator>= (greater than or equal to)
 */

static int	cmpRevItGreaterEqual( std::reverse_iterator<int*> std_rev_it,
								  std::reverse_iterator<int*> std_rev_ite,
								  ft::reverse_iterator<int*> ft_rev_it,
								  ft::reverse_iterator<int*> ft_rev_ite ) {

	std::cout << COL_BLUE_B
			  << "\n_ TEST: operator>= (greater than or equal to)\n\n" << COL_RESET;

	bool	std_res = (std_rev_it >= std_rev_ite);
	bool	ft_res = (ft_rev_it >= ft_rev_ite);

	std::cout << std::boolalpha
			  << "std::rev_it >= std::rev_it ? " << COL_WHITE_B << std_res << COL_RESET
			  << " \nft::rev_it >= ft::rev_it ?   " << COL_WHITE_B << ft_res << COL_RESET
			  << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(std_res == ft_res) )
		return (1);

	std_res = (std_rev_it >= std_rev_it);
	ft_res = (ft_rev_it >= ft_rev_it);

	std::cout << std::boolalpha
			  << "std::rev_it >= std::rev_it ? " << COL_WHITE_B << std_res << COL_RESET
			  << " \nft::rev_it >= ft::rev_it ?   " << COL_WHITE_B << ft_res << COL_RESET
			  << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(std_res == ft_res) )
		return (1);

	return (0);
}

/*
 * Compare relational operators
 */

int	cmpRevItRelationalOps( void ) {

	std::cout << COL_BLUE_B
			  << "\n___________ Relational operators ___________\n\n"
			  << COL_RESET;

	explainUnit("Operators to make comparison between two reverse iterators.");

	int	arr[10];

	// fill test array
	for ( int i = 0; i < 10; i++ )
		arr[i] = i;

	// Original
	std::reverse_iterator<int*>	std_rev_it(arr + 1);
	std::reverse_iterator<int*>	std_rev_ite(arr + 10);

	// ft
	ft::reverse_iterator<int*>	ft_rev_it(arr + 1);
	ft::reverse_iterator<int*>	ft_rev_ite(arr + 10);
	std::cout << std::endl;

	std::cout << "std::rev_it:  " << *std_rev_it << "\tft::rev_it:  " << *ft_rev_it
			  << "\nstd::rev_ite: " << *std_rev_ite << "\tft::rev_ite: " << *ft_rev_ite << std::endl;

	// Test operator==
	if ( cmpRevItEqualTo(std_rev_it, std_rev_ite, ft_rev_it, ft_rev_ite) )
		return ( exitFailedTest("reverse_iterator: relational operator==") );

	// Test operator!=
	if ( cmpRevItNotEqualTo(std_rev_it, std_rev_ite, ft_rev_it, ft_rev_ite) )
		return ( exitFailedTest("reverse_iterator: relational operator!=") );

	// Test operator<
	if ( cmpRevItLessThan(std_rev_it, std_rev_ite, ft_rev_it, ft_rev_ite) )
		return ( exitFailedTest("reverse_iterator: relational operator<") );

	// Test operator>
	if ( cmpRevItGreaterThan(std_rev_it, std_rev_ite, ft_rev_it, ft_rev_ite) )
		return ( exitFailedTest("reverse_iterator: relational operator>") );

	// Test operator<=
	if ( cmpRevItLessEqual(std_rev_it, std_rev_ite, ft_rev_it, ft_rev_ite) )
		return ( exitFailedTest("reverse_iterator: relational operator<=") );

	// Test operator>=
	if ( cmpRevItGreaterEqual(std_rev_it, std_rev_ite, ft_rev_it, ft_rev_ite) )
		return ( exitFailedTest("reverse_iterator: relational operator>=") );

	return (0);
}
