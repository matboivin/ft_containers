/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_relational_ops.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 00:19:50 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/20 00:29:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <iostream>
#include <vector>
#include "tests.hpp"
#include "iterator.hpp"
#include "vector.hpp"
#include "vector_tests.hpp"

/*
 * Compare relational operators
 */

int	cmpVecRelationalOps( void ) {

	std::cout << COL_BLUE_B
			  << "\n___________ Relational operators ___________\n\n"
			  << COL_RESET;

	explainUnit("Operators to make comparison between two vectors.");

	std::vector<int>	vec1(3,100);
	std::vector<int>	vec2(2,200);

	ft::vector<int>		ft_vec1(3,100);
	ft::vector<int>		ft_vec2(2,200);
	std::cout << std::endl;

	assert( (vec1 == vec2) == (ft_vec1 == ft_vec2) );
	assert( (vec1 != vec2) == (ft_vec1 != ft_vec2) );
	assert( (vec1 < vec2) == (ft_vec1 < ft_vec2) );
	assert( (vec1 > vec2) == (ft_vec1 > ft_vec2) );
	assert( (vec1 <= vec2) == (ft_vec1 <= ft_vec2) );
	assert( (vec1 >= vec2) == (ft_vec1 >= ft_vec2) );

	return (0);
}
