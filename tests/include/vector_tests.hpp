/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/27 15:25:18 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTS_HPP
#define VECTOR_TESTS_HPP

#include <iostream>
#include <string>
#include "tests.hpp"

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

#endif