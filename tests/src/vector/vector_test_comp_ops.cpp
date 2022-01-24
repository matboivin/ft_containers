/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_comp_ops.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:45:35 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 16:56:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "tests.hpp"
#include "vector_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_vec_non_mb_comp_ops(void)
	{
		std::cout << "TEST: Non-member comparison operators \n\n";

		explain_test("Operators to make comparison between two vectors.");

		// create vectors
		vector<int>	vec1;
		vector<int>	vec2;
		vector<int>	vec3;

		vec1.push_back(12);
		vec1.push_back(5);
		vec1.push_back(42);
		vec1.push_back(100);
		vec1.push_back(25);

		vec3.push_back(120);

		vector<int>	vec4(vec3);

		std::cout << std::boolalpha
				  << "(vec1 > vec2 && vec1 < vec3) ? " << (vec1 > vec2 && vec1 < vec3)
				  << "\n(vec1 < vec2)   ? " << (vec1 < vec2)
				  << "\n(vec3 != vec2)  ? " << (vec3 != vec2)
				  << "\n(vec3 == vec4)  ? " << (vec3 == vec4)
				  << "\n(vec3 != vec4)  ? " << (vec3 != vec4)
				  << "\n(vec1 != vec4)  ? " << (vec1 != vec4)
				  << "\n(vec3 >= vec4)  ? " << (vec3 >= vec4)
				  << "\n(vec3 <= vec4)  ? " << (vec3 <= vec4)
				  << "\n\n";

		assert(vec1 > vec2 && vec1 < vec3);
		assert((vec1 < vec2) == false);
		assert(vec3 != vec2);
		assert(vec3 == vec4);
		assert((vec3 != vec4) == false);
		assert(vec1 != vec4);
		assert(vec3 >= vec4);
		assert(vec3 <= vec4);
	}
}
