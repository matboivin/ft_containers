/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:25:08 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/14 19:51:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

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
	 * Vector
	 *
	 * vector definition
	 *
	 * vector implementation
	 *   construct/copy/destroy
	 *   capacity
	 *   element access
	 *   modifiers
	 *
	 * non-member function overloads
	 *   relational operators
	 *   swap
	 */


	/* Vector definition **************************************************** */

	/*
	 * Vector template class
	 * Array which size can change dynamically
	 *
	 * @param T      Type of the elements
	 * @param Alloc  Type of the allocator object used to define the storage
	 *               allocation model
	 */
	template< typename T, typename Alloc = std::allocator<T> >
	class vector {

	public:

		// types
		typedef T														value_type;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef std::size_t												size_type;
		typedef ft::base_iterator<pointer, vector>						iterator;
		typedef ft::base_iterator<const_pointer, vector>				const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;

	private:

		// attributes
		allocator_type	_alloc;    // The container keeps and uses an internal copy of the allocator
		size_type		_size;     // number of elements
		size_type		_capacity;
		value_type*		_elements;

		pointer			_begin;
		pointer			_end;

		// calculate capacity growth
		size_type		calculateGrowth( const size_type newSize) const;

	public:

		// default constructor
		vector( const allocator_type& alloc = allocator_type() );

		// fill constructor
		vector( size_type n,
				const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type() );
		
		// range constructor
		// template< typename InputIterator >
		// 	vector( InputIterator first,
		// 			InputIterator last,
		// 			const allocator_type& alloc = allocator_type() );

		// copy constructor
		vector( const vector& x );

		// destructor
		~vector( void );

		// assignment operator
		vector&	operator=( const vector& rhs );

		// allocator
		allocator_type	get_alloc( void ) const;

		// iterators
		iterator				begin( void );
		// const_iterator			begin( void ) const;
		iterator				end( void );
		// const_iterator			end( void ) const;
		reverse_iterator		rbegin( void );
		reverse_iterator		rend( void );

		// capacity
		bool		empty( void ) const;
		size_type	size( void ) const;
		// void		resize( size_type n, value_type val = value_type() );
		size_type	max_size( void ) const;
		size_type	capacity( void ) const;
		void		reserve( size_type n );

		// element access
		reference		operator[]( size_type n );
		const_reference	operator[]( size_type n ) const;
		reference		at( size_type n );
		const_reference	at( size_type n ) const;
		reference		front( void );
		const_reference	front( void ) const;
		reference		back( void );
		const_reference	back( void ) const;

		// modifiers
		// template< typename InputIterator >
		// 	void	assign( InputIterator first, InputIterator last );
		void		assign( size_type n, const value_type& val );
		void		push_back( const value_type& val );
		void		pop_back( void );
		// iterator	insert( iterator position, const value_type& val );
		// void		insert( iterator position, size_type n, const value_type& val );
		// template< typename InputIterator >
		// 	void	insert( iterator position, InputIterator first, InputIterator last );
		// iterator	erase( iterator position );
		// iterator	erase( iterator first, iterator last );
		// void		swap( vector& x );
		void		clear( void );
	};


	/* Vector implementation ************************************************ */


	/* construct/copy/destroy *********************************************** */


	/*
	 * Default constructor
	 * Constructs an empty container, with no elements.
	 *
	 * @param alloc  Allocator object
	 */
	template< typename T, typename Alloc >
	vector<T,Alloc>::vector( const allocator_type& alloc )
			: _alloc(alloc),
			  _size(0),
			  _capacity(0),
			  _elements(),
			  _begin(),
			  _end() {

		std::cout << COL_GREEN
				  << "ft::vector default constructor called" << COL_RESET
				  << std::endl;
	}

	/*
	 * Fill constructor
	 * Constructs a container with n elements. Each element is a copy of val.
	 *
	 * @param n      Initial container size
	 * @param val    Value to fill the container with
	 * @param alloc  Allocator object
	 */
	template< typename T, typename Alloc >
	vector<T,Alloc>::vector( size_type n,
								 const value_type& val,
								 const allocator_type& alloc )
			: _alloc(alloc),
			  _size(n),
			  _capacity(n) {

		std::cout << COL_GREEN
				  << "ft::vector fill constructor called" << COL_RESET
				  << std::endl;

		_elements = _alloc.allocate(n);

		for ( size_type i = 0; i < n; i++ )
			_alloc.construct( _elements + i, val );

		_begin = &(_elements[0]);
		_end = &(_elements[_size]);

	}

	/*
	 * Range constructor
	 * Constructs a container with as many elements as the range [first,last),
	 * with each element constructed from its corresponding element in that range,
	 * in the same order.
	 *
	 * @param alloc        Allocator object
	 * @param first, last  Input iterators to the initial and final positions in a range
	 */
	// template< typename T, typename Alloc >
	// template< typename InputIterator >
	// vector<T,Alloc>::vector( InputIterator first, InputIterator last,
	// 							const allocator_type& alloc = allocator_type() ) {
	// 		: _alloc(alloc) {

	// 	std::cout << "ft::vector range constructor called" << std::endl;
	// }

	/*
	 * Copy constructor
	 * Constructs a container with a copy of each of the elements in x, in the same order.
	 *
	 * @param x  Another vector object of the same type
	 *           (with the same class template arguments T and Allocator)
	 */
	template< typename T, typename Alloc >
	vector<T,Alloc>::vector( const vector& x )
			: _alloc( x._alloc ),
			  _size( x.size() ),
			  _capacity( x.capacity() ) {

		std::cout << COL_GREEN
				  << "ft::vector copy constructor called" << COL_RESET
				  << std::endl;

		_elements = _alloc.allocate( x.size() );

		for ( size_type i = 0; i < _size; i++ )
			_alloc.construct( _elements + i, x[i]);
		
		_begin = &(_elements[0]);
		_end = &(_elements[_size]);
	}

	/*
	 * Destructor
	 *
	 * Destroys all container elements, and deallocates all the storage capacity
	 * allocated by the vector using its allocator.
	 */
	template< typename T, typename Alloc >
	vector<T,Alloc>::~vector( void ) {

		std::cout << COL_YELLOW
				  << "ft::vector destructor called" << COL_RESET
				  << std::endl;

		for ( size_type i = 0; i < _size; i++ )
			_alloc.destroy( _elements + i );

		_alloc.deallocate( _elements, _capacity );
	}

	/*
	 * Assignment operator
	 *
	 * Assigns new contents to the container, replacing its current contents,
	 * and modifying its size accordingly.
	 * The container preserves its current allocator, which is used to allocate storage
	 * in case of reallocation.
	 *
	 * @param x  Another vector object of the same type
	 *           (with the same class template arguments T and Allocator)
	 *
	 * @return  *this
	 */
	template< typename T, typename Alloc >
	vector<T,Alloc>&	vector<T,Alloc>::operator=( const vector& rhs ) {

		std::cout << COL_GREEN
				  << "ft::vector assignment operator called" << COL_RESET
				  << std::endl;

		if ( this != &rhs ) {

			for ( size_type i = 0; i < _size; i++ )
				_alloc.destroy( _elements + i );

			_alloc.deallocate( _elements, _capacity );

			_size = rhs.size();
			if ( _size > _capacity )
				_capacity = _size;

			_elements = _alloc.allocate( _size );

			for ( size_type i = 0; i < _size; i++ )
				_alloc.construct( _elements + i, rhs[i]);

			_begin = &(_elements[0]);
			_end = &(_elements[_size]);
		}

		return ( *this );
	}


	/* allocator ************************************************************ */

	/*
	 * Returns a copy of the allocator object associated with the vector.
	 *
	 * @return  The allocator
	 */
	template< typename T, typename Alloc >
	typename vector<T,Alloc>::allocator_type	vector<T,Alloc>::get_alloc( void ) const {

		return ( static_cast<allocator_type>(_alloc) );
	}


	/* iterators ************************************************************ */

	/*
	 * Returns an iterator pointing to the first element in the vector
	 *
	 * @return  An iterator to the beginning of the sequence container
	 */
	template< typename T, typename Alloc >
	typename vector<T,Alloc>::iterator	vector<T,Alloc>::begin( void ) {

		return ( iterator(_begin) );
	}

	/*
	 * Returns an iterator referring to the past-the-end element
	 * in the vector container
	 *
	 * @return  An iterator to the element past the end of the sequence
	 */
	template< typename T, typename Alloc >
	typename vector<T,Alloc>::iterator	vector<T,Alloc>::end( void ) {

		return ( iterator(_end) );
	}

	/*
	 * Returns a reverse iterator pointing to the last element in the vector
	 *
	 * @return  A reverse iterator to the reverse beginning of the sequence container
	 */
	template< typename T, typename Alloc >
	typename vector<T,Alloc>::reverse_iterator	vector<T,Alloc>::rbegin( void ) {

		return ( reverse_iterator(end()) );
	}

	/*
	 * Returns a reverse iterator pointing to the theoretical element preceding
	 * the first element in the vector
	 *
	 * @return  A reverse iterator to the reverse end of the sequence container
	 */
	template< typename T, typename Alloc >
	typename vector<T,Alloc>::reverse_iterator	vector<T,Alloc>::rend( void ) {

		return ( reverse_iterator(begin()) );
	}


	/* capacity ************************************************************* */


	/*
	 * Checks whether the vector is empty (i.e. whether its size is 0).
	 *
	 * @return  true if the container size is 0, false otherwise
	 */
	template< typename T, typename Alloc >
	bool	vector<T,Alloc>::empty( void ) const {

		return ( _size == 0 );
	}

	/*
	 * Get the size of the vector
	 *
	 * @return  The number of elements in the vector
	 */
	template< typename T, typename Alloc >
	typename vector<T,Alloc>::size_type	vector<T,Alloc>::size( void ) const {

		return ( _size );
	}

	/*
	 * Gets the maximum number of elements that the vector can hold.
	 *
	 * This is the maximum potential size the container can reach due to known system
	 * or library implementation limitations.
	 *
	 * @return  The maximum number of elements a vector container can hold as content
	 */
	template< typename T, typename Alloc >
	typename vector<T,Alloc>::size_type	vector<T,Alloc>::max_size( void ) const {

		return ( _alloc.max_size() );
	}

	/*
	 * Resizes the container so that it contains n elements.
	 *
	 * If n is smaller than the current container size, the content is reduced to
	 * its first n elements, removing those beyond (and destroying them).
	 *
	 * If n is greater than the current container size, the content is expanded
	 * by inserting at the end as many elements as needed to reach a size of n.
	 *
	 * If val is specified, the new elements are initialized as copies of val,
	 * otherwise, they are value-initialized.
	 *
	 * If n is also greater than the current container capacity, an automatic reallocation
	 * of the allocated storage space takes place.
	 *
	 * @param n    New container size, expressed in number of elements
	 * @param val  Object whose content is copied to the added elements in case that n
	 *             is greater than the current container size.
	 *             If not specified, the default constructor is used instead.
	 */

	// TODO
	// insert, erase
	// template< typename T, typename Alloc >
	// void	vector<T,Alloc>::resize( size_type n, value_type val = value_type() ) {

	// 	if ( n < size() )
			

	// 	else if ( n > size() )
			
	// }

	/*
	 * Calculates capacity growth (private member function to help)
	 */
	template< typename T, typename Alloc >
	typename vector<T,Alloc>::size_type	vector<T,Alloc>::calculateGrowth( const size_type newSize) const {

		const size_type	currCapacity = _capacity;
		size_type		capacityLeft = max_size() - currCapacity;

		// handle overflow
		if ( currCapacity > capacityLeft )
			return ( max_size() );

		const size_type	newCapacity = currCapacity + currCapacity;

		if ( newSize > newCapacity )
			return ( newSize );

		return ( newCapacity );
	}

	/*
	 * Gets the size of allocated storage capacity
	 * i.e., size of the storage space currently allocated for the vector,
	 * expressed in terms of elements.
	 *
	 * @return  The size of the currently allocated storage capacity in the vector
	 */
	template< typename T, typename Alloc >
	typename vector<T,Alloc>::size_type	vector<T,Alloc>::capacity( void ) const {

		return ( _capacity );
	}

	/*
	 * Requests that the vector capacity be at least enough to contain n elements.
	 *
	 * If n is greater than the current vector capacity, the function causes
	 * the container to reallocate its storage increasing its capacity to n or greater
	 *
	 * @param n  Minimum capacity for the vector
	 *           Note that the resulting vector capacity may be equal or greater than n
	 */
	template< typename T, typename Alloc >
	void	vector<T,Alloc>::reserve( size_type n ) {

		if ( n <= capacity() )
			return ;

		size_type	newCapacity = calculateGrowth(n);
		value_type*	newElements = _alloc.allocate(newCapacity);

		for ( size_type i = 0; i < _size; i++ ) {

			_alloc.construct( newElements + i, _elements[i]);
			_alloc.destroy( _elements + i );
		}

		_alloc.deallocate( _elements, _capacity );
		_elements = newElements;
		_capacity = newCapacity;
		_begin = &(_elements[0]);
		_end = &(_elements[_size]);
	}


	/* element access ******************************************************* */


	/*
	 * Access an element of the vector
	 *
	 * @param n  Position of an element in the container
	 *
	 * @return  A reference to the element at position n in the vector container
	 *
	 * @exceptsafe If the container size is greater than n, the function
	 * never throws exceptions.
	 * Otherwise, the behavior is undefined.
	 */
	template< typename T, typename Alloc >
	typename vector<T,Alloc>::reference	vector<T,Alloc>::operator[]( size_type n ) {

		return ( _elements[n] );
	}

	template< typename T, typename Alloc >
	typename vector<T,Alloc>::const_reference	vector<T,Alloc>::operator[]( size_type n ) const {

		return ( _elements[n] );
	}

	/*
	 * Access an element of the vector
	 *
	 * @param n  Position of an element in the container
	 *
	 * @return  The element at the specified position in the container
	 *
	 * @exceptsafe If n is out of bounds, out_of_range si thrown
	 */
	template< typename T, typename Alloc >
	typename vector<T,Alloc>::reference	vector<T,Alloc>::at( size_type n ) {

		if ( n > size() )
			throw std::out_of_range("ft::vector::_M_range_check");

		return ( _elements[n] );
	}

	template< typename T, typename Alloc >
	typename vector<T,Alloc>::const_reference	vector<T,Alloc>::at( size_type n ) const {

		if ( n > size() )
			throw std::out_of_range("ft::vector::_M_range_check");

		return ( _elements[n] );
	}

	/*
	 * Access the first element in the vector
	 *
	 * @return  A reference to the first element in the vector container
	 */
	template< typename T, typename Alloc >
	typename vector<T,Alloc>::reference	vector<T,Alloc>::front( void ) {

		return ( _elements[0] );
	}

	template< typename T, typename Alloc >
	typename vector<T,Alloc>::const_reference	vector<T,Alloc>::front( void ) const {

		return ( _elements[0] );
	}

	/*
	 * Access the last element in the vector
	 *
	 * @return  A reference to the last element in the vector container
	 */
	template< typename T, typename Alloc >
	typename vector<T,Alloc>::reference	vector<T,Alloc>::back( void ) {

		size_type	idx = size() - 1;

		return ( _elements[idx] );
	}

	template< typename T, typename Alloc >
	typename vector<T,Alloc>::const_reference	vector<T,Alloc>::back( void ) const {

		size_type	idx = size() - 1;

		return ( _elements[idx] );
	}


	/* modifiers ************************************************************ */


	/*
	 * Assigns new contents to the vector, replacing its current contents,
	 * and modifying its size accordingly.
	 *
	 * The new contents are elements constructed from each of the elements
	 * in the range between first and last, in the same order.
	 *
	 * @param first, last  Input iterators to the initial and final positions in a sequence
	 */
	// template< typename T, typename Alloc >
	// template< typename InputIterator >
	// void	vector<T,Alloc>::assign( InputIterator first, InputIterator last ) {

	// 	this->clear();
	// 	_size = std::distance(first, last);
	// 	// TODO capacity
	// 	_elements = _alloc.allocate(_size);
	// 	_alloc.construct( _elements, val );
	// }

	/*
	 * Assigns new contents to the vector, replacing its current contents,
	 * and modifying its size accordingly.
	 *
	 * @param n    New size for the container
	 * @param val  Value to fill the container with. Each of the n elements in
	 *             the container will be initialized to a copy of this value
	 */
	template< typename T, typename Alloc >
	void	vector<T,Alloc>::assign( size_type n, const value_type& val ) {

		size_type	oldSize = _size;

		this->clear();

		if ( n != oldSize ) {

			_alloc.deallocate( _elements, _capacity );
			_elements = _alloc.allocate(n);
		}

		if ( n > _capacity )
			_capacity = calculateGrowth(n);

		_size = n;
		for ( size_type i = 0; i < n; i++ )
			_alloc.construct( _elements + i, val );

		_begin = &(_elements[0]);
		_end = &(_elements[_size]);
	}

	/*
	 * Adds a new element at the end of the vector, after its current last element.
	 *
	 * If the new vector size surpasses the current vector capacity,
	 * it causes an automatic reallocation of the allocated storage space.
	 *
	 * @param val  Value to be copied (or moved) to the new element
	 */
	template< typename T, typename Alloc >
	void	vector<T,Alloc>::push_back( const value_type& val ) {

		size_type	newSize = _size + 1;

		if ( newSize > _capacity )
			reserve(newSize);

		_elements[_size] = val;
		_size = newSize;
		_begin = &(_elements[0]);
		_end = &(_elements[_size]);
	}

	/*
	 * Removes the last element in the vector, effectively reducing the container size by one.
	 * This destroys the removed element.
	 */
	// template< typename T, typename Alloc >
	// void	vector<T,Alloc>::pop_back( void ) {

	// 	pointer&	last = _elements[_size - 1];

	// 	_alloc.destroy(last);
	// 	_size -= 1;
	// }

	/*
	 * Insert elements
	 * The vector is extended by inserting new elements before the element at the specified
	 * position, effectively increasing the container size by the number of elements inserted.
	 *
	 * If the new vector size surpasses the current vector capacity,
	 * it causes an automatic reallocation of the allocated storage space.
	 *
	 * @param position  Position in the vector where the new elements are inserted
	 * @param val       Value to be copied (or moved) to the inserted elements
	 *
	 * @return  An iterator that points to the first of the newly inserted elements
	 */
	// template< typename T, typename Alloc >
	// typename vector<T,Alloc>::iterator	vector<T,Alloc>::insert( iterator position, const value_type& val ) {

	// 	size_type	newSize = _size + 1;

	// 	if ( newSize > _capacity )
	// 		reserve(newSize);

	// 	*position = val;
	// 	_size = newSize;

	// 	return (position);
	// }

	/*
	 * Insert elements
	 * The vector is extended by inserting new elements before the element at the specified
	 * position, effectively increasing the container size by the number of elements inserted.
	 *
	 * If the new vector size surpasses the current vector capacity,
	 * it causes an automatic reallocation of the allocated storage space.
	 *
	 * @param position  Position in the vector where the new elements are inserted
	 * @param n         Number of elements to insert. Each element is initialized to a copy of val
	 * @param val       Value to be copied (or moved) to the inserted elements
	 *
	 * @return  An iterator that points to the first of the newly inserted elements
	 */
	// template< typename T, typename Alloc >
	// void	vector<T,Alloc>::insert( iterator position, size_type n, const value_type& val ) {

	// 	size_type	newSize = size() + n;

	// 	if ( newSize > _capacity )
	// 		reserve(newSize);
		
	// 	typename T::iterator	ite = position;
	// 	std::advance(ite, n);
		
	// 	for ( typename T::iterator it = position; it != ite; ++it )
	// 		*it = val;

	// 	_size = newSize;
	// }

	/*
	 * Removes all elements from the vector (which are destroyed),
	 * leaving the container with a size of 0.
	 */
	template< typename T, typename Alloc >
	void	vector<T,Alloc>::clear( void ) {

		for ( size_type i = 0; i < _size; i++ )
			_alloc.destroy( _elements + i );

		_size = 0;
		_begin = &(_elements[0]); // to check
		_end = &(_elements[_size]);
	}


	/* non-member function overloads **************************************** */


	/* relational operators ************************************************* */

	template< typename T, typename Alloc >
		bool	operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );

	template< typename T, typename Alloc >
		bool	operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );

	template< typename T, typename Alloc >
		bool	operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );

	template< typename T, typename Alloc >
		bool	operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );

	template< typename T, typename Alloc >
		bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );

	template< typename T, typename Alloc >
		bool	operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );


	/*
	 * Exchange contents of vectors
	 *
	 * @param x,y  vector containers of the same type
	 *             (i.e., having both the same template parameters, T and Allocator)
	 */
	template< typename T, typename Alloc >
		void	swap( vector<T,Alloc>& x, vector<T,Alloc>& y );

}

#endif
