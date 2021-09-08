/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:05:41 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 18:48:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "test_utils.hpp"
#include "vector.hpp"
#include "vector_tests.hpp"

/*
 * List of capacity methods:
 *
 * empty
 * size
 * resize
 * max_size
 * capacity
 * reserve
 */

/*
 * Compare empty
 *
 * This method returns true if the vector is empty. False otherwise.
 */

int	cmpVecEmpty( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ Capacity member function: empty()\n\n" << COL_RESET;

	showTestInfos("This member function returns true if the vector is empty. False otherwise.");

	std::cout << COL_BLUE_B << "______ TEST 1: size equal to zero\n\n" << COL_RESET;

	int	ret = 0;

	// Create two default vectors (size == 0)
	std::vector<int>	vec1;
	ft::vector<int>		ft_vec1;

	std::cout << std::endl;

	// Retrieve if they are empty or not
	bool	vec_is_empty = vec1.empty();
	bool	ft_vec_is_empty = ft_vec1.empty();

	// Display std::vector infos + is empty
	displayVecInfos(vec1, "std::vector 1");
	std::cout << COL_BLUE << "Is std::vector 1 empty? " << COL_RESET
			  << std::boolalpha << vec_is_empty << "\n\n";

	// Display ft::vector infos + is empty
	displayVecInfos(ft_vec1, "ft::vector 1");
	std::cout << COL_BLUE << "Is ft::vector 1 empty? " << COL_RESET
			  << std::boolalpha << ft_vec_is_empty << "\n\n";

	// Print if the results are the same or not between original and ft::vector
	if ( vec_is_empty == ft_vec_is_empty ) {
		std::cout << COL_GREEN_B << "[OK] Same results" << COL_RESET << std::endl;
	}
	else {

		std::cout << COL_RED_B << "[KO] Different results" << COL_RESET << std::endl;
		return (1);
	}

	// Second test where size is not zero
	std::cout << COL_BLUE_B << "\n______ TEST2: size not zero\n\n" << COL_RESET;

	// Create two vectors of size 10
	std::vector<int>	vec2(10);
	ft::vector<int>		ft_vec2(10);

	std::cout << std::endl;

	// Retrieve if they are empty or not
	vec_is_empty = vec2.empty();
	ft_vec_is_empty = ft_vec2.empty();

	// Display std::vector infos + is empty
	displayVecInfos(vec2, "std::vector 2");
	std::cout << COL_BLUE << "Is std::vector 2 empty? " << COL_RESET
			  << std::boolalpha << vec_is_empty << "\n\n";

	// Display ft::vector infos + is empty
	displayVecInfos(ft_vec2, "ft::vector 2");
	std::cout << COL_BLUE << "Is ft::vector 2 empty? " << COL_RESET
			  << std::boolalpha << ft_vec_is_empty << "\n\n";

	// Print if the results are the same or not between original and ft::vector
	if ( vec_is_empty == ft_vec_is_empty ) {
		std::cout << COL_GREEN_B << "[OK] Same results" << COL_RESET << std::endl;
	}
	else {

		std::cout << COL_RED_B << "[KO] Different results" << COL_RESET << std::endl;
		return (1);
	}

	std::cout << std::endl;

	return (ret);
}

/*
 * Compare size
 *
 * This method returns the number of elements in the vector
 */

int	cmpVecSize( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ Capacity methods: size()\n\n" << COL_RESET;

	showTestInfos("This member function returns the number of elements in the vector.");

	// Create two vectors of size 42
	std::vector<int>	vec(42);
	ft::vector<int>		ft_vec(42);

	std::cout << std::endl;

	// Retrieve their size
	std::size_t	vec_size = vec.size();
	std::size_t	ft_vec_size = ft_vec.size();

	// Display sizes
	std::cout << COL_BLUE << "std::vector size is: " << COL_RESET << vec_size << "\n\n";
	std::cout << COL_BLUE << "ft::vector size: " << COL_RESET << ft_vec_size<< "\n\n";

	// Print if the results are the same or not between original and ft::vector
	if ( vec_size == ft_vec_size ) {
		std::cout << COL_GREEN_B << "[OK] Same results" << COL_RESET << std::endl;
	}
	else {

		std::cout << COL_RED_B << "[KO] Different results" << COL_RESET << std::endl;
		return (1);
	}

	std::cout << std::endl;

	return (0);
}
