/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests_iterators.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/28 16:30:44 by mboivin          ###   ########.fr       */
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
	void	test_tree_iterator(void)
	{
		std::cout << "TEST: Iterator \n\n";

		explain_test("Move through the elements of the container like pointers do.");

		// create tree
		int_s_tree	tree;

		std::cout << std::boolalpha << "(tree.begin() == tree.end())? "
				  << (tree.begin() == tree.end()) << '\n';

		assert(tree.begin() == tree.end());

		tree.insert( pair<int, std::string>(8,  "eight") );

		display_tree_infos(tree);

		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(5,  "five") );
		tree.insert( pair<int, std::string>(15, "fifteen") );

		int_s_tree::iterator	it = tree.find(5);

		std::cout << "iterator before: " << (*it).first << '\n';

		tree.erase(15);

		tree.insert( pair<int, std::string>(17, "seventeen") );
		tree.insert( pair<int, std::string>(25, "twenty-five") );
		tree.insert( pair<int, std::string>(40, "fourty") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(11, "eleven") );
		tree.insert( pair<int, std::string>(20, "twenty") );

		tree.insert( pair<int, std::string>(15, "fifteen") );

		std::cout << "iterator after: " << (*it).first << '\n';

		std::cout << std::boolalpha << "(tree.begin() == tree.end())? "
				  << (tree.begin() == tree.end()) << '\n'
				  << "begin(): " << tree.begin()->second << '\n'
				  << "end(): " << (--tree.end())->second << '\n';

		display_tree_infos(tree);
		std::cout << "tree size: " << tree.size() << '\n';

		for (int_s_tree::iterator it = tree.begin(); it != tree.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "TEST: Iterator with empty tree\n\n";

		tree.clear();

		int_s_tree::iterator	end = tree.end();
		--end;

		for (; end != tree.begin(); --end)
			std::cout << end->first << " => " << end->second << '\n';
		std::cout << end->first << " => " << end->second << '\n';
	}

	void	test_tree_rev_iterator(void)
	{
		std::cout << "TEST: Reverse iterator \n\n";

		explain_test("Move through the elements of the container backwards.");

		// create tree
		int_s_tree	tree;

		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(5,  "five") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(17, "seventeen") );
		tree.insert( pair<int, std::string>(25, "twenty-five") );
		tree.insert( pair<int, std::string>(40, "fourty") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(11, "eleven") );
		tree.insert( pair<int, std::string>(20, "twenty") );

		std::cout << std::boolalpha << "(tree.begin() == tree.end())? "
				  << (tree.begin() == tree.end()) << '\n'
				  << "begin(): " << tree.begin()->second << '\n'
				  << "end(): " << (--tree.end())->second << '\n';

		std::cout << "tree size: " << tree.size() << '\n';

		std::cout << "Print the tree content using reverse iterator:" << std::endl;

		for (int_s_tree::reverse_iterator rev_it = tree.rbegin(); rev_it != tree.rend(); ++rev_it)
			std::cout << rev_it->first << " => " << rev_it->second << '\n';
		std::cout << "\n\n";
	}
}
