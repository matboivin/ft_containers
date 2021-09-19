/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:05:41 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/19 19:37:24 by mboivin          ###   ########.fr       */
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
 * This member function returns true if the vector is empty. False otherwise.
 */

int	cmpVecEmpty( void ) {

	std::cout << COL_BLUE_B
			  << "\n__________ Capacity method: empty __________\n\n"
			  << COL_RESET;

	explainUnit("This member function returns true if the vector is empty.\n"
				"False otherwise.");

	std::cout << COL_BLUE_B << "_ TEST 1: size equal to zero\n\n" << COL_RESET;

	// Create two default vectors (size == 0)
	std::vector<int>	vec1;
	ft::vector<int>		ft_vec1;

	std::cout << std::endl;

	// Retrieve if they are empty or not
	bool	vec_is_empty = vec1.empty();
	bool	ft_vec_is_empty = ft_vec1.empty();

	// Display std::vector infos + is empty
	displayVecInfos(vec1, "std::vector 1");
	std::cout << "Is std::vector 1 empty? " << std::boolalpha
			  << COL_WHITE_B << vec_is_empty << COL_RESET << "\n\n";

	// Display ft::vector infos + is empty
	displayVecInfos(ft_vec1, "ft::vector 1");
	std::cout << "Is ft::vector 1 empty? " << std::boolalpha
			  << COL_WHITE_B << ft_vec_is_empty << COL_RESET << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(vec_is_empty == ft_vec_is_empty) )
		return (1);

	// Second test where size is not zero
	std::cout << COL_BLUE_B << "\n_ TEST2: size not zero\n\n" << COL_RESET;

	// Create two vectors of size 10
	std::vector<int>	vec2(10);
	ft::vector<int>		ft_vec2(10);

	std::cout << std::endl;

	// Retrieve if they are empty or not
	vec_is_empty = vec2.empty();
	ft_vec_is_empty = ft_vec2.empty();

	// Display std::vector infos + is empty
	displayVecInfos(vec2, "std::vector 2");
	std::cout << "Is std::vector 2 empty? " << std::boolalpha
			  << COL_WHITE_B << vec_is_empty << COL_RESET << "\n\n";

	// Display ft::vector infos + is empty
	displayVecInfos(ft_vec2, "ft::vector 2");
	std::cout << "Is ft::vector 2 empty? " << std::boolalpha
			  << COL_WHITE_B << ft_vec_is_empty << COL_RESET << "\n\n";

	// Check if the results are the same or not between original and ft
	return ( displayTestResult(vec_is_empty == ft_vec_is_empty) );
}

/*
 * Compare size
 *
 * This member function returns the number of elements in the vector
 */

int	cmpVecSize( void ) {

	std::cout << COL_BLUE_B
			  << "\n___________ Capacity method: size __________\n\n"
			  << COL_RESET;

	explainUnit("This member function returns the number of elements\n"
				"in the vector.");

	// Create two vectors of size 42
	std::vector<int>	vec(42);
	ft::vector<int>		ft_vec(42);

	std::cout << std::endl;

	// Retrieve their size
	std::size_t	vec_size = vec.size();
	std::size_t	ft_vec_size = ft_vec.size();

	// Display sizes
	std::cout << "std::vector size is: "
			  << COL_WHITE_B << vec_size << COL_RESET << '\n'
			  << "ft::vector size is:  "
			  << COL_WHITE_B << ft_vec_size << COL_RESET << "\n\n";

	// Check if the results are the same or not between original and ft
	return ( displayTestResult(vec_size == ft_vec_size) );
}

/*
 * Compare resize
 *
 * This member function resizes the container so that it contains n elements.
 */

int	cmpVecResize( void ) {

	std::cout << COL_BLUE_B
			  << "\n___________ Capacity method: resize ________\n\n"
			  << COL_RESET;

	explainUnit("This member function resizes the container so that\n"
				"it contains n elements.");

	int	errors = 0;

	// Create two vectors
	std::vector<int>	vec;
	ft::vector<int>		ft_vec;
	std::cout << std::endl;

	for ( int i = 1; i < 10 ; i++ )
		vec.push_back(i);

	vec.resize(5);
	vec.resize(8,100);
	vec.resize(12);

	for ( int i = 1; i < 10 ; i++ )
		ft_vec.push_back(i);

	ft_vec.resize(5);
	ft_vec.resize(8,100);
	ft_vec.resize(12);

	// Display results
	displayVecInfos(vec, "std::vector");
	displayVecInfos(ft_vec, "ft::vector");

	// Compare results
	for ( int i = 1; i < 12 ; i++ ) {

		if ( vec[i] != ft_vec[i] )
			errors += 1;
	}

	// Same size doesn't set any values
	// vec.resize(12, 42);
	// ft_vec.resize(12, 42);

	// // Display results
	// displayVecInfos(vec, "std::vector");
	// displayVecInfos(ft_vec, "ft::vector");

	// // Compare results
	// for ( int i = 1; i < 12 ; i++ ) {

	// 	if ( vec[i] != ft_vec[i] )
	// 		errors += 1;
	// }

	// Check if the results are the same or not between original and ft
	return ( displayTestResult(!errors) );
}

/*
 * Compare max_size
 *
 * This member function returns the maximum number of elements that the vector can hold
 */

