/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_iterator.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/02 16:27:39 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "tests.hpp"
#include "vector_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_vec_iterator(void)
	{
		std::cout << "TEST: Iterator \n\n";

		explain_test("Move through the elements of the container like pointers do.");

		// create vector
		vector<int>	vec;

		vec.push_back(12);
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(100);
		vec.push_back(25);

		std::cout << "Print the vector content using iterator:" << std::endl;

		for (vector<int>::iterator it = vec.begin();
			 it != vec.end();
			 ++it)
		{
			std::cout << ' ' << *it;
		}
		std::cout << "\n\n";

		// create iterators
		clock_t	start = clock();
		vector<int>::iterator	it = vec.begin();
		vector<int>::iterator	ite = vec.end();
		display_elapsed_time(start, clock());

		std::cout << "*it      = " << *it
				<< "\n*(--ite) = " << *(--ite)
				<< "\n\n";

		assert(*it == 12);
		assert(*ite == 25);

		// create const iterators
		start = clock();
		vector<int>::const_iterator	const_it = vec.begin();
		vector<int>::const_iterator	const_ite = vec.end();
		display_elapsed_time(start, clock());

		std::cout << std::boolalpha
				  << "(it == const_it)   ? " << (it == const_it)
				  << "\n(ite == const_ite) ? " << (ite == const_ite)
				  << "\n\n";

		// compare
		assert(it == const_it);
		assert((ite == const_ite) == false);

		// move iterators
		const_it += 3;
		const_ite -= 1;

		std::cout << std::boolalpha
				  << "(it == const_it)   ? " << (it == const_it)
				  << "\n(it < const_it)    ? " << (it < const_it)
				  << "\n(it > const_it)    ? " << (it > const_it)
				  << "\n(ite == const_ite) ? " << (ite == const_ite)
				  << "\n\n";

		// compare
		assert((it == const_it) == false);
		assert(it < const_it);
		assert((it > const_it) == false);
		assert(ite == const_ite);
	}

	void	test_vec_rev_iterator(void)
	{
		std::cout << "TEST: Reverse iterator \n\n";

		explain_test("Move through the elements of the container backwards.");

		// create vector
		vector<int>	vec;

		vec.push_back(12);
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(100);
		vec.push_back(25);

		std::cout << "Print the vector content using reverse iterator:" << std::endl;

		for (vector<int>::reverse_iterator rev_it = vec.rbegin();
			 rev_it != vec.rend();
			 ++rev_it)
		{
			std::cout << ' ' << *rev_it;
		}
		std::cout << "\n\n";

		// create iterators
		clock_t	start = clock();
		vector<int>::reverse_iterator	rev_it = vec.rbegin();
		vector<int>::reverse_iterator	rev_ite = vec.rend();
		display_elapsed_time(start, clock());

		std::cout << "*rev_it      = " << *rev_it
				<< "\n*(--rev_ite) = " << *(--rev_ite)
				<< "\n\n";

		assert(*rev_it == 25);
		assert(*rev_ite == 12);

		// create const iterators
		start = clock();
		vector<int>::const_reverse_iterator	const_rev_it = vec.rbegin();
		vector<int>::const_reverse_iterator	const_rev_ite = vec.rend();
		display_elapsed_time(start, clock());

		std::cout << std::boolalpha
				  << "(rev_it == const_rev_it)   ? " << (rev_it == const_rev_it)
				  << "\n(rev_ite == const_rev_ite) ? " << (rev_ite == const_rev_ite)
				  << "\n\n";

		// compare
		assert(rev_it == const_rev_it);
		assert((rev_ite == const_rev_ite) == false);

		// move iterators
		const_rev_it += 3;
		const_rev_ite -= 1;

		std::cout << std::boolalpha
				  << "(rev_it == const_rev_it)   ? " << (rev_it == const_rev_it)
				  << "\n(rev_it < const_rev_it)    ? " << (rev_it < const_rev_it)
				  << "\n(rev_it > const_rev_it)    ? " << (rev_it > const_rev_it)
				  << "\n(rev_ite == const_rev_ite) ? " << (rev_ite == const_rev_ite)
				  << "\n\n";

		// compare
		assert((rev_it == const_rev_it) == false);
		assert(rev_it < const_rev_it);
		assert((rev_it > const_rev_it) == false);
		assert(rev_ite == const_rev_ite);
	}
}
