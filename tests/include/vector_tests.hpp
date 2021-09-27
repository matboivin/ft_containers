/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/27 14:13:07 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTS_HPP
#define VECTOR_TESTS_HPP

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "tests.hpp"
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
	for ( typename Vec::const_iterator it = v.begin();
		  it != v.end();
		  ++it ) {

		std::cout << *it;
		if ( it != (v.end() - 1) )
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
int	cmpVecIterator( void );

/*
 * Capacity
 */

int	cmpVecEmpty( void );
int	cmpVecSize( void );
int	cmpVecResize( void );
int	cmpVecMaxSize( void );
int	cmpVecCapacity( void );
int	cmpVecReserve( void );

/*
 * Element access
 */

int	cmpVecAt( void );

/*
 * Non-member operator overloads
 */

int	cmpVecRelationalOps( void );

/*
 * Run all vector tests
 */

int	testVector( void );

#endif
