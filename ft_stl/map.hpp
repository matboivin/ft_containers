/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:24:54 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/15 18:22:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include "algorithm.hpp"
#include "tree.hpp"
#include "utility.hpp"

namespace ft
{
	/* Map definition ******************************************************* */

	/*
	 * Map template class
	 * Store elements as key,value pairs.
	 */
	template<typename Key,
			 typename T,
			 typename Compare = std::less<Key>,
			 typename Allocator = std::allocator<ft::pair<const Key, T> >
			 >
	class map
	{
	public:
		// types
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef ft::pair<const Key, T>									value_type;
		typedef Compare													key_compare;
		typedef Allocator												allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef ft::base_iterator<pointer, map>							iterator;
		typedef ft::base_iterator<const_pointer,map>					const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef std::size_t												size_type;

	private:
		typedef typename Allocator::value_type							_alloc_value_type;

		class value_compare
		{
			friend class map;

		protected:
			// attributes
			Compare	comp; // A binary predicate
			value_compare(Compare c) : comp(c) {}
		public:
			bool	operator()(const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};

	private:
		typedef typename allocator_type::template rebind<value_type>::other				_pair_alloc_type;
		typedef ft::RedBlackTree<key_type, value_type, key_compare, _pair_alloc_type>	_repr_type;

		_repr_type	_M_tree;

	public:
		// default constructor
		explicit map(const key_compare& comp = key_compare(),
					 const allocator_type& alloc = allocator_type()
					 );

		// range constructor
		template <typename InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()
				);

		// copy constructor
		map(const map& other);

		// destructor
		~map(void);

		// copy assignment operator
		map&	operator=(const map& other);
	};

	/* Map implementation *************************************************** */

	/* construct/copy/destroy *********************************************** */

	// default constructor
	template<typename Key, typename T, typename Compare, typename Allocator>
	map<Key,T,Compare,Allocator>::map(const key_compare& comp, const allocator_type& alloc)
	: _M_tree()
	{
	}

	// range constructor
	template<typename Key, typename T, typename Compare, typename Allocator>
	template <typename InputIterator>
	map<Key,T,Compare,Allocator>::map(InputIterator first, InputIterator last,
									  const key_compare& comp, const allocator_type& alloc
									  )
	: _M_tree()
	{
	}

	// copy constructor
	template<typename Key, typename T, typename Compare, typename Allocator>
	map<Key,T,Compare,Allocator>::map(const map& other)
	: _M_tree(other._M_tree)
	{
	}

	/* Destructor */
	template<typename Key, typename T, typename Compare, typename Allocator>
	map<Key,T,Compare,Allocator>::~map(void)
	{
	}

	// copy assignment operator
	template<typename Key, typename T, typename Compare, typename Allocator>
	map<Key,T,Compare,Allocator>&
	map<Key,T,Compare,Allocator>::operator=(const map& other)
	{
		if (this != &other)
			//

		return (*this);
	}
} // namespace ft

#endif
