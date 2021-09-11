/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:34:57 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/11 18:11:00 by mboivin          ###   ########.fr       */
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
	 * Iterators
	 *
	 * Category Tags: Empty classes to identify categories
	 *
	 * Classes
	 *   iterator
	 *   iterator_traits
	 *   iterator_traits: Partial specialization for pointers
	 *   iterator_traits: Partial specialization for pointers to const
	 *
	 * Predefined iterators
	 *   reverse_iterator
	 */


	/* Category tags ******************************************************** */


	// each value pointed by the iterator is read only once and then the iterator is incremented
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	// access the sequence of elements in a range from its beginning towards its end
	struct forward_iterator_tag : public input_iterator_tag {};
	// access the sequence of elements in a range in both directions
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	// access elements at an arbitrary offset position relative to the element they point to
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};


	/* Classes ************************************************************** */


	/*
	 * Base class to define required types for simple iterators
	 *
	 * @param Category  Category to which the iterator belongs to (Iterator Tags)
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
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	/*
	 * Partial specialization for pointers
	 */
	template< typename T >
	class iterator_traits<T*> {

	public:

		// types
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T*								pointer;
		typedef T&								reference;
	};

	/*
	 * Partial specialization for pointers to const
	 */
	template< typename T >
	class iterator_traits<const T*> {

	public:

		// types
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef const T*						pointer;
		typedef const T&						reference;
	};


	/* Predefined iterators ************************************************* */


	/*
	 * Reverse iterator
	 *
	 * This class reverses the direction in which a bidirectional or
	 * random-access iterator iterates through a range.
	 *
	 * A copy of the original iterator (the base iterator) is kept internally and used
	 * to reflect the operations performed on the reverse_iterator:
	 * whenever the reverse_iterator is incremented, its base iterator is decreased,
	 * and vice versa.
	 * A copy of the base iterator with the current state can be obtained at any time
	 * by calling member base.
	 *
	 * @param Iterator  A bidirectional iterator type
	 *                  Or a random-access iterator
	 */
	template< typename Iterator >
	class reverse_iterator
			: public ft::iterator< typename ft::iterator_traits<Iterator>::iterator_category,
								   typename ft::iterator_traits<Iterator>::value_type,
								   typename ft::iterator_traits<Iterator>::difference_type,
								   typename ft::iterator_traits<Iterator>::pointer,
								   typename ft::iterator_traits<Iterator>::reference >
	{

	public:

		// types
		typedef Iterator	iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

	protected:

		iterator_type	_base; // copy of the original iterator

	public:

		// return copy of the original iterator
		iterator_type	base( void ) const;

	};


	/* Reverse iterator implementation ************************************** */

	// return copy of the original iterator
	template< typename Iterator >
	typename reverse_iterator<Iterator>::iterator_type	reverse_iterator<Iterator>::base( void ) const {

		return (_base);
	}

}

#endif
