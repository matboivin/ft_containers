/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:25:08 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/29 23:30:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

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
	 * Vector template class
	 * Array which size can change dynamically
	 *
	 * @param T      Type of the elements
	 * @param Alloc  Type of the allocator object used to define the storage
	 *               allocation model
	 */
	template<typename T, typename Alloc = std::allocator<T> >
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
		pointer			_M_allocate(size_type __n);
		void			_M_create_storage(size_type __n);
		void			_M_deallocate(pointer __p, size_type __n);
		void			_M_swap_data(vector& __x);
		void			_M_default_initialize(size_type __n);
		template<typename InputIterator>
			void		_M_range_initialize(InputIterator __first, InputIterator __last);
		template<typename InputIterator>
			void		_M_range_insert(iterator __pos, InputIterator __first, InputIterator __last);
		void			_M_fill_insert(iterator __pos, size_type __n, const value_type& __val);
		size_type		_M_calculateGrowth(const size_type __n);
		void			_M_range_check(size_type __n) const;
		size_type		_M_len_check(size_type __n, const char* __s) const;
		void			_M_erase_at_end(pointer __pos);

	public:
		// default constructor
		vector(const allocator_type& alloc = allocator_type());

		// fill constructor
		vector(size_type n, const value_type& val = value_type(),
			   const allocator_type& alloc = allocator_type());
		
		// range constructor
		template<typename InputIterator>
			vector(InputIterator first, InputIterator last,
				   const allocator_type& alloc = allocator_type(),
				   typename ft::requires_input_iter<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0
				   );

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
							   typename ft::requires_input_iter<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0
							   );
		void			assign(size_type n, const value_type& val);
		void			push_back(const value_type& val);
		void			pop_back(void);
		iterator		insert(iterator position, const value_type& val);
		void			insert(iterator position, size_type n, const value_type& val);
		template<typename InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last,
							   typename ft::requires_input_iter<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0
							   );
		iterator		erase(iterator position);
		iterator		erase(iterator first, iterator last);
		void			swap(vector& x);
		void			clear(void);
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


	/* ********************************************************************** */
	/*                                                                        */
	/*                             Implementation                             */
	/*                                                                        */
	/* ********************************************************************** */

	/* helpers ************************************************************** */

	/*
	 * Allocate a storage space of size n
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::pointer
	vector<T,Alloc>::_M_allocate(size_type __n)
	{
		if (__n > 0)
			return (this->_M_alloc.allocate(__n));

		return (pointer());
	}

	/*
	 * Allocate a new storage space and set the pointers to the end
	 * (it's empty, so it points to the beginning) and to the end of storage
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::_M_create_storage(size_type __n)
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
	vector<T,Alloc>::_M_deallocate(pointer __p, size_type __n)
	{
		if (__p)
			this->_M_alloc.deallocate(__p, __n);
	}

	/*
	 * Swap vector's data with x
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::_M_swap_data(vector& __x)
	{
		pointer	__tmp_begin(__x._M_begin);
		pointer	__tmp_end(__x._M_end);
		pointer	__tmp_endOfStorage(__x._M_endOfStorage);

		__x._M_begin = this->_M_begin;
		__x._M_end = this->_M_end;
		__x._M_endOfStorage = this->_M_endOfStorage;

		this->_M_begin = __tmp_begin;
		this->_M_end = __tmp_end;
		this->_M_endOfStorage = __tmp_endOfStorage;
	}

	/*
	 * Construct n elements using default value
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::_M_default_initialize(size_type __n)
	{
		if (__n > 0)
		{
			for ( ; __n > 0; --__n)
			{
				this->_M_alloc.construct(this->_M_end, value_type());
				++this->_M_end;
			}
		}
	}

	/*
	 * Construct with n elements of value val
	 */
	template<typename T, typename Alloc>
	template<typename InputIterator>
	void
	vector<T,Alloc>::_M_range_initialize(InputIterator __first, InputIterator __last)
	{
		difference_type	__len = __first - __last;

		if (__len > 0)
		{
			_M_create_storage(__len);
			for ( ; __first != __last; ++__first )
			{
				this->_M_alloc.construct(this->_M_end, *__first);
				++this->_M_end;
			}
		}
	}

	/*
	 * Insert a range of elements at a given position
	 */
	template<typename T, typename Alloc>
	template<typename InputIterator>
	void
	vector<T, Alloc>::_M_range_insert(iterator __pos, InputIterator __first, InputIterator __last)
	{
		difference_type	__len = __first - __last;

		if (__len > 0)
		{
			if (capacity() - size() >= size_type(__len)) // enough capacity left
			{
				iterator	__backup_end = end();

				_M_default_initialize(__len);
				// if need to move element after filled range
				if (size_type(end() - __pos) > 0)
				{
					iterator	it = end();

					while (__pos != __backup_end)
						*(--it) = *(--__backup_end);
				}
				// fill with the given range
				for ( ; __first != __last; ++__first)
				{
					*__pos = *__first;
					++__pos;
				}
			}
			else // not enough capacity
			{
				size_type		__nb_elem_before = begin() - __pos;
				size_type		__nb_elem_after = __pos - end();

				// alloc new elements
				const size_type	__new_size = _M_len_check(__len, "vector::_M_range_insert");
				pointer			__new_start = this->_M_allocate(__new_size);
				pointer			__new_end = __new_start;
				iterator		__it = begin();

				// if need to copy elements before the range
				if (__nb_elem_before)
				{
					for ( ; __nb_elem_before > 0; --__nb_elem_before, ++__it)
					{
						this->_M_alloc.construct(__new_end, *(__it));
						++__new_end;
					}
				}
				// fill the range with n values
				for ( ; __first != __last; ++__first)
				{
					this->_M_alloc.construct(__new_end, *__first);
					++__new_end;
				}
				// if need to move element after filled range
				if (__nb_elem_after)
				{
					for ( ; __nb_elem_after > 0; --__nb_elem_after, ++__it)
					{
						this->_M_alloc.construct(__new_end, *(__it));
						++__new_end;
					}
				}
				_M_erase_at_end(this->_M_begin);
				_M_deallocate(this->_M_begin, capacity());
				this->_M_begin = pointer(__new_start);
				this->_M_end = pointer(__new_end);
				this->_M_endOfStorage = this->_M_begin + __new_size;
			}
		}
	}

	/*
	 * Insert n elements of value val at a given position
	 */
	template<typename T, typename Alloc>
	void
	vector<T, Alloc>::_M_fill_insert(iterator __pos, size_type __n, const value_type& __val)
	{
		if (__n > 0)
		{
			if (capacity() - size() >= __n) // enough capacity left
			{
				iterator	__backup_end = end();

				_M_default_initialize(__n);
				// if need to move element after filled range
				if (size_type(end() - __pos) > 0)
				{
					iterator	it = end();
					while (__pos != __backup_end)
						*(--it) = *(--__backup_end);
				}
				// fill the range with n values
				for ( ; __n > 0; --__n)
				{
					*__pos = __val;
					++__pos;
				}
			}
			else // not enough capacity
			{
				size_type		__nb_elem_before = begin() - __pos;
				size_type		__nb_elem_after = __pos - end();

				// alloc new elements
				const size_type	__new_size = _M_len_check(__n, "vector::_M_fill_insert");
				pointer			__new_start = this->_M_allocate(__new_size);
				pointer			__new_end = __new_start;
				iterator		__it = begin();

				// if need to copy elements before the range
				if (__nb_elem_before)
				{
					for ( ; __nb_elem_before > 0; --__nb_elem_before, ++__it)
					{
						this->_M_alloc.construct(__new_end, *(__it));
						++__new_end;
					}
				}
				// fill the range with n values
				for ( ; __n > 0; --__n)
				{
					this->_M_alloc.construct(__new_end, __val);
					++__new_end;
				}
				// if need to move element after filled range
				if (__nb_elem_after)
				{
					for ( ; __nb_elem_after > 0; --__nb_elem_after, ++__it)
					{
						this->_M_alloc.construct(__new_end, *(__it));
						++__new_end;
					}
				}
				_M_erase_at_end(this->_M_begin);
				_M_deallocate(this->_M_begin, capacity());
				this->_M_begin = pointer(__new_start);
				this->_M_end = pointer(__new_end);
				this->_M_endOfStorage = this->_M_begin + __new_size;
			}
		}
	}

	/*
	 * Calculates capacity growth (private member function to help)
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::size_type
	vector<T,Alloc>::_M_calculateGrowth(const size_type __n)
	{
		size_type	__dlb_capacity = capacity() + capacity();

		// handle overflow
		if (__dlb_capacity >= max_size())
			return (max_size());
		
		return ( (__n > __dlb_capacity) ? __n : __dlb_capacity );
	}

	/*
	 * Destroy elements from a given position to the end
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::_M_erase_at_end(pointer __pos)
	{
		if (size_type __len = this->_M_end - __pos)
		{
			while (__len--)
			{
				--this->_M_end;
				this->_M_alloc.destroy(this->_M_end);
			}
		}
	}

	/*
	 * Safety check for storage length
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::size_type
	vector<T,Alloc>::_M_len_check(size_type __n, const char* __s) const
	{
		size_type	__size_left = max_size() - size();

		if (__size_left < __n)
			throw std::length_error(__s);

		size_type	__len;

		if (size() > __n)
			__len = size() + size();
		else
			__len = size() + __n;

		return ( (__len > max_size()) ? max_size() : __len );
	}

	/* construct/copy/destroy *********************************************** */

	/*
	 * Default constructor
	 * Constructs an empty container, with no elements.
	 *
	 * @param alloc  Allocator object
	 */
	template<typename T, typename Alloc>
	vector<T,Alloc>::vector(const allocator_type& alloc)
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
	vector<T,Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc)
	: _M_alloc(alloc)
	{
		_M_create_storage(n);
		for ( ; n > 0; ++this->_M_end, --n )
			this->_M_alloc.construct(this->_M_end, val);
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
	vector<T,Alloc>::vector(InputIterator first, InputIterator last,
							const allocator_type& alloc,
							typename ft::requires_input_iter<!ft::is_integral<InputIterator>::value, InputIterator>::type*)
	: _M_alloc(alloc)
	{
		_M_range_initialize(first, last);
	}

	/*
	 * Copy constructor
	 * Constructs a container with a copy of each of the elements in x, in the same order.
	 * Capacity of the new vector is equal to the size of x to avoid unused capacity.
	 *
	 * @param x  Another vector object of the same type
	 *           (with the same class template arguments T and Allocator)
	 */
	template<typename T, typename Alloc>
	vector<T,Alloc>::vector(const vector& x)
	: _M_alloc(x.get_alloc())
	{
		size_type	len = x.size();

		_M_create_storage(len);
		for ( size_type i = 0; i < len; ++i )
		{
			this->_M_alloc.construct(this->_M_end, x[i]);
			++this->_M_end;
		}
	}

	/*
	 * Destructor
	 *
	 * Destroys all container elements, and deallocates all the storage capacity
	 * allocated by the vector using its allocator.
	 */
	template<typename T, typename Alloc>
	vector<T,Alloc>::~vector(void)
	{
		_M_erase_at_end(this->_M_begin);
		_M_deallocate(this->_M_begin, capacity());
	}

	/*
	 * Copy assignment operator
	 *
	 * Assigns new contents to the container, replacing its current contents,
	 * and modifying its size accordingly.
	 * The container preserves its current allocator, which is used to allocate storage
	 * in case of reallocation.
	 * Capacity of the vector is equal to the size of rhs to avoid unused capacity.
	 *
	 * @param x  Another vector object of the same type
	 *           (with the same class template arguments T and Allocator)
	 *
	 * @return  *this
	 */
	template<typename T, typename Alloc>
	vector<T,Alloc>&
	vector<T,Alloc>::operator=(const vector& rhs)
	{
		// avoid self-assignment
		if (this != &rhs)
		{
			size_type	new_size = rhs.size();

			_M_erase_at_end(this->_M_begin);
			if (capacity() < new_size)
			{
				// need to expand capacity
				_M_deallocate(this->_M_begin, capacity());
				_M_create_storage(new_size);
			}
			for ( size_type i = 0; i < new_size; ++i )
			{
				this->_M_alloc.construct(this->_M_end, rhs[i]);
				++this->_M_end;
			}
		}
		return (*this);
	}

	/* allocator ************************************************************ */

	/*
	 * Returns a copy of the allocator object associated with the vector.
	 *
	 * @return  The allocator
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::allocator_type
	vector<T,Alloc>::get_alloc(void) const
	{
		return ( allocator_type(this->_M_alloc) );
	}


	/* iterators ************************************************************ */

	/*
	 * Returns an iterator pointing to the first element in the vector
	 *
	 * @return  An iterator to the beginning of the sequence container
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::iterator
	vector<T,Alloc>::begin(void)
	{
		return ( iterator(this->_M_begin) );
	}

	template<typename T, typename Alloc>
	typename vector<T,Alloc>::const_iterator
	vector<T,Alloc>::begin(void) const
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
	vector<T,Alloc>::end(void)
	{
		return ( iterator(this->_M_end) );
	}

	template<typename T, typename Alloc>
	typename vector<T,Alloc>::const_iterator
	vector<T,Alloc>::end(void) const
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
	vector<T,Alloc>::rbegin(void)
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
	vector<T,Alloc>::rend(void)
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
	vector<T,Alloc>::empty(void) const
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
	vector<T,Alloc>::size(void) const
	{
		return ( size_type(this->_M_end - this->_M_begin) );
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
	vector<T,Alloc>::max_size(void) const
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
	vector<T,Alloc>::resize(size_type n, value_type val)
	{
		if (n > size())
			_M_fill_insert(this->end(), n - size(), val);
		else if (n < size())
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
	vector<T,Alloc>::capacity(void) const
	{
		return (size_type(this->_M_endOfStorage - this->_M_begin));
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
	vector<T,Alloc>::reserve(size_type n)
	{
		if (n <= capacity())
			return ;
		if (n > max_size())
			throw std::length_error("vector::reserve");

		size_type	old_size = size();
		size_type	old_capacity = capacity();
		pointer		tmp = this->_M_begin;

		_M_create_storage(_M_calculateGrowth(n));

		for ( size_type i = 0; i < old_size; ++i )
		{
			this->_M_alloc.construct(this->_M_end, tmp[i]);
			this->_M_alloc.destroy(&tmp[i]);
			++this->_M_end;
		}
		_M_deallocate(tmp, old_capacity);
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
	vector<T,Alloc>::operator[](size_type n)
	{
		return (this->_M_begin[n]);
	}

	template<typename T, typename Alloc>
	typename vector<T,Alloc>::const_reference
	vector<T,Alloc>::operator[](size_type n) const
	{
		return (this->_M_begin[n]);
	}

	/*
	 * Safety check for at()
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::_M_range_check(size_type __n) const
	{
		if (__n > size())
		{
			std::stringstream	err_msg;
	
			err_msg << "vector::_M_range_check: __n (which is " << __n
					<< ") >= this->size() (which is " << size() << ")";

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
	vector<T,Alloc>::at(size_type n)
	{
		_M_range_check(n);
		return (this->_M_begin[n]);
	}

	template<typename T, typename Alloc>
	typename vector<T,Alloc>::const_reference
	vector<T,Alloc>::at(size_type n) const
	{
		_M_range_check(n);
		return (this->_M_begin[n]);
	}

	/*
	 * Access the first element in the vector
	 *
	 * @return  A reference to the first element in the vector container
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::reference
	vector<T,Alloc>::front(void)
	{
		return ( *(begin()) );
	}

	template<typename T, typename Alloc>
	typename vector<T,Alloc>::const_reference
	vector<T,Alloc>::front(void) const
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
	vector<T,Alloc>::back(void)
	{
		return ( *(end() - 1) );
	}

	template<typename T, typename Alloc>
	typename vector<T,Alloc>::const_reference
	vector<T,Alloc>::back(void) const
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
	template<typename T, typename Alloc>
	template<typename InputIterator>
	void
	vector<T,Alloc>::assign(InputIterator first, InputIterator last,
							typename ft::requires_input_iter<!ft::is_integral<InputIterator>::value, InputIterator>::type*
							)
	{
		_M_erase_at_end(_M_begin);
		_M_deallocate(_M_begin, capacity());
		_M_range_initialize(first, last);
	}

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
	vector<T,Alloc>::assign(size_type n, const value_type& val)
	{
		resize(n);
		clear();
		for ( ; n > 0; ++this->_M_end, --n )
			this->_M_alloc.construct(this->_M_end, val);
	}

	/*
	 * Adds a new element at the end of the vector, after its current last element.
	 *
	 * @param val  Value to be copied (or moved) to the new element
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::push_back(const value_type& val)
	{
		// If the new vector size surpasses the current vector capacity,
		// it causes an automatic reallocation of the allocated storage space.
		if (this->_M_end == this->_M_endOfStorage)
			reserve(size() + 1);

		// add the new element
		this->_M_alloc.construct(this->_M_end, val);
		++this->_M_end;
	}

	/*
	 * Removes the last element in the vector, effectively reducing the container size by one.
	 * This destroys the removed element.
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::pop_back(void)
	{
		--this->_M_end;
		this->_M_alloc.destroy(this->_M_end);
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
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::iterator
	vector<T,Alloc>::insert(iterator position, const value_type& val)
	{
		_M_fill_insert(position, 1, val);
		return (position);
	}

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
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::insert(iterator position, size_type n, const value_type& val)
	{
		_M_fill_insert(position, n, val);
	}

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
	template<typename T, typename Alloc>
	template<typename InputIterator>
	void
	vector<T,Alloc>::insert(iterator position, InputIterator first, InputIterator last,
							typename ft::requires_input_iter<!ft::is_integral<InputIterator>::value, InputIterator>::type*
							)
	{
		if (first != last)
			_M_range_insert(position, first, last);
	}

	/*
	 * Removes from the vector the element at the given position
	 *
	 * @param position  Iterator pointing to a single element to be removed
	 *                  from the vector
	 *
	 * @return  An iterator pointing to the new location of the element
	 *          that followed the last element erased by the function call
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::iterator
	vector<T,Alloc>::erase(iterator position)
	{
		iterator	it(position);
		iterator	next = position + 1;
		iterator	ite = end();

		while (next != ite)
			*(it++) = *(next++);
		--this->_M_end;
		this->_M_alloc.destroy(this->_M_end);
		return (position);
	}

	/*
	 * Removes from the vector a range of elements
	 *
	 * @param first, last  Iterators specifying a range within the vector
	 *                     to be removed: [first,last)
	 *
	 * @return  An iterator pointing to the new location of the element
	 *          that followed the last element erased by the function call
	 */
	template<typename T, typename Alloc>
	typename vector<T,Alloc>::iterator
	vector<T,Alloc>::erase(iterator first, iterator last)
	{
		if (first != last)
		{
			iterator	ite = end();

			while (last != ite)
				*(first++) = *(last++);
			_M_erase_at_end(first.base());
		}
		return (first);
	}

	/*
	 * Exchanges the content of the container by the content of x
	 *
	 * @param x  Another vector container of the same type
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::swap(vector& x)
	{
		this->_M_swap_data(x);
	}

	/*
	 * Removes all elements from the vector (which are destroyed),
	 * leaving the container with a size of 0.
	 */
	template<typename T, typename Alloc>
	void
	vector<T,Alloc>::clear(void)
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
	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ( (lhs.size() == rhs.size())
				 && (ft::equal( lhs.begin(), lhs.end(), rhs.begin() )) );
	}

	template<typename T, typename Alloc>
	bool
	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ( !(lhs == rhs) );
	}

	template<typename T, typename Alloc>
	bool
	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ));
	}

	template<typename T, typename Alloc>
	bool
	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return ( !(rhs < lhs) );
	}

	template<typename T, typename Alloc>
	bool
	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<typename T, typename Alloc>
	bool
	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
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
	swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
} // namespace ft

#endif
