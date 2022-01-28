/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests_comp_ops.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:54:38 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/28 15:54:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "tests.hpp"
#include "set_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_set_non_mb_comp_ops(void)
	{
		std::cout << "TEST: Non-member comparison operators \n\n";

		explain_test("Operators to make comparison between two trees.");

		// create trees
		int_set	s1;
		int_set	s2;
		int_set	s3;

		for (int i = 0; i < 42; ++i)
			s1.insert(rand());

		s3.insert(rand());

		// copy of s3
		int_set	s4(s3);

		std::cout << std::boolalpha
				  << "(s1 > s2 && s1 < s3) ? " << (s1 > s2 && s1 < s3)
				  << "\n(s1 < s2)   ? " << (s1 < s2)
				  << "\n(s3 != s2)  ? " << (s3 != s2)
				  << "\n(s3 == s4)  ? " << (s3 == s4)
				  << "\n(s3 != s4)  ? " << (s3 != s4)
				  << "\n(s1 != s4)  ? " << (s1 != s4)
				  << "\n(s3 >= s4)  ? " << (s3 >= s4)
				  << "\n(s3 <= s4)  ? " << (s3 <= s4)
				  << "\n\n";

		assert(s1 > s2 && s1 < s3);
		assert((s1 < s2) == false);
		assert(s3 != s2);
		assert(s3 == s4);
		assert((s3 != s4) == false);
		assert(s1 != s4);
		assert(s3 >= s4);
		assert(s3 <= s4);
	}
}
