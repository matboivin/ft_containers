/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:24:54 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/17 18:43:50 by mboivin          ###   ########.fr       */
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
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const Key, T>						value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef std::size_t									size_type;

			// function object to compare the keys of the stored elements
			class value_compare
			{
				friend class map;
			protected:
				Compare	comp; // A binary predicate
				value_compare(Compare c) : comp(c) {} // constructed with map's comparison object
			public:
				bool	operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
			};

		private:
			// alias for the tree
			typedef ft::RedBlackTree<key_type, value_type, key_compare, allocator_type>	_tree_type;

			// attribute
			_tree_type	_M_tree;

		public:
			// types
			typedef typename _tree_type::iterator				iterator;
			typedef typename _tree_type::const_iterator			const_iterator;
			typedef typename _tree_type::reverse_iterator		reverse_iterator;
			typedef typename _tree_type::const_reverse_iterator	const_reverse_iterator;
			typedef typename _tree_type::difference_type		difference_type;

			// default constructor
			explicit map(const key_compare& comp = key_compare(),
						 const allocator_type& alloc = allocator_type());

			// range constructor
			template <typename InputIterator>
				map(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type());

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
			bool				empty(void) const;
			size_type			size(void) const;
			size_type			max_size(void) const;

			// element access
			mapped_type&		operator[](const key_type& k);

			// modifiers
			pair<iterator,bool>	insert(const value_type& val);
			iterator			insert(iterator position, const value_type& val);
			template <class InputIterator>
				void			insert(InputIterator first, InputIterator last,
									   typename ft::enable_if<
									   		ft::is_same<typename InputIterator::value_type,
									   					value_type>::value>::type* = 0);
			void				erase(iterator position);
			size_type			erase(const key_type& k);
			void				erase(iterator first, iterator last);
			void				swap(map& x);
			void				clear(void);

			// lookup
			iterator			find(const key_type& k);
			const_iterator		find(const key_type& k) const;
			size_type			count(const key_type& k) const;
			iterator			lower_bound(const key_type& k);
			const_iterator		lower_bound(const key_type& k) const;
			iterator			upper_bound(const key_type& k);
			const_iterator		upper_bound(const key_type& k) const;
			pair<iterator,iterator>				equal_range(const key_type& k);
			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;

			// observers
			key_compare			key_comp(void) const;
			value_compare		value_comp(void) const;

			// allocator
			allocator_type		get_allocator(void) const;

			// debug
			void				write_tree_dot(const std::string& filename);
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

	/* Insert a new element. If the key already exists, returns a reference to the stored element. */
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::mapped_type&
		map<Key,T,Compare,Allocator>::operator[](const key_type& k)
		{
			iterator	it = this->_M_tree.lower_bound(k);

			if ((it == end()) || (it->first != k))
			{
				it = insert(it, value_type(k, mapped_type()));
			}
			return ((*it).second);
		}

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
		map<Key,T,Compare,Allocator>::insert(InputIterator first, InputIterator last,
											 typename ft::enable_if<ft::is_same<typename InputIterator::value_type,
											 value_type>::value>::type*)
		{
			return (this->_M_tree.insert(first, last));
		}

	// Erase the element pointed to by the given iterator
	template<typename Key, typename T, typename Compare, typename Allocator>
		void
		map<Key,T,Compare,Allocator>::erase(iterator position)
		{
			this->_M_tree.erase(position);
		}

	// Erase the element with the key k
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::size_type
		map<Key,T,Compare,Allocator>::erase(const key_type& k)
		{
			return (this->_M_tree.erase(k));
		}

	// Erase a range of elements
	template<typename Key, typename T, typename Compare, typename Allocator>
		void
		map<Key,T,Compare,Allocator>::erase(iterator first, iterator last)
		{
			return (this->_M_tree.erase(first, last));
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

	// Gets the element with the key k, else return end
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::iterator
		map<Key,T,Compare,Allocator>::find(const key_type& k)
		{
			return (this->_M_tree.find(k));
		}

	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::const_iterator
		map<Key,T,Compare,Allocator>::find(const key_type& k) const
		{
			return (this->_M_tree.find(k));
		}

	/*
	 * Returns the number of elements matching key k
	 * Since every key in the map is unique, it will return one if found. Otherwise, zero.
	 */
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::size_type
		map<Key,T,Compare,Allocator>::count(const key_type& k) const
		{
			return (this->_M_tree.find(k) != this->_M_tree.end());
		}

	/*
	 * Gets the first element that is equivalent or after k
	 * i.e. The first element for which key_comp(element_key,k) would return false
	 */
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::iterator
		map<Key,T,Compare,Allocator>::lower_bound(const key_type& k)
		{
			return (this->_M_tree.lower_bound(k));
		}

	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::const_iterator
		map<Key,T,Compare,Allocator>::lower_bound(const key_type& k) const
		{
			return (this->_M_tree.lower_bound(k));
		}

	/*
	 * Gets the first element that is after k
	 * i.e. The first element for which key_comp(k,element_key) would return true
	 */
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::iterator
		map<Key,T,Compare,Allocator>::upper_bound(const key_type& k)
		{
			return (this->_M_tree.upper_bound(k));
		}

	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::const_iterator
		map<Key,T,Compare,Allocator>::upper_bound(const key_type& k) const
		{
			return (this->_M_tree.upper_bound(k));
		}

	/*
	 * Returns the bounds of a range that have a key equivalent to k.
	 * Since every key in the map is unique, it will return a range of one element.
	 * If k is not found, returns two iterators pointing to the first element after k.
	 */
	template<typename Key, typename T, typename Compare, typename Allocator>
		ft::pair<typename map<Key,T,Compare,Allocator>::iterator,typename map<Key,T,Compare,Allocator>::iterator>
		map<Key,T,Compare,Allocator>::equal_range(const key_type& k)
		{
			return (this->_M_tree.equal_range(k));
		}

	template<typename Key, typename T, typename Compare, typename Allocator>
		ft::pair<typename map<Key,T,Compare,Allocator>::const_iterator,typename map<Key,T,Compare,Allocator>::const_iterator>
		map<Key,T,Compare,Allocator>::equal_range(const key_type& k) const
		{
			return (this->_M_tree.equal_range(k));
		}

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

	/* allocator ************************************************************ */

	// Returns a copy of the allocator
	template<typename Key, typename T, typename Compare, typename Allocator>
		typename map<Key,T,Compare,Allocator>::allocator_type
		map<Key,T,Compare,Allocator>::get_allocator(void) const
		{
			return (this->_M_tree.get_allocator());
		}

	/* debug **************************************************************** */

	template<typename Key, typename T, typename Compare, typename Allocator>
		void
		map<Key,T,Compare,Allocator>::write_tree_dot(const std::string& filename)
		{
			this->_M_tree.write_tree_dot(filename);
		}
} // namespace ft

#endif
