/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:23:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/27 23:11:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <time.h> // clock
#include "tests.hpp"
#include "vector_tests.hpp"

void	displayElapsedTime( clock_t start, clock_t end)
{
	double	elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << std::fixed << elapsed << " seconds." << std::endl;
}

int	main( void )
{
	clock_t	start = clock();
	clock_t	end = clock();

	displayElapsedTime(start, end);

	return (0);
}
