/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/12/10 18:36:05 by mboivin          ###   ########.fr       */
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

	void	test_tree(void)
	{
		std::cout << std::setw(42) << " MAP \n\n";

		std::map<int, std::string>	m;
		tree_type					tree;

		// map

		std::cout << std::boolalpha << "(m.begin() == m.end())? "
				  << (m.begin() == m.end()) << "\n\n";

		m[10] = "ten";

		std::cout << std::boolalpha << "(m.begin() == m.end())? "
				  << (m.begin() == m.end()) << '\n'
				  << "begin(): " << m.begin()->second << '\n'
				  << "end(): " << (--m.end())->second << "\n\n";

		m.clear();

		std::cout << "map size: " << m.size() << '\n';

		m[1] = "one";
		m[2] = "two";
		m[3] = "three";
		m[4] = "four";
		m[5] = "five";
		m[6] = "six";

		std::cout << "map size: " << m.size() << '\n';

		std::map<int, std::string>::iterator it = m.begin();
		m.erase(it);

		// erase all odd numbers from c
		for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
		{
			if (it->first % 2 != 0)
				m.erase(it++);
		}
	
		for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
			std::cout << it->second << ' ';

		std::cout << "\nmap size: " << m.size() << "\n\n";

		std::cout << std::setw(42) << " TREE \n\n";

		// tree

		std::cout << std::boolalpha << "(tree.begin() == tree.end())? "
				  << (tree.begin() == tree.end()) << '\n';

		tree.insert( pair<int, std::string>(8,  "eight") );

		std::cout << std::boolalpha << "(tree.begin() == tree.end())? "
				  << (tree.begin() == tree.end()) << '\n'
				  << "begin(): " << tree.begin()->second << '\n'
				  << "end(): " << (--tree.end())->second << '\n';

		std::cout << "tree size: " << tree.size() << '\n';
	}

	void	test_tree_insert(void)
	{
		std::cout << std::setw(42) << " TREE \n\n";

		tree_type	tree;
		tree_type	copy_tree;

		std::cout << "tree size: " << tree.size() << '\n';
		std::cout << "copy size: " << copy_tree.size() << '\n';

		std::cout << std::boolalpha << "(tree.begin() == tree.end())? "
				  << (tree.begin() == tree.end()) << '\n'; // true

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

		std::cout << std::boolalpha << "(tree.begin() == tree.end())? "
				  << (tree.begin() == tree.end()) << '\n'; // false

		std::cout << "tree size: " << tree.size() << '\n';
		std::cout << "copy size: " << copy_tree.size() << '\n';

		std::cout << "begin: " << tree.begin()->first << '\n';
		std::cout << "end:   " << tree.end()->first << '\n';

		for (tree_type::iterator it = tree.begin();
			 it != tree.end();
			 ++it)
		{
			std::cout << it->first << " => " << it->second << '\n';
		}

		copy_tree = tree;

		tree.write_tree_dot("ast_before.dot");

		tree.clear();
		std::cout << "tree size: " << tree.size() << '\n';
		std::cout << "copy size: " << copy_tree.size() << '\n';

		tree_type::iterator	end = copy_tree.end();
		--end;

		for ( ; end != copy_tree.begin(); --end)
		{
			std::cout << end->first << " => " << end->second << '\n';
		}
		std::cout << end->first << " => " << end->second << '\n';

		std::cout << std::setw(42) << " TREE RANGE \n\n";

		tree_type::iterator	from = copy_tree.begin();
		tree_type::iterator	to = copy_tree.end();

		for (int i = 0; i < 4; ++i)
			++from;
		for (int i = 0; i < 2; ++i)
			--to;

		std::cout << "from: " << from->first << '\n';
		std::cout << "to:   " << to->first << '\n';

		tree.insert(from, to);
		std::cout << "tree size: " << tree.size() << '\n';

		for (tree_type::iterator it = tree.begin();
			 it != tree.end();
			 ++it)
		{
			std::cout << it->first << " => " << it->second << '\n';
		}

		tree.write_tree_dot("ast_after.dot");

		std::cout << "\n\n";
	}

	void	test_tree_access(void)
	{
		std::cout << std::setw(42) << " MAP \n\n";

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

		std::cout << "m.upper_bound(5):                     " << m.upper_bound(5)->first << '\n'
				  << "tree.upper_bound(5):                  " << tree.upper_bound(5)->first << '\n'
				  << "m.upper_bound(24):                    " << m.upper_bound(24)->first << '\n'
				  << "tree.upper_bound(24):                 " << tree.upper_bound(24)->first << "\n\n"
				  << "(m.upper_bound(99) == m.end())?       " << (m.upper_bound(99) == m.end()) << '\n'
				  << "(tree.upper_bound(99) == tree.end())? " << (tree.upper_bound(99) == tree.end())
				  << "\n\n";

		std::cout << "m.find(5):                     " << m.find(5)->first << '\n'
				  << "tree.find(5):                  " << tree.find(5)->first << '\n'
				  << "m.find(40):                    " << m.find(40)->first << '\n'
				  << "tree.find(40):                 " << tree.find(40)->first << "\n\n"
				  << "(m.find(99) == m.end())?       " << (m.find(99) == m.end()) << '\n'
				  << "(tree.find(99) == tree.end())? " << (tree.find(99) == tree.end())
				  << "\n\n";
	}
}

int	main(void)
{
	// ft::test_tree();
	// ft::test_tree_insert();
	ft::test_tree_access();
	return (0);
}
