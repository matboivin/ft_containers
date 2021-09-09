/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:34:57 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/09 19:33:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/*
 * Credits:
 * Detailed comments mostly from www.cplusplus.com
 */

namespace ft {

	/*
	 * Base class to ease the definition of required types for simple iterators
	 *
	 * This is a base class template that can be used to derive iterator classes
	 * from it. It is not an iterator class and does not provide any of the functionality
	 * an iterator is expected to have.
	 *
	 * @param T         Type of elements pointed by the iterator
	 * @param Distance  Type to represent the difference between two iterators
	 * @param Pointer   Type to represent a pointer to an element pointed by the iterator
	 * @param Reference Type to represent a reference to an element pointed by the iterator
	 */
	template< typename Category, typename T, typename Distance = std::ptrdiff_t,
			  typename Pointer = T*, typename Reference = T& >
	class iterator {

	public:

		// types
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};

	/*
	 * Uniform interface to the properties of an iterator
	 *
	 * @param Iterator  The iterator type to retrieve properties for
	 */
	template< typename Iterator >
	class iterator_traits {

	public:

		// types
		typedef Iterator::iterator_category	iterator_category;
		typedef Iterator::value_type		value_type;
		typedef Iterator::difference_type	difference_type;
		typedef Iterator::pointer			pointer;
		typedef Iterator::reference			reference;
	};

	/*
	 * Specialization for pointers
	 */
	template< typename iterator_traits<T*> >
	class iterator_traits {

	public:

		// types
		//typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T*								pointer;
		typedef T&								reference;
	};

	/*
	 * Specialization for pointers to const
	 */
	template< typename iterator_traits<const T*> >
	class iterator_traits {

	public:

		// types
		//typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef const T*						pointer;
		typedef const T&						reference;
	};
}

#endif
