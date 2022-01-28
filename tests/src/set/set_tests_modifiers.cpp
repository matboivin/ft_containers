/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests_modifiers.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:47:01 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/28 16:01:44 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include "tests.hpp"
#include "set_tests.hpp"

#if defined(TEST_FT)
namespace ft
#else
namespace std
#endif
{
	void	test_set_insert_val(void)
	{
		std::cout << "TEST: Modifiers: insert(val) \n\n";

		explain_test("Insert an element.");

		// create a set
		int_set	s;

		// fill it
		for (int i = 0; i < 10000; ++i)
			s.insert(rand());

		clock_t	time_start = clock();

		// insert a random element
		s.insert(rand());

		display_elapsed_time(time_start, clock());
	}

	void	test_set_insert_pos(void)
	{
		std::cout << "TEST: Modifiers: insert(pos, val) \n\n";

		explain_test("Insert an element giving a hint pos.");

		// create a set
		int_set	m;

		// fill it
		for (int i = 0; i < 10000; ++i)
			s.insert(rand());

		clock_t	time_start = clock();

		// insert a random element
		s.insert(rand());

		display_elapsed_time(time_start, clock());
	}

	void	test_set_insert_range(void)
	{
		std::cout << "TEST: Modifiers: insert(first, last) \n\n";

		explain_test("Insert a range of elements.");

		// create sets
		int_set	s1;
		int_set	s2;

		for (int i = 0; i < 10; ++i)
			s2.insert(rand());

		display_set_infos(s1, "before");

		s1.insert(s2.begin(), s2.end());

		display_set_infos(s1, "after");

		for (int i = 0; i < COUNT; ++i)
			s2.insert(rand());

		clock_t	start = clock();

		s1.insert(s2.begin(), s2.end());

		display_elapsed_time(start, clock());
	}

	void	test_set_erase_range(void)
	{
		std::cout << "TEST: Modifiers: erase() \n\n";

		explain_test("Erase a range of elements from the set.");

		int_set	s;

		s.insert(76);
		s.insert(54);
		s.insert(14);
		s.insert(28);
		s.insert(29);
		s.insert(9);
		s.insert(19);
		s.insert(97);
		s.insert(65);
		s.insert(0);
		s.insert(1);
		s.insert(81);
		s.insert(54);
		s.insert(77);
		s.insert(42);
		s.insert(60);
		s.insert(2);
		s.insert(32);
		s.insert(7);
		s.insert(44);
		s.insert(79);
		s.insert(82);
		s.insert(3);
		s.insert(80);
		s.insert(78);
		s.insert(17);
		s.insert(10);

		display_set_infos(s);

		// test sets
		int_set	cpy_s(s);
		int_set	expected;

		expected.insert(0);
		expected.insert(97);

		int_set::iterator	from = s.find(7);
		int_set::iterator	to = s.find(80);

		std::cout << "Erase range[" << from << ", " << to << ")\n\n";

		s.erase(from, to);
		display_set_infos(s);

		std::cout << "Erase range[" << *(++s.begin()) << ", " << *(--s.end()) << ")\n\n";

		s.erase(++s.begin(), --s.end());
		display_set_infos(s);

		assert(s == expected);

		std::cout << "Erase range[begin, end)\n\n";

		cpy_s.erase(cpy_s.begin(), cpy_s.end());
		display_set_infos(cpy_s);

		assert(cpy_s.empty() == true);
	}

	void	test_set_swap(void)
	{
		std::cout << "TEST: Modifiers: swap() \n\n";

		explain_test("Exchanges the content of the set and the other set.");

		// create sets
		int_set	s1;
		int_set	s2;
		int_set	s3;

		// fill them
		for (int i = 0; i < 5; ++i)
			s1.insert(rand());

		for (int i = 0; i < 500; ++i)
			s2.insert(rand());

		std::cout << "set.swap();\n\n";

		clock_t	time_start = clock();
		s1.swap(s2);
		clock_t	time_end = clock();

		display_elapsed_time(time_start, time_end);

		std::cout << "set.swap();\n\n";

		time_start = clock();
		s1.swap(s3);
		display_elapsed_time(time_start, clock());
	}

	void	test_set_clear(void)
	{
		std::cout << "TEST: Modifiers: clear() \n\n";

		explain_test("Destroys all elements from the container, leaving it with a size of 0.");

		// create a set
		int_set	m;

		// fill it
		for (int i = 0; i < COUNT; ++i)
			s.insert(rand());

		std::cout << "set size: " << s.size()
				  << "\nset.clear();" << std::endl;

		clock_t	time_start = clock();
		s.clear();
		clock_t	time_end = clock();

		std::cout << "set size: " << s.size() << "\n\n";
		display_elapsed_time(time_start, time_end);
	}
}
