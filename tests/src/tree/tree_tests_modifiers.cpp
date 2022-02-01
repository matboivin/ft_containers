/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests_modifiers.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2022/02/01 14:16:42 by mboivin          ###   ########.fr       */
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
	void	test_tree_insert(void)
	{
		std::cout << "TEST: Modifiers: insert() \n\n";

		explain_test("Insert element(s) into the tree.");

		int_s_tree	tree;
		int_s_tree	copy_tree;

		std::cout << "tree size: " << tree.size()
				  << "\ncopy size: " << copy_tree.size() << '\n';

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

		std::cout << "tree size: " << tree.size()
				  << "\ncopy size: " << copy_tree.size()
				  << "\nbegin: " << tree.begin()->first
				  << "\nend:   " << tree.end()->first << '\n';

		display_tree_infos(tree);

		tree.write_tree_dot("rbtree_before");

		// perform copy
		copy_tree = tree;

		// assert they're identical
		assert(copy_tree == tree);

		// delete original tree
		tree.clear();
		// assert copy is not impacted
		assert(copy_tree.empty() == false);

		std::cout << "tree size: " << tree.size()
				  << "\ncopy size: " << copy_tree.size() << '\n';

		std::cout << std::setw(42) << " INSERT RANGE \n\n";

		int_s_tree::iterator	from = copy_tree.begin();
		int_s_tree::iterator	to = copy_tree.end();

		for (int i = 0; i < 4; ++i)
			++from;
		for (int i = 0; i < 2; ++i)
			--to;

		std::cout << "from: " << from->first
				  << "\nto:   " << to->first << '\n';

		tree.insert(from, to);
		display_tree_infos(tree);

		tree.write_tree_dot("rbtree_after");

		std::cout << "\n\n";
	}

	void	test_tree_erase_one(void)
	{
		std::cout << "TEST: Modifiers: erase() \n\n";

		explain_test("Erase element(s) from the tree.");

		int_s_tree	tree;

		tree.insert( pair<int, std::string>(76, "seventy-six") );
		tree.insert( pair<int, std::string>(54, "fifty-four") );
		tree.insert( pair<int, std::string>(14, "fourteen") );
		tree.insert( pair<int, std::string>(28, "twenty-eight") );
		tree.insert( pair<int, std::string>(29, "twenty-nine") );
		tree.insert( pair<int, std::string>(9,  "nine") );
		tree.insert( pair<int, std::string>(19, "nineteen") );
		tree.insert( pair<int, std::string>(97, "ninety-seven") );
		tree.insert( pair<int, std::string>(65, "sixty-five") );
		tree.insert( pair<int, std::string>(0,  "zero") );
		tree.insert( pair<int, std::string>(1,  "one") );
		tree.insert( pair<int, std::string>(81, "eighty-one") );
		tree.insert( pair<int, std::string>(54, "fifty-four") );
		tree.insert( pair<int, std::string>(77, "seventy-seven") );
		tree.insert( pair<int, std::string>(42, "fourty-two") );
		tree.insert( pair<int, std::string>(60, "sixty") );
		tree.insert( pair<int, std::string>(2,  "two") );
		tree.insert( pair<int, std::string>(32, "thirty-two") );
		tree.insert( pair<int, std::string>(7,  "seven") );
		tree.insert( pair<int, std::string>(44, "fourty-four") );
		tree.insert( pair<int, std::string>(79, "seventy-nine") );
		tree.insert( pair<int, std::string>(82, "eighty-two") );
		tree.insert( pair<int, std::string>(3,  "three") );
		tree.insert( pair<int, std::string>(80, "twenty-five") );
		tree.insert( pair<int, std::string>(78, "seventy-eight") );
		tree.insert( pair<int, std::string>(17, "seventeen") );
		tree.insert( pair<int, std::string>(10, "ten") );

		tree.write_tree_dot("rbtree_before");

		display_tree_infos(tree);

		std::cout << "Erase a leaf node: begin / key=" << tree.begin()->first << "\n\n";

		tree.erase(tree.begin());
		display_tree_infos(tree);

		std::cout << "Erase a node that has one child: key=9\n\n";

		tree.erase(9);
		display_tree_infos(tree);

		std::cout << "Erase a node that has one child: key=32\n\n";

		tree.erase(32);
		display_tree_infos(tree);

		std::cout << "Erase a node that has two children: key=79\n\n";

		tree.erase(79);
		display_tree_infos(tree);

		tree.write_tree_dot("rbtree_after");
	}

	void	test_tree_erase_range(void)
	{
		std::cout << "TEST: Modifiers: erase() \n\n";

		explain_test("Erase a range of elements from the tree.");

		int_s_tree	tree;

		tree.insert( pair<int, std::string>(76, "seventy-six") );
		tree.insert( pair<int, std::string>(54, "fifty-four") );
		tree.insert( pair<int, std::string>(14, "fourteen") );
		tree.insert( pair<int, std::string>(28, "twenty-eight") );
		tree.insert( pair<int, std::string>(29, "twenty-nine") );
		tree.insert( pair<int, std::string>(9,  "nine") );
		tree.insert( pair<int, std::string>(19, "nineteen") );
		tree.insert( pair<int, std::string>(97, "ninety-seven") );
		tree.insert( pair<int, std::string>(65, "sixty-five") );
		tree.insert( pair<int, std::string>(0,  "zero") );
		tree.insert( pair<int, std::string>(1,  "one") );
		tree.insert( pair<int, std::string>(81, "eighty-one") );
		tree.insert( pair<int, std::string>(54, "fifty-four") );
		tree.insert( pair<int, std::string>(77, "seventy-seven") );
		tree.insert( pair<int, std::string>(42, "fourty-two") );
		tree.insert( pair<int, std::string>(60, "sixty") );
		tree.insert( pair<int, std::string>(2,  "two") );
		tree.insert( pair<int, std::string>(32, "thirty-two") );
		tree.insert( pair<int, std::string>(7,  "seven") );
		tree.insert( pair<int, std::string>(44, "fourty-four") );
		tree.insert( pair<int, std::string>(79, "seventy-nine") );
		tree.insert( pair<int, std::string>(82, "eighty-two") );
		tree.insert( pair<int, std::string>(3,  "three") );
		tree.insert( pair<int, std::string>(80, "twenty-five") );
		tree.insert( pair<int, std::string>(78, "seventy-eight") );
		tree.insert( pair<int, std::string>(17, "seventeen") );
		tree.insert( pair<int, std::string>(10, "ten") );

		display_tree_infos(tree);

		int_s_tree::iterator	from = tree.find(7);
		int_s_tree::iterator	to = tree.find(80);

		std::cout << "Erase range[" << from->first << ", " << to->first << ")\n\n";

		tree.erase(from, to);
		display_tree_infos(tree);

		tree.write_tree_dot("rbtree_after_range");

		from = ++tree.begin();
		to = --tree.end();

		std::cout << "Erase range[" << from->first << ", " << to->first << ")\n\n";

		tree.erase(from, to);
		display_tree_infos(tree);

		std::cout << "Erase everything\n\n";

		while (tree.empty() == false)
			tree.erase(tree.begin());
		display_tree_infos(tree);
	}

	void	test_tree_swap(void)
	{
		std::cout << "TEST: Modifiers: swap() \n\n";

		explain_test("Exchanges the content of the tree and the other tree.");

		int_s_tree	tree;
		int_s_tree	other_tree;
		int_s_tree	empty_tree;

		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(5,  "five") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(17, "seventeen") );
		tree.insert( pair<int, std::string>(25, "twenty-five") );
		tree.insert( pair<int, std::string>(40, "fourty") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(20, "twenty") );

		other_tree.insert( pair<int, std::string>(12,  "twelve") );

		const pair<int, std::string>&	ref = *(tree.begin());
		const int_s_tree::iterator		it = ++tree.begin();

		display_tree_infos(tree, "tree");
		display_tree_infos(other_tree, "other tree");

		std::cout << "first node (reference): " << ref.first << " => " << ref.second << '\n'
				  << "second node (iterator): " << it->first << " => " << it->second << "\n\n";

		tree.swap(other_tree);

		display_tree_infos(tree, "tree");
		display_tree_infos(other_tree, "other tree");

		std::cout << "first node (reference): " << ref.first << " => " << ref.second << '\n'
				  << "second node (iterator): " << it->first << " => " << it->second << "\n\n";

		empty_tree.swap(other_tree);

		display_tree_infos(empty_tree, "empty tree");
		display_tree_infos(other_tree, "other tree");

		std::cout << "first node (reference): " << ref.first << " => " << ref.second << '\n'
				  << "second node (iterator): " << it->first << " => " << it->second << "\n\n";

		empty_tree.swap(other_tree);

		display_tree_infos(empty_tree, "empty tree");
		display_tree_infos(other_tree, "other tree");

		std::cout << "first node (reference): " << ref.first << " => " << ref.second << '\n'
				  << "second node (iterator): " << it->first << " => " << it->second << "\n\n";

		std::map<int, std::string>	m;
		std::map<int, std::string>	other_m;
		std::map<int, std::string>	empty_m;
	}

	void	test_tree_clear(void)
	{
		std::cout << "TEST: Modifiers: clear() \n\n";

		explain_test("Destroys all elements from the tree, leaving it with a size of 0.");

		int_s_tree	tree;

		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(5,  "five") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(17, "seventeen") );
		tree.insert( pair<int, std::string>(25, "twenty-five") );
		tree.insert( pair<int, std::string>(40, "fourty") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(20, "twenty") );

		assert(tree.empty() == false);
		assert(tree.size() > 0);

		std::cout << "tree size: " << tree.size() << '\n';

		tree.clear();

		// check tree is empty
		assert(tree.empty() == true);
		assert(tree.size() == 0);
	}
}
