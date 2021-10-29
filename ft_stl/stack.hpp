/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:28:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/29 18:40:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

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
	 * Stack template class
	 * Encapsulates another container and provides a LIFO way to access to its 
	 * elements
	 *
	 * @param T          Type of the elements
	 * @param Container  Type of the internal underlying container object where 
	 *                   the elements are stored.
	 */
	template<typename T, typename Container = vector<T> >
	class stack
	{
	public:
		//types
		typedef typename Container::value_type		value_type;
		// typedef typename Container::reference		reference;
		// typedef typename Container::const_reference	const_reference;
		typedef typename Container::size_type		size_type;
		typedef Container							container_type;

	protected:
		// attributes
		Container	c; // the underlying container object

	public:
		// constructor
		stack(const container_type& ctnr = container_type());
	};

	/* non-member function overloads **************************************** */


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

} // namespace ft

#endif
