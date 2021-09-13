/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:25:08 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/13 19:46:02 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <iostream>
#include <memory>
#include "iterator.hpp"
#include "utils.hpp"

/*
 * Credits:
 * Detailed comments mostly from www.cplusplus.com
 */

namespace ft {

	/*
	 * Vector iterator
	 *
	 * vector_iterator definition
	 *   vector_iterator
	 *   const vector_iterator
	 */


	/* Vector iterator definition ******************************************* */

	/*
	 * Vector iterator
	 * A random access iterator to value_type
	 *
	 * @param T  Type of the elements
	 */
	template< typename T >
	class vector_iterator : public ft::iterator<ft::random_access_iterator_tag,T> {

	public:

		// types
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer	pointer;

	protected:

		pointer	_begin;
		pointer	_end;

	};

	/*
	 * Const vector iterator
	 * A random access iterator to value_type
	 *
	 * @param T  Type of the elements
	 */

	template< typename T >
	class const_vector_iterator : public ft::iterator<ft::random_access_iterator_tag,T> {

	public:

		// types
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer	pointer;

	protected:

		const pointer	_begin;
		const pointer	_end;

	};

}

#endif
