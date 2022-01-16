/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revit_test_inc_decr.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:51:13 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/16 23:04:34 by mboivin          ###   ########.fr       */
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
	void	test_revit_increment(void)
	{
		std::cout << "TEST: operator++ \n\n";

		explain_test("Increments iterator position.");

		int	arr[5];

		// fill test array
		for ( int i = 0; i < 5; i++ )
			arr[i] = i;

		std::reverse_iterator<int*>	rev_it(arr + 5);

		std::cout << "*rev_it     = " << *rev_it
				  << "\n*(++rev_it) = " << *(++rev_it) << "\n\n";

		// restore
		rev_it--;

		int	prev = *rev_it;

		std::cout << "*rev_it     = " << *rev_it << std::endl;

		int	res = *(rev_it++);

		assert(res == prev);

		std::cout << "*(std::rev_it++) = " << res
				  << "\n*rev_it     = " << *rev_it << "\n\n";
	}

	void	test_revit_decrement(void)
	{
		std::cout << "TEST: operator-- \n\n";

		explain_test("Decreases iterator position.");

		int	arr[5];

		// fill test array
		for ( int i = 0; i < 5; i++ )
			arr[i] = i;

		std::reverse_iterator<int*>	rev_it(arr + 5);

		std::cout << "*rev_it     = " << *rev_it
				  << "\n*(--rev_it) = " << *(--rev_it) << std::endl;

		// restore
		rev_it++;

		int	prev = *rev_it;

		std::cout << "*rev_it     = " << *rev_it << std::endl;

		int	res = *(rev_it--);

		assert(res == prev);

		std::cout << "*(std::rev_it--) = " << res
				  << "\n*rev_it     = " << *rev_it << "\n\n";
	}

	void	test_revit_advance(void)
	{
		std::cout << "TEST: operator+= \n\n";

		explain_test("Advances the reverse_iterator by n element positions.");

		int	n = 7;
		int	arr[10];

		// fill test array
		for ( int i = 0; i < 10; i++ )
			arr[i] = i;

		// set iterators
		reverse_iterator<int*>	rev_it(arr + 10);

		std::cout << "*rev_it =  " << *rev_it << std::endl;

		rev_it += n;

		std::cout << "*rev_it += " << n << ";"
				  << "\n*rev_it  = " << *rev_it << "\n\n";
	}

	void	test_revit_addition(void)
	{
		std::cout << "TEST: operator+ \n\n";

		explain_test("Returns an iterator pointing to the element n positions away.");

		int	n = 5;
		int	arr[10];

		// fill test array
		for ( int i = 0; i < 10; i++ )
			arr[i] = i;

		// set iterators
		reverse_iterator<int*>	rev_it(arr + 10);

		std::cout << "*rev_it = " << *rev_it << std::endl;

		// storing results
		reverse_iterator<int*>	res = (rev_it + n);

		std::cout << "*(rev_it + " << n << ") = " << *res << "\n\n";
	}

	void	test_revit_retrocede(void)
	{
		std::cout << "TEST: operator-= \n\n";

		explain_test("Decreases the reverse_iterator by n element positions.");

		int	n = 4;
		int	arr[10];

		// fill test array
		for ( int i = 0; i < 10; i++ )
			arr[i] = i;

		// set iterators
		reverse_iterator<int*>	rev_it(arr + 1);

		std::cout << "*rev_it =  " << *rev_it << std::endl;

		rev_it -= n;

		std::cout << "*rev_it -= " << n << ";"
				  << "\n*rev_it  = " << *rev_it << "\n\n";
	}

	void	test_revit_subtract(void)
	{
		std::cout << "TEST: operator- \n\n";

		explain_test("Returns an iterator pointing to the element "
					"n positions before the currently pointed one.");

		int	n = 5;
		int	arr[10];

		// fill test array
		for ( int i = 0; i < 10; i++ )
			arr[i] = i;

		// set iterators
		reverse_iterator<int*>	rev_it(arr + 1);

		std::cout << "*rev_it = " << *rev_it << std::endl;

		// storing results
		reverse_iterator<int*>	res = (rev_it - n);

		std::cout << "*(rev_it - " << n << ") = " << *res << "\n\n";
	}
}
