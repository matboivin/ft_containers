/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revit_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:49:29 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 18:30:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "tests.hpp"
#include "revit_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_revit(void)
	{
		#if defined(TEST_FT)
		std::cout << std::setw(42) << " MY REVERSE ITERATOR \n\n";
		#else
		std::cout << std::setw(42) << " ORIGINAL REVERSE ITERATOR \n\n";
		#endif

		// construct/assign
		test_revit_default_ctor();
		test_revit_init_ctor();
		test_revit_copy_ctor();

		// element access
		test_revit_indirection();
		test_revit_pointer();
		test_revit_subcript();

		// increment/decrement
		test_revit_increment();
		test_revit_decrement();
		test_revit_advance();
		test_revit_addition();
		test_revit_retrocede();
		test_revit_subtract();

		// non-member functions
		test_revit_non_mb_comp_ops();
		test_revit_non_mb_add();
		test_revit_non_mb_sub();
	}
}
