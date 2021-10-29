/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:28:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/29 23:37:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <memory>
#include "algorithm.hpp"

/*
 * Credits:
 * Detailed comments mostly from www.cplusplus.com
 */

namespace ft
{
	/*
	 * Stack template class
	 * Encapsulates another container and provides a LIFO way to access to its 
	 * elements
	 *
	 * @param T          Type of the elements
	 * @param Container  Type of the internal underlying container object where 
	 *                   the elements are stored.
	 */
	template<typename T, typename Container = ft::vector<T> >
	class stack
	{
	public:
		//types
		typedef typename Container::value_type	value_type;
		typedef typename Container::size_type	size_type;
		typedef Container						container_type;

	protected:
		// attributes
		Container	c; // the underlying container object

	public:
		// constructor
		stack(const container_type& ctnr = container_type());

		// destructor
		~stack(void);

		// assignment operator
		stack&	operator=(const stack& other);

		// capacity
		bool		empty(void) const;
		size_type	size(void) const;

		// modifiers
		void		push(const value_type& val);
		void		pop(void);
	};

	/* non-member function overloads **************************************** */

	// relational operators
	template<typename T, typename Container = vector<T> >
		bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template<typename T, typename Container = vector<T> >
		bool	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template<typename T, typename Container = vector<T> >
		bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template<typename T, typename Container = vector<T> >
		bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template<typename T, typename Container = vector<T> >
		bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
	template<typename T, typename Container = vector<T> >
		bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

	/* ********************************************************************** */
	/*                                                                        */
	/*                             Implementation                             */
	/*                                                                        */
	/* ********************************************************************** */

	/* construct/copy/destroy *********************************************** */

	/*
	 * Constructor
	 * Constructs a stack container adaptor object
	 *
	 * @param ctnr  The type of the underlying container type
	 */
	template<typename T, typename Container = vector<T> >
	stack<T, Container>::stack(const container_type& ctnr = container_type())
	: c(ctnr)
	{
	}

	/*
	 * Destructor
	 */
	stack<T, Container>::~stack(void)
	{
	}

	/*
	 * Copy assignment operator
	 * Replaces the contents with a copy of the contents of other.
	 * Calls the assignment operator of the underlying container object.
	 */
	template<typename T, typename Container = vector<T> >
	stack&
	stack<T, Container>::operator=(const stack& other)
	{
		// avoid self-assignment
		if (this != &rhs)
			c = other.c;

		return (*this);
	}

	/* capacity ************************************************************* */

	/*
	 * Test whether container is empty.
	 * Calls the member function empty of the underlying container object.
	 */
	template<typename T, typename Container = vector<T> >
	bool
	stack<T, Container>::empty(void) const
	{
		return (c.empty());
	}

	/*
	 * Returns the number of elements in the stack.
	 * Calls the member function size of the underlying container object.
	 */
	template<typename T, typename Container = vector<T> >
	size_type
	stack<T, Container>::size(void) const
	{
		return (c.size());
	}


	/* modifiers ************************************************************ */

	/*
	 * Inserts a new element at the top of the stack, above its current top element.
	 * Calls the member function push_back of the underlying container object.
	 */
	template<typename T, typename Container = vector<T> >
	void
	stack<T, Container>::push(const value_type& val)
	{
		c.push_back(val);
	}

	/*
	 * Remove top element.
	 * Calls the member function pop_back of the underlying container object.
	 */
	template<typename T, typename Container = vector<T> >
	void
	stack<T, Container>::pop(void)
	{
		c.pop_back();
	}


	/* non-member function overloads **************************************** */

	/*
	 * Relational operators
	 * Make comparison between two stacks
	 */

	template<typename T, typename Container = vector<T> >
	bool
	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}

	template<typename T, typename Container = vector<T> >
	bool
	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return ( !(lhs == rhs) );
	}

	template<typename T, typename Container = vector<T> >
	bool
	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template<typename T, typename Container = vector<T> >
	bool
	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return (lhs.c > rhs.c);
	}

	template<typename T, typename Container = vector<T> >
	bool
	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return ( !(lhs > rhs) );
	}

	template<typename T, typename Container = vector<T> >
	bool
	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return ( !(lhs < rhs) );
	}
} // namespace ft

#endif
