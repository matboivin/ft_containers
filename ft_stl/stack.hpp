/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:28:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/16 18:28:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <memory>
#include "algorithm.hpp"
#include "vector.hpp"

namespace ft
{
	/*
	 * Stack template class
	 * Encapsulates another container and provides a LIFO way to access to its elements
	 */
	template<typename T, typename Container = ft::vector<T> >
		class stack
		{
		public:
			//types
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;

		protected:
			// attributes
			Container	c; // the underlying container object

		public:
			// constructor
			explicit stack(const container_type& ctnr = container_type())
			: c(ctnr)
			{
			}

			// copy constructor
			stack(const stack& other)
			: c(other.c)
			{
			}

			// destructor
			~stack(void) {}

			// copy assignment operator
			stack&	operator=(const stack& other)
			{
				if (this != &other)
					c = other.c;

				return (*this);
			}

			// capacity
			bool		empty(void) const { return (c.empty()); }
			size_type	size(void) const  { return (c.size()); }

			// element access
			// returns the last element (top of the stack)
			value_type&			top(void)       { return (c.back()); }
			const value_type&	top(void) const { return (c.back()); }

			// modifiers
			// push an element on the stop of the stack
			void	push(const value_type& val) { c.push_back(val); }
			// removes the last element added
			void	pop(void) { c.pop_back(); }

			// friend relational operators
			template<typename _T, typename _Container>
				friend bool	operator==(const stack<_T, _Container>& lhs,
									   const stack<_T, _Container>& rhs);

			template<typename _T, typename _Container>
				friend bool	operator<(const stack<_T, _Container>& lhs,
									  const stack<_T, _Container>& rhs);
		}; // class stack

	/*
	 * Relational operators
	 * Make comparison between two stacks
	 */

	template<typename T, typename Container>
		bool
		operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (lhs.c == rhs.c);
		}

	template<typename T, typename Container>
		bool
		operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return ( !(lhs == rhs) );
		}

	template<typename T, typename Container>
		bool
		operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (lhs.c < rhs.c);
		}

	template<typename T, typename Container>
		bool
		operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (rhs < lhs);
		}

	template<typename T, typename Container>
		bool
		operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return ( !(lhs > rhs) );
		}

	template<typename T, typename Container>
		bool
		operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return ( !(lhs < rhs) );
		}
} // namespace ft

#endif
