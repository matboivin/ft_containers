/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:53:39 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 23:53:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include <cstdlib> // system
#include <fstream> // debug
#include <iostream> // debug
#include <memory>
#include "algorithm.hpp"
#include "iterator.hpp"
#include "utility.hpp"

namespace ft
{
	enum NodeColor
	{
		RED = 0,
		BLACK = 1
	};

	/* Node definition and implementation *********************************** */

	/*
	 * Red Black Tree Node template class
	 */
	template<typename Val>
		struct RBTreeNode
		{
			// types
			typedef RBTreeNode<Val>*		node_pointer;
			typedef const RBTreeNode<Val>*	const_node_pointer;

			// attributes
			NodeColor		_M_color;
			node_pointer	_M_parent;
			node_pointer	_M_left;
			node_pointer	_M_right;
			Val				_M_value;
			int				_M_sentinel;

			// Retrieve the value address
			Val*
			_get_value_ptr(void)
			{ return (&this->_M_value); }

			const Val*
			_get_value_ptr(void) const
			{ return (&this->_M_value); }

			// Get node holding lower value
			static node_pointer
			_get_leftmost(node_pointer node)
			{
				if (node != 0)
				{
					while (node->_M_left != 0)
						node = node->_M_left;
				}
				return (node);
			}

			static const_node_pointer
			_get_leftmost(const_node_pointer node)
			{
				if (node != 0)
				{
					while (node->_M_left != 0)
						node = node->_M_left;
				}
				return (node);
			}

			// Get node holding greater value
			static node_pointer
			_get_rightmost(node_pointer node)
			{
				if (node != 0)
				{
					while (node->_M_right != 0)
						node = node->_M_right;
				}
				return (node);
			}

			static const_node_pointer
			_get_rightmost(const_node_pointer node)
			{
				if (node != 0)
				{
					while (node->_M_right != 0)
						node = node->_M_right;
				}
				return (node);
			}

			// Increment node
			static node_pointer
			_increment_node(node_pointer node)
			{
				if (node != 0)
				{
					if (node->_M_right != 0)
					{
						node = node->_M_right;
						while (node->_M_left != 0)
							node = node->_M_left;
					}
					else
					{
						node_pointer	__parent = node->_M_parent;

						while (node == __parent->_M_right)
						{
							node = __parent;
							if (node->_M_sentinel == 1)
								break ;
							__parent = __parent->_M_parent;
						}
						if (node != __parent)
							node = __parent;
					}
				}
				return (node);
			}

			static const_node_pointer
			_increment_node(const_node_pointer node)
			{
				if (node != 0)
				{
					if (node->_M_right != 0)
					{
						node = node->_M_right;
						while (node->_M_left != 0)
							node = node->_M_left;
					}
					else
					{
						node_pointer	__parent = node->_M_parent;

						while (node == __parent->_M_right)
						{
							node = __parent;
							if (node->_M_sentinel == 1)
								break ;
							__parent = __parent->_M_parent;
						}
						if (node != __parent)
							node = __parent;
					}
				}
				return (node);
			}

			// Decrement node
			static node_pointer
			_decrement_node(node_pointer node)
			{
				if (node != 0)
				{
					if (node->_M_sentinel == 1)
					{
						node = node->_M_right;
					}
					else if (node->_M_left != 0)
					{
						node = node->_M_left;
						while (node->_M_right != 0)
							node = node->_M_right;
					}
					else
					{
						node_pointer	__parent = node->_M_parent;

						while (node == __parent->_M_left)
						{
							node = __parent;
							__parent = __parent->_M_parent;
						}
						node = __parent;
					}
				}
				return (node);
			}

			static const_node_pointer
			_decrement_node(const_node_pointer node)
			{
				if (node != 0)
				{
					if (node->_M_sentinel == 1)
					{
						node = node->_M_right;
					}
					else if (node->_M_left != 0)
					{
						node = node->_M_left;
						while (node->_M_right != 0)
							node = node->_M_right;
					}
					else
					{
						const_node_pointer	__parent = node->_M_parent;

						while (node == __parent->_M_left)
						{
							node = __parent;
							__parent = __parent->_M_parent;
						}
						node = __parent;
					}
				}
				return (node);
			}
		}; // struct RBTreeNode


	/* Header definition and implementation ********************************* */

	/*
	 * Red Black Tree Header template class
	 */
	template<typename Val>
		struct RBTreeHeader
		{
			// attributes
			RBTreeNode<Val>		_M_header;
			std::size_t			_M_node_count;

			// default constructor
			RBTreeHeader(void)
			{ _M_reset(); }

			// set defaults
			void
			_M_reset(void)
			{
				_M_header._M_color = RED;
				_M_header._M_parent = 0;
				_M_header._M_left = &_M_header;
				_M_header._M_right = &_M_header;
				_M_header._M_sentinel = 1;
				_M_node_count = 0;
			}

			void
			_M_copy_reset(RBTreeHeader& other)
			{
				_M_header._M_color = other._M_header._M_color;
				_M_header._M_parent = other._M_header._M_parent;
				_M_header._M_left = other._M_header._M_left;
				_M_header._M_right = other._M_header._M_right;
				_M_header._M_sentinel = other._M_header._M_sentinel;
				_M_header._M_parent->_M_parent = &_M_header;
				_M_node_count = other._M_node_count;
				other._M_reset();
			}

