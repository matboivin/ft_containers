/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator_tests.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:32:00 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/12 16:27:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include "test_utils.hpp"
#include "utils.hpp"

/*
 * Assign
 */

void	cmpRevItAssignmentOperator( std::reverse_iterator<int*> std_it,
									std::reverse_iterator<int*> std_ite,
									ft::reverse_iterator<int*> ft_it,
									ft::reverse_iterator<int*> ft_ite );

/*
 * Relational operators
 */

int	cmpRevItRelationalOps( std::reverse_iterator<int*> std_it,
						   std::reverse_iterator<int*> std_ite,
						   ft::reverse_iterator<int*> ft_it,
						   ft::reverse_iterator<int*> ft_ite );

/*
 * Run all reverse iterator tests
 */

int	testReverseIterator( void );

#endif
