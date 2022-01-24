/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests_capacity.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 20:32:59 by mboivin          ###   ########.fr       */
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
	void	test_tree_empty(void)
	{
		std::cout << "TEST: Capacity: empty() \n\n";

		explain_test("Returns true if the tree is empty.");

		// create tree
		int_s_tree	tree;

		bool	is_empty = tree.empty();

		std::cout << std::boolalpha << "tree.empty()? " << is_empty << std::endl;
		assert(is_empty == true);

		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(5,  "five") );
		tree.insert( pair<int, std::string>(15, "fifteen") );

		is_empty = tree.empty();

		std::cout << std::boolalpha << "tree.empty()? " << is_empty << std::endl;
		assert(is_empty == false);
	}

	void	test_tree_size(void)
	{
		std::cout << "TEST: Capacity: size() \n\n";

		explain_test("Returns true the number of element in the tree.");

		// create tree
		int_s_tree	tree;

		std::size_t	tree_size = tree.size();

		std::cout << std::boolalpha << "tree.size() = " << tree_size << std::endl;
		assert(tree_size == 0);

		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(5,  "five") );
		tree.insert( pair<int, std::string>(15, "fifteen") );

		tree_size = tree.size();

		std::cout << std::boolalpha << "tree.size() = " << tree_size << std::endl;
		assert(tree_size == 4);
	}

	void	test_tree_max_size(void)
	{
		std::cout << "TEST: Capacity: max_size() \n\n";

		explain_test("Returns the maximum number of elements that the tree can hold.");

		// Create tree
		int_s_tree	tree;

		// Display capacity
		std::cout << "tree max size:  " << tree.max_size() << std::endl;
	}
}
