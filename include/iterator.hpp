/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:34:57 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/12 13:19:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "utils.hpp"

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

		// attributes
		iterator_type	_baseIterator; // copy of the original iterator

	public:

		// default constructor
		reverse_iterator( void );

		// initalization constructor
		explicit reverse_iterator( iterator_type it );

		// copy constructor
		template< typename Iter >
			reverse_iterator( const reverse_iterator<Iter>& rev_it );

		// assignment operator
		template< typename Iter >
			reverse_iterator&	operator=( const reverse_iterator<Iter>& other );

		// return copy of the original iterator
		iterator_type	base( void ) const;

		// accesses the pointed-to element
		reference	operator*( void ) const;
		reference	operator->( void ) const;

		// accesses an element by index
		reference	operator[]( difference_type n ) const;

		// advances or decrements the iterator
		reverse_iterator&	operator++( void );
		reverse_iterator	operator++( int );
		reverse_iterator&	operator+= ( difference_type n );
		reverse_iterator	operator+( difference_type n ) const;
		reverse_iterator&	operator--( void );
		reverse_iterator	operator--( int );
		reverse_iterator&	operator-=( difference_type n );
		reverse_iterator	operator-( difference_type n ) const;

	};


	/* Reverse iterator implementation ************************************** */


	/* construct/copy/destroy *********************************************** */

	/*
	 * Default constructor
	 * Constructs a reverse iterator that points to no object
	 */
	template< typename Iterator >
	reverse_iterator<Iterator>::reverse_iterator( void ) : _baseIterator(0) {

		std::cout << COL_GREEN
				  << "ft::reverse_iterator default constructor called" << COL_RESET
				  << std::endl;
	}

	/*
	 * Initalization constructor
	 * Constructs a reverse iterator from some original iterator it
	 *
	 * @param it  An iterator
	 */
	template< typename Iterator >
	reverse_iterator<Iterator>::reverse_iterator( iterator_type it ) : _baseIterator(it) {

		std::cout << COL_GREEN
				  << "ft::reverse_iterator initalization constructor called" << COL_RESET
				  << std::endl;
	}

	/*
	 * Copy constructor
	 * Constructs a reverse iterator from some other reverse iterator
	 *
	 * @param rev_it  An iterator of a reverse_iterator type
	 */
	template< typename Iterator >
	template< typename Iter >
	reverse_iterator<Iterator>::reverse_iterator( const reverse_iterator<Iter>& rev_it )
			: _baseIterator( rev_it._baseIterator ) {

		std::cout << COL_GREEN
				  << "ft::reverse_iterator copy constructor called" << COL_RESET
				  << std::endl;
	}

	/*
	 * Assignment operator
	 *
	 * @param other  An iterator of a reverse_iterator type
	 *
	 * @return  *this
	 */
	template< typename Iterator >
	template< typename Iter >
	reverse_iterator<Iterator>&	reverse_iterator<Iterator>::operator=( const reverse_iterator<Iter>& other ) {

		std::cout << COL_GREEN
				  << "ft::reverse_iterator assignment operator called" << COL_RESET
				  << std::endl;

		if ( this != &other )
			_baseIterator = other.base();

		return ( *this );
	}


	/* getter *************************************************************** */


	/*
	 * Returns a copy of the base iterator
	 *
	 * @return  A copy of the base iterator, which iterates in the opposite direction
	 */
	template< typename Iterator >
	typename reverse_iterator<Iterator>::iterator_type	reverse_iterator<Iterator>::base( void ) const {

		return (_baseIterator);
	}


	/* element access ******************************************************* */


	/*
	 * Dereference iterator
	 * Internally, the function decreases a copy of its base iterator and returns
	 * the result of dereferencing it
	 *
	 * @return  A reference to the element pointed by the iterator
	 */
	template< typename Iterator >
	typename reverse_iterator<Iterator>::reference	reverse_iterator<Iterator>::operator*( void ) const {

		iterator_type	copy = _baseIterator;

		--copy;
		return ( *copy );
	}

	/*
	 * Dereference iterator
	 * Internally, the function calls operator* and returns its address
	 *
	 * @return  A pointer to the element pointed to by the iterator
	 */
	template< typename Iterator >
	typename reverse_iterator<Iterator>::reference	reverse_iterator<Iterator>::operator->( void ) const {

		return ( &(operator*()) );
	}

	/*
	 * Dereference iterator with offset
	 * Accesses the element located n positions away from the element
	 * currently pointed to by the iterator.
	 *
	 * @param n  Number of elements to offset
	 *
	 * @return  A reference to the element
	 */
	template< typename Iterator >
	typename reverse_iterator<Iterator>::reference	reverse_iterator<Iterator>::operator[]( difference_type n ) const {

		return ( *(*this + n) );
	}


	/* advance/decrement **************************************************** */

	template< typename Iterator >
	reverse_iterator<Iterator>&	reverse_iterator<Iterator>::operator++( void ) {

		--_baseIterator;
		return ( *this );
	}

	template< typename Iterator >
	reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator++( int ) {

		reverse_iterator	backup = *this;
		--_baseIterator;
		return ( backup );
	}

	template< typename Iterator >
	reverse_iterator<Iterator>&	reverse_iterator<Iterator>::operator+= ( difference_type n ) {

		_baseIterator -= n;
		return ( *this );
	}

	template< typename Iterator >
	reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator+( difference_type n ) const {

		return ( reverse_iterator( _baseIterator - n ) );
	}

	template< typename Iterator >
	reverse_iterator<Iterator>&	reverse_iterator<Iterator>::operator--( void ) {

		++_baseIterator;
		return ( *this );
	}

	template< typename Iterator >
	reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator--( int ) {

		reverse_iterator	backup = *this;
		++_baseIterator;
		return ( backup );
	}

	template< typename Iterator >
	reverse_iterator<Iterator>&	reverse_iterator<Iterator>::operator-=( difference_type n ) {

		_baseIterator += n;
		return ( *this );
	}

	template< typename Iterator >
	reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator-( difference_type n ) const {

		return ( reverse_iterator( _baseIterator + n ) );
	}

}

#endif
