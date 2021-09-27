/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:25:08 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/28 00:30:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <sstream>
#include <memory>
#include "algorithm.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"

/*
 * Credits:
 * Detailed comments mostly from www.cplusplus.com
 */

namespace ft
{
	/*
	 * Vector
	 *
	 * vector definition
	 *
	 * vector implementation
	 *   helpers
	 *   construct/copy/destroy
	 *   capacity
	 *   element access
	 *   modifiers
	 *   non-member function overloads
	 *
	 * non-member function overloads implementation
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
	class vector
	{
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
		allocator_type	_M_alloc;
		pointer			_M_begin;
		pointer			_M_end;
		pointer			_M_endOfStorage;

	protected:
		// helpers
		pointer		_M_allocate( size_type __n );
		void		_M_create_storage( size_type __n );
		void		_M_deallocate( pointer __p, size_type __n );
		void		_M_fill_initialize( size_type __n, const value_type& __val );
		template<typename InputIterator>
			void	_M_range_initialize( InputIterator __first, InputIterator __last );
		size_type	_M_calculateGrowth( const size_type __newSize) const;
		void		_M_range_check( size_type __n ) const;
		size_type	_M_len_check( size_type __n, const char* __s ) const;
		void		_M_erase_at_end( pointer __from );
		void		_M_fill_insert( iterator __pos, size_type __n, const value_type& __val );

	public:
		// default constructor
		vector( const allocator_type& alloc = allocator_type() );

		// fill constructor
		vector( size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type() );
		
		// range constructor
		template<typename InputIterator>
			vector(
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type first,
				InputIterator last,
				const allocator_type& alloc = allocator_type() );

		// copy constructor
		vector( const vector& x );

		// destructor
		~vector( void );

		// assignment operator
		vector&	operator=( const vector& rhs );

		// allocator
		allocator_type	get_alloc( void ) const;

		// iterators
		iterator			begin( void );
		const_iterator		begin( void ) const;
		iterator			end( void );
		const_iterator		end( void ) const;
		reverse_iterator	rbegin( void );
		reverse_iterator	rend( void );

		// capacity
		bool		empty( void ) const;
		size_type	size( void ) const;
		void		resize( size_type n, value_type val = value_type() );
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
		// template<typename InputIterator>
		// 	void	assign( InputIterator first, InputIterator last );
		void		assign( size_type n, const value_type& val );
		void		push_back( const value_type& val );
		void		pop_back( void );
		// iterator	insert( iterator position, const value_type& val );
		// void		insert( iterator position, size_type n, const value_type& val );
		// template<typename InputIterator>
		// 	void	insert( iterator position, InputIterator first, InputIterator last );
		// iterator	erase( iterator position );
		// iterator	erase( iterator first, iterator last );
		void		swap( vector& x );
		void		clear( void );
	};

	/* non-member function overloads **************************************** */

