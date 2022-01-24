/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests_comp_ops.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:18:55 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 20:32:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "tests.hpp"
#include "tree_tests.hpp"

namespace ft
{
	void	test_tree_non_mb_comp_ops(void)
	{
		std::cout << "TEST: Non-member comparison operators \n\n";

		explain_test("Operators to make comparison between two trees.");

		// create trees
		int_s_tree	tree1;
		int_s_tree	tree2;
		int_s_tree	tree3;

		tree1.insert( ft::make_pair(12,  "twelve"));
		tree1.insert( ft::make_pair(5,   "five"));
		tree1.insert( ft::make_pair(42,  "fourty-two"));
		tree1.insert( ft::make_pair(100, "one-hundred"));
		tree1.insert( ft::make_pair(25,  "twenty-five"));

		tree3.insert( ft::make_pair(120,  "one-hundred twenty"));

		// copy of tree3
		int_s_tree	tree4(tree3);

		std::cout << std::boolalpha
				  << "(tree1 > tree2 && tree1 < tree3) ? " << (tree1 > tree2 && tree1 < tree3)
				  << "\n(tree1 < tree2)   ? " << (tree1 < tree2)
				  << "\n(tree3 != tree2)  ? " << (tree3 != tree2)
				  << "\n(tree3 == tree4)  ? " << (tree3 == tree4)
				  << "\n(tree3 != tree4)  ? " << (tree3 != tree4)
				  << "\n(tree1 != tree4)  ? " << (tree1 != tree4)
				  << "\n(tree3 >= tree4)  ? " << (tree3 >= tree4)
				  << "\n(tree3 <= tree4)  ? " << (tree3 <= tree4)
				  << "\n\n";

		assert(tree1 > tree2 && tree1 < tree3);
		assert((tree1 < tree2) == false);
		assert(tree3 != tree2);
		assert(tree3 == tree4);
		assert((tree3 != tree4) == false);
		assert(tree1 != tree4);
		assert(tree3 >= tree4);
		assert(tree3 <= tree4);
	}
}
