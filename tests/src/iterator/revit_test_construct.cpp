/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revit_test_construct.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:51:13 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 16:01:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "tests.hpp"
#include "revit_tests.hpp"
#include <vector>

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_revit_default_ctor(void)
	{
		std::cout << "TEST: Default Constructor \n\n";

		explainTest("Constructs a reverse iterator that points to no object.");

		clock_t	start = clock();

		reverse_iterator<int*>	rev_it;

		displayElapsedTime(start, clock());
	}

	void	test_revit_init_ctor(void)
	{
		std::cout << "TEST: Init Constructor \n\n";

		explainTest("Constructs a reverse iterator from some original iterator it.");

		typedef std::vector<int>::iterator	iter_type;

		// create test vector
		std::vector<int>	vec;

		for ( int i = 0; i < 20; i++ )
			vec.push_back(i);

		iter_type	it = vec.begin();
		it += 8;

		reverse_iterator<iter_type>	rev_it(it);

		std::cout << "revit: " << *rev_it << std::endl;

		assert(*rev_it == 7);
	}

	void	test_revit_copy_ctor(void)
	{
		std::cout << "TEST: Copy Constructor \n\n";

		explainTest("Constructs a reverse iterator from some other reverse iterator.");

		std::vector<int>::reverse_iterator	rev_it;

		// create test vector
		std::vector<int>	vec;

		for ( int i = 0; i < 20; i++ )
			vec.push_back(i);

		rev_it = vec.rbegin();

		std::vector<int>::reverse_iterator	rev_it_cpy(rev_it);

		std::cout << "revit: " << *rev_it << std::endl;

		assert(rev_it == rev_it_cpy);
	}
}