	// relational operators
	template<typename T, typename Alloc>
		bool	operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );
	template<typename T, typename Alloc>
		bool	operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );
	template<typename T, typename Alloc>
		bool	operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );
	template<typename T, typename Alloc>
		bool	operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );
	template<typename T, typename Alloc>
		bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) ;
	template<typename T, typename Alloc>
		bool	operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs );

	// swap
	template<typename T, typename Alloc>
		void	swap( vector<T,Alloc>& x, vector<T,Alloc>& y );


	/* Vector implementation ************************************************ */


	/* helpers ************************************************************** */

	/*
	 * Allocate a storage space of size n
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::pointer
	vector<T,Alloc>::_M_allocate( size_type __n )
	{
		if (__n > 0)
			return (this->_M_alloc.allocate(__n));

		return (pointer());
	}

	/*
	 * Allocate storage and move pointers to end of size and end of storage
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::_M_create_storage( size_type __n )
	{
		this->_M_begin = this->_M_allocate(__n);
		this->_M_end = this->_M_begin;
		this->_M_endOfStorage = this->_M_begin + __n;
	}

	/*
	 * Deallocate a storage space of size n pointed to by pointer p
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::_M_deallocate( pointer __p, size_type __n )
	{
		if (__p)
			this->_M_alloc.deallocate(__p, __n);
	}

	/*
	 * Construct with n elements of value val
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::_M_fill_initialize( size_type __n, const value_type& __val )
	{
		if (__n > 0)
		{
			for ( size_type i = 0; i < __n; i++ )
				this->_M_alloc.construct( this->_M_begin + i, __val );
			this->_M_end = this->_M_begin + __n;
		}
	}

	/*
	 * Construct with n elements of value val
	 */
	template<typename T, typename Alloc>
	template<typename InputIterator>
	void
	vector<T,Alloc>::_M_range_initialize( InputIterator __first, InputIterator __last )
	{
		size_type	n = __last - __first;

		_M_create_storage(n);

		size_type	i = 0;

		for ( ; __first != __last; ++__first )
		{
			this->_M_alloc.construct( this->_M_begin + i , __first);
			i++;
		}
		this->_M_end = this->_M_begin + i;
	}

	/*
	 * Calculates capacity growth (private member function to help)
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::size_type
	vector<T,Alloc>::_M_calculateGrowth( const size_type __newSize) const
	{
		const size_type	currCapacity = capacity();
		size_type		capacityLeft = max_size() - currCapacity;

		// handle overflow
		if ( currCapacity > capacityLeft )
			return ( max_size() );

		const size_type	newCapacity = currCapacity + currCapacity;

		if ( __newSize > newCapacity )
			return ( __newSize );

		return ( newCapacity );
	}

	/*
	 * Destroy elements from a given position
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::_M_erase_at_end( pointer __from )
	{
		size_type	len = this->_M_end - __from;

		if (len > 0)
		{
			for ( size_type i = 0; i < len; i++ )
				this->_M_alloc.destroy( __from + i);
			
			this->_M_end = __from;
		}
	}

	/*
	 * Safety check for storage length
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::size_type
	vector<T,Alloc>::_M_len_check( size_type __n, const char* __s ) const
	{
		size_type	sizeLeft = max_size() - size();
		size_type	len = size() + __n;

		if ( sizeLeft < __n )
			throw std::length_error(__s);

		return ( (len > max_size()) ? max_size() : len );
	}

	/*
	 * Safety check for storage length
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::_M_fill_insert( iterator __pos, size_type __n, const value_type& __val )
	{
		if ( __n > 0)
		{
			if ( capacity() < __n )
			{
				size_type	len = this->_M_len_check(__n, "vector::_M_fill_insert");
				this->reserve(len);
			}
			for ( size_type i = size(); i < __n; i++ )
			{
				*__pos = __val;
				__pos++;
			}
			this->_M_end = this->_M_begin + __n;
		}
	}

	/* construct/copy/destroy *********************************************** */

	/*
	 * Default constructor
	 * Constructs an empty container, with no elements.
	 *
	 * @param alloc  Allocator object
	 */
	template<typename T, typename Alloc>
	vector<T,Alloc>::vector( const allocator_type& alloc )
	: _M_alloc(alloc), _M_begin(), _M_end(), _M_endOfStorage()
	{
	}

	/*
	 * Fill constructor
	 * Constructs a container with n elements. Each element is a copy of val.
	 *
	 * @param n      Initial container size
	 * @param val    Value to fill the container with
	 * @param alloc  Allocator object
	 */
	template<typename T, typename Alloc>
	vector<T,Alloc>::vector( size_type n, const value_type& val, const allocator_type& alloc )
	: _M_alloc(alloc)
	{
		_M_create_storage(n);
		_M_fill_initialize(n, val);
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
	template<typename T, typename Alloc>
	template<typename InputIterator>
	vector<T,Alloc>::vector(
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type first,
		InputIterator last,
		const allocator_type& alloc )
	: _M_alloc(alloc)
	{
		std::cout << "ft::vector range constructor called" << std::endl;
		_M_range_initialize(first, last);
	}

	/*
	 * Copy constructor
	 * Constructs a container with a copy of each of the elements in x, in the same order.
	 *
	 * @param x  Another vector object of the same type
	 *           (with the same class template arguments T and Allocator)
	 */
	template<typename T, typename Alloc>
	vector<T,Alloc>::vector( const vector& x )
	: _M_alloc( x._M_alloc )
	{
		std::cout << "ft::vector copy constructor called" << std::endl;

		_M_create_storage(x.capacity());

		for ( size_type i = 0; i < x.size(); i++ )
			this->_M_alloc.construct( this->_M_begin + i, x[i]);
		this->_M_end = this->_M_begin + x.size();
	}

	/*
	 * Destructor
	 *
	 * Destroys all container elements, and deallocates all the storage capacity
	 * allocated by the vector using its allocator.
	 */
	template<typename T, typename Alloc>
	vector<T,Alloc>::~vector( void )
	{
		_M_erase_at_end(this->_M_begin);
		_M_deallocate(this->_M_begin, capacity());
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
	template<typename T, typename Alloc>
	vector<T,Alloc>&
	vector<T,Alloc>::operator=( const vector& rhs )
	{
		if ( this != &rhs )
		{
			size_type	newSize = rhs.size();
			size_type	newCapacity = (newSize > capacity()) ? newSize : capacity();
			pointer		newElements = _M_allocate(newCapacity);

			for ( size_type i = 0; i < newSize; i++ )
				this->_M_alloc.construct( newElements + i, rhs[i]);

			_M_erase_at_end(this->_M_begin);
			_M_deallocate(this->_M_begin, capacity());

			this->_M_begin = pointer(newElements);
			this->_M_end = this->_M_begin + newSize;
			this->_M_endOfStorage = this->_M_begin + newCapacity;
		}
		return ( *this );
	}

	/* allocator ************************************************************ */

	/*
	 * Returns a copy of the allocator object associated with the vector.
	 *
	 * @return  The allocator
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::allocator_type
	vector<T,Alloc>::get_alloc( void ) const
	{
		return ( static_cast<allocator_type>(this->_M_alloc) );
	}


	/* iterators ************************************************************ */

	/*
	 * Returns an iterator pointing to the first element in the vector
	 *
	 * @return  An iterator to the beginning of the sequence container
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::iterator
	vector<T,Alloc>::begin( void )
	{
		return ( iterator(this->_M_begin) );
	}

	template<typename T, typename Alloc>
	typename vector<T,Alloc>::const_iterator
	vector<T,Alloc>::begin( void ) const
	{
		return ( const_iterator(this->_M_begin) );
	}

	/*
	 * Returns an iterator referring to the past-the-end element
	 * in the vector container
	 *
	 * @return  An iterator to the element past the end of the sequence
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::iterator
	vector<T,Alloc>::end( void )
	{
		return ( iterator(this->_M_end) );
	}

	template<typename T, typename Alloc>
	typename vector<T,Alloc>::const_iterator
	vector<T,Alloc>::end( void ) const
	{
		return ( const_iterator(this->_M_end) );
	}

	/*
	 * Returns a reverse iterator pointing to the last element in the vector
	 *
	 * @return  A reverse iterator to the reverse beginning of the sequence container
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::reverse_iterator
	vector<T,Alloc>::rbegin( void )
	{
		return ( reverse_iterator(end()) );
	}

	/*
	 * Returns a reverse iterator pointing to the theoretical element preceding
	 * the first element in the vector
	 *
	 * @return  A reverse iterator to the reverse end of the sequence container
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::reverse_iterator
	vector<T,Alloc>::rend( void )
	{
		return ( reverse_iterator(begin()) );
	}


	/* capacity ************************************************************* */


	/*
	 * Checks whether the vector is empty (i.e. whether its size is 0).
	 *
	 * @return  true if the container size is 0, false otherwise
	 */
	template<typename T, typename Alloc>
	bool
	vector<T,Alloc>::empty( void ) const
	{
		return ( begin() == end() );
	}

	/*
	 * Get the size of the vector
	 *
	 * @return  The number of elements in the vector
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::size_type
	vector<T,Alloc>::size( void ) const
	{
		return ( size_type( this->_M_end - this->_M_begin ) );
	}

	/*
	 * Gets the maximum number of elements that the vector can hold.
	 *
	 * This is the maximum potential size the container can reach due to known system
	 * or library implementation limitations.
	 *
	 * @return  The maximum number of elements a vector container can hold as content
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::size_type
	vector<T,Alloc>::max_size( void ) const
	{
		return ( this->_M_alloc.max_size() );
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
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::resize( size_type n, value_type val )
	{
		if ( n > size() )
			_M_fill_insert( this->end(), n, val );
		else if ( n < size() )
			_M_erase_at_end(this->_M_begin + n);
	}

	/*
	 * Gets the size of allocated storage capacity
	 * i.e., size of the storage space currently allocated for the vector,
	 * expressed in terms of elements.
	 *
	 * @return  The size of the currently allocated storage capacity in the vector
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::size_type
	vector<T,Alloc>::capacity( void ) const
	{
		return ( size_type( this->_M_endOfStorage - this->_M_begin ) );
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
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::reserve( size_type n )
	{
		if ( n <= capacity() )
			return ;
		if ( n > max_size() )
			throw std::length_error("vector::reserve");

		size_type	oldSize = size();
		size_type	newCapacity = _M_calculateGrowth(n);
		pointer		newElements = _M_allocate(newCapacity);

		for ( size_type i = 0; i < oldSize; i++ )
			this->_M_alloc.construct( newElements + i, this->_M_begin[i]);

		_M_erase_at_end(this->_M_begin);
		_M_deallocate(this->_M_begin, capacity());

		this->_M_begin = pointer(newElements);
		this->_M_end = this->_M_begin + oldSize;
		this->_M_endOfStorage = this->_M_begin + newCapacity;
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
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::reference
	vector<T,Alloc>::operator[]( size_type n )
	{
		return ( this->_M_begin[n] );
	}

	template<typename T, typename Alloc>
	typename vector<T,Alloc>::const_reference
	vector<T,Alloc>::operator[]( size_type n ) const
	{
		return ( this->_M_begin[n] );
	}

	/*
	 * Safety check for at()
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::_M_range_check( size_type __n ) const
	{
		if ( __n > size() )
		{
			std::stringstream	err_msg;
	
			err_msg << "vector::_M_range_check: __n (which is " << __n
					<< ") >= size() (which is " << size() << ")";
			throw std::out_of_range(err_msg.str());
		}
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
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::reference
	vector<T,Alloc>::at( size_type n )
	{
		_M_range_check(n);
		return ( this->_M_begin[n] );
	}

	template<typename T, typename Alloc>
	typename vector<T,Alloc>::const_reference
	vector<T,Alloc>::at( size_type n ) const
	{
		_M_range_check(n);
		return ( this->_M_begin[n] );
	}

	/*
	 * Access the first element in the vector
	 *
	 * @return  A reference to the first element in the vector container
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::reference
	vector<T,Alloc>::front( void )
	{
		return ( *(begin()) );
	}

	template<typename T, typename Alloc>
	typename vector<T,Alloc>::const_reference
	vector<T,Alloc>::front( void ) const
	{
		return ( *(begin()) );
	}

	/*
	 * Access the last element in the vector
	 *
	 * @return  A reference to the last element in the vector container
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::reference
	vector<T,Alloc>::back( void )
	{
		return ( *(end() - 1) );
	}

	template<typename T, typename Alloc>
	typename vector<T,Alloc>::const_reference
	vector<T,Alloc>::back( void ) const
	{
		return ( *(end() - 1) );
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
	// template<typename T, typename Alloc>
	// template<typename InputIterator>
	// void	vector<T,Alloc>::assign( InputIterator first, InputIterator last )
	// {
	// 	_M_erase_at_end(_M_begin);
	// 	_M_deallocate(_M_begin, capacity());
	// 	_M_range_initialize( InputIterator __first, InputIterator __last );
	// }

	/*
	 * Assigns new contents to the vector, replacing its current contents,
	 * and modifying its size accordingly.
	 *
	 * @param n    New size for the container
	 * @param val  Value to fill the container with. Each of the n elements in
	 *             the container will be initialized to a copy of this value
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::assign( size_type n, const value_type& val )
	{
		resize(n);
		clear();
		_M_fill_initialize(n, val);
	}

	/*
	 * Adds a new element at the end of the vector, after its current last element.
	 *
	 * If the new vector size surpasses the current vector capacity,
	 * it causes an automatic reallocation of the allocated storage space.
	 *
	 * @param val  Value to be copied (or moved) to the new element
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::push_back( const value_type& val )
	{
		size_type	newSize = size() + 1;

		if ( newSize > capacity() )
			reserve(newSize);

		this->_M_alloc.construct( this->_M_end, val );
		this->_M_end = this->_M_begin + newSize;
	}

	/*
	 * Removes the last element in the vector, effectively reducing the container size by one.
	 * This destroys the removed element.
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::pop_back( void )
	{
		this->_M_alloc.destroy(end() - 1);
		this->_M_end -= 1;
	}

	/*
	 * Insert elements
	 * The vector is extended by inserting a single before the element at the specified
	 * position, effectively increasing the container size by 1.
	 *
	 * If the new vector size surpasses the current vector capacity,
	 * it causes an automatic reallocation of the allocated storage space.
	 *
	 * @param position  Position in the vector where the new elements are inserted
	 * @param val       Value to be copied (or moved) to the inserted elements
	 *
	 * @return  An iterator that points to the first of the newly inserted elements
	 */
	// template<typename T, typename Alloc>
	// typename vector<T,Alloc>::iterator
	// vector<T,Alloc>::insert( iterator position, const value_type& val )
	// {
	// 	size_type	newSize = _size + 1;

	// 	if ( newSize > _capacity )
	// 		reserve(newSize);

	// 	*(position - 1) = val;
	// 	_M_end = _M_begin + newSize;

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
	 */
	// template<typename T, typename Alloc>
	// void
	// vector<T,Alloc>::insert( iterator position, size_type n, const value_type& val )
	// {
	// 	size_type	newSize = size() + n;
	// 	typename T::iterator	ite = position + n;

	// 	if ( newSize > _capacity )
	// 		reserve(newSize);

	// 	for ( typename T::iterator it = position; it != ite; ++it )
	// 		*it = val;

	// 	_M_end = _M_begin + newSize;
	// }

	/*
	 * Insert elements
	 * The vector is extended by inserting a range of elements before the element at the specified
	 * position, effectively increasing the container size by the number of elements inserted.
	 *
	 * If the new vector size surpasses the current vector capacity,
	 * it causes an automatic reallocation of the allocated storage space.
	 *
	 * @param position     Position in the vector where the new elements are inserted
	 * @param first, last  Iterators specifying a range of elements
	 */
	// template<typename T, typename Alloc>
	// template<typename InputIterator>
	// void
	// vector<T,Alloc>::insert( iterator position, InputIterator first, InputIterator last )
	// {
	// 	size_type	newSize = size() + std::distance(first, last);

	// 	if ( newSize > _capacity )
	// 		reserve(newSize);

	// 	_M_range_initialize( InputIterator __first, InputIterator __last );
	// }

	// template<typename T, typename Alloc>
	// typename vector<T,Alloc>::iterator
	// vector<T,Alloc>::erase( iterator position )

	// template<typename T, typename Alloc>
	// typename vector<T,Alloc>::iterator
	// vector<T,Alloc>::erase( iterator first, iterator last )

	/*
	 * Exchanges the content of the container by the content of x
	 *
	 * @param x  Another vector container of the same type
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::swap( vector& x )
	{
		ft::swap(this, x);
	}

	/*
	 * Removes all elements from the vector (which are destroyed),
	 * leaving the container with a size of 0.
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::clear( void )
	{
		_M_erase_at_end(this->_M_begin);
	}


	/* non-member function overloads implementation ************************* */


	/*
	 * Relational operators
	 * Make comparison between two vectors
	 */

	template<typename T, typename Alloc>
	bool
	operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		return ( (lhs.size() == rhs.size())
				 && (ft::equal(lhs.begin(), lhs.end(), rhs.begin())) );
	}

	template<typename T, typename Alloc>
	bool
	operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		return ( !(lhs == rhs) );
	}

	template<typename T, typename Alloc>
	bool
	operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		return ( ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) );
	}

	template<typename T, typename Alloc>
	bool
	operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		return ( !(rhs < lhs) );
	}

	template<typename T, typename Alloc>
	bool
	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		return ( rhs < lhs );
	}

	template<typename T, typename Alloc>
	bool
	operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
	{
		return ( !(lhs < rhs) );
	}


	/*
	 * Exchange contents of vectors
	 *
	 * @param x,y  vector containers of the same type
	 *             (i.e., having both the same template parameters, T and Allocator)
	 */
	template<typename T, typename Alloc>
	void
	swap( vector<T,Alloc>& x, vector<T,Alloc>& y )
	{
		vector<T,Alloc>	tmp(x);
		x = y;
		y = tmp;
	}
} // namespace ft

#endif
