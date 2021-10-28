/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:23:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/28 18:43:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include "vector_tests.hpp"
#include "revit_tests.hpp"

int	main(void)
{
	#if defined(TEST_FT)
	ft::test_vector();
	// ft::test_revit();
	#elif defined(TEST_STD)
	std::test_vector();
	// std::test_revit();
	#else
		generate_output();
	#endif

	return (0);
}
