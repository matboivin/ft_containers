/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 16:30:44 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTS_HPP
#define VECTOR_TESTS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <vector.hpp>

/*
 * Display the vector size, capacity and content
 */

template< typename Vec >
static void	displayInfos( const Vec& v, const std::string& title="vector" ) {

	std::cout << title
			  << "\n- size:        " << v.size()
			  << "\n- capacity:    " << v.capacity()
			  << "\n- contents:\n";

	if ( v.size() ) {

		for ( std::size_t i = 0; i < v.size(); i++ )
			std::cout << v[i] << ' ';
		std::cout << '\n';
	}
	std::cout << std::endl;
}

/*
 * Test launchers
 */

void	cmpDefaultConstructors( void );
void	cmpFillConstructors( void );
void	cmpCopyAssign( void );

int		testVector( void );

#endif
