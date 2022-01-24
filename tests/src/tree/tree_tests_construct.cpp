/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests_construct.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 16:04:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include "tests.hpp"
#include "tree_tests.hpp"

namespace ft
{
	void	test_tree_default_ctor(void)
	{
		std::cout << "TEST: Default Constructor \n\n";

		explain_test("Constructs an empty tree.");

		clock_t	start = clock();

		tree_type	tree;

		display_elapsed_time(start, clock());
	}

	void	test_tree_copy_ctor(void)
	{
		std::cout << "TEST: Copy constructor \n\n";

		explain_test("Creates a new object from existing one passed as parameter.");

		// create tree
		tree_type	tree;

		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(5,  "five") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(17, "seventeen") );
		tree.insert( pair<int, std::string>(25, "twenty-five") );
		tree.insert( pair<int, std::string>(40, "fourty") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(11, "eleven") );
		tree.insert( pair<int, std::string>(11, "eleven") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(11, "eleven") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(20, "twenty") );

		clock_t	start = clock();

		// create a copy from tree
		tree_type	copy_tree(tree);

		display_elapsed_time(start, clock());

		// assert they're identical
		assert(tree == copy_tree);

		std::cout << "tree size: " << tree.size() << '\n';
		std::cout << "copy size: " << copy_tree.size() << '\n';
	}

	void	test_tree_copy_assign(void)
	{
		std::cout << "TEST: Copy assignment operator \n\n";

		explain_test("Copies a tree from an existing one.");

		// create trees
		tree_type	tree;
		tree_type	copy_tree;

		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(5,  "five") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(17, "seventeen") );
		tree.insert( pair<int, std::string>(25, "twenty-five") );
		tree.insert( pair<int, std::string>(40, "fourty") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(11, "eleven") );
		tree.insert( pair<int, std::string>(11, "eleven") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(11, "eleven") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(20, "twenty") );

		clock_t	start = clock();

		// create a copy from tree
		copy_tree = tree;

		display_elapsed_time(start, clock());

		// assert they're identical
		assert(tree == copy_tree);

		std::cout << "tree size: " << tree.size() << '\n';
		std::cout << "copy size: " << copy_tree.size() << '\n';
	}
}
