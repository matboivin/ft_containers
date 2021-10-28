/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revit_tests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:48:39 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 18:29:39 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVIT_TESTS_HPP
#define REVIT_TESTS_HPP

#include <iostream>
#include <string>
#include "tests.hpp"

#if defined(TEST_FT)
# include "iterator.hpp"

namespace ft
#else
# include <iterator>

namespace std
#endif
{
	void	test_revit(void);

	// construct/assign
	void	test_revit_default_ctor(void);
	void	test_revit_init_ctor(void);
	void	test_revit_copy_ctor(void);
	void	test_revit_base(void);

	// element access
	void	test_revit_indirection(void);
	void	test_revit_pointer(void);
	void	test_revit_subcript(void);

	// increment/decrement
	void	test_revit_increment(void);
	void	test_revit_decrement(void);
	void	test_revit_advance(void);
	void	test_revit_addition(void);
	void	test_revit_retrocede(void);
	void	test_revit_subtract(void);

	// non-member functions
	void	test_revit_non_mb_comp_ops(void);
	void	test_revit_non_mb_add(void);
	void	test_revit_non_mb_sub(void);
}

#endif
