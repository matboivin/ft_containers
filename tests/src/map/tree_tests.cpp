/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/18 15:49:03 by mboivin          ###   ########.fr       */
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

		typedef RedBlackTree<int,pair<int, std::string> >						tree_type;
		typedef pair<RedBlackTree<int,pair<int, std::string> >::iterator,bool>	pair_type;

		tree_type	tree;
		pair_type	ret;

		std::cout << "size: " << tree.size() << '\n';

		tree.insert( pair<int, std::string>(10, "ten") );
		tree.insert( pair<int, std::string>(10, "ten") );
		tree.insert( pair<int, std::string>(10, "ten") );
		tree.insert( pair<int, std::string>(10, "ten") );
		tree.insert( pair<int, std::string>(10, "ten") );
		tree.insert( pair<int, std::string>(10, "ten") );
		tree.insert( pair<int, std::string>(18, "eighteen") );
		tree.insert( pair<int, std::string>(7,  "seven") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(15, "fifteen") );
		tree.insert( pair<int, std::string>(7,  "seven") );
		tree.insert( pair<int, std::string>(16, "sixteen") );

		std::cout << "size: " << tree.size() << '\n';

		// std::cout << "begin: " << tree.begin()->first << '\n';
		// std::cout << "end:   " << tree.end()->first << '\n';

		// for (tree_type::iterator it = tree.begin();
		// 	 it != tree.end();
		// 	 ++it)
		// {
		// 	std::cout << it->first << " => " << it->second << '\n';
		// }

		tree.write_tree_dot();
	}
}

int	main(void)
{
	ft::test_tree();
	return (0);
}
