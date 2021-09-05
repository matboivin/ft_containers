/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:25:08 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/05 18:55:55 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

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

		T*			_elements;
		size_type	_size;       // number of elements
		size_type	_capacity;

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
		template < typename InputIterator >
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
		reference		operator[]( size_type n );
		const_reference	operator[]( size_type n ) const;
		reference		at( size_type n );
		const_reference	at( size_type n ) const;
		reference		front( void );
		const_reference	front( void ) const;
		reference		back( void );
		const_reference	back( void ) const;

		// modifiers
		// template < typename InputIterator >
		// 	void	assign( InputIterator first, InputIterator last );
		// void		assign( size_type n, const value_type& val );
		// void		push_back( const value_type& val );
		// void		pop_back( void );
		// iterator	insert( iterator position, const value_type& val );
		// void		insert( iterator position, size_type n, const value_type& val );
		// template < typename InputIterator >
		// 	void	insert( iterator position, InputIterator first, InputIterator last );
		// iterator	erase( iterator position );
		// iterator	erase( iterator first, iterator last );
		// void		swap( vector& x );
		// void		clear( void );

	};

	// default constructor
	template< typename T, typename Allocator >
	vector<T,Allocator>::vector( void )
			: vector( Allocator() ),
			  _elements(),
			  _size(0),
			  _capacity(0) {

		return ;
	}

	// fill constructor
	template< typename T, typename Allocator >
	vector<T,Allocator>::vector( size_type n, const value_type& val, const allocator_type& allocator )
			: vector( Allocator() ),
			  _size(n),
			  _capacity(n) {

		// TODO
		static_cast<void>(allocator);

		this->elements = new T[n];

		for ( size_type i = 0; i < n; i++ )
			this->elements[i] = val;
	}

	// destructor
	template< typename T, typename Allocator >
	vector<T,Allocator>::~vector( void ) {

		delete [] this->_elements;
	}

	// assignment operator
	template< typename T, typename Allocator >
	vector<T,Allocator>&	vector<T,Allocator>::operator=( const vector& rhs ) {

		if ( this != &rhs ) {

			// TODO
			this->_size = rhs.size();
			this->_capacity = rhs.capacity();
		}

		return ( *this );
	}

	// capacity

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