int	cmpVecMaxSize( void ) {

	std::cout << COL_BLUE_B
			  << "\n_________ Capacity method: max_size ________\n\n"
			  << COL_RESET;

	explainUnit("This member function returns the maximum number of elements\n"
				"that the vector can hold.");

	// First test
	std::cout << COL_BLUE_B << "\n_ TEST1: Vectors of int\n\n" << COL_RESET;

	// Create two vectors of size 42
	std::vector<int>	vec1(42);
	ft::vector<int>		ft_vec1(42);

	std::cout << std::endl;

	// Retrieve their max size
	std::size_t	vec_max_size = vec1.max_size();
	std::size_t	ft_vec_max_size = ft_vec1.max_size();

	// Display sizes
	std::cout <<  "std::vector max size is: "
			  << COL_WHITE_B << vec_max_size << COL_RESET << '\n'
			  << "ft::vector max size is:  "
			  << COL_WHITE_B << ft_vec_max_size << COL_RESET << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(vec_max_size == ft_vec_max_size) )
		return (1);

	// Second test with vectors of char
	std::cout << COL_BLUE_B << "\n_ TEST2: Vectors of chars\n\n" << COL_RESET;

	// Create two vectors of size 42
	std::vector<char>	vec2(42);
	ft::vector<char>	ft_vec2(42);

	std::cout << std::endl;

	// Retrieve their max size
	vec_max_size = vec2.max_size();
	ft_vec_max_size = ft_vec2.max_size();

	// Display sizes
	std::cout << "std::vector max size is: "
			  << COL_WHITE_B << vec_max_size << COL_RESET << '\n'
			  << "ft::vector max size is:  "
			  << COL_WHITE_B << ft_vec_max_size << COL_RESET << "\n\n";

	// Check if the results are the same or not between original and ft
	return ( displayTestResult(vec_max_size == ft_vec_max_size) );
}

/*
 * Compare capacity
 *
 * This member function returns the size of allocated storage capacity
 */

int	cmpVecCapacity( void ) {

	std::cout << COL_BLUE_B
			  << "\n_________ Capacity method: capacity ________\n\n"
			  << COL_RESET;

	explainUnit("This member function returns the size of allocated\n"
				"storage capacity.");

	// First test
	std::cout << COL_BLUE_B << "\n_ TEST1: Vectors of int\n\n" << COL_RESET;

	// Create two vectors of size 42
	std::vector<int>	vec1(42);
	ft::vector<int>		ft_vec1(42);

	std::cout << std::endl;

	// Retrieve their capacity
	std::size_t	vec_capacity = vec1.capacity();
	std::size_t	ft_vec_capacity = ft_vec1.capacity();

	// Display sizes
	std::cout << "std::vector capacity is: "
			  << COL_WHITE_B << vec_capacity << COL_RESET << '\n'
			  << "ft::vector capacity is:  "
			  << COL_WHITE_B << ft_vec_capacity << COL_RESET << "\n\n";

	// Check if the results are the same or not between original and ft
	if ( displayTestResult(vec_capacity == ft_vec_capacity) )
		return (1);

	// Second test with vectors of char
	std::cout << COL_BLUE_B << "\n_ TEST2: Vectors of chars\n\n" << COL_RESET;

	// Create two vectors of size 42
	std::vector<char>	vec2(42);
	ft::vector<char>	ft_vec2(42);

	std::cout << std::endl;

	// Retrieve their capacity
	vec_capacity = vec2.capacity();
	ft_vec_capacity = ft_vec2.capacity();

	// Display sizes
	std::cout << "std::vector capacity is: "
			  << COL_WHITE_B << vec_capacity << COL_RESET << '\n'
			  << "ft::vector capacity is:  "
			  << COL_WHITE_B << ft_vec_capacity << COL_RESET << "\n\n";

	// Check if the results are the same or not between original and ft
	return ( displayTestResult(vec_capacity == ft_vec_capacity) );
}

/*
 * Compare reserve
 *
 * This member function requests that the vector capacity be at least enough
 * to contain n elements
 */

int	cmpVecReserve( void ) {

	std::cout << COL_BLUE_B
			  << "\n_________ Capacity method: reserve _________\n\n"
			  << COL_RESET;

	explainUnit("This member function requests that the vector capacity\n"
				"be at least enough to contain n elements.");

	// Create two vectors of size 1
	std::vector<int>	vec(1);
	ft::vector<int>		ft_vec(1);

	std::cout << std::endl;

	// Retrieve their capacity
	std::size_t	vec_capacity = vec.capacity();
	std::size_t	ft_vec_capacity = ft_vec.capacity();

	// Display their informations
	displayVecInfos(vec, "std::vector");
	displayVecInfos(ft_vec, "ft::vector");
	std::cout << "std::vector capacity is: "
			  << COL_WHITE_B << vec_capacity << COL_RESET << '\n'
			  << "ft::vector capacity is:  "
			  << COL_WHITE_B << ft_vec_capacity << COL_RESET << "\n\n";

	std::cout << COL_BLUE_B << "AFTER\n\n" << COL_RESET;

	// reserve
	vec.reserve(42);
	ft_vec.reserve(42);

	// Retrieve new capacity
	vec_capacity = vec.capacity();
	ft_vec_capacity = ft_vec.capacity();

	// Display their informations after calling reserve()
	displayVecInfos(vec, "std::vector");
	displayVecInfos(ft_vec, "ft::vector");
	std::cout << "std::vector capacity is: "
			  << COL_WHITE_B << vec_capacity << COL_RESET << '\n'
			  << "ft::vector capacity is:  "
			  << COL_WHITE_B << ft_vec_capacity << COL_RESET << "\n\n";

	// Check if the results are the same or not between original and ft
	return ( displayTestResult(vec_capacity == ft_vec_capacity) );
}
