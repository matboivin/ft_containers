/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:42 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/29 16:20:06 by mboivin          ###   ########.fr       */
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
	void	test_vec_subscript_op(void);
	void	test_vec_at(void);
	void	test_vec_front(void);
	void	test_vec_back(void);

	// modifiers
	void	test_vec_assign_it(void);
	void	test_vec_assign_val(void);
	void	test_vec_push_back(void);
	void	test_vec_insert_val(void);
	void	test_vec_insert_nval(void);
	void	test_vec_insert_it(void);
	void	test_vec_pop_back(void);
	void	test_vec_erase_pos(void);
	void	test_vec_erase_it(void);
	void	test_vec_swap(void);
	void	test_vec_clear(void);

	// non-member functions
	void	test_vec_non_mb_comp_ops(void);
	void	test_vec_non_mb_swap(void);
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

	typename Vec::const_iterator it = v.begin();

	std::cout << "[ ";
	for ( int i = 0; it != v.end(); ++i, ++it )
	{
		std::cout << *it;
		if ( it != (v.end() - 1) )
			std::cout << ", ";
		if ((i != 0) && (i % 10 == 0))
			std::cout << "\n               ";
	}
	std::cout << " ]\n\n";
}

#endif
