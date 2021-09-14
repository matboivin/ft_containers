/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/14 19:34:06 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTS_HPP
#define VECTOR_TESTS_HPP

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "test_utils.hpp"
#include "utils.hpp"

/*
 * Display the vector size, capacity and content
 */

template< typename Vec >
static void	displayVecInfos( const Vec& v, const std::string& title="vector" ) {

	std::cout << COL_WHITE_B << title << COL_RESET
			  << "\n- size:      " << v.size()
			  << "\n- capacity:  " << v.capacity()
			  << "\n- contents:  ";
			
	if ( !v.size() ) {

		std::cout << "(empty)\n\n";
		return ;
	}

	std::cout << "[ ";
	for ( std::size_t i = 0; i < v.size(); i++ ) {

		std::cout << v[i];
		if ( i < v.size() - 1 )
			std::cout << ", ";
	}

	std::cout << " ]\n\n";
}

/*
 * Construct/Destroy/Assign
 */

void	cmpVecDefaultConstructor( void );
void	cmpVecFillConstructor( void );
void	cmpVecCopyConstructor( void );
void	cmpVecAssignmentOperator( void );

/*
 * Iterator
 */
int		cmpVecIterator( void );

/*
 * Capacity
 */

int		cmpVecEmpty( void );
int		cmpVecSize( void );
// int		cmpVecResize( void );
int		cmpVecMaxSize( void );
int		cmpVecCapacity( void );
int		cmpVecReserve( void );

/*
 * Run all vector tests
 */

int		testVector( void );

#endif
