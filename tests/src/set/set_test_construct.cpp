/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test_construct.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:37:19 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/16 23:39:44 by mboivin          ###   ########.fr       */
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
	void	test_set_default_ctor(void)
	{
		std::cout << "TEST: Default Constructor \n\n";

		explain_test("Constructs an empty set.");

		clock_t	start = clock();

		int_set	s;

		display_elapsed_time(start, clock());
	}
}
