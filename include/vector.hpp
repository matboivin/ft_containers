/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:25:08 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/06 17:07:18 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <iterator>

/*
 * Vector template class
 *
 * Array which size can change dynamically
 */

namespace ft {

	template< typename T, typename Allocator = std::allocator<T> >
	class vector {

	public:

		// types
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		// TODO
		// iterator
		// const_iterator
		// typedef std::reverse_iterator<iterator>					reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>			const_reverse_iterator;
		// typedef std::iterator_traits<iterator>::difference_type	difference_type;
		// TODO: Re-implement iterators_traits and reverse_iterator
		typedef std::size_t										size_type;

	private:

		// attributes
		allocator_type	_allocator;  // The container keeps and uses an internal copy of this allocator
		size_type		_size;       // number of elements
		size_type		_capacity;
		T*				_elements;

		// calculate capacity growth
		size_type		calculateGrowth( const size_type newSize) const;

	public:

		// default constructor
		vector( const allocator_type& allocator = allocator_type() );

		// fill constructor
		vector( size_type n,
				const value_type& val = value_type(),
				const allocator_type& allocator = allocator_type() );
		
		// range constructor
		template< typename InputIterator >
			vector( InputIterator first,
					InputIterator last,
					const allocator_type& allocator = allocator_type() );

		// copy constructor
		vector( const vector& x );

		// destructor
		~vector( void );

		// assignment operator
		vector&	operator=( const vector& rhs );

		// allocator
		allocator_type	get_allocator( void ) const;

		// iterators
		// iterator				begin( void );
		// iterator				end( void );
		// reverse_iterator		rbegin( void );
		// reverse_iterator		rend( void );

		// capacity
		bool		empty( void ) const;
		size_type	size( void ) const;
		size_type	max_size( void ) const;
		size_type	capacity( void ) const;
		void		reserve( size_type n );

		// element access
		reference		operator[]( size_type n );
		const_reference	operator[]( size_type n ) const;
		// reference		at( size_type n );
		// const_reference	at( size_type n ) const;
		// reference		front( void );
		// const_reference	front( void ) const;
		// reference		back( void );
		// const_reference	back( void ) const;

		// modifiers
		// template< typename InputIterator >
		// 	void	assign( InputIterator first, InputIterator last );
		// void		assign( size_type n, const value_type& val );
		// void		push_back( const value_type& val );
		// void		pop_back( void );
		// iterator	insert( iterator position, const value_type& val );
		// void		insert( iterator position, size_type n, const value_type& val );
		// template< typename InputIterator >
		// 	void	insert( iterator position, InputIterator first, InputIterator last );
		// iterator	erase( iterator position );
		// iterator	erase( iterator first, iterator last );
		// void		swap( vector& x );
		// void		clear( void );
	};

	/*
	 * Default constructor
	 * Constructs an empty container, with no elements.
	 *
	 * @param alloc  Allocator object
	 */
	template< typename T, typename Allocator >
	vector<T,Allocator>::vector( const allocator_type& allocator )
			: _allocator(allocator),
			  _size(0),
			  _capacity(0),
			  _elements() {

		std::cout << "ft::vector default constructor called" << std::endl;
	}

