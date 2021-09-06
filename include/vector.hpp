/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:25:08 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/06 16:04:52 by mboivin          ###   ########.fr       */
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

		allocator_type	_allocator;
		size_type		_size;       // number of elements
		size_type		_capacity;
		T*				_elements;

		// calculate capacity growth
		size_type		calculateGrowth( const size_type newSize) const;

	public:

		// default constructor
		vector( void );

		// copy constructor
		vector( const vector& x );

		// fill constructor
		vector( size_type n,
				const value_type& val = value_type(),
				const allocator_type& allocator = allocator_type() );
		
		// range constructor
		template< typename InputIterator >
			vector( InputIterator first,
					InputIterator last,
					const allocator_type& allocator = allocator_type() );

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
		// reference		operator[]( size_type n );
		// const_reference	operator[]( size_type n ) const;
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

	// default constructor
	template< typename T, typename Allocator >
	vector<T,Allocator>::vector( void )
			: _allocator( Allocator() ),
			  _size(0),
			  _capacity(0),
			  _elements() {

		std::cout << "ft::vector default constructor called" << std::endl;
	}

	/*
	 * Fill constructor
	 *
	 * Constructs a container with n elements. Each element is a copy of val.
	 */
	template< typename T, typename Allocator >
	vector<T,Allocator>::vector( size_type n,
								 const value_type& val,
								 const allocator_type& allocator )
			: _allocator( allocator() ),
			  _size(n),
			  _capacity(n) {

		std::cout << "ft::vector fill constructor called" << std::endl;

		_elements = allocator.allocate(n);
		allocator.construct( _elements, val );
	}

	/*
	 * Range constructor
	 *
	 * Constructs a container with as many elements as the range [first,last),
	 * with each element constructed from its corresponding element in that range,
	 * in the same order.
	 */
	// template< typename InputIterator >
	// vector<T,Allocator>::vector( InputIterator first, InputIterator last,
	// 							const allocator_type& allocator = allocator_type() ) {
	// 		: _allocator( allocator() ) {

	// 	std::cout << "ft::vector range constructor called" << std::endl;
	// }

	/*
	 * Destructor
	 *
	 * Destroys all container elements, and deallocates all the storage capacity allocated
	 * by the vector using its allocator.
	 */
	template< typename T, typename Allocator >
	vector<T,Allocator>::~vector( void ) {

		std::cout << "ft::vector destructor called" << std::endl;

		_allocator.destroy( _elements );
		_allocator.deallocate( _elements, _capacity );
	}

	/*
	 * Assignment operator
	 *
	 * Assigns new contents to the container, replacing its current contents,
	 * and modifying its size accordingly.
	 * The container preserves its current allocator, which is used to allocate storage
	 * in case of reallocation.
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
			_allocator.construct( _elements, rhs._elements );
		}

		return ( *this );
	}

	/*
	 * Returns a copy of the allocator object associated with the vector.
	 */
	template< typename T, typename Allocator >
	typename vector<T,Allocator>::allocator_type	vector<T,Allocator>::get_allocator( void ) const {

		return ( static_cast<allocator_type>(this->_allocator) );
	}

	// capacity

	/*
	 * Calculate capacity growth
	 */
	template< typename T, typename Allocator >
	typename vector<T,Allocator>::size_type	vector<T,Allocator>::calculateGrowth( const size_type newSize) const {

		const size_type	currCapacity = capacity();
		size_type		capacityLeft = max_size() - currCapacity;

		if ( currCapacity > capacityLeft )
			return ( max_size() );
		
		const size_type	newCapacity = currCapacity + currCapacity;

		if ( newSize > newCapacity )
			return ( newSize );

		return ( newCapacity );
	}

	/*
	 * Returns whether the vector is empty (i.e. whether its size is 0).
	 */
	template< typename T, typename Allocator >
	bool	vector<T,Allocator>::empty( void ) const {

		return ( this->size() == 0 );
	}

	/*
	 * Returns the number of elements in the vector.
	 *
	 * This is the number of actual objects held in the vector,
	 * which is not necessarily equal to its storage capacity.
	 */
	template< typename T, typename Allocator >
	typename vector<T,Allocator>::size_type	vector<T,Allocator>::size( void ) const {

		return ( this->_size );
	}

	/*
	 * Returns the maximum number of elements that the vector can hold.
	 */
	template< typename T, typename Allocator >
	typename vector<T,Allocator>::size_type	vector<T,Allocator>::max_size( void ) const {

		return ( this->_allocator.max_size() );
	}

	/* 
	 * Return size of allocated storage capacity
	 * i.e., size of the storage space currently allocated for the vector,
	 * expressed in terms of elements.
	 */
	template< typename T, typename Allocator >
	typename vector<T,Allocator>::size_type	vector<T,Allocator>::capacity( void ) const {

		return ( this->_capacity );
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
