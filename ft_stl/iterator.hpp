/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:34:57 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/27 15:02:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "utils.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"

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
	 *
	 *   reverse_iterator definition
	 *   reverse_iterator implementation
	 *     construct/copy/destroy
	 *     getter
	 *     element access
	 *     advance/decrease
	 *     non-member function overloads
	 *       relational operators
	 *       operator+
	 *       operator-
	 *
	 *   base_iterator definition
	 *   base_iterator implementation
	 *     non-member function overloads
	 *       relational operators
	 *       operator+
	 *       operator-
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
	 * @param Iterator  The iterator type to retrieve properties for iterators
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

		iterator_type	current; // copy of the original iterator

	public:

		// default constructor
		reverse_iterator( void );

		// initalization constructor
		explicit reverse_iterator( iterator_type it );

		// copy constructor
		template< typename Iter >
			reverse_iterator( const reverse_iterator<Iter>& rev_it );

		// return copy of the original iterator
		iterator_type	base( void ) const;

		// accesses the pointed-to element
		reference	operator*( void ) const;
		pointer		operator->( void ) const;

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
	reverse_iterator<Iterator>::reverse_iterator( void ) : current(0) {

		return ;
	}

	/*
	 * Initalization constructor
	 * Constructs a reverse iterator from some original iterator it.
	 * The behavior of the constructed object replicates the original,
	 * except that it iterates through its pointed elements in the reverse order.
	 *
	 * @param it  An iterator
	 */
	template< typename Iterator >
	reverse_iterator<Iterator>::reverse_iterator( iterator_type it ) : current(it) {

		return ;
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
			: current( rev_it.base() ) {

		return ;
	}

	/* getter *************************************************************** */

	/*
	 * Returns a copy of the base iterator
	 *
	 * @return  A copy of the base iterator, which iterates in the opposite direction
	 */
	template< typename Iterator >
	typename reverse_iterator<Iterator>::iterator_type
	reverse_iterator<Iterator>::base( void ) const {

		return (current);
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
	typename reverse_iterator<Iterator>::reference
	reverse_iterator<Iterator>::operator*( void ) const {

		iterator_type	copy = current;

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
	typename reverse_iterator<Iterator>::pointer
	reverse_iterator<Iterator>::operator->( void ) const {

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
	typename reverse_iterator<Iterator>::reference
	reverse_iterator<Iterator>::operator[]( difference_type n ) const {

		return ( *(*this + n) );
	}


	/* advance/decrease ***************************************************** */

	/*
	 * Increment iterator position: pre-increment version
	 *
	 * @return  *this
	 */
	template< typename Iterator >
	reverse_iterator<Iterator>&
	reverse_iterator<Iterator>::operator++( void ) {

		--current;
		return ( *this );
	}

	/*
	 * Increment iterator position: post-increment version
	 *
	 * @return  A copy of *this that was made before the change
	 */
	template< typename Iterator >
	reverse_iterator<Iterator>
	reverse_iterator<Iterator>::operator++( int ) {

		reverse_iterator	backup = *this;
		++(*this);
		return ( backup );
	}

	/*
	 * Advance iterator
	 * Advances the reverse_iterator by n element positions
	 *
	 * @param n  Number of elements to offset
	 *
	 * @return  *this
	 */
	template< typename Iterator >
	reverse_iterator<Iterator>&
	reverse_iterator<Iterator>::operator+=( difference_type n ) {

		current -= n;
		return ( *this );
	}

	/*
	 * Addition operator
	 *
	 * @param n  Number of elements to offset
	 *
	 * @return  An iterator pointing to the element n positions away
	 */
	template< typename Iterator >
	reverse_iterator<Iterator>
	reverse_iterator<Iterator>::operator+( difference_type n ) const {

		return ( reverse_iterator( base() - n ) );
	}

	/*
	 * Decrease iterator position: pre-decrement version
	 *
	 * @return  *this
	 */
	template< typename Iterator >
	reverse_iterator<Iterator>&
	reverse_iterator<Iterator>::operator--( void ) {

		++current;
		return ( *this );
	}

	/*
	 * Decrease iterator position: post-decrement version
	 *
	 * @return  A copy of *this that was made before the change
	 */
	template< typename Iterator >
	reverse_iterator<Iterator>
	reverse_iterator<Iterator>::operator--( int ) {

		reverse_iterator	backup = *this;
		--(*this);
		return ( backup );
	}

	/*
	 * Retrocede iterator
	 * Decreases the reverse_iterator by n element positions
	 *
	 * @param n  Number of elements to offset
	 *
	 * @return  *this
	 */
	template< typename Iterator >
	reverse_iterator<Iterator>&
	reverse_iterator<Iterator>::operator-=( difference_type n ) {

		current += n;
		return ( *this );
	}

	/*
	 * Subtraction operator
	 *
	 * @param n  Number of elements to offset
	 *
	 * @return  An iterator pointing to the element n positions before the currently pointed one
	 */
	template< typename Iterator >
	reverse_iterator<Iterator>
	reverse_iterator<Iterator>::operator-( difference_type n ) const {

		return ( reverse_iterator( base() + n ) );
	}


	/* non-member function overloads **************************************** */

	/*
	 * relational operators
	 */

	template< typename Iterator >
	bool	operator==( const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs ) {

		return ( lhs.base() == rhs.base() );
	}

	template< typename Iterator >
	bool	operator!=( const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs ) {

		return ( lhs.base() != rhs.base() );
	}

	template< typename Iterator >
	bool	operator<( const reverse_iterator<Iterator>& lhs,
					   const reverse_iterator<Iterator>& rhs ) {
		return ( lhs.base() > rhs.base() );
	}

	template< typename Iterator >
	bool	operator<=( const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs ) {
		return ( lhs.base() >= rhs.base() );
	}

	template< typename Iterator >
	bool	operator>( const reverse_iterator<Iterator>& lhs,
					   const reverse_iterator<Iterator>& rhs ) {
		return ( lhs.base() < rhs.base() );
	}

	template< typename Iterator >
	bool	operator>=( const reverse_iterator<Iterator>& lhs,
						const reverse_iterator<Iterator>& rhs ) {
		return ( lhs.base() <= rhs.base() );
	}

	/*
	 * Addition operator
	 * Returns a reverse iterator pointing to the element located n positions
	 * away from the element pointed to by rev_it
	 *
	 * @param n       Number of elements to offset
	 * @param rev_it  Reverse iterator
	 *
	 * @return  An iterator pointing to the element n positions away from rev_it
	 */
	template< typename Iterator >
	reverse_iterator<Iterator>
	operator+( typename reverse_iterator<Iterator>::difference_type n,
			   const reverse_iterator<Iterator>& rev_it ) {

		return ( reverse_iterator<Iterator>( rev_it.base() - n ) );
	}

	/*
	 * Subtraction operator
	 * Computes the distance between two reverse iterators
	 * The function returns the same as subtracting lhs's base iterator from rhs's base iterator
	 *
	 * @param lhs, rhs  reverse_iterator objects having both the same template parameter
	 *
	 * @return  The number of elements between lhs and rhs
	 */
	template< typename Iterator >
	typename reverse_iterator<Iterator>::difference_type
	operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {

		return ( rhs.base() - lhs.base() );
	}


	/* Base iterator definition ********************************************* */

	/*
	 * Base iterator
	 *
	 * This class provides a base for custom iterators
	 *
	 * @param Iterator   The iterator type
	 * @param Container  The container
	 */

	template< typename Iterator, typename Container >
	class base_iterator
			: public ft::iterator< typename ft::iterator_traits<Iterator>::iterator_category,
								   typename ft::iterator_traits<Iterator>::value_type,
								   typename ft::iterator_traits<Iterator>::difference_type,
								   typename ft::iterator_traits<Iterator>::pointer,
								   typename ft::iterator_traits<Iterator>::reference >
	{

	private:

		// More readable private alias
		typedef typename ft::iterator_traits<Iterator>	_iter_traits;

	public:

		// types
		typedef Iterator	iterator_type;
		typedef typename _iter_traits::iterator_category	iterator_category;
		typedef typename _iter_traits::value_type			value_type;
		typedef typename _iter_traits::difference_type		difference_type;
		typedef typename _iter_traits::pointer				pointer;
		typedef typename _iter_traits::reference			reference;

	protected:

		iterator_type	current; // copy of the original iterator

	public:

		// default constructor
		base_iterator( void );

		// initalization constructor
		explicit base_iterator( iterator_type it );

		// copy constructor
		template< typename Iter >
			base_iterator( const base_iterator<Iter, Container>& it );

		// return copy of the original iterator
		iterator_type	base( void ) const;

		// accesses the pointed-to element
		reference	operator*( void ) const;
		pointer		operator->( void ) const;

		// accesses an element by index
		reference	operator[]( difference_type n ) const;

		// advances or decrements the iterator
		base_iterator&	operator++( void );
		base_iterator	operator++( int );
		base_iterator&	operator+= ( difference_type n );
		base_iterator	operator+( difference_type n ) const;
		base_iterator&	operator--( void );
		base_iterator	operator--( int );
		base_iterator&	operator-=( difference_type n );
		base_iterator	operator-( difference_type n ) const;

	};


	/* Base iterator implementation ***************************************** */

	/* construct/copy/destroy *********************************************** */

	/*
	 * Default constructor
	 * Constructs an iterator that points to no object
	 */
	template< typename Iterator, typename Container >
	base_iterator<Iterator, Container>::base_iterator( void ) : current(0) {

		return ;
	}

	/*
	 * Initalization constructor
	 * Constructs an iterator from some original iterator it.
	 *
	 * @param it  An iterator
	 */
	template< typename Iterator, typename Container >
	base_iterator<Iterator, Container>::base_iterator( iterator_type it ) : current(it) {

		return ;
	}

	/*
	 * Copy constructor
	 * Constructs an iterator from some other iterator
	 *
	 * @param it  An iterator of a base_iterator type
	 */
	template< typename Iterator, typename Container >
	template< typename Iter >
	base_iterator<Iterator, Container>::base_iterator( const base_iterator<Iter, Container>& it )
			: current( it.base() ) {

		return ;
	}

	/* getter *************************************************************** */

	/*
	 * Returns a copy of the base iterator
	 *
	 * @return  A copy of the base iterator
	 */
	template< typename Iterator, typename Container >
	typename base_iterator<Iterator, Container>::iterator_type
	base_iterator<Iterator, Container>::base( void ) const {

		return (current);
	}


	/* element access ******************************************************* */

	/*
	 * Dereference iterator
	 *
	 * @return  A reference to the element pointed by the iterator
	 */
	template< typename Iterator, typename Container >
	typename base_iterator<Iterator, Container>::reference
	base_iterator<Iterator, Container>::operator*( void ) const {

		return ( *current );
	}

	/*
	 * Dereference iterator
	 *
	 * @return  A pointer to the element pointed to by the iterator
	 */
	template< typename Iterator, typename Container >
	typename base_iterator<Iterator, Container>::pointer
	base_iterator<Iterator, Container>::operator->( void ) const {

		return ( current );
	}

	/*
	 * Dereference iterator with offset
	 *
	 * @param n  Number of elements to offset
	 *
	 * @return  A reference to the element
	 */
	template< typename Iterator, typename Container >
	typename base_iterator<Iterator, Container>::reference
	base_iterator<Iterator, Container>::operator[]( difference_type n ) const {

		return ( current[n] );
	}


	/* advance/decrease ***************************************************** */

	/*
	 * Increment iterator position: pre-increment version
	 *
	 * @return  *this
	 */
	template< typename Iterator, typename Container >
	base_iterator<Iterator, Container>&
	base_iterator<Iterator, Container>::operator++( void ) {

		++current;
		return ( *this );
	}

	/*
	 * Increment iterator position: post-increment version
	 *
	 * @return  A copy of *this that was made before the change
	 */
	template< typename Iterator, typename Container >
	base_iterator<Iterator, Container>
	base_iterator<Iterator, Container>::operator++( int ) {

		base_iterator	backup = *this;
		++current;
		return ( backup );
	}

	/*
	 * Advance iterator
	 * Advances the base_iterator by n element positions
	 *
	 * @param n  Number of elements to offset
	 *
	 * @return  *this
	 */
	template< typename Iterator, typename Container >
	base_iterator<Iterator, Container>&
	base_iterator<Iterator, Container>::operator+=( difference_type n ) {

		current -= n;
		return ( *this );
	}

	/*
	 * Addition operator
	 *
	 * @param n  Number of elements to offset
	 *
	 * @return  An iterator pointing to the element n positions away
	 */
	template< typename Iterator, typename Container >
	base_iterator<Iterator, Container>
	base_iterator<Iterator, Container>::operator+( difference_type n ) const {

		return ( base_iterator( base() + n ) );
	}

	/*
	 * Decrease iterator position: pre-decrement version
	 *
	 * @return  *this
	 */
	template< typename Iterator, typename Container >
	base_iterator<Iterator, Container>&
	base_iterator<Iterator, Container>::operator--( void ) {

		--current;
		return ( *this );
	}

	/*
	 * Decrease iterator position: post-decrement version
	 *
	 * @return  A copy of *this that was made before the change
	 */
	template< typename Iterator, typename Container >
	base_iterator<Iterator, Container>
	base_iterator<Iterator, Container>::operator--( int ) {

		base_iterator	backup = *this;
		--current;
		return ( backup );
	}

	/*
	 * Retrocede iterator
	 * Decreases the base_iterator by n element positions
	 *
	 * @param n  Number of elements to offset
	 *
	 * @return  *this
	 */
	template< typename Iterator, typename Container >
	base_iterator<Iterator, Container>&
	base_iterator<Iterator, Container>::operator-=( difference_type n ) {

		current += n;
		return ( *this );
	}

	/*
	 * Subtraction operator
	 *
	 * @param n  Number of elements to offset
	 *
	 * @return  An iterator pointing to the element n positions before the currently pointed one
	 */
	template< typename Iterator, typename Container >
	base_iterator<Iterator, Container>
	base_iterator<Iterator, Container>::operator-( difference_type n ) const {

		return ( base_iterator( base() - n ) );
	}


	/* non-member function overloads **************************************** */

	/*
	 * relational operators
	 */

	template< typename Iterator, typename Container >
	bool	operator==( const base_iterator<Iterator, Container>& lhs,
						const base_iterator<Iterator, Container>& rhs ) {

		return ( lhs.base() == rhs.base() );
	}

	template< typename Iterator, typename Container >
	bool	operator!=( const base_iterator<Iterator, Container>& lhs,
						const base_iterator<Iterator, Container>& rhs ) {

		return ( lhs.base() != rhs.base() );
	}

	template< typename Iterator, typename Container >
	bool	operator<( const base_iterator<Iterator, Container>& lhs,
					   const base_iterator<Iterator, Container>& rhs ) {
		return ( lhs.base() > rhs.base() );
	}

	template< typename Iterator, typename Container >
	bool	operator<=( const base_iterator<Iterator, Container>& lhs,
						const base_iterator<Iterator, Container>& rhs ) {
		return ( lhs.base() >= rhs.base() );
	}

	template< typename Iterator, typename Container >
	bool	operator>( const base_iterator<Iterator, Container>& lhs,
					   const base_iterator<Iterator, Container>& rhs ) {
		return ( lhs.base() < rhs.base() );
	}

	template< typename Iterator, typename Container >
	bool	operator>=( const base_iterator<Iterator, Container>& lhs,
						const base_iterator<Iterator, Container>& rhs ) {
		return ( lhs.base() <= rhs.base() );
	}

	/*
	 * Addition operator
	 * Returns a base iterator pointing to the element located n positions
	 * away from the element pointed to by it
	 *
	 * @param n   Number of elements to offset
	 * @param it  Base iterator
	 *
	 * @return  An iterator pointing to the element n positions away from it
	 */
	template< typename Iterator, typename Container >
	base_iterator<Iterator, Container>
	operator+( typename base_iterator<Iterator, Container>::difference_type n,
			   const base_iterator<Iterator, Container>& it ) {

		return ( base_iterator<Iterator, Container>( it.base() + n ) );
	}

	/*
	 * Subtraction operator
	 * Computes the distance between two base iterators
	 * The function returns the same as subtracting lhs's base iterator from rhs's base iterator
	 *
	 * @param lhs, rhs  base_iterator objects having both the same template parameter
	 *
	 * @return  The number of elements between lhs and rhs
	 */
	template< typename Iterator, typename Container >
	typename base_iterator<Iterator, Container>::difference_type
	operator-( const base_iterator<Iterator, Container>& lhs,
			   const base_iterator<Iterator, Container>& rhs) {

		return ( rhs.base() - lhs.base() );
	}

}

#endif
