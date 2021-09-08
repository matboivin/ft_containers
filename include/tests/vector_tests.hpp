/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 17:18:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTS_HPP
#define VECTOR_TESTS_HPP

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"

#define COL_RESET "\033[0m"
#define COL_BLUE_B "\033[1;34m"
#define COL_RED "\033[0;31m"

/*
 * Display the vector size, capacity and content
 */

template< typename Vec >
static void	displayInfos( const Vec& v, const std::string& title="vector" ) {

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
 * Test launchers
 */

void	cmpDefaultConstructor( void );
void	cmpFillConstructor( void );
void	cmpCopyConstructor( void );
void	cmpAssignmentOperator( void );

int		testVector( void );

#endif
