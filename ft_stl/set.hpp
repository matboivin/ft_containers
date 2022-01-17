/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:18:28 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/17 17:57:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <memory>
#include "algorithm.hpp"
#include "tree.hpp"
#include "utility.hpp"

namespace ft
{
	/* Set definition ******************************************************* */

	/*
	 * Set template class
	 * Store elements of key type which is unique.
	 */
	template<typename Key,
			 typename Compare = std::less<Key>,
			 typename Alloc = std::allocator<Key>
			>
		class set
		{
		public:
			// types
			typedef Key											key_type;
			typedef Key											value_type;
			typedef Compare										key_compare;
			typedef Compare										value_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef std::size_t									size_type;

		private:
			// alias for the tree
			typedef ft::RedBlackTree<key_type, value_type, key_compare, allocator_type>	_repr_type;

			// attribute
			_repr_type	_M_tree;

		public:
			// types
			typedef typename _repr_type::iterator				iterator;
			typedef typename _repr_type::const_iterator			const_iterator;
			typedef typename _repr_type::reverse_iterator		reverse_iterator;
			typedef typename _repr_type::const_reverse_iterator	const_reverse_iterator;
			typedef typename _repr_type::difference_type		difference_type;

			// default constructor
			explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			// range constructor
			template <class InputIterator>
				set(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type());

			// copy constructor
			set(const set& other);

			// destructor
			~set(void);

		}; // class set

	/* Set implementation *************************************************** */

	/* construct/copy/destroy *********************************************** */

	// default constructor
	template<typename Key, typename Compare, typename Alloc>
		set<Key,Compare,Alloc>::set(const key_compare& comp, const allocator_type& alloc)
		: _M_tree(comp, alloc)
		{
		}

	// range constructor
	template<typename Key, typename Compare, typename Alloc>
	template <class InputIterator>
		set<Key,Compare,Alloc>::set(InputIterator first, InputIterator last,
									const key_compare& comp, const allocator_type& alloc)
		: _M_tree(comp, alloc)
		{
			this->_M_tree.insert(first, last);
		}

	// copy constructor
	template<typename Key, typename Compare, typename Alloc>
		set<Key,Compare,Alloc>::set(const set& other)
		: _M_tree(other._M_tree)
		{
		}

	// destructor
	template<typename Key, typename Compare, typename Alloc>
		set<Key,Compare,Alloc>::~set(void)
		{
		}


} // namespace ft

#endif
