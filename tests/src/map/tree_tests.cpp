/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/12/09 23:51:31 by mboivin          ###   ########.fr       */
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
		pair_type	ret;

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

		std::size_t i = 0;

		for (tree_type::iterator it = tree.begin();
			 it != tree.end();
			 ++it, ++i)
		{
			std::cout << it->first << " => " << it->second << '\n';
		}

		// copy_tree = tree;

		tree.write_tree_dot();

		tree.clear();
		std::cout << "tree size: " << tree.size() << '\n';
		std::cout << "copy size: " << copy_tree.size() << '\n';
	}
}

int	main(void)
{
	// ft::test_tree();
	ft::test_tree_insert();
	return (0);
}
