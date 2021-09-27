/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits_tests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:54:52 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/25 19:22:07 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <iostream>
#include <type_traits>
#include "type_traits.hpp"
#include "tests.hpp"
#include "utils.hpp"

int	isIntegralTests( void ) {

	std::cout << COL_BLUE_B
			  << "\n________________ is_integral _______________\n\n"
			  << COL_RESET;

	explainUnit("Identifies whether T is an integral type.");

	assert(std::is_integral<bool>::value == ft::is_integral<bool>::value);
	assert(std::is_integral<char>::value == ft::is_integral<char>::value);
	assert(std::is_integral<wchar_t>::value == ft::is_integral<wchar_t>::value);
	assert(std::is_integral<signed char>::value == ft::is_integral<signed char>::value);
	assert(std::is_integral<short int>::value == ft::is_integral<short int>::value);
	assert(std::is_integral<int>::value == ft::is_integral<int>::value);
	assert(std::is_integral<long int>::value == ft::is_integral<long int>::value);
	assert(std::is_integral<long long int>::value == ft::is_integral<long long int>::value);
	assert(std::is_integral<unsigned char>::value == ft::is_integral<unsigned char>::value);
	assert(std::is_integral<unsigned short int>::value == ft::is_integral<unsigned short int>::value);
	assert(std::is_integral<unsigned int>::value == ft::is_integral<unsigned int>::value);
	assert(std::is_integral<unsigned long int>::value == ft::is_integral<unsigned long int>::value);
	assert(std::is_integral<unsigned long long int>::value == ft::is_integral<unsigned long long int>::value);

	assert(std::is_integral<float>::value == ft::is_integral<float>::value);
	assert(std::is_integral<double>::value == ft::is_integral<double>::value);

	return ( displayTestResult(1) );
}
