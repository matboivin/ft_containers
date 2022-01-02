/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests_modifiers.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/02 18:35:17 by mboivin          ###   ########.fr       */
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

		tree_type	tree;
		tree_type	copy_tree;

		std::cout << "tree size: " << tree.size() << '\n';
		std::cout << "copy size: " << copy_tree.size() << '\n';

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

		tree.write_tree_dot("ast_before");

		copy_tree = tree;

		tree.clear();

		std::cout << "tree size: " << tree.size()
				  << "\ncopy size: " << copy_tree.size() << '\n';

		tree_type::iterator	end = copy_tree.end();
		--end;

		for ( ; end != copy_tree.begin(); --end)
		{
			std::cout << end->first << " => " << end->second << '\n';
		}
		std::cout << end->first << " => " << end->second << "\n\n";

		std::cout << std::setw(42) << " INSERT RANGE \n\n";

		tree_type::iterator	from = copy_tree.begin();
		tree_type::iterator	to = copy_tree.end();

		for (int i = 0; i < 4; ++i)
			++from;
		for (int i = 0; i < 2; ++i)
			--to;

		std::cout << "from: " << from->first << '\n';
		std::cout << "to:   " << to->first << '\n';

		tree.insert(from, to);
		display_tree_infos(tree);

		tree.write_tree_dot("ast_after");

		std::cout << "\n\n";
	}

	void	test_tree_erase(void)
	{
		std::cout << "TEST: Modifiers: erase() \n\n";

		explain_test("Erase element(s) from the tree.");

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

		tree.write_tree_dot("ast_before");

		display_tree_infos(tree);

		tree.erase(tree.begin());

		display_tree_infos(tree);

		tree.write_tree_dot("ast_after");

		std::cout << "tree size: " << tree.size() << '\n';

		std::cout << "\n\n";
	}

	void	test_tree_swap(void)
	{
		std::cout << "TEST: Modifiers: swap() \n\n";

		explain_test("Exchanges the content of the tree and the other tree.");

		tree_type	tree;
		tree_type	other_tree;
		tree_type	empty_tree;

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
		const tree_type::iterator		it = ++tree.begin();

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

		// m[8]  = "eight";
		// m[18] = "eighteen";
		// m[5]  = "five";
		// m[15] = "fifteen";
		// m[17] = "seventeen";
		// m[25] = "twenty-five";
		// m[40] = "fourty";
		// m[80] = "eigthy";
		// m[11] = "eleven";
		// m[20] = "twenty";

		// other_m[12] = "twelve";

		// const std::pair<int, std::string>&			ref_m = *(m.begin());
		// const std::map<int, std::string>::iterator	it_m = ++m.begin();

		// display_map_infos(m);
		// display_map_infos(other_m, "other map");

		// std::cout << "first node (reference): " << ref_m.first << " => " << ref_m.second << '\n'
		// 		  << "second node (iterator): " << it_m->first << " => " << it_m->second << "\n\n";

		// m.swap(other_m);

		// display_map_infos(m);
		// display_map_infos(other_m, "other map");

		// std::cout << "first node (reference): " << ref_m.first << " => " << ref_m.second << '\n'
		// 		  << "second node (iterator): " << it_m->first << " => " << it_m->second << "\n\n";

		// other_m.swap(empty_m);

		// display_map_infos(other_m, "other map");
		// display_map_infos(empty_m, "empty map");
	}

	void	test_tree_clear(void)
	{
		std::cout << "TEST: Modifiers: clear() \n\n";

		explain_test("Destroys all elements from the tree, leaving it with a size of 0.");

		tree_type	tree;

		tree.insert( pair<int, std::string>(8,  "eight") );
		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(5,  "five") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(17, "seventeen") );
		tree.insert( pair<int, std::string>(25, "twenty-five") );
		tree.insert( pair<int, std::string>(40, "fourty") );
		tree.insert( pair<int, std::string>(80, "eighty") );
		tree.insert( pair<int, std::string>(20, "twenty") );

		std::cout << "tree size: " << tree.size() << '\n';

		tree.clear();

		std::cout << "tree size: " << tree.size() << '\n';
	}
}
