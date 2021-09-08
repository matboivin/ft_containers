/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:05:41 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 18:32:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "test_utils.hpp"
#include "vector.hpp"
#include "vector_tests.hpp"

/*
 * empty
 * size
 * resize
 * max_size
 * capacity
 * reserve
 */

/*
 * Compare empty
 */

int	cmpVecEmpty( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ Capacity methods: empty\n\n"
				 "TEST 1: size equal to zero\n\n"
			  << COL_RESET;

	int	ret = 0;

	// Create two default vectors (size == 0)
	std::vector<int>	vec1;
	ft::vector<int>		ft_vec1;

	std::cout << std::endl;

	// Retrieve if they are empty or not
	bool	vec_is_empty = vec1.empty();
	bool	ft_vec_is_empty = ft_vec1.empty();

	// Display std::vector infos + is empty
	displayInfos(vec1, "std::vector 1");
	std::cout << COL_BLUE << "Is std::vector 1 empty? " << COL_RESET
			  << std::boolalpha << vec_is_empty << "\n\n";

	// Display ft::vector infos + is empty
	displayInfos(ft_vec1, "ft::vector 1");
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
	std::cout << COL_BLUE_B << "\nTEST2: size not zero\n\n" << COL_RESET;

	// Create two vectors of size 10
	std::vector<int>	vec2(10);
	ft::vector<int>		ft_vec2(10);

	std::cout << std::endl;

	// Retrieve if they are empty or not
	vec_is_empty = vec2.empty();
	ft_vec_is_empty = ft_vec2.empty();

	// Display std::vector infos + is empty
	displayInfos(vec2, "std::vector 2");
	std::cout << COL_BLUE << "Is std::vector 2 empty? " << COL_RESET
			  << std::boolalpha << vec_is_empty << "\n\n";

	// Display ft::vector infos + is empty
	displayInfos(ft_vec2, "ft::vector 2");
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
 * Compare empty
 */
