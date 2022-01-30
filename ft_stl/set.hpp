/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:18:28 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/30 19:15:52 by mboivin          ###   ########.fr       */
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
			// alias
			typedef RedBlackTree<key_type, value_type, get_key<key_type>, key_compare, allocator_type>	_tree_type;

			// attribute
			_tree_type	_M_tree;

		public:
			// types
			typedef typename _tree_type::const_iterator			iterator;
			typedef typename _tree_type::const_iterator			const_iterator;
			typedef typename _tree_type::const_reverse_iterator	reverse_iterator;
			typedef typename _tree_type::const_reverse_iterator	const_reverse_iterator;
			typedef typename _tree_type::difference_type		difference_type;

			// default constructor
			explicit set(const key_compare& comp = key_compare(),
						 const allocator_type& alloc = allocator_type());

			// range constructor
			template <class InputIterator>
				set(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type());

			// copy constructor
			set(const set& other);

			// destructor
			~set(void);

			// copy assignment operator
			set&	operator=(const set& other);

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
			bool					empty(void) const;
			size_type				size(void) const;
			size_type				max_size(void) const;

			// modifiers
			pair<iterator,bool>		insert(const value_type& val);
			iterator				insert(iterator position, const value_type& val);
			template <class InputIterator>
				void				insert(InputIterator first, InputIterator last, typename enable_if<
											is_same<typename InputIterator::value_type,
											value_type>::value>::type* = 0);
			void					erase(iterator position);
			size_type				erase(const key_type& k);
			void					erase(iterator first, iterator last);
			void					swap(set& x);
			void					clear(void);

			// lookup
			iterator				find(const key_type& k) const;
			size_type				count(const key_type& k) const;
			iterator				lower_bound(const key_type& k) const;
			iterator				upper_bound(const key_type& k) const;
			pair<iterator,iterator>	equal_range(const key_type& k) const;

			// observers
			key_compare				key_comp(void) const;
			value_compare			value_comp(void) const;

			// allocator
			allocator_type			get_allocator(void) const;

			// friend relational operators
			template<typename _Key, typename _Compare, typename _Alloc>
				friend bool	operator==(const set<_Key,_Compare,_Alloc>& x,
									   const set<_Key,_Compare,_Alloc>& y);

			template<typename _Key, typename _Compare, typename _Alloc>
				friend bool	operator<(const set<_Key,_Compare,_Alloc>& x,
									  const set<_Key,_Compare,_Alloc>& y);
		}; // class set

	/* Set implementation *************************************************** */

	/* construct/copy/destroy *********************************************** */

	// default constructor
	template<typename Key, typename Compare, typename Alloc>
		set<Key,Compare,Alloc>::set(const key_compare& comp, const allocator_type& alloc)
		: _M_tree(comp, alloc) { }

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
		: _M_tree(other._M_tree) { }

	// destructor
	template<typename Key, typename Compare, typename Alloc>
		set<Key,Compare,Alloc>::~set(void) { }

	// copy assignment operator
	template<typename Key, typename Compare, typename Alloc>
		set<Key,Compare,Alloc>&
		set<Key,Compare,Alloc>::operator=(const set& other)
		{
			if (this != &other)
				this->_M_tree = other._M_tree;
			return (*this);
		}

	/* iterators ************************************************************ */

	/* Returns an iterator pointing to the first element in the set */
	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::iterator
		set<Key,Compare,Alloc>::begin(void)
		{ return (this->_M_tree.begin()); }

	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::const_iterator
		set<Key,Compare,Alloc>::begin(void) const
		{ return (this->_M_tree.begin()); }

	/* Returns an iterator representing the past-the-end element in the tree */
	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::iterator
		set<Key,Compare,Alloc>::end(void)
		{ return (this->_M_tree.end()); }

	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::const_iterator
		set<Key,Compare,Alloc>::end(void) const
		{ return (this->_M_tree.end()); }

	/* Returns a reverse iterator pointing to the last element in the set */
	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::reverse_iterator
		set<Key,Compare,Alloc>::rbegin(void)
		{ return (this->_M_tree.rbegin()); }

	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::const_reverse_iterator
		set<Key,Compare,Alloc>::rbegin(void) const
		{ return (this->_M_tree.rbegin()); }

	/*
	 * Returns a reverse iterator pointing to the theoretical element preceding
	 * the first element in the set
	 */
	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::reverse_iterator
		set<Key,Compare,Alloc>::rend(void)
		{ return (this->_M_tree.rend()); }

	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::const_reverse_iterator
		set<Key,Compare,Alloc>::rend(void) const
		{ return (this->_M_tree.rend()); }

	/* capacity ************************************************************* */

	template<typename Key, typename Compare, typename Alloc>
		bool
		set<Key,Compare,Alloc>::empty(void) const
		{ return (this->_M_tree.empty()); }

	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::size_type
		set<Key,Compare,Alloc>::size(void) const
		{ return (this->_M_tree.size()); }

	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::size_type
		set<Key,Compare,Alloc>::max_size(void) const
		{ return (this->_M_tree.max_size()); }

	/* modifiers ************************************************************ */

	/* Insert */
	template<typename Key, typename Compare, typename Alloc>
		pair<typename set<Key,Compare,Alloc>::iterator,bool>
		set<Key,Compare,Alloc>::insert(const value_type& val)
		{ return (this->_M_tree.insert(val)); }

	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::iterator
		set<Key,Compare,Alloc>::insert(iterator position, const value_type& val)
		{ return (this->_M_tree.insert(position.remove_const(), val)); }

	template<typename Key, typename Compare, typename Alloc>
	template <class InputIterator>
		void
		set<Key,Compare,Alloc>::insert(
			InputIterator first, InputIterator last,
			typename enable_if<is_same<typename InputIterator::value_type, value_type>::value>::type*)
		{ return (this->_M_tree.insert(first, last)); }

	/* Erase */
	template<typename Key, typename Compare, typename Alloc>
		void
		set<Key,Compare,Alloc>::erase(iterator position)
		{
			this->_M_tree.erase(position.remove_const());
		}

	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::size_type
		set<Key,Compare,Alloc>::erase(const key_type& k)
		{ return (this->_M_tree.erase(k)); }

	template<typename Key, typename Compare, typename Alloc>
		void
		set<Key,Compare,Alloc>::erase(iterator first, iterator last)
		{ return (this->_M_tree.erase(first.remove_const(), last.remove_const())); }

	/* Exchanges the content of the set and the other set */
	template<typename Key, typename Compare, typename Alloc>
		void
		set<Key,Compare,Alloc>::swap(set& x)
		{ return (this->_M_tree.swap(x._M_tree)); }

	/* Destroys all elements from the container, leaving it with a size of 0 */
	template<typename Key, typename Compare, typename Alloc>
		void
		set<Key,Compare,Alloc>::clear(void)
		{ return (this->_M_tree.clear()); }

	/* lookup *************************************************************** */

	/* Gets the element with the key k, else return end */
	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::iterator
		set<Key,Compare,Alloc>::find(const key_type& k) const
		{ return ((this->_M_tree.find(k)).remove_const()); }

	/*
	 * Returns the number of elements matching key k
	 * Since every key in the set is unique, it will return one if found. Otherwise, zero.
	 */
	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::size_type
		set<Key,Compare,Alloc>::count(const key_type& k) const
		{ return (this->_M_tree.find(k) != this->_M_tree.end()); }

	/*
	 * Gets the first element that is equivalent or after k
	 * i.e. The first element for which key_comp(element_key,k) would return false
	 */
	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::iterator
		set<Key,Compare,Alloc>::lower_bound(const key_type& k) const
		{ return ((this->_M_tree.lower_bound(k)).remove_const()); }

	/*
	 * Gets the first element that is after k
	 * i.e. The first element for which key_comp(k,element_key) would return true
	 */
	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::iterator
		set<Key,Compare,Alloc>::upper_bound(const key_type& k) const
		{ return ((this->_M_tree.upper_bound(k)).remove_const()); }

	/*
	 * Returns the bounds of a range that have a key equivalent to k.
	 * Since every key in the set is unique, it will return a range of one element.
	 * If k is not found, returns two iterators pointing to the first element after k.
	 */
	template<typename Key, typename Compare, typename Alloc>
		pair<typename set<Key,Compare,Alloc>::iterator, typename set<Key,Compare,Alloc>::iterator>
		set<Key,Compare,Alloc>::equal_range(const key_type& k) const
		{
			pair<const_iterator,const_iterator>	range = this->_M_tree.equal_range(k);

			return (pair<iterator,iterator>(range.first.remove_const(), range.second.remove_const()));
		}

	/* observers ************************************************************ */

	/* Returns a copy of the function used to compare the keys of elements */
	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::key_compare
		set<Key,Compare,Alloc>::key_comp(void) const
		{ return (this->_M_tree.key_comp()); }

	/* Returns a new function object to compare the keys of elements */
	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::value_compare
		set<Key,Compare,Alloc>::value_comp(void) const
		{ return (value_compare(this->_M_tree.key_comp())); }

	/* allocator ************************************************************ */

	template<typename Key, typename Compare, typename Alloc>
		typename set<Key,Compare,Alloc>::allocator_type
		set<Key,Compare,Alloc>::get_allocator(void) const
		{ return (this->_M_tree.get_allocator()); }

	/* non-member function overloads **************************************** */

	/* Relational operators: make comparison between two sets */

	template<typename Key, typename Compare, typename Alloc>
		bool
		operator==(const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs)
		{ return (lhs._M_tree == rhs._M_tree); }

	template<typename Key, typename Compare, typename Alloc>
		bool
		operator!=(const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs)
		{ return (!(lhs == rhs)); }

	template<typename Key, typename Compare, typename Alloc>
		bool
		operator<(const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs)
		{ return (lhs._M_tree < rhs._M_tree); }

	template<typename Key, typename Compare, typename Alloc>
		bool
		operator>(const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs)
		{ return (rhs < lhs); }

	template<typename Key, typename Compare, typename Alloc>
		bool
		operator<=(const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs)
		{ return (!(rhs < lhs)); }

	template<typename Key, typename Compare, typename Alloc>
		bool
		operator>=(const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs)
		{ return (!(lhs < rhs)); }

	/* Exchange contents of two sets */
	template<typename Key, typename Compare, typename Alloc>
		void
		swap(set<Key,Compare,Alloc>& x, set<Key,Compare,Alloc>& y)
		{
			x.swap(y);
		}

} // namespace ft

#endif
