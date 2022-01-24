/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 16:26:50 by mboivin          ###   ########.fr       */
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
		ft::test_tree_erase_one();
		ft::test_tree_erase_range();
		ft::test_tree_swap();
		ft::test_tree_clear();

		// non-member functions
		ft::test_tree_non_mb_comp_ops();
		ft::test_tree_non_mb_swap();
	}
}
