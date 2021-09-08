/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/08 18:47:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include <iostream>
#include <string>

#define COL_RESET   "\033[0m"
#define COL_BLUE    "\033[0;34m"
#define COL_BLUE_B  "\033[1;34m"
#define COL_GREEN   "\033[0;32m"
#define COL_GREEN_B "\033[1;32m"
#define COL_RED     "\033[0;31m"
#define COL_RED_B   "\033[1;31m"

std::string	strToLower( std::string str );
void		showTestInfos( const std::string& msg );
int			continueTests( const std::string& next_test );

#endif
