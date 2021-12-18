/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/16 17:42:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TESTS_HPP
#define MAP_TESTS_HPP

#include <iostream>
#include <string>
#include "tests.hpp"

#if defined(TEST_FT)
# include "map.hpp"

namespace ft
#else
# include <map>

namespace std
#endif
{
	typedef map<int, std::string>	map_type;

	void	test_map(void);

	// construct/assign
	void	test_map_default_ctor(void);
	void	test_map_range_ctor(void);
	void	test_map_copy_ctor(void);
	void	test_map_copy_assign(void);
}

#endif
