/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:05:41 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/12 15:35:49 by mboivin          ###   ########.fr       */
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
			  << "\n______________ Capacity member function: empty()\n\n" << COL_RESET;

	showTestInfos("This member function returns true if the vector is empty. False otherwise.");

	std::cout << COL_BLUE_B << "______ TEST 1: size equal to zero\n\n" << COL_RESET;

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

	// Check if the results are the same or not between original and ft::vector
	if ( cmpResults(vec_is_empty == ft_vec_is_empty) )
		return (1);

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

	// Check if the results are the same or not between original and ft::vector
	return ( cmpResults(vec_is_empty == ft_vec_is_empty) );
}

/*
 * Compare size
 *
 * This member function returns the number of elements in the vector
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
	std::cout << COL_BLUE << "std::vector size is: " << COL_RESET
			  << vec_size << '\n'
			  << COL_BLUE << "ft::vector size is:  " << COL_RESET
			  << ft_vec_size << "\n\n";

	// Check if the results are the same or not between original and ft::vector
	return ( cmpResults(vec_size == ft_vec_size) );
}

/*
 * Compare resize
 *
 * This member function resizes the container so that it contains n elements.
 */

// TODO

/*
 * Compare max_size
 *
 * This member function returns the maximum number of elements that the vector can hold
 */

int	cmpVecMaxSize( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ Capacity methods: max_size()\n\n" << COL_RESET;

	showTestInfos("This member function returns the maximum number of elements that the vector can hold.");

	// First test
	std::cout << COL_BLUE_B << "\n______ TEST1: Vectors of int\n\n" << COL_RESET;

	// Create two vectors of size 42
	std::vector<int>	vec1(42);
	ft::vector<int>		ft_vec1(42);

	std::cout << std::endl;

	// Retrieve their max size
	std::size_t	vec_max_size = vec1.max_size();
	std::size_t	ft_vec_max_size = ft_vec1.max_size();

	// Display sizes
	std::cout << COL_BLUE << "std::vector max size is: " << COL_RESET
			  << vec_max_size << '\n'
			  << COL_BLUE << "ft::vector max size is:  " << COL_RESET
			  << ft_vec_max_size << "\n\n";

	// Check if the results are the same or not between original and ft::vector
	if ( cmpResults(vec_max_size == ft_vec_max_size) )
		return (1);

	// Second test with vectors of char
	std::cout << COL_BLUE_B << "\n______ TEST2: Vectors of chars\n\n" << COL_RESET;

	// Create two vectors of size 42
	std::vector<char>	vec2(42);
	ft::vector<char>	ft_vec2(42);

	std::cout << std::endl;

	// Retrieve their max size
	vec_max_size = vec2.max_size();
	ft_vec_max_size = ft_vec2.max_size();

	// Display sizes
	std::cout << COL_BLUE << "std::vector max size is: " << COL_RESET
			  << vec_max_size << '\n'
			  << COL_BLUE << "ft::vector max size is:  " << COL_RESET
			  << ft_vec_max_size << "\n\n";

	// Check if the results are the same or not between original and ft::vector
	return ( cmpResults(vec_max_size == ft_vec_max_size) );
}

/*
 * Compare capacity
 *
 * This member function returns the size of allocated storage capacity
 */

int	cmpVecCapacity( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ Capacity methods: capacity()\n\n" << COL_RESET;

	showTestInfos("This member function returns the size of allocated storage capacity.");

	// First test
	std::cout << COL_BLUE_B << "\n______ TEST1: Vectors of int\n\n" << COL_RESET;

	// Create two vectors of size 42
	std::vector<int>	vec1(42);
	ft::vector<int>		ft_vec1(42);

	std::cout << std::endl;

	// Retrieve their capacity
	std::size_t	vec_capacity = vec1.capacity();
	std::size_t	ft_vec_capacity = ft_vec1.capacity();

	// Display sizes
	std::cout << COL_BLUE << "std::vector capacity is: " << COL_RESET
			  << vec_capacity << '\n'
			  << COL_BLUE << "ft::vector capacity is:  " << COL_RESET
			  << ft_vec_capacity << "\n\n";

	// Check if the results are the same or not between original and ft::vector
	if ( cmpResults(vec_capacity == ft_vec_capacity) )
		return (1);

	// Second test with vectors of char
	std::cout << COL_BLUE_B << "\n______ TEST2: Vectors of chars\n\n" << COL_RESET;

	// Create two vectors of size 42
	std::vector<char>	vec2(42);
	ft::vector<char>	ft_vec2(42);

	std::cout << std::endl;

	// Retrieve their capacity
	vec_capacity = vec2.capacity();
	ft_vec_capacity = ft_vec2.capacity();

	// Display sizes
	std::cout << COL_BLUE << "std::vector capacity is: " << COL_RESET
			  << vec_capacity << '\n'
			  << COL_BLUE << "ft::vector capacity is:  " << COL_RESET
			  << ft_vec_capacity << "\n\n";

	// Check if the results are the same or not between original and ft::vector
	return ( cmpResults(vec_capacity == ft_vec_capacity) );
}

/*
 * Compare reserve
 *
 * This member function requests that the vector capacity be at least enough
 * to contain n elements
 */

int	cmpVecReserve( void ) {

	std::cout << COL_BLUE_B
			  << "\n______________ Capacity methods: reserve()\n\n" << COL_RESET;

	showTestInfos("This member function requests that the vector capacity be at least enough to contain n elements.");

	// Create two vectors of size 1
	std::vector<int>	vec(1);
	ft::vector<int>		ft_vec(1);

	std::cout << std::endl;

	// Display their informations
	displayVecInfos(vec, "std::vector");
	displayVecInfos(ft_vec, "ft::vector");
	std::cout << COL_BLUE << "std::vector capacity is: " << COL_RESET
			  << vec.capacity() << '\n'
			  << COL_BLUE << "ft::vector capacity is:  " << COL_RESET
			  << ft_vec.capacity() << "\n\n";

	std::cout << COL_BLUE_B << "AFTER\n\n" << COL_RESET;

	vec.reserve(42);
	ft_vec.reserve(42);

	// Display their informations after calling reserve()
	displayVecInfos(vec, "std::vector");
	displayVecInfos(ft_vec, "ft::vector");
	std::cout << COL_BLUE << "std::vector capacity is: " << COL_RESET
			  << vec.capacity() << '\n'
			  << COL_BLUE << "ft::vector capacity is:  " << COL_RESET
			  << ft_vec.capacity() << "\n\n";

	// Check if the results are the same or not between original and ft::vector
	return ( cmpResults(vec.capacity() == ft_vec.capacity()) );
}
