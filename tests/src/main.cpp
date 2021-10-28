/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:23:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 16:18:51 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "tests.hpp"
#include "vector_tests.hpp"
#include "revit_tests.hpp"

void	displayElapsedTime(clock_t start, clock_t end)
{
	double	elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << std::fixed << elapsed << " seconds\n\n";
}

void	explainTest(const std::string& msg) {

	std::cout << "Test description: " << msg << "\n\n";
}

int	main(void)
{
	#if defined(TEST_FT)
	ft::test_vector();
	ft::test_revit();
	#elif defined(TEST_STD)
	std::test_vector();
	std::test_revit();
	#else
		generate_output();
	#endif

	return (0);
}
