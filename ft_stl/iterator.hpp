/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:34:57 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/06 23:40:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "algorithm.hpp"
#include "type_traits.hpp"

/*
 * Credits:
 * Detailed comments mostly from www.cplusplus.com
 */

namespace ft
{
	/*
	 * Iterators
	 */

	/* Category tags ******************************************************** */

	/* Empty classes to identify categories */

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
	template<typename Category, typename T, typename Distance = std::ptrdiff_t,
			 typename Pointer = T*, typename Reference = T&>
	struct iterator
	{
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
	template<typename Iterator>
	struct iterator_traits
	{
		// types
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	/* Partial specialization for pointers */
	template<typename T>
	struct iterator_traits<T*>
	{
	public:
		// types
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T*								pointer;
		typedef T&								reference;
	};

	/* Partial specialization for pointers to const */
	template<typename T>
	struct iterator_traits<const T*>
	{
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
	 */
	template<typename Iterator>
	class reverse_iterator
	: public ft::iterator<typename ft::iterator_traits<Iterator>::iterator_category,
						  typename ft::iterator_traits<Iterator>::value_type,
						  typename ft::iterator_traits<Iterator>::difference_type,
						  typename ft::iterator_traits<Iterator>::pointer,
						  typename ft::iterator_traits<Iterator>::reference>
	{
	public:
		// types
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

	protected:
		Iterator	_M_current; // copy of the original iterator

	public:
		// default constructor
		reverse_iterator(void);

		// initalization constructor
		explicit reverse_iterator(iterator_type x);

		// copy constructor
		template<typename Iter>
			reverse_iterator(const reverse_iterator<Iter>& other);

		// copy assignment operator
		template<typename Iter>
			reverse_iterator&	operator=(const reverse_iterator<Iter>& other);

		// return copy of the original iterator
		iterator_type		base(void) const;

		// accesses the pointed-to element
		reference			operator*(void) const;
		pointer				operator->(void) const;

		// accesses an element by index
		reference			operator[](difference_type n) const;

		// advances or decrements the iterator
		reverse_iterator&	operator++(void);
		reverse_iterator	operator++(int);
		reverse_iterator&	operator+= (difference_type n);
		reverse_iterator	operator+(difference_type n) const;
		reverse_iterator&	operator--(void);
		reverse_iterator	operator--(int);
		reverse_iterator&	operator-=(difference_type n);
		reverse_iterator	operator-(difference_type n) const;
	};

	/* non-member function overloads **************************************** */

	// relational operators
	template<typename Iter1, typename Iter2>
		bool	operator==(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs);
	template<typename Iter1, typename Iter2>
		bool	operator!=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs);
	template<typename Iter1, typename Iter2>
		bool	operator<(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs);
	template<typename Iter1, typename Iter2>
		bool	operator<=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs);
	template<typename Iter1, typename Iter2>
		bool	operator>(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs);
	template<typename Iter1, typename Iter2>
		bool	operator>=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs);

	// addition operator
	template<typename Iterator>
		reverse_iterator<Iterator>
		operator+(typename reverse_iterator<Iterator>::difference_type n,
				  const reverse_iterator<Iterator>& rev_it);

	// subtraction operator
	template<typename Iterator>
		typename reverse_iterator<Iterator>::difference_type
		operator-(const reverse_iterator<Iterator>& lhs,
				  const reverse_iterator<Iterator>& rhs);


	/* Reverse iterator implementation ************************************** */

	/* construct/copy/destroy *********************************************** */

	/*
	 * Default constructor
	 * Constructs a reverse iterator that points to no object
	 */
	template<typename Iterator>
	reverse_iterator<Iterator>::reverse_iterator(void)
	: _M_current()
	{
	}

	/*
	 * Initalization constructor
	 * Constructs a reverse iterator from some original iterator x.
	 */
	template<typename Iterator>
	reverse_iterator<Iterator>::reverse_iterator(iterator_type x)
	: _M_current(x)
	{
	}