			void
			_M_swap(RBTreeHeader& other)
			{
				const NodeColor		tmp_color(_M_header._M_color);
				RBTreeNode<Val>*	tmp_parent(_M_header._M_parent);
				RBTreeNode<Val>*	tmp_left(_M_header._M_left);
				RBTreeNode<Val>*	tmp_right(_M_header._M_right);
				const int			tmp_sentinel(_M_header._M_sentinel);
				const std::size_t	tmp_count(_M_node_count);

				_M_header._M_color = other._M_header._M_color;
				_M_header._M_parent = other._M_header._M_parent;
				_M_header._M_left = other._M_header._M_left;
				_M_header._M_right = other._M_header._M_right;
				_M_header._M_sentinel = other._M_header._M_sentinel;
				_M_header._M_parent->_M_parent = &_M_header;
				_M_node_count = other._M_node_count;

				other._M_header._M_color = tmp_color;
				other._M_header._M_parent = tmp_parent;
				other._M_header._M_left = tmp_left;
				other._M_header._M_right = tmp_right;
				other._M_header._M_sentinel = tmp_sentinel;
				other._M_header._M_parent->_M_parent = &other._M_header;
				other._M_node_count = tmp_count;
			}
		}; // struct RBTreeHeader


	/* Red Black Tree iterators ********************************************* */

	// Red Black Tree iterator
	template<typename T>
		struct RBtree_iterator
		{
			// types
			typedef T							value_type;
			typedef T&							reference;
			typedef T*							pointer;
			typedef bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t				difference_type;
			typedef RBTreeNode<T>*				node_pointer;

			node_pointer	_M_node; // copy of the original iterator

			// default constructor
			RBtree_iterator(void)
			: _M_node(0) { }

			// initalization constructor
			RBtree_iterator(node_pointer node)
			: _M_node(node) { }

			// copy constructor
			RBtree_iterator(const RBtree_iterator& other)
			: _M_node(other.get_node()) { }

			// copy assignment operator
			RBtree_iterator&
			operator=(const RBtree_iterator& other)
			{
				if (this != &other)
					this->_M_node = other.get_node();
				return (*this);
			}

			// return copy of the underlying node
			node_pointer
			get_node(void) const
			{ return (_M_node); }

			// accesses the pointed-to element
			reference	operator*(void) const
			{ return (*_M_node->_get_value_ptr()); }

			pointer	operator->(void) const
			{ return (_M_node->_get_value_ptr()); }

			// decrements the iterator
			RBtree_iterator&
			operator++(void)
			{
				this->_M_node = this->_M_node->_increment_node(this->_M_node);
				return (*this);
			}

			RBtree_iterator
			operator++(int)
			{
				RBtree_iterator	backup = *this;

				this->_M_node = this->_M_node->_increment_node(this->_M_node);
				return (backup);
			}

			// decrements the iterator
			RBtree_iterator&
			operator--(void)
			{
				this->_M_node = this->_M_node->_decrement_node(this->_M_node);
				return (*this);
			}

			RBtree_iterator
			operator--(int)
			{
				RBtree_iterator	backup = *this;

				this->_M_node = this->_M_node->_decrement_node(this->_M_node);
				return (backup);
			}

			// friend relational operators
			friend bool
			operator==(const RBtree_iterator<T>& lhs, const RBtree_iterator<T>& rhs)
			{ return (lhs._M_node == rhs._M_node); }

			friend bool
			operator!=(const RBtree_iterator<T>& lhs, const RBtree_iterator<T>& rhs)
			{ return (!(lhs == rhs)); }
		}; // struct RBtree_iterator

	// Red Black Tree const_iterator
	template<typename T>
		struct RBtree_const_iterator
		{
			// types
			typedef T							value_type;
			typedef const T&					reference;
			typedef const T*					pointer;
			typedef RBtree_iterator<T>			iterator;
			typedef bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t				difference_type;
			typedef const RBTreeNode<T>*		const_node_pointer;

			const_node_pointer	_M_node; // copy of the original iterator

			// default constructor
			RBtree_const_iterator(void)
			: _M_node(0) { }

			// initalization constructor
			RBtree_const_iterator(const_node_pointer node)
			: _M_node(node) { }

			// copy constructor
			RBtree_const_iterator(const RBtree_const_iterator& other)
			: _M_node(other.get_node()) { }

			RBtree_const_iterator(const iterator& other)
			: _M_node(other.get_node()) { }

			// copy assignment operator
			RBtree_const_iterator&
			operator=(const RBtree_const_iterator& other)
			{
				if (this != &other)
					this->_M_node = other.get_node();
				return (*this);
			}

			iterator
			remove_const(void) const
			{ return (iterator(const_cast<typename iterator::node_pointer>(this->_M_node))); }

			// return copy of the underlying node
			const_node_pointer
			get_node(void) const
			{ return (_M_node); }

			// accesses the pointed-to element
			reference
			operator*(void) const
			{ return (*_M_node->_get_value_ptr()); }

			pointer
			operator->(void) const
			{ return (_M_node->_get_value_ptr()); }

			// advances the iterator
			RBtree_const_iterator&
			operator++(void)
			{
				this->_M_node = this->_M_node->_increment_node(this->_M_node);
				return (*this);
			}

			RBtree_const_iterator
			operator++(int)
			{
				RBtree_const_iterator	backup = *this;

				this->_M_node = this->_M_node->_increment_node(this->_M_node);
				return (backup);
			}

			// decrements the iterator
			RBtree_const_iterator&
			operator--(void)
			{
				this->_M_node = this->_M_node->_decrement_node(this->_M_node);
				return (*this);
			}

			RBtree_const_iterator
			operator--(int)
			{
				RBtree_const_iterator	backup = *this;

				this->_M_node = this->_M_node->_decrement_node(this->_M_node);
				return (backup);
			}

			// friend relational operators
			friend bool
			operator==(const RBtree_const_iterator<T>& lhs, const RBtree_const_iterator<T>& rhs)
			{ return (lhs._M_node == rhs._M_node); }

