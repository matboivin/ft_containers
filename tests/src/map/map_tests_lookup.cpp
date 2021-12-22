/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests_lookup.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/12/21 00:02:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include <string>
#include "tests.hpp"
#include "map_tests.hpp"

#define MAX_RAM 4294967295
#define BUFFER_SIZE 4096

struct Buffer
{
	int		idx;
	char	buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_map_lookup(void)
	{
		std::cout << "TEST: Lookup: count() \n\n";

		explain_test("Returns the number of elements matching key k.");

		int_map		m;


		for (int i = 0; i < 100; ++i)
		{
			m[rand()] = rand();
		}

		int_map::iterator	it = m.end();
		--it;

		clock_t	start = clock();

		std::cout << "m.count(" << it->first << "):  " << m.count(it->first) << "\n\n";

		display_elapsed_time(start, clock());
	}
}
