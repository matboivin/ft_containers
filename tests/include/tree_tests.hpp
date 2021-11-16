/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/16 17:43:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_TESTS_HPP
#define TREE_TESTS_HPP

#include <iostream>
#include <string>
#include "tests.hpp"
#include "tree.hpp"

namespace ft
{
	void	test_tree(void);
}

/*
 * Display the tree size and nodes
 */

template<typename RBTree>
static void	displayTreeInfos(const RBTree& tree, const std::string& title="RB Tree")
{
	std::cout << title
			  << "\n- size:      " << tree.size()
			  << "\n- contents:  ";
			
	if ( !tree.size() )
	{
		std::cout << "(empty)\n\n";
		return ;
	}
}

#endif
