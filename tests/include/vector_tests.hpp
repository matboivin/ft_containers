/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/26 19:02:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTS_HPP
#define VECTOR_TESTS_HPP

#include <iostream>
#include <string>
#include "tests.hpp"

#if defined(TEST_FT)
# include "vector.hpp"

namespace ft
#else
# include <vector>

namespace std
#endif
{
	void	test_vector(void);

	// construct/assign
	void	test_vec_default_ctor(void);
	void	test_vec_fill_ctor(void);
	void	test_vec_copy_ctor(void);
	void	test_vec_range_ctor(void);
	void	test_vec_copy_assign(void);

	// iterators
	void	test_vec_iterator(void);

	// capacity
	void	test_vec_empty(void);
	void	test_vec_size(void);
	void	test_vec_resize(void);
	void	test_vec_max_size(void);
	void	test_vec_capacity(void);
	void	test_vec_reserve(void);

	// elements access
	void	test_vec_at(void);

	// modifiers
	void	test_vec_push_back(void);
}

/*
 * Display the vector size, capacity and content
 */

template<typename Vec>
static void	displayVecInfos(const Vec& v, const std::string& title="vector")
{
	std::cout << title
			  << "\n- size:      " << v.size()
			  << "\n- capacity:  " << v.capacity()
			  << "\n- contents:  ";
			
	if ( !v.size() )
	{
		std::cout << "(empty)\n\n";
		return ;
	}

	std::cout << "[ ";
	for ( typename Vec::const_iterator it = v.begin();
		  it != v.end();
		  ++it )
	{
		std::cout << *it;
		if ( it != (v.end() - 1) )
			std::cout << ", ";
	}
	std::cout << " ]\n\n";
}

#endif
