/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:20:45 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/16 23:39:26 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_TESTS_HPP
#define SET_TESTS_HPP

#include <iostream>
#include <string>
#include "tests.hpp"

#if defined(TEST_FT)
# include "set.hpp"

namespace ft
#else
# include <set>

namespace std
#endif
{
	typedef set<int>	int_set;

	void	test_set(void);

	// construct/assign
	void	test_set_default_ctor(void);
}

#endif
