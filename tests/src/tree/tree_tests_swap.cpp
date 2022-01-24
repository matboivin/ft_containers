/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests_swap.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:18:58 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 20:32:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "tests.hpp"
#include "tree_tests.hpp"

namespace ft
{
	void	test_tree_non_mb_swap(void)
	{
		std::cout << "TEST: Non-member swap() \n\n";

		explain_test("Exchange contents of 2 trees.");

		// create trees
		int_s_tree	tree1;
		int_s_tree	tree2;
		int_s_tree	tree3;

		// fill them
		for (int i = 0; i < 10000; ++i)
			tree3.insert(ft::make_pair(rand(), "three"));

		for (int i = 0; i < 20; ++i)
			tree1.insert(ft::make_pair(rand(), "one"));

		for (int i = 0; i < 10; ++i)
			tree2.insert(ft::make_pair(rand(), "two"));

		// create backup
		int_s_tree	backup1(tree1);
		int_s_tree	backup2(tree2);
		int_s_tree	backup3(tree3);

		// first test
		display_tree_infos(tree1, "before: tree 1");
		display_tree_infos(tree2, "before: tree 2");

		std::cout << "swap(tree1, tree2);\n\n";

		clock_t	time_start = clock();
		swap(tree1, tree2);
		clock_t	time_end = clock();

		display_tree_infos(tree1, "after: tree 1");
		display_tree_infos(tree2, "after: tree 2");
		display_elapsed_time(time_start, time_end);

		// assert using backup trees
		assert(tree1 == backup2);
		assert(tree2 == backup1);

		// second test
		std::cout << "swap(tree1, tree3);\n\n";

		time_start = clock();
		swap(tree1, tree3);
		display_elapsed_time(time_start, clock());

		// assert using backup trees
		assert(tree1 == backup3);
		assert(tree3 == backup2);
	}
}
