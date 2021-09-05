/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:25:08 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/05 16:49:29 by mboivin          ###   ########.fr       */
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
	class Vector {

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

	};

}

#endif
