/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/16 17:50:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include "tests.hpp"
#include "tree_tests.hpp"

namespace ft
{
	void	test_tree(void)
	{
		std::cout << std::setw(42) << " TREE \n\n";

		RedBlackTree<int,std::string>	tree;

		displayTreeInfos(tree);
	}
}

int	main(void)
{
	ft::test_tree();
	return (0);
}
