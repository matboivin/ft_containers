/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:24:54 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/16 20:54:33 by mboivin          ###   ########.fr       */
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
	 * Store elements as key,value pairs. Each key is unique.
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
			typedef ft::RBtree_iterator<pointer>							iterator;
			typedef ft::RBtree_const_iterator<pointer>						const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef std::size_t												size_type;

			// function object to compare the keys of the stored elements
			class value_compare
			{
				friend class map;
			protected:
				// attributes
				Compare	comp; // A binary predicate
				value_compare(Compare c) : comp(c) {} // constructed with map's comparison object
			public:
				bool	operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
			};

		private:
			typedef typename Allocator::value_type											_alloc_value_type;
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
			bool		empty(void) const;
			size_type	size(void) const;
			size_type	max_size(void) const;

			// element access
			//mapped_type&	operator[](const key_type& k);

			// modifiers
			pair<iterator,bool>	insert(const value_type& val);
			iterator			insert(iterator position, const value_type& val);
			template <class InputIterator>
				void			insert(InputIterator first, InputIterator last);
			// void				erase(iterator position);
			// size_type			erase(const key_type& k);
			// void				erase(iterator first, iterator last);
			void				swap(map& x);
			void				clear(void);

			// lookup

			// observers
			key_compare		key_comp(void) const;
			value_compare	value_comp(void) const;
		}; // class map

	/* Map implementation *************************************************** */

	/* construct/copy/destroy *********************************************** */

	// default constructor
	template<typename Key, typename T, typename Compare, typename Allocator>
		map<Key,T,Compare,Allocator>::map(const key_compare& comp, const allocator_type& alloc)
		: _M_tree(comp, alloc)
		{
		}

	// range constructor
	template<typename Key, typename T, typename Compare, typename Allocator>
	template <typename InputIterator>
		map<Key,T,Compare,Allocator>::map(InputIterator first, InputIterator last,
										  const key_compare& comp, const allocator_type& alloc)
		: _M_tree(comp, alloc)
		{
			this->_M_tree.insert(first, last);
		}

	// copy constructor
	template<typename Key, typename T, typename Compare, typename Allocator>
		map<Key,T,Compare,Allocator>::map(const map& other)
		: _M_tree(other._M_tree)
		{
		}

	// destructor
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
				this->_M_tree = other._M_tree;
			return (*this);
		}

	/* iterators ************************************************************ */

	// Returns an iterator pointing to the first element in the map
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::iterator
		map<Key,T,Compare,Allocator>::begin(void)
		{
			return (this->_M_tree.begin());
		}

	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::const_iterator
		map<Key,T,Compare,Allocator>::begin(void) const
		{
			return (this->_M_tree.begin());
		}

	// Returns an iterator representing the past-the-end element in the tree
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::iterator
		map<Key,T,Compare,Allocator>::end(void)
		{
			return (this->_M_tree.end());
		}

	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::const_iterator
		map<Key,T,Compare,Allocator>::end(void) const
		{
			return (this->_M_tree.end());
		}

	// Returns a reverse iterator pointing to the last element in the map

	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::reverse_iterator
		map<Key,T,Compare,Allocator>::rbegin(void)
		{
			return (this->_M_tree.rbegin());
		}

	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::const_reverse_iterator
		map<Key,T,Compare,Allocator>::rbegin(void) const
		{
			return (this->_M_tree.rbegin());
		}

	/*
	 * Returns a reverse iterator pointing to the theoretical element preceding
	 * the first element in the map
	 */
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::reverse_iterator
		map<Key,T,Compare,Allocator>::rend(void)
		{
			return (this->_M_tree.rend());
		}

	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::const_reverse_iterator
		map<Key,T,Compare,Allocator>::rend(void) const
		{
			return (this->_M_tree.rend());
		}

	/* capacity ************************************************************* */

	// Returns true if the map is empty, false otherwise
	template<typename Key, typename T, typename Compare, typename Allocator>
		bool
		map<Key,T,Compare,Allocator>::empty(void) const
		{
			return (this->_M_tree.empty());
		}

	// Returns the number of elements in the map
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::size_type
		map<Key,T,Compare,Allocator>::size(void) const
		{
			return (this->_M_tree.size());
		}

	/*
	 * Gets the maximum number of elements that the map can hold.
	 *
	 * This is the maximum potential size the container can reach due to known system
	 * or library implementation limitations.
	 */
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::size_type
		map<Key,T,Compare,Allocator>::max_size(void) const
		{
			return (this->_M_tree.max_size());
		}

	/* element access ******************************************************* */

	// template<typename Key, typename T, typename Compare, typename Allocator>
	// 	typename map<Key,T,Compare,Allocator>::imapped_type&
	// 	map<Key,T,Compare,Allocator>::operator[](const key_type& k)
	// 	{
	// 	}

	/* modifiers ************************************************************ */

	// Inserts a new element
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename ft::pair<typename map<Key,T,Compare,Allocator>::iterator,bool>
		map<Key,T,Compare,Allocator>::insert(const value_type& val)
		{
			return (this->_M_tree.insert(val));
		}

	// Inserts a new element with a hint for the position
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::iterator
		map<Key,T,Compare,Allocator>::insert(iterator position, const value_type& val)
		{
			return (this->_M_tree.insert(position, val));
		}

	// Inserts a range of new elements
	template<typename Key, typename T, typename Compare, typename Allocator>
	template <class InputIterator>
		void
		map<Key,T,Compare,Allocator>::insert(InputIterator first, InputIterator last)
		{
			return (this->_M_tree.insert(first, last));
		}

	// Exchanges the content of the map and the other map
	template<typename Key, typename T, typename Compare, typename Allocator>
		void
		map<Key,T,Compare,Allocator>::swap(map& x)
		{
			return (this->_M_tree.swap(x._M_tree));
		}

	// Destroys all elements from the container, leaving it with a size of 0
	template<typename Key, typename T, typename Compare, typename Allocator>
		void
		map<Key,T,Compare,Allocator>::clear(void)
		{
			return (this->_M_tree.clear());
		}

	/* lookup *************************************************************** */

	/* observers ************************************************************ */

	// Returns a copy of the function used to compare the keys of elements
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::key_compare
		map<Key,T,Compare,Allocator>::key_comp(void) const
		{
			return (this->_M_tree.key_comp());
		}

	// Returns a new function object to compare the keys of elements
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::value_compare
		map<Key,T,Compare,Allocator>::value_comp(void) const
		{
			return (value_compare(this->_M_tree.key_comp()));
		}

} // namespace ft

#endif
