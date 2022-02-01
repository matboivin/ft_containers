/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:23:19 by mboivin           #+#    #+#             */
/*   Updated: 2022/02/01 13:31:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "vector_tests.hpp"
#include "stack_tests.hpp"
#include "map_tests.hpp"
#include "set_tests.hpp"
#include "revit_tests.hpp"
#include "tree_tests.hpp"

int	main(void)
{
	#if defined(TEST_FT)
	ft::test_vector();
	ft::test_stack();
	ft::test_map();
	ft::test_set();
	ft::test_revit();
	#elif defined(TEST_STD)
	std::test_vector();
	std::test_stack();
	std::test_map();
	std::test_set();
	std::test_revit();
	#else
	// ft::test_tree();
	generate_output();
	#endif

	return (0);
}
