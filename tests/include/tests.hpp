/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:45:41 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 16:35:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
#define TESTS_HPP

#include <assert.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

/*
 * Colors for a more readable output
 */

#define COL_RESET    "\033[0m"
#define COL_WHITE_B  "\033[1;37m"
#define COL_BLUE     "\033[0;34m"
#define COL_BLUE_B   "\033[1;34m"
#define COL_RED      "\033[0;31m"
#define COL_RED_B    "\033[1;31m"
#define COL_GREEN    "\033[0;32m"
#define COL_GREEN_B  "\033[1;32m"
#define COL_YELLOW   "\033[0;33m"
#define COL_YELLOW_B "\033[1;33m"

void		display_elapsed_time(clock_t start, clock_t end);
void		explain_test(const std::string& msg);
int			continue_tests(const std::string& next_test);
int			generate_output(void);
std::string	str_to_lower(std::string str);

#endif
