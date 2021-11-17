/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/16 19:46:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include "tests.hpp"
#include "map_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_map(void)
	{
		#if defined(TEST_FT)
		std::cout << std::setw(42) << " MY MAP \n\n";
		#else
		std::cout << std::setw(42) << " ORIGINAL MAP \n\n";
		#endif

		std::map<char,int> m;

		m['b'] = 100;
		m['b'] = 100;
		m['b'] = 100;
		m['b'] = 100;
		m['a'] = 200;
		m['z'] = 200;
		m['c'] = 300;
		m['c'] = 300;
		m['c'] = 300;

		// show content:
		for (std::map<char,int>::iterator it = m.begin(); it != m.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "size: " << m.size() << '\n';
	}
}