			friend bool
			operator!=(const RBtree_const_iterator<T>& lhs, const RBtree_const_iterator<T>& rhs)
			{ return (!(lhs == rhs)); }
		}; // struct RBtree_const_iterator

	/* Tree definition ****************************************************** */

	/*
	 * Red Black Tree template class
	 * A self-balancing binary tree
	 */
	template<typename Key,
			 typename Val,
			 typename KeyGetter,
			 typename Compare = std::less<Key>,
			 typename Alloc = std::allocator<Val>
			>
		class RedBlackTree
		: public RBTreeHeader<Val>
		{
		public:
			// types
			typedef Alloc									allocator_type;
			typedef Key										key_type;
			typedef Val										value_type;
			typedef Compare									key_compare;
			typedef value_type*								pointer;
			typedef const value_type*						const_pointer;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef std::ptrdiff_t							difference_type;
			typedef std::size_t								size_type;
			typedef RBTreeNode<Val>*						node_pointer;
			typedef const RBTreeNode<Val>*					const_node_pointer;

			// iterators
			typedef RBtree_iterator<Val>					iterator;
			typedef RBtree_const_iterator<Val>				const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			// alias for the node allocator
			typedef typename allocator_type::template rebind<RBTreeNode<Val> >::other	_node_alloc_type;

			// attributes
			allocator_type	_M_alloc;
			key_compare		_M_key_compare;

		protected:
			// helpers creation/destruction
			node_pointer			_M_allocate_node(void);
			void					_M_construct_node(node_pointer __node, const value_type& __val);
			node_pointer			_M_create_node(const value_type& __val);
			void					_M_deallocate_node(node_pointer __node);
			void					_M_destroy_node(node_pointer __node);
			void					_M_drop_node(node_pointer __node);
			void					_M_erase_recursive(node_pointer __node);
			// getters
			node_pointer			_M_get_root(void);
			const_node_pointer		_M_get_root(void) const;
			node_pointer			_M_get_end(void);
			const_node_pointer		_M_get_end(void) const;
			node_pointer			_M_get_leftmost(void);
			const_node_pointer		_M_get_leftmost(void) const;
			node_pointer			_M_get_rightmost(void);
			const_node_pointer		_M_get_rightmost(void) const;
			const key_type&			_M_get_key(node_pointer __node) const;
			const key_type&			_M_get_key(const_node_pointer __node) const;
			const_reference			_M_get_value(node_pointer __node) const;
			const_reference			_M_get_value(const_node_pointer __node) const;
			// checkers
			bool					_M_key_exists(const_node_pointer __node, const key_type& __k) const;
			// helpers balancing
			void					_M_rotate_left(node_pointer __x);
			void					_M_rotate_right(node_pointer __x);
			// helpers insertion
			void					_M_rebalance_insert(node_pointer __node);
			node_pointer			_M_get_pos_from_hint(iterator __hint, const key_type& __k);
			pair<node_pointer,bool>	_M_get_insert_pos(iterator __hint, const key_type& __k);
			void					_M_insert_node(const bool __insert_left,
												   node_pointer __node, node_pointer __parent);
			pair<iterator,bool>		_M_insert(iterator __pos, const value_type& __val);
			// helpers deletion
			void					_M_rebalance_del(node_pointer __subst, node_pointer __parent);
			node_pointer			_M_get_subst(node_pointer __node);
			void					_M_set_subst(node_pointer __node, node_pointer __subst);
			void					_M_delete_node(node_pointer __node);

		public:
			// default constructor
			RedBlackTree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			// copy constructor
			RedBlackTree(const RedBlackTree& other);

			// copy assignment operator
			RedBlackTree&	operator=(const RedBlackTree& other);

			// destructor
			~RedBlackTree(void);

			// allocator
			allocator_type			get_alloc(void) const;
			_node_alloc_type		get_node_alloc(void) const;

			// getters
			key_compare				key_comp(void) const;

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
			template<typename InputIterator>
				void				insert(InputIterator first, InputIterator last,
										   typename enable_if<
												is_same<typename InputIterator::value_type,
												value_type>::value>::type* = 0);
			void					erase(iterator position);
			size_type				erase(const key_type& k);
			void					erase(iterator first, iterator last);
			void					swap(RedBlackTree& other);
			void					clear(void);

			// lookup
			iterator				find(const key_type& k);
			const_iterator			find(const key_type& k) const;
			size_type				count(const key_type& k) const;
			iterator				lower_bound(const key_type& k);
			const_iterator			lower_bound(const key_type& k) const;
			iterator				upper_bound(const key_type& k);
			const_iterator			upper_bound(const key_type& k) const;
			pair<iterator,iterator>				equal_range(const key_type& k);
			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;

			// debug
			static void	write_node(std::ofstream& outfile, node_pointer node);
			static void	write_node_next(std::ofstream& outfile, node_pointer node);
			static void	write_leaf(std::ofstream& outfile, char side, int count);
			static void	write_branch(std::ofstream& outfile, node_pointer node);
			void		write_tree_dot(const std::string& filename);
		}; // class RedBlackTree

	/* Tree implementation ************************************************** */

