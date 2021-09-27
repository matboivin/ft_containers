/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/28 00:33:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "tests.hpp"
#include "vector_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_vec_fill_ctor( void )
	{
		clock_t	start = clock();

		vector<int>	vec1(14, 1);
		vector<int>	vec2(5,  2);

		displayElapsedTime(start, clock());

		displayVecInfos(vec1, "vector 1 (14, 1)");
		displayVecInfos(vec2, "vector 2 (5,  2)");
	}

	void	test_vector( void )
	{
		test_vec_fill_ctor();
	}
}
