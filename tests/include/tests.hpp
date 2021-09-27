/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:45:41 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/25 18:57:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_TEST_HPP
#define OTHER_TEST_HPP

#include <iostream>
#include <string>

std::string	strToLower( std::string str );

void	explainUnit( const std::string& msg );

int	continueTests( const std::string& next_test );
int	displayTestResult( bool succeeded );
int	exitFailedTest( const std::string& test_name );

int	otherTests( void );
int	equalTests( void );
int	lexCmpTests( void );
int	isIntegralTests( void );

#endif
