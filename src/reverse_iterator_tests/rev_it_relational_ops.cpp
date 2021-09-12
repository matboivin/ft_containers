/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_it_relational_ops.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:33:44 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/12 17:32:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "test_utils.hpp"
#include "reverse_iterator_tests.hpp"

/*
 * Test operator==
 */

static int	cmpRevItEqualTo( std::reverse_iterator<int*> std_it,
							 std::reverse_iterator<int*> std_ite,
							 ft::reverse_iterator<int*> ft_it,
							 ft::reverse_iterator<int*> ft_ite ) {

	std::cout << COL_BLUE_B
			  << "\n______ Test operator== (equal to)\n\n" << COL_RESET;

	bool	std_res = (std_it == std_ite);
	bool	ft_res = (ft_it == ft_ite);

	std::cout << std::boolalpha
			  << COL_BLUE << "std::it == std::ite ? " << COL_RESET << std_res
			  << COL_BLUE << " \nft::it == ft::ite ?   " << COL_RESET << ft_res << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( cmpResults(std_res == ft_res) )
		return (1);

	std_res = (std_it == std_it);
	ft_res = (ft_it == ft_it);

	std::cout << std::boolalpha
			  << COL_BLUE << "std::it == std::it ? " << COL_RESET << std_res
			  << COL_BLUE << " \nft::it == ft::it ?   " << COL_RESET << ft_res << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( cmpResults(std_res == ft_res) )
		return (1);

	return (0);
}

/*
 * Test operator!=
 */

static int	cmpRevItNotEqualTo( std::reverse_iterator<int*> std_it,
							 std::reverse_iterator<int*> std_ite,
							 ft::reverse_iterator<int*> ft_it,
							 ft::reverse_iterator<int*> ft_ite ) {

	std::cout << COL_BLUE_B
			  << "\n______ Test operator!= (not equal to)\n\n" << COL_RESET;

	bool	std_res = (std_it != std_ite);
	bool	ft_res = (ft_it != ft_ite);

	std::cout << std::boolalpha
			  << COL_BLUE << "std::it != std::ite ? " << COL_RESET << std_res
			  << COL_BLUE << " \nft::it != ft::ite ?   " << COL_RESET << ft_res << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( cmpResults(std_res == ft_res) )
		return (1);

	std_res = (std_it != std_it);
	ft_res = (ft_it != ft_it);

	std::cout << std::boolalpha
			  << COL_BLUE << "std::it != std::it ? " << COL_RESET << std_res
			  << COL_BLUE << " \nft::it != ft::it ?   " << COL_RESET << ft_res << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( cmpResults(std_res == ft_res) )
		return (1);

	return (0);
}

/*
 * Test operator<
 */

static int	cmpRevItLessThan( std::reverse_iterator<int*> std_it,
							  std::reverse_iterator<int*> std_ite,
							  ft::reverse_iterator<int*> ft_it,
							  ft::reverse_iterator<int*> ft_ite ) {

	std::cout << COL_BLUE_B
			  << "\n______ Test operator< (less than)\n\n" << COL_RESET;

	bool	std_res = (std_it < std_ite);
	bool	ft_res = (ft_it < ft_ite);

	std::cout << std::boolalpha
			  << COL_BLUE << "std::it < std::ite ? " << COL_RESET << std_res
			  << COL_BLUE << " \nft::it < ft::ite ?   " << COL_RESET << ft_res << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( cmpResults(std_res == ft_res) )
		return (1);

	std_res = (std_it < std_it);
	ft_res = (ft_it < ft_it);

	std::cout << std::boolalpha
			  << COL_BLUE << "std::it < std::it ? " << COL_RESET << std_res
			  << COL_BLUE << " \nft::it < ft::it ?   " << COL_RESET << ft_res << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( cmpResults(std_res == ft_res) )
		return (1);

	return (0);
}

/*
 * Test operator>
 */

static int	cmpRevItGreaterThan( std::reverse_iterator<int*> std_it,
								 std::reverse_iterator<int*> std_ite,
								 ft::reverse_iterator<int*> ft_it,
								 ft::reverse_iterator<int*> ft_ite ) {

	std::cout << COL_BLUE_B
			  << "\n______ Test operator> (greater than)\n\n" << COL_RESET;

	bool	std_res = (std_it > std_ite);
	bool	ft_res = (ft_it > ft_ite);

	std::cout << std::boolalpha
			  << COL_BLUE << "std::it > std::ite ? " << COL_RESET << std_res
			  << COL_BLUE << " \nft::it > ft::ite ?   " << COL_RESET << ft_res << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( cmpResults(std_res == ft_res) )
		return (1);

	std_res = (std_it > std_it);
	ft_res = (ft_it > ft_it);

	std::cout << std::boolalpha
			  << COL_BLUE << "std::it > std::it ? " << COL_RESET << std_res
			  << COL_BLUE << " \nft::it > ft::it ?   " << COL_RESET << ft_res << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( cmpResults(std_res == ft_res) )
		return (1);

	return (0);
}

