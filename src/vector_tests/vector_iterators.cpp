/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:32:08 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/14 19:39:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "test_utils.hpp"
#include "iterator.hpp"
#include "vector.hpp"
#include "vector_tests.hpp"

/*
 * Compare iterators
 */

int	cmpVecIterator( void ) {

	std::cout << COL_BLUE_B
			  << "\n_________________ Iterator _________________\n\n"
			  << COL_RESET;

	explainUnit("iterators");

	// iterator type pointing on vector of int
	typedef std::vector<int>::iterator	iter_type;
	typedef ft::vector<int>::iterator	ft_iter_type;

	// Original
	std::cout << COL_BLUE_B << "_ std::vector\n\n" << COL_RESET;

	// create a vector
	std::vector<int>	vec(5);
	// add some numbers to it
	vec.push_back(12);
	vec.push_back(5);
	vec.push_back(42);
	vec.push_back(100);
	vec.push_back(25);

	// create iterators
	iter_type	std_it = vec.begin();
	iter_type	std_ite = vec.end();

	std::cout << "*std::it      = " << *std_it
			  << "\n*(--std::ite) = " << *(--std_ite) << "\n\n";

	// ft::vector
	std::cout << COL_BLUE_B << "_ ft::vector\n\n" << COL_RESET;

	// create a vector
	ft::vector<int>	ft_vec(5);
	std::cout << std::endl;
	// add some numbers to it
	ft_vec.push_back(12);
	ft_vec.push_back(5);
	ft_vec.push_back(42);
	ft_vec.push_back(100);
	ft_vec.push_back(25);

	// create iterators
	ft_iter_type	ft_it = ft_vec.begin();
	ft_iter_type	ft_ite = ft_vec.end();
	std::cout << std::endl;

	std::cout << "*ft::it      = " << *ft_it
			  << "\n*(--ft::ite) = " << *(--ft_ite) << "\n\n";

	return (0);
}