	/*
	 * Fill constructor
	 * Constructs a container with n elements. Each element is a copy of val.
	 *
	 * @param n      Initial container size
	 * @param val    Value to fill the container with
	 * @param alloc  Allocator object
	 */
	template< typename T, typename Allocator >
	vector<T,Allocator>::vector( size_type n,
								 const value_type& val,
								 const allocator_type& allocator )
			: _allocator(allocator),
			  _size(n),
			  _capacity(n) {

		std::cout << "ft::vector fill constructor called" << std::endl;

		_elements = allocator.allocate(n);
		allocator.construct( _elements, val ); //TODO
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
	// template< typename InputIterator >
	// vector<T,Allocator>::vector( InputIterator first, InputIterator last,
	// 							const allocator_type& allocator = allocator_type() ) {
	// 		: _allocator( allocator() ) {

	// 	std::cout << "ft::vector range constructor called" << std::endl;
	// }

	/*
	 * Copy constructor
	 * Constructs a container with a copy of each of the elements in x, in the same order.
	 *
	 * @param x  Another vector object of the same type
	 *           (with the same class template arguments T and Allocator)
	 */
	template< typename T, typename Allocator >
	vector<T,Allocator>::vector( const vector& x )
			: _allocator( x._allocator() ),
			  _size( x.size() ),
			  _capacity( x.capacity() ) {

		std::cout << "ft::vector copy constructor called" << std::endl;

		_elements = _allocator.allocate( x.size() );
		_allocator.construct( _elements, x._elements ); // TODO
	}

	/*
	 * Destructor
	 *
	 * Destroys all container elements, and deallocates all the storage capacity
	 * allocated by the vector using its allocator.
	 */
	template< typename T, typename Allocator >
	vector<T,Allocator>::~vector( void ) {

		std::cout << "ft::vector destructor called" << std::endl;

		_allocator.destroy( _elements );
		//_allocator.deallocate( _elements, _capacity );
	}

	/*
	 * Assignment operator
	 *
	 * Assigns new contents to the container, replacing its current contents,
	 * and modifying its size accordingly.
	 * The container preserves its current allocator, which is used to allocate storage
	 * in case of reallocation.
	 *
	 * @param x Another vector object of the same type
	 *          (with the same class template arguments T and Allocator)
	 *
	 * @return  *this
	 */
	template< typename T, typename Allocator >
	vector<T,Allocator>&	vector<T,Allocator>::operator=( const vector& rhs ) {

		std::cout << "ft::vector assignment operator called" << std::endl;

		if ( this != &rhs ) {

			_allocator.destroy( _elements );
			_allocator.deallocate( _elements, capacity() );

			_size = rhs.size();
			_capacity = calculateGrowth( rhs.capacity() );

			_elements = _allocator.allocate( rhs.size() );
			_allocator.construct( _elements, rhs._elements ); // TODO
		}

		return ( *this );
	}

	/*
	 * Returns a copy of the allocator object associated with the vector.
	 *
	 * @return The allocator
	 */
	template< typename T, typename Allocator >
	typename vector<T,Allocator>::allocator_type	vector<T,Allocator>::get_allocator( void ) const {

		return ( static_cast<allocator_type>(this->_allocator) );
	}

	// capacity

	/*
	 * Checks whether the vector is empty (i.e. whether its size is 0).
	 *
	 * @return true if the container size is 0, false otherwise.
	 */
	template< typename T, typename Allocator >
	bool	vector<T,Allocator>::empty( void ) const {

		return ( this->size() == 0 );
	}

	/*
	 * Get the size of the vector
	 *
	 * @return The number of elements in the vector.
	 */
	template< typename T, typename Allocator >
	typename vector<T,Allocator>::size_type	vector<T,Allocator>::size( void ) const {

		return ( this->_size );
	}

	/*
	 * Gets the maximum number of elements that the vector can hold.
	 *
	 * This is the maximum potential size the container can reach due to known system
	 * or library implementation limitations.
	 *
	 * @return The maximum number of elements a vector container can hold as content.
	 */
	template< typename T, typename Allocator >
	typename vector<T,Allocator>::size_type	vector<T,Allocator>::max_size( void ) const {

		return ( this->_allocator.max_size() );
	}

	/*
	 * Calculates capacity growth (private member function to help)
	 */
	template< typename T, typename Allocator >
	typename vector<T,Allocator>::size_type	vector<T,Allocator>::calculateGrowth( const size_type newSize) const {

		const size_type	currCapacity = capacity();
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
	 * @return The size of the currently allocated storage capacity in the vector
	 */
	template< typename T, typename Allocator >
	typename vector<T,Allocator>::size_type	vector<T,Allocator>::capacity( void ) const {

		return ( this->_capacity );
	}

	// element access

	/* 
	 * Access an element of the vector
	 *
	 * @param n  Position of an element in the container.
	 *
	 * @return A reference to the element at position n in the vector container.
	 *
	 * @exceptsafe If the container size is greater than n, the function never throws exceptions.
	 * Otherwise, the behavior is undefined.
	 */
	template< typename T, typename Allocator >
	typename vector<T,Allocator>::reference	vector<T,Allocator>::operator[]( size_type n ) {

		return ( this->_elements[n] );
	}

	template< typename T, typename Allocator >
	typename vector<T,Allocator>::const_reference	vector<T,Allocator>::operator[]( size_type n ) const {

		return ( this->_elements[n] );
	}

	// non-member function overloads

	// relational operators

	template < typename T, typename Allocator >
		bool	operator==( const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs );

	template < typename T, typename Allocator >
		bool	operator!=( const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs );

	template < typename T, typename Allocator >
		bool	operator<( const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs );

	template < typename T, typename Allocator >
		bool	operator<=( const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs );

	template < typename T, typename Allocator >
		bool	operator>(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs );

	template < typename T, typename Allocator >
		bool	operator>=( const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs );

	// swap

	template < typename T, typename Allocator >
		void	swap( vector<T,Allocator>& x, vector<T,Allocator>& y );

}

#endif
