/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/12/10 19:13:13 by mboivin          ###   ########.fr       */
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
	typedef RedBlackTree<int,pair<int, std::string> >						tree_type;
	typedef pair<RedBlackTree<int,pair<int, std::string> >::iterator,bool>	pair_type;

	void	display_map_infos(const std::map<int, std::string>& m, const std::string& title="map")
	{
		std::cout << title
				  << "\n- size:      " << m.size()
				  << "\n- contents:  \n";

		if ( !m.size() )
		{
			std::cout << "(empty)\n\n";
			return ;
		}

		for (std::map<int, std::string>::const_iterator it_m = m.begin(); it_m != m.end(); ++it_m)
			std::cout << it_m->first << " => " << it_m->second << '\n';
		std::cout << "\n\n";
	}

	void	test_tree_default_ctor(void)
	{
		std::cout << "TEST: Default Constructor \n\n";

		explainTest("Constructs an empty tree.");

		clock_t	start = clock();

		tree_type	tree;

		displayElapsedTime(start, clock());
	}

	void	test_tree_copy_ctor(void)
	{
		std::cout << "TEST: Copy constructor \n\n";

		explainTest("Creates a new object from existing one passed as parameter.");

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

		displayElapsedTime(start, clock());

		// assert they're identical
		//assert(tree == copy_tree);

		std::cout << "tree size: " << tree.size() << '\n';
		std::cout << "copy size: " << copy_tree.size() << '\n';
	}

	void	test_tree_copy_assign(void)
	{
		std::cout << "TEST: Copy assignment operator \n\n";

		explainTest("Copies a tree from an existing one.");

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

		displayElapsedTime(start, clock());

		// assert they're identical
		//assert(tree == copy_tree);

		std::cout << "tree size: " << tree.size() << '\n';
		std::cout << "copy size: " << copy_tree.size() << '\n';
	}

	void	test_tree_iterator(void)
	{
		std::cout << "TEST: Iterator \n\n";

		explainTest("Move through the elements of the container like pointers do.");

		// create tree
		tree_type	tree;

		std::cout << std::boolalpha << "(tree.begin() == tree.end())? "
				  << (tree.begin() == tree.end()) << '\n';

		assert(tree.begin() == tree.end());

		tree.insert( pair<int, std::string>(8,  "eight") );

		displayTreeInfos(tree);

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

		displayTreeInfos(tree);
	}

	void	test_tree_rev_iterator(void)
	{
		std::cout << "TEST: Reverse iterator \n\n";

		explainTest("Move through the elements of the container backwards.");

		// create tree
		tree_type	tree;

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

		for (tree_type::reverse_iterator rev_it = tree.rbegin();
			 rev_it != tree.rend();
			 ++rev_it)
		{
			std::cout << rev_it->first << " => " << rev_it->second << '\n';
		}
		std::cout << "\n\n";
	}

	void	test_tree_empty(void)
	{
		std::cout << "TEST: Capacity: empty() \n\n";

		explainTest("Returns true if the tree is empty.");

		// create tree
		tree_type	tree;

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

		explainTest("Returns true the number of element in the tree.");

		// create tree
		tree_type	tree;

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

		explainTest("Returns the maximum number of elements that the tree can hold.");

		// Create tree
		tree_type	tree;

		// Display capacity
		std::cout << "tree max size:  " << tree.max_size() << std::endl;
	}

	void	test_tree_count(void)
	{
		std::cout << "TEST: Element access: count() \n\n";

		explainTest("Returns 1 if the tree contains an element matching key k.");

		std::map<int, std::string>	m;
		tree_type					tree;

		m[8]  = "eight";
		m[18] = "eighteen";
		m[5]  = "five";
		m[15] = "fifteen";
		m[17] = "seventeen";
		m[25] = "twenty-five";
		m[40] = "fourty";
		m[80] = "eigthy";
		m[11] = "eleven";
		m[20] = "twenty";

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

		std::cout << "m.count(5):                     " << m.count(5) << '\n'
				  << "tree.count(5):                  " << tree.count(5) << '\n'
				  << "m.count(40):                    " << m.count(40) << '\n'
				  << "tree.count(40):                 " << tree.count(40) << "\n\n"
				  << "m.count(99):                    " << m.count(99) << '\n'
				  << "tree.count(99):                 " << tree.count(99)
				  << "\n\n";
	}

	void	test_tree_find(void)
	{
		std::cout << "TEST: Element access: find() \n\n";

		explainTest("Returns the element with the key k, else return end.");

		std::map<int, std::string>	m;
		tree_type					tree;

		m[8]  = "eight";
		m[18] = "eighteen";
		m[5]  = "five";
		m[15] = "fifteen";
		m[17] = "seventeen";
		m[25] = "twenty-five";
		m[40] = "fourty";
		m[80] = "eigthy";
		m[11] = "eleven";
		m[20] = "twenty";

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

		std::cout << "m.find(5):                     " << m.find(5)->first << '\n'
				  << "tree.find(5):                  " << tree.find(5)->first << '\n'
				  << "m.find(40):                    " << m.find(40)->first << '\n'
				  << "tree.find(40):                 " << tree.find(40)->first << "\n\n"
				  << "(m.find(99) == m.end())?       " << (m.find(99) == m.end()) << '\n'
				  << "(tree.find(99) == tree.end())? " << (tree.find(99) == tree.end())
				  << "\n\n";
	}


	void	test_tree_lower_bound(void)
	{
		std::cout << "TEST: Element access: lower_bound() \n\n";

		explainTest("Returns the first element that is equivalent or after k.");

		std::map<int, std::string>	m;
		tree_type					tree;

		m[8]  = "eight";
		m[18] = "eighteen";
		m[5]  = "five";
		m[15] = "fifteen";
		m[17] = "seventeen";
		m[25] = "twenty-five";
		m[40] = "fourty";
		m[80] = "eigthy";
		m[11] = "eleven";
		m[20] = "twenty";

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

		std::cout << "m.lower_bound(5):                     " << m.lower_bound(5)->first << '\n'
				  << "tree.lower_bound(5):                  " << tree.lower_bound(5)->first << '\n'
				  << "m.lower_bound(24):                    " << m.lower_bound(24)->first << '\n'
				  << "tree.lower_bound(24):                 " << tree.lower_bound(24)->first << "\n\n"
				  << "(m.lower_bound(99) == m.end())?       " << (m.lower_bound(99) == m.end()) << '\n'
				  << "(tree.lower_bound(99) == tree.end())? " << (tree.lower_bound(99) == tree.end())
				  << "\n\n";
	}

	void	test_tree_upper_bound(void)
	{
		std::cout << "TEST: Element access: upper_bound() \n\n";

		explainTest("Returns the first element that is after k.");

		std::map<int, std::string>	m;
		tree_type					tree;

		m[8]  = "eight";
		m[18] = "eighteen";
		m[5]  = "five";
		m[15] = "fifteen";
		m[17] = "seventeen";
		m[25] = "twenty-five";
		m[40] = "fourty";
		m[80] = "eigthy";
		m[11] = "eleven";
		m[20] = "twenty";

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

		std::cout << "m.upper_bound(5):                     " << m.upper_bound(5)->first << '\n'
				  << "tree.upper_bound(5):                  " << tree.upper_bound(5)->first << '\n'
				  << "m.upper_bound(24):                    " << m.upper_bound(24)->first << '\n'
				  << "tree.upper_bound(24):                 " << tree.upper_bound(24)->first << "\n\n"
				  << "(m.upper_bound(99) == m.end())?       " << (m.upper_bound(99) == m.end()) << '\n'
				  << "(tree.upper_bound(99) == tree.end())? " << (tree.upper_bound(99) == tree.end())
				  << "\n\n";
	}

	void	test_tree_equal_range(void)
	{
		std::cout << "TEST: Element access: equal_range() \n\n";

		explainTest("Returns the bounds of a range that have a key equivalent to k.");

		std::map<int, std::string>	m;
		tree_type					tree;

		m[8]  = "eight";
		m[18] = "eighteen";
		m[5]  = "five";
		m[15] = "fifteen";
		m[17] = "seventeen";
		m[25] = "twenty-five";
		m[40] = "fourty";
		m[80] = "eigthy";
		m[11] = "eleven";
		m[20] = "twenty";

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

		std::cout << "m.equal_range(5):                     " << m.equal_range(5).first->first << '\n'
				  << "tree.equal_range(5):                  " << tree.equal_range(5).first->first << '\n'
				  << "m.equal_range(24):                    " << m.equal_range(24).first->first << '\n'
				  << "tree.equal_range(24):                 " << tree.equal_range(24).first->first << "\n\n"
				  << "(m.equal_range(99) == m.end())?       " << (m.equal_range(99).first == m.end()) << '\n'
				  << "(tree.equal_range(99) == tree.end())? " << (tree.equal_range(99).first == tree.end())
				  << "\n\n";
	}

	void	test_tree_insert(void)
	{
		std::cout << "TEST: Modifiers: insert() \n\n";

		explainTest("Insert element(s) into the tree.");

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

		displayTreeInfos(tree);

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
		displayTreeInfos(tree);

		tree.write_tree_dot("ast_after");

		std::cout << "\n\n";
	}

	void	test_tree_swap(void)
	{
		std::cout << "TEST: Modifiers: swap() \n\n";

		explainTest("Exchanges the content of the tree and the other tree.");

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

		displayTreeInfos(tree, "tree");
		displayTreeInfos(other_tree, "other tree");

		std::cout << "first node (reference): " << ref.first << " => " << ref.second << '\n'
				  << "second node (iterator): " << it->first << " => " << it->second << "\n\n";

		tree.swap(other_tree);

		displayTreeInfos(tree, "tree");
		displayTreeInfos(other_tree, "other tree");

		std::cout << "first node (reference): " << ref.first << " => " << ref.second << '\n'
				  << "second node (iterator): " << it->first << " => " << it->second << "\n\n";

		empty_tree.swap(other_tree);

		displayTreeInfos(tree, "tree");
		displayTreeInfos(other_tree, "other tree");

		std::cout << "first node (reference): " << ref.first << " => " << ref.second << '\n'
				  << "second node (iterator): " << it->first << " => " << it->second << "\n\n";

		empty_tree.swap(other_tree);

		displayTreeInfos(tree, "tree");
		displayTreeInfos(other_tree, "other tree");

		std::cout << "first node (reference): " << ref.first << " => " << ref.second << '\n'
				  << "second node (iterator): " << it->first << " => " << it->second << "\n\n";

		// std::map<int, std::string>	m;
		// std::map<int, std::string>	other_m;
		// std::map<int, std::string>	empty_m;

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

		explainTest("Destroys all elements from the tree, leaving it with a size of 0.");

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

	void	test_tree(void)
	{
		ft::test_tree_default_ctor();
		ft::test_tree_copy_ctor();
		ft::test_tree_copy_assign();

		// iterators
		ft::test_tree_iterator();
		ft::test_tree_rev_iterator();

		// capacity
		ft::test_tree_empty();
		ft::test_tree_size();
		ft::test_tree_max_size();

		// elements access
		ft::test_tree_count();
		ft::test_tree_find();
		ft::test_tree_lower_bound();
		ft::test_tree_upper_bound();
		ft::test_tree_equal_range();

		// modifiers
		ft::test_tree_insert();
		// ft::test_tree_erase();
		ft::test_tree_swap();
		ft::test_tree_clear();
	}
}
