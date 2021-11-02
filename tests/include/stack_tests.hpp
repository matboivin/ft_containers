/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:48:12 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/02 11:58:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TESTS_HPP
#define STACK_TESTS_HPP

#include <iostream>
#include <string>
#include "tests.hpp"

#if defined(TEST_FT)
# include "stack.hpp"
# include "vector.hpp"

namespace ft
#else
# include <stack>
# include <vector>

namespace std
#endif
{
	void	test_stack(void);

	// construct/assign
	void	test_stack_default_ctor(void);
	void	test_stack_copy_ctor(void);
	void	test_stack_copy_assign(void);

	// capacity
	void	test_stack_empty(void);
	void	test_stack_size(void);

	// element access
	void	test_stack_top(void);

	// modifiers
	void	test_stack_push(void);
	void	test_stack_pop(void);

	// non-member functions
	void	test_stack_non_mb_comp_ops(void);
}

#endif
