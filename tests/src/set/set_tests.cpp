/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:21:25 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 18:52:15 by mboivin          ###   ########.fr       */
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
	void	test_set(void)
	{
		#if defined(TEST_FT)
		std::cout << std::setw(42) << " MY SET \n\n";
		#else
		std::cout << std::setw(42) << " ORIGINAL SET \n\n";
		#endif

		// construct/assign
		test_set_default_ctor();
		test_set_range_ctor();
		test_set_copy_ctor();
		test_set_copy_assign();
	}
}
