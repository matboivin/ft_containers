/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:25:08 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/05 17:19:16 by mboivin          ###   ########.fr       */
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

		// Default constructor
		vector( void ) : vector( Allocator() ) {}

		// Destructor
		~vector( void ) {}

		// Assignment operator
		vector&	operator=( const vector& rhs ) {

			static_cast<void>(rhs);
			return (*this); // tmp
		}

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
		template < typename InputIterator >
			void	assign( InputIterator first, InputIterator last );
		void		assign( size_type n, const value_type& val );
		void		push_back( const value_type& val );
		void		pop_back( void );
		iterator	insert( iterator position, const value_type& val );
		void		insert( iterator position, size_type n, const value_type& val );
		template < typename InputIterator >
			void	insert( iterator position, InputIterator first, InputIterator last );
		iterator	erase( iterator position );
		iterator	erase( iterator first, iterator last );
		void		swap( vector& x );
		void		clear( void );

	};

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

#endif