	/* helpers creation/destruction ***************************************** */

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_allocate_node(void)
		{ return (this->get_node_alloc().allocate(1)); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_construct_node(node_pointer __node, const value_type& __val)
		{
			this->_M_alloc.construct(__node->_get_value_ptr(), __val);
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_create_node(const value_type& __val)
		{
			node_pointer	__node = this->_M_allocate_node();

			_M_construct_node(__node, __val);
			__node->_M_color = RED;
			__node->_M_parent = 0;
			__node->_M_left = 0;
			__node->_M_right = 0;
			__node->_M_sentinel = 0;
			return (__node);
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_deallocate_node(node_pointer __node)
		{
			if (__node != 0)
				this->get_node_alloc().deallocate(__node, 1);
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_destroy_node(node_pointer __node)
		{
			if (__node != 0)
				this->_M_alloc.destroy(__node->_get_value_ptr());
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_drop_node(node_pointer __node)
		{
			if (__node != 0)
			{
				_M_destroy_node(__node);
				_M_deallocate_node(__node);
			}
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_erase_recursive(node_pointer __node)
		{
			if (__node != 0)
			{
				_M_erase_recursive(__node->_M_left);
				_M_erase_recursive(__node->_M_right);
				_M_drop_node(__node);
			}
		}

	/* getters ************************************************************** */

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_root(void)
		{ return (this->_M_header._M_parent); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_node_pointer
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_root(void) const
		{ return (static_cast<const_node_pointer>(this->_M_header._M_parent)); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_end(void)
		{ return (&this->_M_header); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_node_pointer
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_end(void) const
		{ return (&this->_M_header); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_leftmost(void)
		{ return (this->_M_header._M_left); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_node_pointer
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_leftmost(void) const
		{ return (this->_M_header._M_left); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_rightmost(void)
		{ return (this->_M_header._M_right); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_node_pointer
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_rightmost(void) const
		{ return (this->_M_header._M_right); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		const typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::key_type&
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_key(node_pointer __node) const
		{ return (KeyGetter()(_M_get_value(__node))); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		const typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::key_type&
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_key(const_node_pointer __node) const
		{ return (KeyGetter()(_M_get_value(__node))); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_reference
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_value(node_pointer __node) const
		{ return (*__node->_get_value_ptr()); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_reference
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_value(const_node_pointer __node) const
		{ return (*__node->_get_value_ptr()); }

	/* checkers ************************************************************* */

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		bool
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_key_exists(const_node_pointer __node, const key_type& __k) const
		{
			return (__node != end().get_node()
					&& !(_M_key_compare(__k, _M_get_key(__node)))
					&& !(_M_key_compare(_M_get_key(__node), __k)));
		}

	/* helpers balancing **************************************************** */

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_rotate_left(node_pointer __x)
		{
			if (__x == 0)
				return ;

			node_pointer	__y = __x->_M_right;

			if (__y != 0)
			{
				__x->_M_right = __y->_M_left;
				if (__y->_M_left != 0)
					__y->_M_left->_M_parent = __x;
				__y->_M_parent = __x->_M_parent;
				if (__x == this->_M_header._M_parent)
					this->_M_header._M_parent = __y;
				else if (__x == __x->_M_parent->_M_left)
					__x->_M_parent->_M_left = __y;
				else
					__x->_M_parent->_M_right = __y;
				__y->_M_left = __x;
				__x->_M_parent = __y;
			}
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_rotate_right(node_pointer __x)
		{
			if (__x == 0)
				return ;

			node_pointer	__y = __x->_M_left;

			if (__y != 0)
			{
				__x->_M_left = __y->_M_right;
				if (__y->_M_right != 0)
					__y->_M_right->_M_parent = __x;
				__y->_M_parent = __x->_M_parent;
				if (__x == this->_M_header._M_parent)
					this->_M_header._M_parent = __y;
				else if (__x == __x->_M_parent->_M_right)
					__x->_M_parent->_M_right = __y;
				else
					__x->_M_parent->_M_left = __y;
				__y->_M_right = __x;
				__x->_M_parent = __y;
			}
		}

	/* helpers insertion **************************************************** */

	// Maintain Red-Black property after insertion
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_rebalance_insert(node_pointer __node)
		{
			// while node is not root or has red parent, rebalance
			while (__node != this->_M_header._M_parent && __node->_M_parent->_M_color == RED)
			{
				node_pointer	__grand_parent = __node->_M_parent->_M_parent;
				node_pointer	__uncle;

				if (__node->_M_parent == __grand_parent->_M_left)
					__uncle = __grand_parent->_M_right;
				else
					__uncle = __grand_parent->_M_left;

				if (__uncle != 0 && __uncle->_M_color == RED) // uncle is red
				{
					__node->_M_parent->_M_color = BLACK;
					__uncle->_M_color = BLACK;
					__grand_parent->_M_color = RED;
					__node = __grand_parent;
				}
				else // no uncle or uncle is black
				{
					if (__node->_M_parent == __grand_parent->_M_left)
					{
						if (__node == __node->_M_parent->_M_right)
						{
							__node = __node->_M_parent;
							_M_rotate_left(__node);
						}
						__node->_M_parent->_M_color = BLACK;
						__grand_parent->_M_color = RED;
						_M_rotate_right(__grand_parent);
					}
					else
					{
						if (__node == __node->_M_parent->_M_left)
						{
							__node = __node->_M_parent;
							_M_rotate_right(__node);
						}
						__node->_M_parent->_M_color = BLACK;
						__grand_parent->_M_color = RED;
						_M_rotate_left(__grand_parent);
					}
				}
			}
			this->_M_header._M_parent->_M_color = BLACK;
		}

	/* Gets position to insert new node using the given hint */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_pos_from_hint(iterator __hint, const key_type& __k)
		{
			// decrement if hint is past the last element
			if (__hint == end())
				--__hint;

			if (__hint.get_node() == this->_M_header._M_parent)
				return (__hint.get_node());

			iterator	__prev(__hint);

			// node < hint pos
			if (_M_key_compare( __k, _M_get_key(__hint.get_node()) ))
			{
				// node < root && root < hint pos
				if (_M_key_compare(__k, _M_get_key(this->_M_header._M_parent))
					&& _M_key_compare(_M_get_key(this->_M_header._M_parent), _M_get_key(__hint.get_node())))
				{
					__hint = this->_M_header._M_parent; // start from root directly
				}
				else
				{
					--__hint;
					while (__hint.get_node() && _M_key_compare(__k, _M_get_key(__hint.get_node())))
					{
						__prev = __hint;
						--__hint;
					}
				}
			}
			else if (_M_key_compare(_M_get_key(__hint.get_node()), __k)) // node > hint pos
			{
				// node > root && root > hint pos
				if (_M_key_compare(_M_get_key(this->_M_header._M_parent), __k)
					&& _M_key_compare(_M_get_key(__hint.get_node()), _M_get_key(this->_M_header._M_parent)))
				{
					__hint = this->_M_header._M_parent; // start from root directly
				}
				else
				{
					++__hint;
					while (__hint.get_node() && _M_key_compare(_M_get_key(__hint.get_node()), __k))
					{
						__prev = __hint;
						++__hint;
					}
				}
			}
			return (__hint.get_node());
		}

	/* Gets position to insert new node */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		pair<typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::node_pointer,bool>
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_insert_pos(iterator __hint, const key_type& __k)
		{
			bool			__insert_left = true;
			node_pointer	__pos = 0;

			if (this->_M_node_count == 0)
			{
				__pos = _M_get_end();
			}
			else if (_M_key_compare(__k, _M_get_key(_M_get_leftmost())))
			{
				__pos = _M_get_leftmost();
			}
			else if (_M_key_compare(_M_get_key(_M_get_rightmost()), __k))
			{
				__insert_left = false;
				__pos = _M_get_rightmost();
			}
			else // move down the tree until finding a leaf
			{
				node_pointer	__cursor = _M_get_pos_from_hint(__hint, __k);

				while (__cursor != 0)
				{
					__pos = __cursor;
					if (_M_key_compare(__k, _M_get_key(__cursor))) // (node < cursor)
					{
						__cursor = __cursor->_M_left;
						__insert_left = true;
					}
					else if (_M_key_compare(_M_get_key(__cursor), __k)) // (node > cursor)
					{
						__cursor = __cursor->_M_right;
						__insert_left = false;
					}
					else // key already exists
					{
						return (pair<node_pointer,bool>(__pos, false));
					}
				}
			}
			return (pair<node_pointer,bool>(__pos, __insert_left));
		}

	/* Insert a node and rebalance the tree */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_insert_node(const bool __insert_left,
																	  node_pointer __node, node_pointer __parent)
		{
			__node->_M_parent = __parent;

			if (this->_M_node_count == 0) // first node becomes the root
			{
				this->_M_header._M_parent = __node;
				this->_M_header._M_left = __node;
				this->_M_header._M_right = __node;
			}
			else if (__insert_left)
			{
				__parent->_M_left = __node;
				if (__parent == this->_M_header._M_left)
					this->_M_header._M_left = __node; // update leftmost
			}
			else
			{
				__parent->_M_right = __node;
				if (__parent == this->_M_header._M_right)
					this->_M_header._M_right = __node; // update rightmost
			}
			_M_rebalance_insert(__node);
			++this->_M_node_count;
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		pair<typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::iterator,bool>
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_insert(iterator __pos, const value_type& __val)
		{
			const key_type				__k = KeyGetter()(__val);
			pair<node_pointer,bool>	__pos_k = _M_get_insert_pos(__pos, __k);

			if (_M_key_exists(__pos_k.first, __k))
				return (pair<iterator,bool>(iterator(__pos_k.first), false));

			node_pointer	__node = _M_create_node(__val);

			_M_insert_node(__pos_k.second, __node, __pos_k.first);
			return (pair<iterator,bool>(iterator(__node), true));
		}

	/* helpers deletion ***************************************************** */

	/* Maintain Red-Black property after deletion */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_rebalance_del(node_pointer __subst, node_pointer __parent)
		{
			bool	__is_left;

			// while substitute node is not root and is not red (null or black)
			while (__subst != this->_M_header._M_parent && (__subst == 0 || __subst->_M_color == BLACK))
			{
				__is_left = (__subst == __parent->_M_left);

				if (__is_left) // substitute node is left child
				{
					node_pointer	__sibling = __parent->_M_right;

					// sibling is red
					if (__sibling != 0 && __sibling->_M_color == RED)
					{
						__sibling->_M_color = BLACK;
						__parent->_M_color = RED;
						_M_rotate_left(__parent);
						__sibling = __parent->_M_right;
					}
					// sibling's children are both not red
					else if (__sibling != 0
						&& (__sibling->_M_left == 0 || __sibling->_M_left->_M_color == BLACK)
						&& (__sibling->_M_right == 0 || __sibling->_M_right->_M_color == BLACK))
					{
						__sibling->_M_color = RED;
						__subst = __parent;
						__parent = __parent->_M_parent;
					}
					else
					{
						if (__sibling != 0)
						{
							// only sibling's right child is not red
							if (__sibling->_M_right == 0 || __sibling->_M_right->_M_color == BLACK)
							{
								if (__sibling->_M_left != 0)
									__sibling->_M_left->_M_color = BLACK;
								__sibling->_M_color = RED;
								_M_rotate_right(__sibling);
								__sibling = __parent->_M_right;
							}
							else
							{
								__sibling->_M_color = __parent->_M_color;
								__parent->_M_color = BLACK;
								if (__sibling->_M_right != 0)
									__sibling->_M_right->_M_color = BLACK;
								_M_rotate_left(__parent);
							}
						}
						break ;
					}
				}
				else // substitute node is right child
				{
					node_pointer	__sibling = __parent->_M_left;

					// sibling is red
					if (__sibling != 0 && __sibling->_M_color == RED)
					{
						__sibling->_M_color = BLACK;
						__parent->_M_color = RED;
						_M_rotate_right(__parent);
						__sibling = __parent->_M_left;
					}
					// sibling's children are both not red
					else if (__sibling != 0
						&& (__sibling->_M_right == 0 || __sibling->_M_right->_M_color == BLACK)
						&& (__sibling->_M_left == 0 || __sibling->_M_left->_M_color == BLACK))
					{
						__sibling->_M_color = RED;
						__subst = __parent;
						__parent = __parent->_M_parent;
					}
					else
					{
						if (__sibling != 0)
						{
							// only sibling's left child is not red
							if (__sibling->_M_left == 0 || __sibling->_M_left->_M_color == BLACK)
							{
								if (__sibling->_M_right != 0)
									__sibling->_M_right->_M_color = BLACK;
								__sibling->_M_color = RED;
								_M_rotate_left(__sibling);
								__sibling = __parent->_M_left;
							}
							else
							{
								__sibling->_M_color = __parent->_M_color;
								__parent->_M_color = BLACK;
								if (__sibling->_M_left != 0)
									__sibling->_M_left->_M_color = BLACK;
								_M_rotate_right(__parent);
							}
						}
						break ;
					}
				}
			}
			if (__subst != 0 && __subst->_M_color == RED)
				__subst->_M_color = BLACK;
		}

	/* Find successor that will replace the node to be deleted */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_get_subst(node_pointer __node)
		{
			node_pointer	__subst = 0;

			if (__node->_M_left != 0 && __node->_M_right != 0)
				__subst = __node->_increment_node(__node);
			else if (__node->_M_left != 0)
				__subst = __node->_M_left;
			else if (__node->_M_right != 0)
				__subst = __node->_M_right;
			return (__subst);
		}

	/* Set successor of node to be deleted */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_set_subst(node_pointer __node, node_pointer __subst)
		{
			NodeColor		__deleted_color = __node->_M_color;
			bool			__delete_left = (__node == __node->_M_parent->_M_left);
			node_pointer	__last_subst = __subst;
			node_pointer	__parent = __node->_M_parent;

			if (__node->_M_left != 0 && __node->_M_right != 0) // node to be deleted has two children
			{
				__last_subst = __subst->_M_right;
				if (__node->_M_left != __subst)
				{
					__subst->_M_left = __node->_M_left;
					__node->_M_left->_M_parent = __subst;
				}
				if (__node->_M_right != __subst)
				{
					__parent = __subst->_M_parent;
					__subst->_M_parent->_M_left = __last_subst;
					__subst->_M_right = __node->_M_right;
					__node->_M_right->_M_parent = __subst;
				}
				else
					__parent = __subst;
				if (this->_M_header._M_parent == __node) // update root
					this->_M_header._M_parent = __subst;
				else if (__delete_left)
					__node->_M_parent->_M_left = __subst;
				else
					__node->_M_parent->_M_right = __subst;
				__subst->_M_parent = __node->_M_parent;
				__node->_M_color = __subst->_M_color;
				__subst->_M_color = __deleted_color;
			}
			else
			{
				if (this->_M_header._M_parent == __node) // update root
					this->_M_header._M_parent = __subst;
				else if (__delete_left)
					__node->_M_parent->_M_left = __subst;
				else
					__node->_M_parent->_M_right = __subst;
				if (this->_M_header._M_left == __node) // update leftmost
				{
					if (__node->_M_right == 0)
						this->_M_header._M_left = __node->_M_parent;
					else if (__subst != 0)
						this->_M_header._M_left = __last_subst->_get_leftmost(__last_subst);
				}
				else if (this->_M_header._M_right == __node) // update rightmost
				{
					if (__node->_M_left == 0)
						this->_M_header._M_right = __node->_M_parent;
					else if (__last_subst != 0)
						this->_M_header._M_left = __last_subst->_get_rightmost(__last_subst);
				}
			}
			if (__last_subst != 0)
				__last_subst->_M_parent = __parent;
			if (__subst != 0)
				__subst->_M_parent = __node->_M_parent;
			if (__deleted_color == BLACK)
				_M_rebalance_del(__last_subst, __parent);
		}

	/* Delete a node and rebalance the tree */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_M_delete_node(node_pointer __node)
		{
			if (__node != 0)
			{
				node_pointer	__subst = _M_get_subst(__node);

				_M_set_subst(__node, __subst);
				_M_drop_node(__node);
				--this->_M_node_count;
			}
		}

	/* construct/copy/destroy *********************************************** */

	/* default constructor */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::RedBlackTree(const key_compare& comp, const allocator_type& alloc)
		: _M_alloc(alloc),
		  _M_key_compare(comp) { }

	/* copy constructor */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::RedBlackTree(const RedBlackTree& other)
		: _M_alloc(other._M_alloc),
		  _M_key_compare(other._M_key_compare)
		{
			const_iterator	first = other.begin();
			const_iterator	last = other.end();

			while (first != last)
			{
				_M_insert(end(), *first);
				++first;
			}
		}

	/* copy assignment operator */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>&
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::operator=(const RedBlackTree& other)
		{
			if (this != &other)
			{
				_M_erase_recursive(this->_M_header._M_parent);
				this->_M_reset();
				this->_M_key_compare = other._M_key_compare;

				const_iterator	first = other.begin();
				const_iterator	last = other.end();

				while (first != last)
				{
					_M_insert(end(), *first);
					++first;
				}
			}
			return (*this);
		}

	/* destructor */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::~RedBlackTree(void)
		{
			_M_erase_recursive(this->_M_header._M_parent);
			this->_M_reset();
		}

	/* allocator ************************************************************ */

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::allocator_type
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::get_alloc(void) const
		{ return (allocator_type(this->_M_alloc)); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::_node_alloc_type
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::get_node_alloc(void) const
		{ return (_node_alloc_type(this->_M_alloc)); }

	/* getters ************************************************************** */

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::key_compare
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::key_comp(void) const
		{ return (this->_M_key_compare); }

	/* iterators ************************************************************ */

	/* Returns an iterator pointing to the first element in the tree */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::begin(void)
		{ return (iterator(this->_M_header._M_left)); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::begin(void) const
		{ return (const_iterator(this->_M_header._M_left)); }

	/* Returns an iterator representing the past-the-end element in the tree */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::end(void)
		{ return (iterator(&this->_M_header)); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::end(void) const
		{ return (const_iterator(&this->_M_header)); }

	/* Returns a reverse iterator pointing to the last element in the tree */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::reverse_iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::rbegin(void)
		{ return (reverse_iterator(end())); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_reverse_iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::rbegin(void) const
		{ return (const_reverse_iterator(end())); }

	/*
	 * Returns a reverse iterator pointing to the theoretical element preceding
	 * the first element in the tree
	 */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::reverse_iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::rend(void)
		{ return (reverse_iterator(begin())); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_reverse_iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::rend(void) const
		{ return (const_reverse_iterator(begin())); }

	/* capacity ************************************************************* */

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		bool
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::empty(void) const
		{ return (this->_M_node_count == 0); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::size_type
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::size(void) const
		{ return (this->_M_node_count); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::size_type
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::max_size(void) const
		{ return (this->get_node_alloc().max_size()); }

	/* modifiers ************************************************************ */

	/* Inserts */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		pair<typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::iterator,bool>
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::insert(const value_type& val)
		{ return (_M_insert(iterator(_M_get_root()), val)); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::insert(iterator position, const value_type& val)
		{ return (_M_insert(position, val).first); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
	template<typename InputIterator>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::insert(InputIterator first, InputIterator last,
															  typename enable_if<
																is_same<typename InputIterator::value_type,
																value_type>::value>::type*)
		{
			for ( ; first != last; ++first)
				_M_insert(end(), *first);
		}

	/* Erase */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::erase(iterator position)
		{
			_M_delete_node(position.get_node());
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::size_type
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::erase(const key_type& k)
		{
			iterator	it = find(k);

			if (it != end())
			{
				_M_delete_node(it.get_node());
				return (1);
			}
			return (0);
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::erase(iterator first, iterator last)
		{
			if (first == begin() && last == end()) // everything
			{
				_M_erase_recursive(this->_M_header._M_parent);
				this->_M_reset();
			}
			else
			{
				while (first != last)
					erase(first++);
			}
		}

	/* Exchanges the content of the tree and the other tree */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::swap(RedBlackTree& other)
		{
			if (this == &other)
				return ;

			key_compare	tmp(this->_M_key_compare);

			this->_M_key_compare = other._M_key_compare;
			other._M_key_compare = tmp;

			if (size() > 0 && other.size() > 0)
				this->_M_swap(other);
			else if (other.size() > 0)
				this->_M_copy_reset(other);
			else if (size() > 0)
				other._M_copy_reset(*this);
		}

	/* Destroys all elements from the tree, leaving it with a size of 0 */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::clear(void)
		{
			_M_erase_recursive(this->_M_header._M_parent);
			this->_M_reset();
		}

	/* lookup *************************************************************** */

	/* Gets the element with the key k, else return end */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::find(const key_type& k)
		{
			node_pointer	__cursor = this->_M_header._M_parent;

			while (__cursor != 0)
			{
				if (k == _M_get_key(__cursor))
					return (iterator(__cursor));
				else if (_M_key_compare(k, _M_get_key(__cursor)))
					__cursor = __cursor->_M_left;
				else
					__cursor = __cursor->_M_right;
			}
			return (iterator(&this->_M_header));
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::find(const key_type& k) const
		{
			node_pointer	__cursor = this->_M_header._M_parent;

			while (__cursor != 0)
			{
				if (k == _M_get_key(__cursor))
					return (iterator(__cursor));
				else if (_M_key_compare(k, _M_get_key(__cursor)))
					__cursor = __cursor->_M_left;
				else
					__cursor = __cursor->_M_right;
			}
			return (const_iterator(&this->_M_header));
		}

	/* Returns the number of elements matching key k */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::size_type
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::count(const key_type& k) const
		{
			size_type		count = 0;
			const_iterator	it = this->find(k);

			while (it != this->end() && k == _M_get_key(it.get_node()))
			{
				++count;
				++it;
			}
			return (count);
		}

	/*
	 * Gets the first element that is equivalent or after k
	 * i.e. The first element for which key_comp(element_key,k) would return false
	 */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::lower_bound(const key_type& k)
		{
			node_pointer	__cursor = _M_get_root();
			node_pointer	__lower_bound = _M_get_end();

			while (__cursor != 0)
			{
				if (!_M_key_compare(_M_get_key(__cursor), k)) // k <= elem
				{
					__lower_bound = __cursor;
					__cursor = __cursor->_M_left;
				}
				else
				{
					__cursor = __cursor->_M_right;
				}
			}
			return (iterator(__lower_bound));
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::lower_bound(const key_type& k) const
		{
			const_node_pointer	__cursor = _M_get_root();
			const_node_pointer	__lower_bound = _M_get_end();

			while (__cursor != 0)
			{
				if (!_M_key_compare(_M_get_key(__cursor), k)) // k <= elem
				{
					__lower_bound = __cursor;
					__cursor = __cursor->_M_left;
				}
				else
				{
					__cursor = __cursor->_M_right;
				}
			}
			return (const_iterator(__lower_bound));
		}

	/*
	 * Gets the first element that is after k
	 * i.e. The first element for which key_comp(k,element_key) would return true
	 */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::upper_bound(const key_type& k)
		{
			node_pointer	__cursor = _M_get_root();
			node_pointer	__upper_bound = _M_get_end();

			while (__cursor != 0)
			{
				if (_M_key_compare(k, _M_get_key(__cursor))) // k < elem
				{
					__upper_bound = __cursor;
					__cursor = __cursor->_M_left;
				}
				else
				{
					__cursor = __cursor->_M_right;
				}
			}
			return (iterator(__upper_bound));
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_iterator
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::upper_bound(const key_type& k) const
		{
			const_node_pointer	__cursor = _M_get_root();
			const_node_pointer	__upper_bound = _M_get_end();

			while (__cursor != 0)
			{
				if (_M_key_compare(k, _M_get_key(__cursor))) // k < elem
				{
					__upper_bound = __cursor;
					__cursor = __cursor->_M_left;
				}
				else
				{
					__cursor = __cursor->_M_right;
				}
			}
			return (const_iterator(__upper_bound));
		}

	/*
	 * Returns the bounds of a range that have a key equivalent to k.
	 * If k is not found, returns two iterators pointing to the first element after k.
	 */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		pair<typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::iterator,typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::iterator>
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::equal_range(const key_type& k)
		{
			iterator	first = lower_bound(k);
			iterator	last = upper_bound(k);

			return (pair<iterator,iterator>(first, last));
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		pair<typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_iterator,typename RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::const_iterator>
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::equal_range(const key_type& k) const
		{
			const_iterator	first = lower_bound(k);
			const_iterator	last = upper_bound(k);

			return (pair<const_iterator,const_iterator>(first, last));
		}

	/* debug **************************************************************** */

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::write_node(std::ofstream& outfile, node_pointer node)
		{
			if (node != 0)
			{
				if (node->_M_color == RED)
				{
					outfile << "\n    \""
						<< node->_M_value.first << "=" << node->_M_value.second
						<< "\\n" << node << "\" [color=\"red\"]";
				}
				outfile << "\n    \""
						<< node->_M_value.first << "=" << node->_M_value.second
						<< "\\n" << node << "\"";
			}
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::write_node_next(std::ofstream& outfile, node_pointer node)
		{
			if (node != 0)
			{
				outfile << " -> \""
						<< node->_M_value.first << "=" << node->_M_value.second
						<< "\\n" << node << "\";";
			}
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::write_leaf(std::ofstream& outfile, char side, int count)
		{
			outfile << " -> leaf_" << side << "_" << count << ";";
			outfile << "\n    leaf_" << side << "_" << count << " [shape=plain];";
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::write_branch(std::ofstream& outfile, node_pointer node)
		{
			static int	count = 0;

			write_node(outfile, node);
			if (node->_M_left)
			{
				write_node_next(outfile, node->_M_left);
				write_branch(outfile, node->_M_left);
			}
			else if (node->_M_left == 0)
				write_leaf(outfile, 'L', count++);
			write_node(outfile, node);
			if (node->_M_right)
			{
				write_node_next(outfile, node->_M_right);
				write_branch(outfile, node->_M_right);
			}
			else if (node->_M_right == 0)
				write_leaf(outfile, 'R', count++);
		}

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>::write_tree_dot(const std::string& filename)
		{
			std::ofstream	outfile;
			std::string		filename_dot = filename + ".dot";

			if (size() == 0)
			{
				std::cout << "Didn't create " << filename_dot << std::endl;
				return ;
			}

			outfile.open(filename_dot.c_str(), std::ios::out);

			if ( !outfile.is_open() )
			{
				std::cout << "Error: Unable to open \'" << filename_dot << "'" << std::endl;
				return ;
			}

			outfile << "digraph rb_tree {\n"
						"    graph [\n    charset = \"UTF-8\";\n    fontcolor = white,\n"
						"    fontsize = 18,\n    style = \"filled\"\n  ];\n\n"
						"  node [\n    style = \"solid,filled\"\n    color = black,\n"
						"\n    fontcolor = white\n  ];\n";

			node_pointer	root = _M_get_root();

			if (!root->_M_left && !root->_M_right)
				outfile << "    '" << root->_M_value.first << "=" << root->_M_value.second << "';";
			else
				write_branch(outfile, root);
			outfile << "\n}";

			outfile.close();
			// std::cout << "Successfully created " << filename_dot << " in working dir" << std::endl;

			std::string	dot_cmd = "dot -Tsvg ";
			dot_cmd += filename;
			dot_cmd += ".dot -o ";
			dot_cmd += filename;
			dot_cmd += ".svg";
			system(dot_cmd.c_str());
		}


	/* non-member function overloads **************************************** */

	/*
	 * Relational operators
	 * Make comparison between two trees
	 */

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		bool
		operator==(const RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>& lhs,
				   const RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>& rhs)
		{ return ((lhs.size() == rhs.size()) && (ft::equal( lhs.begin(), lhs.end(), rhs.begin()))); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		bool
		operator!=(const RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>& lhs,
				   const RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>& rhs)
		{ return (!(lhs == rhs)); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		bool
		operator<(const RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>& lhs,
				  const RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>& rhs)
		{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		bool
		operator>(const RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>& lhs,
				  const RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>& rhs)
		{ return (rhs < lhs); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		bool
		operator<=(const RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>& lhs,
				   const RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>& rhs)
		{ return (!(rhs < lhs)); }

	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		bool
		operator>=(const RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>& lhs,
				   const RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>& rhs)
		{ return (!(lhs < rhs)); }

	/* Exchange contents of two trees */
	template<typename Key, typename Val, typename KeyGetter, typename Compare, typename Alloc>
		void
		swap(RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>& x, RedBlackTree<Key,Val,KeyGetter,Compare,Alloc>& y)
		{
			x.swap(y);
		}

} // namespace ft

#endif
