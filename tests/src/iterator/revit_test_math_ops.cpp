/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revit_test_math_ops.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:51:13 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 16:14:12 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "tests.hpp"
#include "revit_tests.hpp"
#include <vector>

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_revit_non_add(void)
	{
		std::cout << "TEST: Non-member operator+ \n\n";

		explainTest("Returns a reverse iterator pointing to the element located "
					"n positions away from the element pointed to by rev_it.");

		int	n = 3;

		// iterator type pointing on vector of int
		typedef std::vector<int>::iterator	iter_type;

		// create test vector
		std::vector<int>	vec;

		for ( int i = 0; i < 10; i++ )
			vec.push_back(i);

		// create iterators
		reverse_iterator<iter_type>	ite(vec.end());
		reverse_iterator<iter_type>	rev_it;

		rev_it = n + ite;

		std::cout << "*rev_it = " << *rev_it << "\n\n";
	}

	void	test_revit_non_sub(void)
	{
		std::cout << "TEST: Non-member operator- \n\n";

		explainTest("Computes the distance between two reverse iterators. "
					"Returns the same as subtracting lhs's base iterator "
					"from rhs's base iterator");

		// iterator type pointing on vector of int
		typedef std::vector<int>::iterator	iter_type;

		// create test vector
		std::vector<int>	vec;

		for ( int i = 0; i < 10; i++ )
			vec.push_back(i);

		iter_type	it = vec.begin();
		iter_type	ite = vec.end();

		reverse_iterator<iter_type>	rev_end(it);
		reverse_iterator<iter_type>	rev_start(ite);

		std::size_t	count = rev_end - rev_start;

		std::cout << "vector has " << count << " elements.\n\n";
	}
}
