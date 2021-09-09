/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:34:57 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/09 18:52:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/*
 * Credits:
 * Detailed comments mostly from www.cplusplus.com
 */

namespace ft {

	/*
	 * Base class to ease the definition of required types for simple iterators
	 *
	 * This is a base class template that can be used to derive iterator classes
	 * from it. It is not an iterator class and does not provide any of the functionality
	 * an iterator is expected to have.
	 *
	 * @param T         Type of elements pointed by the iterator
	 * @param Distance  Type to represent the difference between two iterators
	 * @param Pointer   Type to represent a pointer to an element pointed by the iterator
	 * @param Reference Type to represent a reference to an element pointed by the iterator
	 */
	template< typename Category, typename T, typename Distance = std::ptrdiff_t,
			  typename Pointer = T*, typename Reference = T& >
	struct iterator {

		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};
}

#endif
