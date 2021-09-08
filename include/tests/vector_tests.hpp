/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 19:07:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTS_HPP
#define VECTOR_TESTS_HPP

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "test_utils.hpp"

/*
 * Display the vector size, capacity and content
 */

template< typename Vec >
static void	displayVecInfos( const Vec& v, const std::string& title="vector" ) {

	std::cout << title
			  << "\n- size:        " << v.size()
			  << "\n- capacity:    " << v.capacity()
			  << "\n- contents:";
			
	if ( !v.size() ) {

		std::cout << COL_RED << " (empty)\n\n" << COL_RESET;
		return ;
	}

	std::cout << '\n';
	for ( std::size_t i = 0; i < v.size(); i++ )
		std::cout << v[i] << ' ';

	std::cout << "\n\n";
}

/*
 * Construct/Destroy/Assign
 */

void	cmpVecDefaultConstructor( void );
void	cmpVecFillConstructor( void );
void	cmpVecCopyConstructor( void );
void	cmpVecAssignmentOperator( void );

/*
 * Capacity
 */

int		cmpVecEmpty( void );
int		cmpVecSize( void );
// int		cmpVecResize( void );
int		cmpVecMaxSize( void );
int		cmpCapacity( void );

int		testVector( void );

#endif
