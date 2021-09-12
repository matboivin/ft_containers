/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator_tests.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:32:00 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/12 17:03:38 by mboivin          ###   ########.fr       */
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

int	cmpRevItAssignmentOperator( void );

/*
 * advance/decrease
 */

int	cmpRevItIncrement( void );
int	cmpRevItDecrement( void );

/*
 * Relational operators
 */

int	cmpRevItRelationalOps( void );

/*
 * Run all reverse iterator tests
 */

int	testReverseIterator( void );

#endif
