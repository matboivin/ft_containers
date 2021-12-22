/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/12/21 00:28:02 by mboivin          ###   ########.fr       */
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

	// element access
	void	test_map_subscript_op(void);

	// lookup
	void	test_map_lookup(void);
}

#endif