/*
 * Test operator<=
 */

static int	cmpRevItLessEqual( std::reverse_iterator<int*> std_it,
							   std::reverse_iterator<int*> std_ite,
							   ft::reverse_iterator<int*> ft_it,
							   ft::reverse_iterator<int*> ft_ite ) {

	std::cout << COL_BLUE_B
			  << "\n______ Test operator<= (less than or equal to)\n\n" << COL_RESET;

	bool	std_res = (std_it <= std_ite);
	bool	ft_res = (ft_it <= ft_ite);

	std::cout << std::boolalpha
			  << COL_BLUE << "std::it <= std::ite ? " << COL_RESET << std_res
			  << COL_BLUE << " \nft::it <= ft::ite ?   " << COL_RESET << ft_res << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( cmpResults(std_res == ft_res) )
		return (1);

	std_res = (std_it <= std_it);
	ft_res = (ft_it <= ft_it);

	std::cout << std::boolalpha
			  << COL_BLUE << "std::it <= std::it ? " << COL_RESET << std_res
			  << COL_BLUE << " \nft::it <= ft::it ?   " << COL_RESET << ft_res << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( cmpResults(std_res == ft_res) )
		return (1);

	return (0);
}

/*
 * Test operator>=
 */

static int	cmpRevItGreaterEqual( std::reverse_iterator<int*> std_it,
								  std::reverse_iterator<int*> std_ite,
								  ft::reverse_iterator<int*> ft_it,
								  ft::reverse_iterator<int*> ft_ite ) {

	std::cout << COL_BLUE_B
			  << "\n______ Test operator>= (greater than or equal to)\n\n" << COL_RESET;

	bool	std_res = (std_it >= std_ite);
	bool	ft_res = (ft_it >= ft_ite);

	std::cout << std::boolalpha
			  << COL_BLUE << "std::it >= std::ite ? " << COL_RESET << std_res
			  << COL_BLUE << " \nft::it >= ft::ite ?   " << COL_RESET << ft_res << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( cmpResults(std_res == ft_res) )
		return (1);

	std_res = (std_it >= std_it);
	ft_res = (ft_it >= ft_it);

	std::cout << std::boolalpha
			  << COL_BLUE << "std::it >= std::it ? " << COL_RESET << std_res
			  << COL_BLUE << " \nft::it >= ft::it ?   " << COL_RESET << ft_res << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( cmpResults(std_res == ft_res) )
		return (1);

	return (0);
}

/*
 * Compare relational operators
 */

int	cmpRevItRelationalOps( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ Relational operators\n\n"
			  << COL_RESET;

	showTestInfos("Operators to make comparison between two reverse iterators.");

	int	arr[10];

	// fill test array
	for ( int i = 0; i < 10; i++ )
		arr[i] = i;

	// Original
	std::reverse_iterator<int*>	std_it(arr + 1);
	std::reverse_iterator<int*>	std_ite(arr + 10);

	// ft
	ft::reverse_iterator<int*>	ft_it(arr + 1);
	ft::reverse_iterator<int*>	ft_ite(arr + 10);
	std::cout << std::endl;

	std::cout << "std::it:  " << *std_it << "\tft::it:  " << *ft_it
			  << "\nstd::ite: " << *std_ite << "\tft::ite: " << *ft_ite << std::endl;

	// Test operator==
	if ( cmpRevItEqualTo(std_it, std_ite, ft_it, ft_ite) )
		return (1);

	// Test operator!=
	if ( cmpRevItNotEqualTo(std_it, std_ite, ft_it, ft_ite) )
		return (1);

	// Test operator<
	if ( cmpRevItLessThan(std_it, std_ite, ft_it, ft_ite) )
		return (1);

	// Test operator>
	if ( cmpRevItGreaterThan(std_it, std_ite, ft_it, ft_ite) )
		return (1);

	// Test operator<=
	if ( cmpRevItLessEqual(std_it, std_ite, ft_it, ft_ite) )
		return (1);

	// Test operator>=
	if ( cmpRevItGreaterEqual(std_it, std_ite, ft_it, ft_ite) )
		return (1);

	return (0);
}