	/*
	 * Copy constructor
	 * Constructs a reverse iterator from some other reverse iterator
	 */
	template<typename Iterator>
	template<typename Iter>
	reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter>& other)
	: _M_current(other.base())
	{
	}

	/*
	 * Copy assignment operator
	 */
	template<typename Iterator>
	template<typename Iter>
	reverse_iterator<Iterator>&
	reverse_iterator<Iterator>::operator=(const reverse_iterator<Iter>& other)
	{
		if (this != &other)
			this->_M_current = other.base();

		return (*this);
	}

	/* getter *************************************************************** */

	/* Returns a copy of the base iterator */
	template<typename Iterator>
	typename reverse_iterator<Iterator>::iterator_type
	reverse_iterator<Iterator>::base(void) const
	{
		return (_M_current);
	}


	/* element access ******************************************************* */

	/*
	 * Dereference iterator
	 * Internally, the function decreases a copy of its base iterator and returns
	 * the result of dereferencing it
	 */
	template<typename Iterator>
	typename reverse_iterator<Iterator>::reference
	reverse_iterator<Iterator>::operator*(void) const
	{
		iterator_type	copy = _M_current;

		--copy;
		return (*copy);
	}

	/*
	 * Dereference iterator
	 * Internally, the function calls operator* and returns its address
	 */
	template<typename Iterator>
	typename reverse_iterator<Iterator>::pointer
	reverse_iterator<Iterator>::operator->(void) const
	{
		return ( &(operator*()) );
	}

	/*
	 * Dereference iterator with offset
	 * Accesses the element located n positions away from the element
	 * currently pointed to by the iterator.
	 */
	template<typename Iterator>
	typename reverse_iterator<Iterator>::reference
	reverse_iterator<Iterator>::operator[](difference_type n) const
	{
		return ( *(*this + n) );
	}


	/* advance/decrease ***************************************************** */

	/* Increment iterator position: pre-increment version */
	template<typename Iterator>
	reverse_iterator<Iterator>&
	reverse_iterator<Iterator>::operator++(void)
	{
		--_M_current;
		return (*this);
	}

	/* Increment iterator position: post-increment version */
	template<typename Iterator>
	reverse_iterator<Iterator>
	reverse_iterator<Iterator>::operator++(int)
	{
		reverse_iterator	backup = *this;

		++(*this);
		return (backup);
	}

	/*
	 * Advance iterator
	 * Advances the reverse_iterator by n element positions
	 */
	template<typename Iterator>
	reverse_iterator<Iterator>&
	reverse_iterator<Iterator>::operator+=(difference_type n)
	{
		_M_current -= n;
		return (*this);
	}

	/* Addition operator */
	template<typename Iterator>
	reverse_iterator<Iterator>
	reverse_iterator<Iterator>::operator+(difference_type n) const
	{
		return ( reverse_iterator(base() - n) );
	}

	/* Decrease iterator position: pre-decrement version */
	template<typename Iterator>
	reverse_iterator<Iterator>&
	reverse_iterator<Iterator>::operator--(void)
	{
		++_M_current;
		return (*this);
	}

	/* Decrease iterator position: post-decrement version */
	template<typename Iterator>
	reverse_iterator<Iterator>
	reverse_iterator<Iterator>::operator--(int)
	{
		reverse_iterator	backup = *this;

		--(*this);
		return (backup);
	}

	/*
	 * Retrocede iterator
	 * Decreases the reverse_iterator by n element positions
	 */
	template<typename Iterator>
	reverse_iterator<Iterator>&
	reverse_iterator<Iterator>::operator-=(difference_type n)
	{
		_M_current += n;
		return (*this);
	}

	/* Subtraction operator */
	template<typename Iterator>
	reverse_iterator<Iterator>
	reverse_iterator<Iterator>::operator-(difference_type n) const
	{
		return ( reverse_iterator(base() + n) );
	}


	/* non-member function overloads **************************************** */

	/* Relational operators */

	template<typename Iter1, typename Iter2>
	bool
	operator==(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename Iter1, typename Iter2>
	bool
	operator!=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename Iter1, typename Iter2>
	bool
	operator<(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename Iter1, typename Iter2>
	bool
	operator<=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<typename Iter1, typename Iter2>
	bool
	operator>(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<typename Iter1, typename Iter2>
	bool
	operator>=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	/*
	 * Addition operator
	 * Returns a reverse iterator pointing to the element located n positions
	 * away from the element pointed to by rev_it
	 */
	template<typename Iterator>
	reverse_iterator<Iterator>
	operator+(typename reverse_iterator<Iterator>::difference_type n,
			  const reverse_iterator<Iterator>& rev_it)
	{
		return ( reverse_iterator<Iterator>(rev_it.base() - n) );
	}

	/*
	 * Subtraction operator
	 * Computes the distance between two reverse iterators
	 * The function returns the same as subtracting lhs's base iterator from rhs's base iterator
	 */
	template<typename Iterator>
	typename reverse_iterator<Iterator>::difference_type
	operator-(const reverse_iterator<Iterator>& lhs,
			  const reverse_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	}


	/* Base iterator definition ********************************************* */

	/*
	 * Base iterator
	 * This class provides a base for custom iterators
	 */

	template<typename Iterator, typename Container>
	class base_iterator
	: public ft::iterator<typename ft::iterator_traits<Iterator>::iterator_category,
						  typename ft::iterator_traits<Iterator>::value_type,
						  typename ft::iterator_traits<Iterator>::difference_type,
						  typename ft::iterator_traits<Iterator>::pointer,
						  typename ft::iterator_traits<Iterator>::reference>
	{
	private:
		// More readable private alias
		typedef typename ft::iterator_traits<Iterator>		_iter_traits;

	public:
		// types
		typedef Iterator									iterator_type;
		typedef typename _iter_traits::iterator_category	iterator_category;
		typedef typename _iter_traits::value_type			value_type;
		typedef typename _iter_traits::difference_type		difference_type;
		typedef typename _iter_traits::pointer				pointer;
		typedef typename _iter_traits::reference			reference;

	protected:
		Iterator	_M_current; // copy of the original iterator

	public:
		// default constructor
		base_iterator(void);

		// initalization constructor
		explicit base_iterator(iterator_type x);

		// copy constructor
		template<typename Iter>
			base_iterator(const base_iterator<Iter,typename ft::enable_if<(ft::is_same<Iter, typename Container::pointer>::value), Container>::type>& other);

		// copy assignment operator
		template<typename Iter>
			base_iterator&	operator=(const base_iterator<Iter,Container>& other);

		// return copy of the original iterator
		iterator_type	base(void) const;

		// accesses the pointed-to element
		reference		operator*(void) const;
		pointer			operator->(void) const;

		// accesses an element by index
		reference		operator[](difference_type n) const;

		// advances or decrements the iterator
		base_iterator&	operator++(void);
		base_iterator	operator++(int);
		base_iterator&	operator+=(difference_type n);
		base_iterator	operator+(difference_type n) const;
		base_iterator&	operator--(void);
		base_iterator	operator--(int);
		base_iterator&	operator-=(difference_type n);
		base_iterator	operator-(difference_type n) const;
	};

	/* non-member function overloads **************************************** */

	template<typename Iter1, typename Iter2, typename Container>
		bool	operator==(const base_iterator<Iter1,Container>& lhs,
						   const base_iterator<Iter2,Container>& rhs);
	template<typename Iter1, typename Iter2, typename Container>
		bool	operator!=(const base_iterator<Iter1,Container>& lhs,
						   const base_iterator<Iter2,Container>& rhs);
	template<typename Iter1, typename Iter2, typename Container>
		bool	operator<(const base_iterator<Iter1,Container>& lhs,
						  const base_iterator<Iter2,Container>& rhs);
	template<typename Iter1, typename Iter2, typename Container>
		bool	operator<=(const base_iterator<Iter1,Container>& lhs,
						   const base_iterator<Iter2,Container>& rhs);
	template<typename Iter1, typename Iter2, typename Container>
		bool	operator>(const base_iterator<Iter1,Container>& lhs,
						  const base_iterator<Iter2,Container>& rhs);
	template<typename Iter1, typename Iter2, typename Container>
		bool	operator>=(const base_iterator<Iter1,Container>& lhs,
						   const base_iterator<Iter2,Container>& rhs);

	template<typename Iterator, typename Container>
		base_iterator<Iterator,Container>
		operator+(typename base_iterator<Iterator,Container>::difference_type n,
				  const base_iterator<Iterator,Container>& it);

	template<typename Iterator, typename Container>
		typename base_iterator<Iterator,Container>::difference_type
		operator-(const base_iterator<Iterator,Container>& lhs,
				  const base_iterator<Iterator,Container>& rhs);


	/* Base iterator implementation ***************************************** */

	/* construct/copy/destroy *********************************************** */

	/*
	 * Default constructor
	 * Constructs an iterator that points to no object
	 */
	template<typename Iterator, typename Container>
	base_iterator<Iterator,Container>::base_iterator(void)
	: _M_current(Iterator())
	{
	}

	/*
	 * Initalization constructor
	 * Constructs an iterator from some original iterator x
	 */
	template<typename Iterator, typename Container>
	base_iterator<Iterator,Container>::base_iterator(iterator_type x)
	: _M_current(x)
	{
	}

	/*
	 * Copy constructor
	 * Constructs an iterator from some other iterator
	 */
	template<typename Iterator, typename Container>
	template<typename Iter>
	base_iterator<Iterator,Container>::base_iterator(const base_iterator<Iter,typename ft::enable_if<(ft::is_same<Iter, typename Container::pointer>::value), Container>::type>& other)
	: _M_current(other.base())
	{
	}

	/* Copy assignment operator */
	template<typename Iterator, typename Container>
	template<typename Iter>
	base_iterator<Iterator,Container>&
	base_iterator<Iterator,Container>::operator=(const base_iterator<Iter,Container>& other)
	{
		if (this != &other)
			this->_M_current = other.base();

		return (*this);
	}

	/* getter *************************************************************** */

	/* Returns a copy of the base iterator */
	template<typename Iterator, typename Container>
	typename base_iterator<Iterator,Container>::iterator_type
	base_iterator<Iterator,Container>::base(void) const
	{
		return (_M_current);
	}


	/* element access ******************************************************* */

	/* Dereference iterator and returns a reference to the element pointed by the iterator */
	template<typename Iterator, typename Container>
	typename base_iterator<Iterator,Container>::reference
	base_iterator<Iterator,Container>::operator*(void) const
	{
		return (*_M_current);
	}

	/* Dereference iterator and returns a pointer to the element pointed to by the iterator */
	template<typename Iterator, typename Container>
	typename base_iterator<Iterator,Container>::pointer
	base_iterator<Iterator,Container>::operator->(void) const
	{
		return (_M_current);
	}

	/* Dereference iterator with offset */
	template<typename Iterator, typename Container>
	typename base_iterator<Iterator,Container>::reference
	base_iterator<Iterator,Container>::operator[](difference_type n) const
	{
		return (_M_current[n]);
	}


	/* advance/decrease ***************************************************** */

	/* Increment iterator position: pre-increment version */
	template<typename Iterator, typename Container>
	base_iterator<Iterator,Container>&
	base_iterator<Iterator,Container>::operator++(void)
	{
		++_M_current;
		return (*this);
	}

	/* Increment iterator position: post-increment version */
	template<typename Iterator, typename Container>
	base_iterator<Iterator,Container>
	base_iterator<Iterator,Container>::operator++(int)
	{
		base_iterator	backup = *this;

		++_M_current;
		return (backup);
	}

	/*
	 * Advance iterator
	 * Advances the base_iterator by n element positions
	 */
	template<typename Iterator, typename Container>
	base_iterator<Iterator,Container>&
	base_iterator<Iterator,Container>::operator+=(difference_type n)
	{
		_M_current += n;
		return (*this);
	}

	/* Addition operator */
	template<typename Iterator, typename Container>
	base_iterator<Iterator,Container>
	base_iterator<Iterator,Container>::operator+(difference_type n) const
	{
		return ( base_iterator(base() + n) );
	}

	/* Decrease iterator position: pre-decrement version */
	template<typename Iterator, typename Container>
	base_iterator<Iterator,Container>&
	base_iterator<Iterator,Container>::operator--(void)
	{
		--_M_current;
		return (*this);
	}

	/* Decrease iterator position: post-decrement version */
	template<typename Iterator, typename Container>
	base_iterator<Iterator,Container>
	base_iterator<Iterator,Container>::operator--(int)
	{
		base_iterator	backup = *this;

		--_M_current;
		return (backup);
	}

	/*
	 * Retrocede iterator
	 * Decreases the base_iterator by n element positions
	 */
	template<typename Iterator, typename Container>
	base_iterator<Iterator,Container>&
	base_iterator<Iterator,Container>::operator-=(difference_type n)
	{
		_M_current -= n;
		return (*this);
	}

	/* Subtraction operator */
	template<typename Iterator, typename Container>
	base_iterator<Iterator,Container>
	base_iterator<Iterator,Container>::operator-(difference_type n) const
	{
		return ( base_iterator(base() - n) );
	}


	/* non-member function overloads **************************************** */

	/* Relational operators */

	template<typename Iter1, typename Iter2, typename Container>
	bool
	operator==(const base_iterator<Iter1,Container>& lhs,
			   const base_iterator<Iter2,Container>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename Iter1, typename Iter2, typename Container>
	bool
	operator!=(const base_iterator<Iter1,Container>& lhs,
			   const base_iterator<Iter2,Container>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename Iter1, typename Iter2, typename Container>
	bool
	operator<(const base_iterator<Iter1,Container>& lhs,
			  const base_iterator<Iter2,Container>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<typename Iter1, typename Iter2, typename Container>
	bool
	operator<=(const base_iterator<Iter1,Container>& lhs,
			   const base_iterator<Iter2,Container>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template<typename Iter1, typename Iter2, typename Container>
	bool
	operator>(const base_iterator<Iter1,Container>& lhs,
			  const base_iterator<Iter2,Container>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename Iter1, typename Iter2, typename Container>
	bool
	operator>=(const base_iterator<Iter1,Container>& lhs,
			   const base_iterator<Iter2,Container>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	/*
	 * Addition operator
	 * Returns a base iterator pointing to the element located n positions
	 * away from the element pointed to by it
	 */
	template<typename Iterator, typename Container>
	base_iterator<Iterator,Container>
	operator+(typename base_iterator<Iterator,Container>::difference_type n,
			  const base_iterator<Iterator,Container>& it)
	{
		return ( base_iterator<Iterator,Container>(it.base() + n) );
	}

	/*
	 * Subtraction operator
	 * Computes the distance between two base iterators
	 * The function returns the same as subtracting lhs's base iterator from rhs's base iterator
	 */
	template<typename Iterator, typename Container>
	typename base_iterator<Iterator,Container>::difference_type
	operator-(const base_iterator<Iterator,Container>& lhs,
			   const base_iterator<Iterator,Container>& rhs)
	{
		return (rhs.base() - lhs.base());
	}

	/* iterator types ******************************************************* */

	/* Helpers for iter_is_input */

	// false by default
	template<typename Iter>
	struct iter_is_input : public false_type {};

	// specializations to return true for iterators that can be cast to input iterator
	template<>
	struct iter_is_input<ft::input_iterator_tag> : public true_type {};

	template<>
	struct iter_is_input<ft::forward_iterator_tag> : public true_type {};

	template<>
	struct iter_is_input<ft::bidirectional_iterator_tag> : public true_type {};

	template<>
	struct iter_is_input<ft::random_access_iterator_tag> : public true_type {};

	/*
	 * The type T is defined only if Cond (T is not an integral type) is true
	 *
	 * @param Cond  A compile-time constant of type bool
	 * @param T     A type
	 */

	template<bool Cond, typename T = void>
	struct requires_input_iter {};

	template<typename T>
	struct requires_input_iter<true, T>
	: public iter_is_input<typename ft::iterator_traits<T>::iterator_category>
	{
		typedef T	type;
	};
} // namespace ft

#endif
