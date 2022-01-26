/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:24:54 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/26 21:20:18 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include "tree.hpp"

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
			 typename Alloc = std::allocator<ft::pair<const Key, T> >
			 >
		class map
		{
		public:
			// types
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const Key,T>						value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
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
				bool	operator()(const value_type& x, const value_type& y) const
				{ return comp(x.first, y.first); }
			};

		private:
			// alias for the tree
			typedef RedBlackTree<key_type, value_type, get_key_from_pair<key_type, value_type>, key_compare, allocator_type>	_tree_type;

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
			template<typename InputIterator>
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
			template<class InputIterator>
				void			insert(InputIterator first, InputIterator last, typename enable_if<
									is_same<typename InputIterator::value_type,
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

			// friend relational operators
			template<typename _Key, typename _T, typename _Compare, typename _Alloc>
				friend bool	operator==(const map<_Key,_T,_Compare,_Alloc>& x,
									   const map<_Key,_T,_Compare,_Alloc>& y);

			template<typename _Key, typename _T, typename _Compare, typename _Alloc>
				friend bool	operator<(const map<_Key,_T,_Compare,_Alloc>& x,
									  const map<_Key,_T,_Compare,_Alloc>& y);
		}; // class map

	/* Map implementation *************************************************** */

	/* construct/copy/destroy *********************************************** */

	/* default constructor */
	template<typename Key, typename T, typename Compare, typename Alloc>
		map<Key,T,Compare,Alloc>::map(const key_compare& comp, const allocator_type& alloc)
		: _M_tree(comp, alloc) { }

	/* range constructor */
	template<typename Key, typename T, typename Compare, typename Alloc>
	template<typename InputIterator>
		map<Key,T,Compare,Alloc>::map(
			InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc)
		: _M_tree(comp, alloc)
		{
			this->_M_tree.insert(first, last);
		}

	/* copy constructor */
	template<typename Key, typename T, typename Compare, typename Alloc>
		map<Key,T,Compare,Alloc>::map(const map& other)
		: _M_tree(other._M_tree) { }

	/* destructor */
	template<typename Key, typename T, typename Compare, typename Alloc>
		map<Key,T,Compare,Alloc>::~map(void) { }

	/* copy assignment operator */
	template<typename Key, typename T, typename Compare, typename Alloc>
		map<Key,T,Compare,Alloc>&
		map<Key,T,Compare,Alloc>::operator=(const map& other)
		{
			if (this != &other)
				this->_M_tree = other._M_tree;
			return (*this);
		}

	/* iterators ************************************************************ */

	/* Returns an iterator pointing to the first element in the map */
	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::iterator
		map<Key,T,Compare,Alloc>::begin(void)
		{ return (this->_M_tree.begin()); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::const_iterator
		map<Key,T,Compare,Alloc>::begin(void) const
		{ return (this->_M_tree.begin()); }

	/* Returns an iterator representing the past-the-end element in the tree */
	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::iterator
		map<Key,T,Compare,Alloc>::end(void)
		{ return (this->_M_tree.end()); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::const_iterator
		map<Key,T,Compare,Alloc>::end(void) const
		{ return (this->_M_tree.end()); }

	/* Returns a reverse iterator pointing to the last element in the map */
	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::reverse_iterator
		map<Key,T,Compare,Alloc>::rbegin(void)
		{ return (this->_M_tree.rbegin()); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::const_reverse_iterator
		map<Key,T,Compare,Alloc>::rbegin(void) const
		{ return (this->_M_tree.rbegin()); }

	/*
	 * Returns a reverse iterator pointing to the theoretical element preceding
	 * the first element in the map
	 */
	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::reverse_iterator
		map<Key,T,Compare,Alloc>::rend(void)
		{ return (this->_M_tree.rend()); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::const_reverse_iterator
		map<Key,T,Compare,Alloc>::rend(void) const
		{ return (this->_M_tree.rend()); }

	/* capacity ************************************************************* */

	template<typename Key, typename T, typename Compare, typename Alloc>
		bool
		map<Key,T,Compare,Alloc>::empty(void) const
		{ return (this->_M_tree.empty()); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::size_type
		map<Key,T,Compare,Alloc>::size(void) const
		{ return (this->_M_tree.size()); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::size_type
		map<Key,T,Compare,Alloc>::max_size(void) const
		{ return (this->_M_tree.max_size()); }

	/* element access ******************************************************* */

	/* Inserts a new element. If the key already exists, returns a reference to the stored element. */
	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::mapped_type&
		map<Key,T,Compare,Alloc>::operator[](const key_type& k)
		{
			iterator	it = lower_bound(k);

			if ((it == end()) || key_comp()(k, (*it).first))
				it = insert(it, value_type(k, mapped_type()));
			return ((*it).second);
		}

	/* modifiers ************************************************************ */

	/* Insert */
	template<typename Key, typename T, typename Compare, typename Alloc>
		pair<typename map<Key,T,Compare,Alloc>::iterator,bool>
		map<Key,T,Compare,Alloc>::insert(const value_type& val)
		{ return (this->_M_tree.insert(val)); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::iterator
		map<Key,T,Compare,Alloc>::insert(iterator position, const value_type& val)
		{ return (this->_M_tree.insert(position, val)); }

	template<typename Key, typename T, typename Compare, typename Alloc>
	template<class InputIterator>
		void
		map<Key,T,Compare,Alloc>::insert(
			InputIterator first, InputIterator last,
			typename enable_if<is_same<typename InputIterator::value_type, value_type>::value>::type*)
		{ return (this->_M_tree.insert(first, last)); }

	/* Erase */
	template<typename Key, typename T, typename Compare, typename Alloc>
		void
		map<Key,T,Compare,Alloc>::erase(iterator position)
		{
			this->_M_tree.erase(position);
		}

	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::size_type
		map<Key,T,Compare,Alloc>::erase(const key_type& k)
		{ return (this->_M_tree.erase(k)); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		void
		map<Key,T,Compare,Alloc>::erase(iterator first, iterator last)
		{
			this->_M_tree.erase(first, last);
		}

	/* Exchanges the content of the map and the other map */
	template<typename Key, typename T, typename Compare, typename Alloc>
		void
		map<Key,T,Compare,Alloc>::swap(map& x)
		{ return (this->_M_tree.swap(x._M_tree)); }

	/* Destroys all elements from the container, leaving it with a size of 0 */
	template<typename Key, typename T, typename Compare, typename Alloc>
		void
		map<Key,T,Compare,Alloc>::clear(void)
		{ return (this->_M_tree.clear()); }

	/* lookup *************************************************************** */

	/* Gets the element with the key k, else return end */
	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::iterator
		map<Key,T,Compare,Alloc>::find(const key_type& k)
		{ return (this->_M_tree.find(k)); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::const_iterator
		map<Key,T,Compare,Alloc>::find(const key_type& k) const
		{ return (this->_M_tree.find(k)); }

	/*
	 * Returns the number of elements matching key k
	 * Since every key in the map is unique, it will return one if found. Otherwise, zero.
	 */
	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::size_type
		map<Key,T,Compare,Alloc>::count(const key_type& k) const
		{ return (this->_M_tree.find(k) != this->_M_tree.end()); }

	/*
	 * Gets the first element that is equivalent or after k
	 * i.e. The first element for which key_comp(element_key,k) would return false
	 */
	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::iterator
		map<Key,T,Compare,Alloc>::lower_bound(const key_type& k)
		{ return (this->_M_tree.lower_bound(k)); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::const_iterator
		map<Key,T,Compare,Alloc>::lower_bound(const key_type& k) const
		{ return (this->_M_tree.lower_bound(k)); }

	/*
	 * Gets the first element that is after k
	 * i.e. The first element for which key_comp(k,element_key) would return true
	 */
	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::iterator
		map<Key,T,Compare,Alloc>::upper_bound(const key_type& k)
		{ return (this->_M_tree.upper_bound(k)); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::const_iterator
		map<Key,T,Compare,Alloc>::upper_bound(const key_type& k) const
		{ return (this->_M_tree.upper_bound(k)); }

	/*
	 * Returns the bounds of a range that have a key equivalent to k.
	 * Since every key in the map is unique, it will return a range of one element.
	 * If k is not found, returns two iterators pointing to the first element after k.
	 */
	template<typename Key, typename T, typename Compare, typename Alloc>
		pair<typename map<Key,T,Compare,Alloc>::iterator,typename map<Key,T,Compare,Alloc>::iterator>
		map<Key,T,Compare,Alloc>::equal_range(const key_type& k)
		{ return (this->_M_tree.equal_range(k)); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		pair<typename map<Key,T,Compare,Alloc>::const_iterator,typename map<Key,T,Compare,Alloc>::const_iterator>
		map<Key,T,Compare,Alloc>::equal_range(const key_type& k) const
		{ return (this->_M_tree.equal_range(k)); }

	/* observers ************************************************************ */

	/* Returns a copy of the function used to compare the keys of elements */
	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::key_compare
		map<Key,T,Compare,Alloc>::key_comp(void) const
		{ return (this->_M_tree.key_comp()); }

	/* Returns a new function object to compare the keys of elements */
	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::value_compare
		map<Key,T,Compare,Alloc>::value_comp(void) const
		{ return (value_compare(this->_M_tree.key_comp())); }

	/* allocator ************************************************************ */

	template<typename Key, typename T, typename Compare, typename Alloc>
		typename map<Key,T,Compare,Alloc>::allocator_type
		map<Key,T,Compare,Alloc>::get_allocator(void) const
		{ return (this->_M_tree.get_allocator()); }

	/* debug **************************************************************** */

	template<typename Key, typename T, typename Compare, typename Alloc>
		void
		map<Key,T,Compare,Alloc>::write_tree_dot(const std::string& filename)
		{
			this->_M_tree.write_tree_dot(filename);
		}

	/* non-member function overloads **************************************** */

	/* Relational operators: make comparison between two maps */

	template<typename Key, typename T, typename Compare, typename Alloc>
		bool
		operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
		{ return (lhs._M_tree == rhs._M_tree); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		bool
		operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
		{ return (!(lhs == rhs)); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		bool
		operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
		{ return (lhs._M_tree < rhs._M_tree); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		bool
		operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
		{ return (rhs < lhs); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		bool
		operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
		{ return (!(rhs < lhs)); }

	template<typename Key, typename T, typename Compare, typename Alloc>
		bool
		operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
		{ return (!(lhs < rhs)); }

	/* Exchange contents of two maps */
	template<typename Key, typename T, typename Compare, typename Alloc>
		void
		swap(map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
		{
			x.swap(y);
		}

} // namespace ft

#endif
