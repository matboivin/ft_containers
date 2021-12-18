/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:23:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/12/10 19:10:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "vector_tests.hpp"
#include "stack_tests.hpp"
#include "map_tests.hpp"
#include "revit_tests.hpp"
#include "tree_tests.hpp"

int	main(void)
{
	#if defined(TEST_FT)
	// ft::test_vector();
	// ft::test_stack();
	// ft::test_revit();
	ft::test_map();
	#elif defined(TEST_STD)
	// std::test_vector();
	// std::test_stack();
	// std::test_revit();
	std::test_map();
	#else
	// ft::test_tree();
	generate_output();
	#endif

	return (0);
}
