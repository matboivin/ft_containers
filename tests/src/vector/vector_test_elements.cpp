/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test_elements.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:32:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/07 18:54:30 by mboivin          ###   ########.fr       */
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
	void	test_vec_at(void)
	{
		std::cout << "TEST: Element access: at() \n\n";

		explainTest("This member function accesses the element at "
					"the specified position in the container.");

		int	n = 2;
		int	out = 15;

		// create vector
		vector<int>	vec;

		vec.push_back(12);
		vec.push_back(5);
		vec.push_back(42);
		vec.push_back(100);
		vec.push_back(25);

		try
		{
			clock_t	start = clock();
			std::cout << "vector.at(" << n << ") " << vec.at(n) << "\n\n";
			displayElapsedTime(start, clock());
		}
		catch (std::out_of_range& oor)
		{
			std::cout << "Catched 'out_of_range':\n" << oor.what() << "\n\n";
		}

		try
		{
			std::cout << "vector.at(" << out << ") " << vec.at(out) << "\n\n";
		}
		catch (std::out_of_range& oor)
		{
			std::cout << "Catched 'out_of_range':\n" << oor.what() << "\n\n";
		}
	}
}
