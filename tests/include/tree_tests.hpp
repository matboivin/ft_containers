/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:42 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 20:34:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_TESTS_HPP
#define TREE_TESTS_HPP

#include <iostream>
#include <string>
#include <map>
#include "tests.hpp"
#include "tree.hpp"

namespace ft
{
	typedef RedBlackTree<int,pair<int, std::string>,get_key_from_pair<int,pair<int, std::string> > >	int_s_tree;
	typedef pair<typename int_s_tree::iterator,bool>	pair_type;

	void	test_tree(void);

	// construct/assign
	void	test_tree_default_ctor(void);
	void	test_tree_copy_ctor(void);
	void	test_tree_copy_assign(void);

	// iterators
	void	test_tree_iterator(void);
	void	test_tree_rev_iterator(void);

	// capacity
	void	test_tree_empty(void);
	void	test_tree_size(void);
	void	test_tree_max_size(void);

	// elements access
	void	test_tree_count(void);
	void	test_tree_find(void);
	void	test_tree_lower_bound(void);
	void	test_tree_upper_bound(void);
	void	test_tree_equal_range(void);

	// modifiers
	void	test_tree_insert(void);
	void	test_tree_erase_one(void);
	void	test_tree_erase_range(void);
	void	test_tree_swap(void);
	void	test_tree_clear(void);

	// non-member functions
	void	test_tree_non_mb_comp_ops(void);
	void	test_tree_non_mb_swap(void);
}

/* Display the tree size and nodes */

template<typename RBTree>
	static void	display_tree_infos(const RBTree& tree, const std::string& title="RB Tree")
	{
		std::cout << title
				<< "\n- size:      " << tree.size()
				<< "\n- contents:  ";
				
		if (tree.empty() == true)
			std::cout << "(empty)\n\n";
		else
		{
			std::cout << '\n';
			for (typename RBTree::const_iterator it = tree.begin(); it != tree.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			std::cout << "\n\n";
		}
	}

#endif
