/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:25:08 by mboivin           #+#    #+#             */
/*   Updated: 2022/02/01 13:31:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <sstream>
#include <memory>
#include "algorithm.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"

namespace ft
{
	/* Vector definition *************************************************** */

	/*
	 * Vector template class
	 * Array which size can change dynamically
	 */
	template<typename T, typename Alloc = std::allocator<T> >
		class vector
		{
		public:
			// types
			typedef T													value_type;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef ft::base_iterator<pointer, vector>					iterator;
			typedef ft::base_iterator<const_pointer, vector>			const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type	difference_type;
			typedef std::size_t											size_type;

		private:
			// attributes
			allocator_type	_M_alloc; // internal copy of the allocator
			pointer			_M_begin; // points to the beginning of the dynamic array
			pointer			_M_end;   // points to the end of the dynamic array
			pointer			_M_end_of_storage; // points to the end of the allocation

		protected:
			// helpers
			pointer			_M_allocate(const size_type __n);
			void			_M_create_storage(const size_type __n);
			void			_M_deallocate(pointer __p, const size_type __n);
			void			_M_swap(vector& __x);
			void			_M_default_initialize(size_type __n);
			template<typename InputIterator>
				void		_M_range_initialize(InputIterator __first, InputIterator __last);
			template<typename InputIterator>
				void		_M_range_insert(iterator __pos, InputIterator __first, InputIterator __last);
			void			_M_fill_insert(iterator __pos, size_type __n, const value_type& __val);
			size_type		_M_calculate_growth(const size_type __n);
			void			_M_erase_at_end(pointer __pos);
			void			_M_range_check(const size_type __n) const;
			size_type		_M_len_check(const size_type __n, const char* __s) const;

		public:
			// default constructor
			explicit vector(const allocator_type& alloc = allocator_type());

			// fill constructor
			explicit vector(size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type());
			
			// range constructor
			template<typename InputIterator>
				vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					   typename requires_input_iter<(!is_integral<InputIterator>::value), InputIterator>::type* = 0);

			// copy constructor
			vector(const vector& other);

			// destructor
			~vector(void);

			// copy assignment operator
			vector&	operator=(const vector& other);

			// allocator
			allocator_type	get_alloc(void) const;

			// iterators
			iterator				begin(void);
			const_iterator			begin(void) const;
			iterator				end(void);
			const_iterator			end(void) const;
			reverse_iterator		rbegin(void);
			const_reverse_iterator	rbegin(void) const;
			reverse_iterator		rend(void);
			const_reverse_iterator	rend(void) const;

			// capacity
			bool			empty(void) const;
			size_type		size(void) const;
			void			resize(size_type n, value_type val = value_type());
			size_type		max_size(void) const;
			size_type		capacity(void) const;
			void			reserve(size_type n);

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
				void		assign(InputIterator first, InputIterator last,
								   typename requires_input_iter<(!is_integral<InputIterator>::value), InputIterator>::type* = 0);
			void			assign(size_type n, const value_type& val);
			void			push_back(const value_type& val);
			void			pop_back(void);
			iterator		insert(iterator position, const value_type& val);
			void			insert(iterator position, size_type n, const value_type& val);
			template<typename InputIterator>
				void		insert(iterator position, InputIterator first, InputIterator last,
								   typename requires_input_iter<(!is_integral<InputIterator>::value), InputIterator>::type* = 0);
			iterator		erase(iterator position);
			iterator		erase(iterator first, iterator last);
			void			swap(vector& other);
			void			clear(void);
		}; // class vector

	/* Vector implementation ************************************************ */

	/* helpers ************************************************************** */

	/* Allocate a storage space of size n */
	template<typename T, typename Alloc>
		typename vector<T,Alloc>::pointer
		vector<T,Alloc>::_M_allocate(const size_type __n)
		{
			if (__n > 0)
				return (this->_M_alloc.allocate(__n));
			return (pointer());
		}

	/* Allocate a new storage space and set the pointers */
	template<typename T, typename Alloc>
		void
		vector<T,Alloc>::_M_create_storage(const size_type __n)
		{
			this->_M_begin = this->_M_allocate(__n);
			this->_M_end = this->_M_begin;
			this->_M_end_of_storage = this->_M_begin + __n;
		}

	/* Deallocate a storage space of size n pointed to by pointer p */
	template<typename T, typename Alloc>
		void
		vector<T,Alloc>::_M_deallocate(pointer __p, const size_type __n)
		{
			if (__p)
				this->_M_alloc.deallocate(__p, __n);
		}

	/* Swap vector's data with x */
	template<typename T, typename Alloc>
		void
		vector<T,Alloc>::_M_swap(vector& __x)
		{
			pointer	__tmp_begin(__x._M_begin);
			pointer	__tmp_end(__x._M_end);
			pointer	__tmp_endOfStorage(__x._M_end_of_storage);

			__x._M_begin = this->_M_begin;
			__x._M_end = this->_M_end;
			__x._M_end_of_storage = this->_M_end_of_storage;

			this->_M_begin = __tmp_begin;
			this->_M_end = __tmp_end;
			this->_M_end_of_storage = __tmp_endOfStorage;
		}

	/* Construct n elements using default value */
	template<typename T, typename Alloc>
		void
		vector<T,Alloc>::_M_default_initialize(size_type __n)
		{
			for (size_type __i = 0;
				 __i < __n && this->_M_end != this->_M_end_of_storage;
				 ++__i, ++this->_M_end)
			{
				this->_M_alloc.construct(this->_M_end, value_type());
			}
		}

	/* Construct with n elements of value val */
	template<typename T, typename Alloc>
	template<typename InputIterator>
		void
		vector<T,Alloc>::_M_range_initialize(InputIterator __first, InputIterator __last)
		{
			size_type	__len = 0;

			for (InputIterator __cursor(__first); __cursor != __last; ++__cursor)
				++__len;

			if (__len > 0)
			{
				_M_create_storage(__len);
				for ( ; __first != __last; ++__first, ++this->_M_end)
					this->_M_alloc.construct(this->_M_end, *__first);
			}
		}

	/* Insert a range of elements at a given position */
	template<typename T, typename Alloc>
	template<typename InputIterator>
		void
		vector<T, Alloc>::_M_range_insert(iterator __pos, InputIterator __first, InputIterator __last)
		{
			size_type	__len = 0;

			for (InputIterator __cursor(__first); __cursor != __last; ++__cursor)
				++__len;

			if (__len > 0)
			{
				if (capacity() - size() >= __len) // enough capacity left
				{
					size_type	__nb_elem_after = end() - __pos;
					iterator	__backup_end(end());

					_M_default_initialize(__len);
					// if need to move element after filled range
					if (__pos != end())
					{
						for (iterator __it(end()); __nb_elem_after > 0; --__nb_elem_after)
							*(--__it) = *(--__backup_end);
					}
					// fill with the given range
					for ( ; __first != __last && __pos != end(); ++__first, ++__pos)
						*__pos = *__first;
				}
				else // not enough capacity
				{
					const size_type	__new_size = _M_len_check(__len, "vector::_M_range_insert");
					iterator		__it(begin());
					size_type		__nb_elem_before = __pos - begin();
					size_type		__nb_elem_after = end() - __pos;
					pointer			__new_start = this->_M_allocate(__new_size);
					pointer			__new_end(__new_start);

					for ( ; __nb_elem_before > 0 && __it != end(); --__nb_elem_before, ++__it, ++__new_end)
						this->_M_alloc.construct(__new_end, *__it);
					for ( ; __first != __last; ++__first, ++__new_end)
						this->_M_alloc.construct(__new_end, *__first);
					for ( ; __nb_elem_after > 0 && __it != end(); --__nb_elem_after, ++__it, ++__new_end)
						this->_M_alloc.construct(__new_end, *__it);
					_M_erase_at_end(this->_M_begin);
					_M_deallocate(this->_M_begin, capacity());
					this->_M_begin = pointer(__new_start);
					this->_M_end = pointer(__new_end);
					this->_M_end_of_storage = this->_M_begin + __new_size;
				}
			}
		}

	/* Insert n elements of value val at a given position */
	template<typename T, typename Alloc>
		void
		vector<T, Alloc>::_M_fill_insert(iterator __pos, size_type __n, const value_type& __val)
		{
			if (__n > 0)
			{
				if (capacity() - size() >= __n) // enough capacity left
				{
					size_type	__nb_elem_after = end() - __pos;
					iterator	__backup_end(end());

					_M_default_initialize(__n);
					// if need to move element after filled range
					if (__pos != end())
					{
						for (iterator __it(end()); __nb_elem_after > 0; --__nb_elem_after)
							*(--__it) = *(--__backup_end);
					}
					// fill the range with n values
					for ( ; __n > 0 && __pos != end(); --__n, ++__pos)
						*__pos = value_type(__val);
				}
				else // not enough capacity
				{
					const size_type	__new_size = _M_len_check(__n, "vector::_M_fill_insert");
					iterator		__it(begin());
					size_type		__nb_elem_before = __pos - begin();
					size_type		__nb_elem_after = end() - __pos;
					pointer			__new_start = this->_M_allocate(__new_size);
					pointer			__new_end(__new_start);

					for ( ; __nb_elem_before > 0 && __it != end(); --__nb_elem_before, ++__it, ++__new_end)
						this->_M_alloc.construct(__new_end, *__it);
					for ( ; __n > 0; --__n, ++__new_end)
						this->_M_alloc.construct(__new_end, value_type(__val));
					for ( ; __nb_elem_after > 0 && __it != end(); --__nb_elem_after, ++__it, ++__new_end)
						this->_M_alloc.construct(__new_end, *__it);
					_M_erase_at_end(this->_M_begin);
					_M_deallocate(this->_M_begin, capacity());
					this->_M_begin = pointer(__new_start);
					this->_M_end = pointer(__new_end);
					this->_M_end_of_storage = this->_M_begin + __new_size;
				}
			}
		}

	/* Calculates capacity growth (private member function to help) */
	template<typename T, typename Alloc>
		typename vector<T,Alloc>::size_type
		vector<T,Alloc>::_M_calculate_growth(const size_type __n)
		{
			size_type	__dlb_capacity = capacity() + capacity();

			if (__dlb_capacity >= max_size())
				return (max_size());
			return ((__n > __dlb_capacity) ? __n : __dlb_capacity);
		}

	/* Destroy elements from a given position to the end */
	template<typename T, typename Alloc>
		void
		vector<T,Alloc>::_M_erase_at_end(pointer __pos)
		{
			size_type	__len = this->_M_end - __pos;

			for ( ; __len > 0; --__len)
			{
				--this->_M_end;
				this->_M_alloc.destroy(this->_M_end);
			}
		}

	/* Safety check for storage length */
	template<typename T, typename Alloc>
		typename vector<T,Alloc>::size_type
		vector<T,Alloc>::_M_len_check(const size_type __n, const char* __s) const
		{
			size_type	__size_left = max_size() - size();
			size_type	__len;

			if (__size_left < __n)
				throw std::length_error(__s);

			if (size() > __n)
				__len = size() + size();
			else
				__len = size() + __n;
			return ((__len > max_size()) ? max_size() : __len);
		}

	/* Safety check for at() */
	template<typename T, typename Alloc>
		void
		vector<T,Alloc>::_M_range_check(const size_type __n) const
		{
			if (__n >= size())
			{
				std::stringstream	err_msg;

				err_msg << "vector::_M_range_check: __n (which is " << __n
						<< ") >= this->size() (which is " << this->size() << ")";
				throw std::out_of_range(err_msg.str());
			}
		}

	/* construct/copy/destroy *********************************************** */

	/* Default constructor */
	template<typename T, typename Alloc>
		vector<T,Alloc>::vector(const allocator_type& alloc)
		: _M_alloc(alloc), _M_begin(), _M_end(), _M_end_of_storage() { }

	/* Fill constructor */
	template<typename T, typename Alloc>
		vector<T,Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc)
		: _M_alloc(alloc), _M_begin(), _M_end(), _M_end_of_storage()
		{
			_M_create_storage(n);
			for ( ; n > 0; ++this->_M_end, --n)
				this->_M_alloc.construct(this->_M_end, val);
		}

	/* Range constructor */
	template<typename T, typename Alloc>
	template<typename InputIterator>
		vector<T,Alloc>::vector(
			InputIterator first, InputIterator last, const allocator_type& alloc,
			typename requires_input_iter<(!is_integral<InputIterator>::value), InputIterator>::type*)
		: _M_alloc(alloc), _M_begin(), _M_end(), _M_end_of_storage()
		{
			_M_range_initialize(first, last);
		}

	/* Copy constructor */
	template<typename T, typename Alloc>
		vector<T,Alloc>::vector(const vector& other)
		: _M_alloc(other.get_alloc())
		{
			size_type	len = other.size();

			_M_create_storage(len);
			for (size_type i = 0; i < len; ++i, ++this->_M_end)
				this->_M_alloc.construct(this->_M_end, other[i]);
		}

	/* Destructor */
	template<typename T, typename Alloc>
		vector<T,Alloc>::~vector(void)
		{
			_M_erase_at_end(this->_M_begin);
			_M_deallocate(this->_M_begin, capacity());
		}

	/* Copy assignment operator */
	template<typename T, typename Alloc>
		vector<T,Alloc>&
		vector<T,Alloc>::operator=(const vector& other)
		{
			if (this != &other)
			{
				size_type	new_size = other.size();

				_M_erase_at_end(this->_M_begin);
				if (capacity() < new_size)
				{
					_M_deallocate(this->_M_begin, capacity());
					_M_create_storage(new_size);
				}
				for (size_type i = 0; i < new_size; ++i, ++this->_M_end)
					this->_M_alloc.construct(this->_M_end, other[i]);
			}
			return (*this);
		}

	/* allocator ************************************************************ */

	template<typename T, typename Alloc>
		typename vector<T,Alloc>::allocator_type
		vector<T,Alloc>::get_alloc(void) const
		{ return (allocator_type(this->_M_alloc)); }

	/* iterators ************************************************************ */

	/* Returns an iterator pointing to the first element in the vector */
	template<typename T, typename Alloc>
		typename vector<T,Alloc>::iterator
		vector<T,Alloc>::begin(void)
		{ return (iterator(this->_M_begin)); }

	template<typename T, typename Alloc>
		typename vector<T,Alloc>::const_iterator
		vector<T,Alloc>::begin(void) const
		{ return (const_iterator(this->_M_begin)); }

	/* Returns an iterator referring to the past-the-end element in the vector */
	template<typename T, typename Alloc>
		typename vector<T,Alloc>::iterator
		vector<T,Alloc>::end(void)
		{ return (iterator(this->_M_end)); }

	template<typename T, typename Alloc>
		typename vector<T,Alloc>::const_iterator
		vector<T,Alloc>::end(void) const
		{ return (const_iterator(this->_M_end)); }

	/* Returns a reverse iterator pointing to the last element in the vector */
	template<typename T, typename Alloc>
		typename vector<T,Alloc>::reverse_iterator
		vector<T,Alloc>::rbegin(void)
		{ return (reverse_iterator(end())); }

	template<typename T, typename Alloc>
		typename vector<T,Alloc>::const_reverse_iterator
		vector<T,Alloc>::rbegin(void) const
		{ return (const_reverse_iterator(end())); }

	/*
	 * Returns a reverse iterator pointing to the theoretical element preceding
	 * the first element in the vector
	 */
	template<typename T, typename Alloc>
		typename vector<T,Alloc>::reverse_iterator
		vector<T,Alloc>::rend(void)
		{ return (reverse_iterator(begin())); }

	template<typename T, typename Alloc>
		typename vector<T,Alloc>::const_reverse_iterator
		vector<T,Alloc>::rend(void) const
		{ return (const_reverse_iterator(begin())); }

	/* capacity ************************************************************* */

	template<typename T, typename Alloc>
		bool
		vector<T,Alloc>::empty(void) const
		{ return (begin() == end()); }

	template<typename T, typename Alloc>
		typename vector<T,Alloc>::size_type
		vector<T,Alloc>::size(void) const
		{ return (size_type(this->_M_end - this->_M_begin)); }

	template<typename T, typename Alloc>
		typename vector<T,Alloc>::size_type
		vector<T,Alloc>::max_size(void) const
		{ return (this->_M_alloc.max_size()); }

	/* Resizes the container so that it contains n elements. */
	template<typename T, typename Alloc>
		void
		vector<T,Alloc>::resize(size_type n, value_type val)
		{
			if (n < size())
				_M_erase_at_end(this->_M_begin + n);
			else if (n > size())
				_M_fill_insert(this->end(), n - size(), val);
		}

	template<typename T, typename Alloc>
		typename vector<T,Alloc>::size_type
		vector<T,Alloc>::capacity(void) const
		{ return (size_type(this->_M_end_of_storage - this->_M_begin)); }

	/* Requests that the vector capacity be at least enough to contain n elements */
	template<typename T, typename Alloc>
		void
		vector<T,Alloc>::reserve(size_type n)
		{
			if (n <= capacity())
				return ;
			if (n > max_size())
				throw std::length_error("vector::reserve");

			size_type	old_size = size();
			size_type	old_capacity = capacity();
			pointer		tmp = this->_M_begin;

			_M_create_storage(_M_calculate_growth(n));
			for (size_type i = 0; i < old_size; ++i, ++this->_M_end)
			{
				this->_M_alloc.construct(this->_M_end, tmp[i]);
				this->_M_alloc.destroy(&tmp[i]);
			}
			_M_deallocate(tmp, old_capacity);
		}


	/* element access ******************************************************* */

	/* Returns a reference to the element at position n in the vector container */
	template<typename T, typename Alloc>
		typename vector<T,Alloc>::reference
		vector<T,Alloc>::operator[](size_type n)
		{ return (this->_M_begin[n]); }

	template<typename T, typename Alloc>
		typename vector<T,Alloc>::const_reference
		vector<T,Alloc>::operator[](size_type n) const
		{ return (this->_M_begin[n]); }

	/* Returns the element at the specified position in the container */
	template<typename T, typename Alloc>
		typename vector<T,Alloc>::reference
		vector<T,Alloc>::at(size_type n)
		{
			_M_range_check(n);
			return ((*this)[n]);
		}

	template<typename T, typename Alloc>
		typename vector<T,Alloc>::const_reference
		vector<T,Alloc>::at(size_type n) const
		{
			_M_range_check(n);
			return ((*this)[n]);
		}

	/* Returns the first element in the vector */
	template<typename T, typename Alloc>
		typename vector<T,Alloc>::reference
		vector<T,Alloc>::front(void)
		{ return (*(begin())); }

	template<typename T, typename Alloc>
		typename vector<T,Alloc>::const_reference
		vector<T,Alloc>::front(void) const
		{ return (*(begin())); }

	/* Returns the last element in the vector */
	template<typename T, typename Alloc>
		typename vector<T,Alloc>::reference
		vector<T,Alloc>::back(void)
		{ return (*(end() - 1)); }

	template<typename T, typename Alloc>
		typename vector<T,Alloc>::const_reference
		vector<T,Alloc>::back(void) const
		{ return (*(end() - 1)); }

	/* modifiers ************************************************************ */

	/* Assigns new contents to the vector, replacing its current contents */
	template<typename T, typename Alloc>
	template<typename InputIterator>
		void
		vector<T,Alloc>::assign(
			InputIterator first, InputIterator last,
			typename requires_input_iter<(!is_integral<InputIterator>::value), InputIterator>::type*)
		{
			_M_erase_at_end(_M_begin);
			_M_deallocate(_M_begin, capacity());
			_M_range_initialize(first, last);
		}

	template<typename T, typename Alloc>
		void
		vector<T,Alloc>::assign(size_type n, const value_type& val)
		{
			resize(n);
			clear();
			for ( ; n > 0; --n, ++this->_M_end)
				this->_M_alloc.construct(this->_M_end, val);
		}

	/* Adds a new element at the end of the vector, after its current last element. */
	template<typename T, typename Alloc>
		void
		vector<T,Alloc>::push_back(const value_type& val)
		{
			if (this->_M_end == this->_M_end_of_storage)
				reserve(size() + 1);
			this->_M_alloc.construct(this->_M_end, val);
			++this->_M_end;
		}

	/* Removes the last element in the vector. */
	template<typename T, typename Alloc>
		void
		vector<T,Alloc>::pop_back(void)
		{
			--this->_M_end;
			this->_M_alloc.destroy(this->_M_end);
		}

	/* Insert a single element before the element at the specified position */
	template<typename T, typename Alloc>
		typename vector<T,Alloc>::iterator
		vector<T,Alloc>::insert(iterator position, const value_type& val)
		{
			size_type	n = position - begin();

			_M_fill_insert(position, 1, val);
			return (begin() + n);
		}

	/* Insert n new elements before the element at the specified position */
	template<typename T, typename Alloc>
		void
		vector<T,Alloc>::insert(iterator position, size_type n, const value_type& val)
		{
			_M_fill_insert(position, n, val);
		}

	/* Insert a range of elements before the element at the specified position */
	template<typename T, typename Alloc>
	template<typename InputIterator>
		void
		vector<T,Alloc>::insert(
			iterator position, InputIterator first, InputIterator last,
			typename requires_input_iter<(!is_integral<InputIterator>::value), InputIterator>::type*)
		{
			if (first != last)
				_M_range_insert(position, first, last);
		}

	/* Removes from the vector the element at the given position */
	template<typename T, typename Alloc>
		typename vector<T,Alloc>::iterator
		vector<T,Alloc>::erase(iterator position)
		{
			iterator	it(position);
			iterator	next(position + 1);
			iterator	ite(end());

			while (next != ite)
				*(it++) = *(next++);
			--this->_M_end;
			this->_M_alloc.destroy(this->_M_end);
			return (position);
		}

	/* Removes from the vector a range of elements */
	template<typename T, typename Alloc>
		typename vector<T,Alloc>::iterator
		vector<T,Alloc>::erase(iterator first, iterator last)
		{
			iterator	pos(first);

			if (first != last)
			{
				iterator	ite = end();

				while (last != ite)
					*(first++) = *(last++);
				_M_erase_at_end(first.base());
			}
			return (pos);
		}

	/* Exchanges the content of the vector and the other vector */
	template<typename T, typename Alloc>
		void
		vector<T,Alloc>::swap(vector& other)
		{
			this->_M_swap(other);
		}

	/* Destroys all elements from the vector, leaving the container with a size of 0 */
	template<typename T, typename Alloc>
		void
		vector<T,Alloc>::clear(void)
		{
			_M_erase_at_end(this->_M_begin);
		}

	/* non-member function overloads **************************************** */

	/* Relational operators: make comparison between two vectors */

	template<typename T, typename Alloc>
		bool
		operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{ return ((lhs.size() == rhs.size()) && (ft::equal( lhs.begin(), lhs.end(), rhs.begin()))); }

	template<typename T, typename Alloc>
		bool
		operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{ return (!(lhs == rhs)); }

	template<typename T, typename Alloc>
		bool
		operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template<typename T, typename Alloc>
		bool
		operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{ return (rhs < lhs); }

	template<typename T, typename Alloc>
		bool
		operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{ return (!(rhs < lhs)); }

	template<typename T, typename Alloc>
		bool
		operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{ return (!(lhs < rhs)); }

	/* Exchange contents of two vectors */
	template<typename T, typename Alloc>
		void
		swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			x.swap(y);
		}
} // namespace ft

#endif
