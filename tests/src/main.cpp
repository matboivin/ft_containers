/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:23:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/05 18:34:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "tests.hpp"
#include "vector_tests.hpp"

void	displayElapsedTime(clock_t start, clock_t end)
{
	double	elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << std::fixed << "time: " << elapsed << " seconds\n\n";
}

int	main(void)
{
	#if defined(TEST_FT)
	ft::test_vector();
	#elif defined(TEST_STD)
	std::test_vector();
	#else
		generate_output();
	#endif

	return (0);
}
