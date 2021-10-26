/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:25:08 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/26 18:07:29 by mboivin          ###   ########.fr       */
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
		allocator_type	_M_alloc; // internal copy of the allocator
		pointer			_M_begin; // points to the beginning of the dynamic array
		pointer			_M_end;   // points to the end of the dynamic array
		pointer			_M_endOfStorage; // points to the end of the allocation

	protected:
		// helpers
		pointer		_M_allocate(size_type __n);
		void		_M_create_storage(size_type __n);
		void		_M_deallocate(pointer __p, size_type __n);
		void		_M_swap_data(vector& __x);
		void		_M_fill_insert(iterator __pos, size_type __n, const value_type& __val);
		template<typename InputIterator>
			void	_M_range_initialize(InputIterator __first, InputIterator __last);
		size_type	_M_calculateGrowth(const size_type __n);
		void		_M_range_check(size_type __n) const;
		size_type	_M_len_check(size_type __n, const char* __s) const;
		void		_M_erase_at_end(pointer __pos);

	public:
		// default constructor
		vector(const allocator_type& alloc = allocator_type());

		// fill constructor
		vector(size_type n, const value_type& val = value_type(),
			   const allocator_type& alloc = allocator_type());
		
		// range constructor
		template<typename InputIterator>
			vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type first,
				   InputIterator last,
				   const allocator_type& alloc = allocator_type());

		// copy constructor
		vector(const vector& x);

		// destructor
		~vector(void);

		// assignment operator
		vector&	operator=(const vector& rhs);

		// allocator
		allocator_type	get_alloc(void) const;

		// iterators
		iterator			begin(void);
		const_iterator		begin(void) const;
		iterator			end(void);
		const_iterator		end(void) const;
		reverse_iterator	rbegin(void);
		reverse_iterator	rend(void);

		// capacity
		bool		empty(void) const;
		size_type	size(void) const;
		void		resize(size_type n, value_type val = value_type());
		size_type	max_size(void) const;
		size_type	capacity(void) const;
		void		reserve(size_type n);

		// element access
		reference		operator[](size_type n);
		const_reference	operator[](size_type n) const;
		reference		at(size_type n);
		const_reference	at(size_type n) const;
		reference		front(void);
		const_reference	front(void) const;
		reference		back(void);
		const_reference	back(void) const;

		// modifiers
		template<typename InputIterator>
			void	assign(InputIterator first, InputIterator last);
		void		assign(size_type n, const value_type& val);
		void		push_back(const value_type& val);
		void		pop_back(void);
		// iterator	insert(iterator position, const value_type& val);
		// void		insert(iterator position, size_type n, const value_type& val);
		// template<typename InputIterator>
		// 	void	insert(iterator position, InputIterator first, InputIterator last);
		iterator	erase(iterator position);
		// iterator	erase(iterator first, iterator last);
		void		swap(vector& x);
		void		clear(void);
	};

	/* non-member function overloads **************************************** */

	// relational operators
	template<typename T, typename Alloc>
		bool	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template<typename T, typename Alloc>
		bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template<typename T, typename Alloc>
		bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template<typename T, typename Alloc>
		bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template<typename T, typename Alloc>
		bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template<typename T, typename Alloc>
		bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	// swap
	template<typename T, typename Alloc>
		void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y);
} // namespace ft

#include "vector.tpp"

#endif
