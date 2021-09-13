/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator_tests.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:32:00 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/13 16:52:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include "test_utils.hpp"
#include "utils.hpp"

/*
 * Construct/Destroy/Assign
 */

void	cmpRevItDefaultConstructor( void );
void	cmpRevItInitConstructor( void );
void	cmpRevItCopyConstructor( void );

/*
 * element access
 */
int	cmpRevItSubscriptingOp( void );

/*
 * advance/decrease
 */

int	cmpRevItAdvDecr( void );
int	cmpRevItIncrement( void );
int	cmpRevItDecrement( void );
int	cmpRevItAdvanceOp( void );
int	cmpRevItRetrocedeOp( void );
int	cmpRevItAdditionOp( void );
int	cmpRevItSubtractOp( void );

/*
 * Relational operators
 */

int	cmpRevItRelationalOps( void );

/*
 * Run all reverse iterator tests
 */

int	testReverseIterator( void );

#endif
