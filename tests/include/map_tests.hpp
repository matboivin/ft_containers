/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:42 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 18:27:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TESTS_HPP
#define MAP_TESTS_HPP

#include <iostream>
#include <string>
#include "tests.hpp"

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096

struct Buffer
{
	int		idx;
	char	buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

#if defined(TEST_FT)
# include "map.hpp"

namespace ft
#else
# include <map>

namespace std
#endif
{
	typedef map<int, std::string>	int_s_map;
	typedef map<int, int>			int_map;

	void	test_map(void);

	// construct/assign
	void	test_map_default_ctor(void);
	void	test_map_range_ctor(void);
	void	test_map_copy_ctor(void);
	void	test_map_copy_assign(void);

	// iterators
	void	test_map_iterator(void);
	void	test_map_rev_iterator(void);

	// capacity
	void	test_map_empty(void);
	void	test_map_size(void);
	void	test_map_max_size(void);

	// element access
	void	test_map_subscript_op(void);

	// modifiers
	void	test_map_insert_val(void);
	void	test_map_insert_pos(void);
	void	test_map_insert_range(void);
	void	test_map_swap(void);
	void	test_map_clear(void);

	// lookup
	void	test_map_lookup(void);

	// observers
	void	test_map_key_comp(void);
	void	test_map_value_comp(void);

	// non-member functions
	void	test_map_non_mb_comp_ops(void);
	void	test_map_non_mb_swap(void);

	template<typename Map>
		void	display_map_infos(const Map& m, const std::string& title="map")
		{
			std::cout << title
					<< "\n- size:      " << m.size()
					<< "\n- contents:  ";

			if (m.empty() == true)
				std::cout << "(empty)\n\n";
			else
			{
				std::cout << '\n';
				for (typename Map::const_iterator it = m.begin(); it != m.end(); ++it)
					std::cout << it->first << " => " << it->second << '\n';
				std::cout << "\n\n";
			}
		}

	template<typename T>
		struct size_compare
		{
			bool	operator()(const T& lhs, const T& rhs) const
			{ return (lhs.size() < rhs.size()); }
		};
}

#endif
