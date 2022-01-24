/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:20:45 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 18:46:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_TESTS_HPP
#define SET_TESTS_HPP

#include <iostream>
#include <string>
#include "tests.hpp"

#if defined(TEST_FT)
# include "set.hpp"

namespace ft
#else
# include <set>

namespace std
#endif
{
	typedef set<int>			int_set;
	typedef set<std::string>	str_set;

	void	test_set(void);

	// construct/assign
	void	test_set_default_ctor(void);
	void	test_set_range_ctor(void);
	void	test_set_copy_ctor(void);
	void	test_set_copy_assign(void);

	// iterators
	void	test_set_iterator(void);
	void	test_set_rev_iterator(void);

	// capacity
	void	test_set_empty(void);
	void	test_set_size(void);
	void	test_set_max_size(void);

	// modifiers
	void	test_set_insert_val(void);
	void	test_set_insert_pos(void);
	void	test_set_insert_range(void);
	void	test_set_swap(void);
	void	test_set_clear(void);

	// lookup
	void	test_set_lookup(void);

	// observers
	void	test_set_key_comp(void);
	void	test_set_value_comp(void);

	// non-member functions
	void	test_set_non_mb_comp_ops(void);
	void	test_set_non_mb_swap(void);

	template<typename Set>
		void	display_set_infos(const Set& s, const std::string& title="set")
		{
			std::cout << title
					<< "\n- size:      " << s.size()
					<< "\n- contents:  ";

			if (s.empty() == true)
				std::cout << "(empty)\n\n";
			else
			{
				std::cout << '\n';
				for (typename Set::const_iterator it = s.begin(); it != s.end(); ++it)
					std::cout << it->first << " => " << it->second << '\n';
				std::cout << "\n\n";
			}
		}
}

#endif
