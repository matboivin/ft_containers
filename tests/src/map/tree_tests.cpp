/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/17 21:24:53 by mboivin          ###   ########.fr       */
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
	void	test_tree(void)
	{
		std::cout << std::setw(42) << " TREE \n\n";

		typedef RedBlackTree<char,pair<char,int> >						tree_type;
		typedef pair<RedBlackTree<char,pair<char,int> >::iterator,bool>	pair_type;

		tree_type	tree;
		pair_type	ret;

		std::cout << "size: " << tree.size() << '\n';

		tree.insert( pair<char,int>('b', 100) );
		tree.insert( pair<char,int>('b', 100) );
		tree.insert( pair<char,int>('b', 100) );
		tree.insert( pair<char,int>('b', 100) );
		tree.insert( pair<char,int>('b', 100) );
		tree.insert( pair<char,int>('b', 100) );
		tree.insert( pair<char,int>('a', 200) );
		tree.insert( pair<char,int>('z', 200) );
		// tree.insert( pair<char,int>('c', 300) );
		// tree.insert( pair<char,int>('c', 300) );

		std::cout << "size: " << tree.size() << '\n';

		std::cout << "begin: " << tree.begin()->first << '\n';
		std::cout << "end:   " << tree.end()->first << '\n';

		for (tree_type::iterator it = tree.begin();
			 it != tree.end();
			 ++it)
		{
			std::cout << it->first << " => " << it->second << '\n';
		}

		//displayTreeInfos(tree);
	}
}

int	main(void)
{
	ft::test_tree();
	return (0);
}
