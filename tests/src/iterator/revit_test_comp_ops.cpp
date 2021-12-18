/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revit_test_comp_ops.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:51:13 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/02 14:38:52 by mboivin          ###   ########.fr       */
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
	void	test_revit_non_mb_comp_ops(void)
	{
		std::cout << "TEST: Comparison operators \n\n";

		explain_test("Operators to make comparison between two reverse iterators.");

		int	arr[10];

		// fill test array
		for ( int i = 0; i < 10; i++ )
			arr[i] = i;

		reverse_iterator<int*>	rev_it(arr + 1);
		reverse_iterator<int*>	rev_ite(arr + 10);

		std::cout << std::boolalpha
				  << "(rev_it == rev_ite) ? " << (rev_it == rev_ite)
				  << "\n(rev_it != rev_ite) ? " << (rev_it != rev_ite)
				  << "\n(rev_it > rev_ite)  ? " << (rev_it > rev_ite)
				  << "\n(rev_it < rev_ite)  ? " << (rev_it < rev_ite)
				  << "\n(rev_it <= rev_ite) ? " << (rev_it <= rev_ite)
				  << "\n(rev_it >= rev_ite) ? " << (rev_it >= rev_ite)
				  << "\n\n";

		assert((rev_it == rev_ite) == false);
		assert(rev_it != rev_ite);
		assert(rev_it > rev_ite);
		assert((rev_it < rev_ite) == false);
		assert((rev_it <= rev_ite) == false);
		assert(rev_it >= rev_ite);
	}
}
