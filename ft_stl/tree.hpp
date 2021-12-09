/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:53:39 by mboivin           #+#    #+#             */
/*   Updated: 2021/12/09 23:40:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include <cstdlib> // system
#include <memory>
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

			// Retrieve the value address
			Val*	_get_value_ptr(void)
			{
				return (&this->_M_value);
			}

			const Val*	_get_value_ptr(void) const
			{
				return (&this->_M_value);
			}

			// Get node holding lower value
			static node_pointer	_get_leftmost(node_pointer x)
			{
				while (x->_M_left != 0)
					x = x->_M_left;
				return (x);
			}

			static const_node_pointer	_get_leftmost(const_node_pointer x)
			{
				while (x->_M_left != 0)
					x = x->_M_left;
				return (x);
			}

			// Get node holding greater value
			static node_pointer	_get_rightmost(node_pointer x)
			{
				while (x->_M_right != 0)
					x = x->_M_right;
				return (x);
			}

			static const_node_pointer	_get_rightmost(const_node_pointer x)
			{
				while (x->_M_right != 0)
					x = x->_M_right;
				return (x);
			}

			// Increment node
			static node_pointer	_increment_node(node_pointer x)
			{
				if (x->_M_right != 0)
				{
					x = x->_M_right;
					while (x->_M_left != 0)
						x = x->_M_left;
				}
				else
				{
					if (x->_M_parent != 0)
						x = x->_M_parent;
				}
				return (x);
			}

			static const_node_pointer	_increment_node(const_node_pointer x)
			{
				if (x->_M_right != 0)
				{
					x = x->_M_right;
					while (x->_M_left != 0)
						x = x->_M_left;
				}
				else
				{
					if (x->_M_parent != 0)
						x = x->_M_parent;
				}
				return (x);
			}

			// Decrement node
			static node_pointer	_decrement_node(node_pointer x)
			{
				if (x->_M_left != 0)
				{
					x = x->_M_left;
					while (x->_M_right != 0)
						x = x->_M_right;
				}
				return (x);
			}

			static const_node_pointer	_decrement_node(const_node_pointer x)
			{
				if (x->_M_left != 0)
				{
					x = x->_M_left;
					while (x->_M_right != 0)
						x = x->_M_right;
				}
				return (x);
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
			{
				_M_reset();
			}

			// set defaults
			void	_M_reset(void)
			{
				_M_header._M_color = RED;
				_M_header._M_parent = 0; // will be the root
				_M_header._M_left = &_M_header; // leftmost
				_M_header._M_right = &_M_header; // rightmost
				_M_node_count = 0;
			}
		}; // struct RBTreeHeader


	/* Red Black Tree iterators ********************************************* */

	// Red Black Tree iterator
	template<typename T>
		struct RBtree_iterator
		{
			// types
			typedef T										value_type;
			typedef T&										reference;
			typedef T*										pointer;
			typedef typename ft::bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t							difference_type;
			typedef RBTreeNode<T>*							node_pointer;

			node_pointer	_M_node; // copy of the original iterator

			// default constructor
			RBtree_iterator(void)
			: _M_node(0)
			{
			}

			// initalization constructor
			RBtree_iterator(node_pointer x)
			: _M_node(x)
			{
			}

			// copy constructor
			RBtree_iterator(const RBtree_iterator& other)
			: _M_node(other.get_node())
			{
			}

			// copy assignment operator
			RBtree_iterator&	operator=(const RBtree_iterator& other)
			{
				if (this != &other)
					this->_M_node = other.get_node();
				return (*this);
			}

			// return copy of the underlying node
			node_pointer	get_node(void) const
			{
				return (_M_node);
			}

			// accesses the pointed-to element
			reference	operator*(void) const
			{
				return (*_M_node->_get_value_ptr());
			}

			pointer	operator->(void) const
			{
				return (_M_node->_get_value_ptr());
			}

			// advances or decrements the iterator

			RBtree_iterator&	operator++(void)
			{
				this->_M_node = this->_M_node->_increment_node(this->_M_node);
				return (*this);
			}

			RBtree_iterator	operator++(int)
			{
				RBtree_iterator	backup = *this;

				this->_M_node = this->_M_node->_increment_node(this->_M_node);
				return (backup);
			}

			RBtree_iterator&	operator--(void)
			{
				this->_M_node = this->_M_node->_decrement_node(this->_M_node);
				return (*this);
			}

			RBtree_iterator	operator--(int)
			{
				RBtree_iterator	backup = *this;

				this->_M_node = this->_M_node->_decrement_node(this->_M_node);
				return (backup);
			}
		}; // struct RBtree_iterator

	/* Relational operators */

	template<typename T1, typename T2>
		bool
		operator==(const RBtree_iterator<T1>& lhs,
				   const RBtree_iterator<T2>& rhs)
		{
			return (lhs.get_node() == rhs.get_node());
		}

	template<typename T1, typename T2>
		bool
		operator!=(const RBtree_iterator<T1>& lhs,
				   const RBtree_iterator<T2>& rhs)
		{
			return (lhs.get_node() != rhs.get_node());
		}

	// Red Black Tree const_iterator
	template<typename T>
		struct RBtree_const_iterator
		{
			// types
			typedef T										value_type;
			typedef T&										reference;
			typedef T*										pointer;
			typedef RBtree_iterator<T>						iterator;
			typedef typename ft::bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t							difference_type;
			typedef RBTreeNode<T>*							node_pointer;

			node_pointer	_M_node; // copy of the original iterator

			// default constructor
			RBtree_const_iterator(void)
			: _M_node()
			{
			}

			// initalization constructor
			RBtree_const_iterator(node_pointer x)
			: _M_node(x)
			{
			}

			// copy constructor
			RBtree_const_iterator(const RBtree_const_iterator& other)
			: _M_node(other.get_node())
			{
			}

			RBtree_const_iterator(const iterator& other)
			: _M_node(other.get_node())
			{
			}

			// copy assignment operator
			RBtree_const_iterator&	operator=(const RBtree_const_iterator& other)
			{
				if (this != &other)
					this->_M_node = other.get_node();
				return (*this);
			}

			iterator	remove_const(void) const
			{
				return (iterator(const_cast<typename iterator::node_pointer>(this->_M_node)));
			}

			// return copy of the underlying node
			node_pointer	get_node(void) const
			{
				return (_M_node);
			}

			// accesses the pointed-to element
			reference	operator*(void) const
			{
				return (*_M_node->_get_value_ptr());
			}

			pointer	operator->(void) const
			{
				return (_M_node->_get_value_ptr());
			}

			// advances or decrements the iterator

			RBtree_const_iterator&	operator++(void)
			{
				this->_M_node = this->_M_node->_increment_node(this->_M_node);
				return (*this);
			}

			RBtree_const_iterator	operator++(int)
			{
				RBtree_const_iterator	backup = *this;

				this->_M_node = this->_M_node->_increment_node(this->_M_node);
				return (backup);
			}

			RBtree_const_iterator&	operator--(void)
			{
				this->_M_node = this->_M_node->_decrement_node(this->_M_node);
				return (*this);
			}

			RBtree_const_iterator	operator--(int)
			{
				RBtree_const_iterator	backup = *this;

				this->_M_node = this->_M_node->_decrement_node(this->_M_node);
				return (backup);
			}
		}; // struct RBtree_const_iterator

	/* Relational operators */

	template<typename T1, typename T2>
		bool
		operator==(const RBtree_const_iterator<T1>& lhs,
				   const RBtree_const_iterator<T2>& rhs)
		{
			return (lhs.get_node() == rhs.get_node());
		}

	template<typename T1, typename T2>
		bool
		operator!=(const RBtree_const_iterator<T1>& lhs,
				   const RBtree_const_iterator<T2>& rhs)
		{
			return (lhs.get_node() != rhs.get_node());
		}

	/* Tree definition ****************************************************** */

	/*
	 * Red Black Tree template class
	 */
	template<typename Key, typename Val,
			 typename Compare = std::less<Key>,
			 typename Alloc = std::allocator<Val> >
		class RedBlackTree
		: public RBTreeHeader<Val>
		{
		protected:
			// types
			typedef Alloc						allocator_type;
			typedef Key							key_type;
			typedef Val							value_type;
			typedef Compare						key_compare;
			typedef value_type*					pointer;
			typedef const value_type*			const_pointer;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef std::ptrdiff_t				difference_type;
			typedef std::size_t					size_type;
			typedef RBTreeNode<Val>*			node_pointer;
			typedef const RBTreeNode<Val>*		const_node_pointer;

		public:
			// iterators
			typedef RBtree_iterator<Val>		iterator;
			typedef RBtree_const_iterator<Val>	const_iterator;

		private:
			// aliases
			typedef typename allocator_type::template rebind<RBTreeNode<Val> >::other	_node_alloc_type;
			typedef typename ft::pair<iterator,bool>									_pair_it_bool;

			// attributes
			allocator_type	_M_alloc; // internal copy of the allocator
			key_compare		_M_key_compare;

		protected:
			// helpers
			node_pointer			_M_allocate_node(void);
			void					_M_construct_node(node_pointer __node, const value_type& __val);
			node_pointer			_M_create_node(const value_type& __val);
			void					_M_destroy_node(node_pointer __node);
			void					_M_deallocate_node(node_pointer __node);
			void					_M_drop_node(node_pointer __node);
			void					_M_erase(node_pointer __node);
			node_pointer			_M_get_root(void) const;
			node_pointer			_M_get_end(void) const;
			node_pointer			_M_get_leftmost(void) const;
			node_pointer			_M_get_rightmost(void) const;
			const key_type&			_M_get_key(node_pointer __node) const;
			const_reference			_M_get_value(node_pointer __node) const;
			void					_M_rotate_left(node_pointer __x);
			void					_M_rotate_right(node_pointer __x);
			void					_M_rebalance(node_pointer __node);
			void					_M_insert(bool insert_left,
											  node_pointer __node, node_pointer __parent);
			ft::pair<iterator,bool>	_M_insert_node(const value_type& __val);

		public:
			// default constructor
			RedBlackTree(const allocator_type& alloc = allocator_type());

			// copy constructor
			RedBlackTree(const RedBlackTree& other);

			// copy assignment operator
			RedBlackTree&	operator=(const RedBlackTree& other);

			// destructor
			~RedBlackTree(void);

			// allocator
			allocator_type		get_alloc(void) const;
			_node_alloc_type	get_node_alloc(void) const;

			// getters
			key_compare			key_comp(void) const;

			// iterators
			iterator			begin(void);
			const_iterator		begin(void) const;
			iterator			end(void);
			const_iterator		end(void) const;

			// capacity
			bool				empty(void) const;
			size_type			size(void) const;
			size_type			max_size(void) const;

			// modifiers
			ft::pair<iterator,bool>	insert(const value_type& val); // tmp
			void					clear(void);

			// debug
			static void	write_node(std::ofstream& outfile, node_pointer node);
			static void	write_node_next(std::ofstream& outfile, node_pointer node);
			static void	write_leaf(std::ofstream& outfile, char side, int count);
			static void	write_branch(std::ofstream& outfile, node_pointer node);
			void		write_tree_dot(void);
		}; // class RedBlackTree

	/* Tree implementation ************************************************** */

	/* helpers ************************************************************** */

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,Compare,Alloc>::_M_allocate_node(void)
		{
			return (this->get_node_alloc().allocate(1));
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::_M_construct_node(node_pointer __node, const value_type& __val)
		{
			this->_M_alloc.construct(__node->_get_value_ptr(), __val);
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,Compare,Alloc>::_M_create_node(const value_type& __val)
		{
			node_pointer	__node = this->_M_allocate_node();

			_M_construct_node(__node, __val);
			__node->_M_color = RED;
			__node->_M_parent = 0;
			__node->_M_left = 0;
			__node->_M_right = 0;
			return (__node);
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::_M_destroy_node(node_pointer __node)
		{
			this->_M_alloc.destroy(__node->_get_value_ptr());
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::_M_deallocate_node(node_pointer __node)
		{
			if (__node)
				this->get_node_alloc().deallocate(__node, 1);
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::_M_drop_node(node_pointer __node)
		{
			if (__node != 0)
			{
				_M_destroy_node(__node);
				_M_deallocate_node(__node);
			}
		}

	// Erase recursively the tree from the node passed as parameter
	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::_M_erase(node_pointer __node)
		{
			while (__node != 0)
			{
				_M_erase(__node->_M_right);
				node_pointer	__tmp = __node->_M_left;
				_M_drop_node(__node);
				__node = __tmp;
			}
		}

	// Get root node
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,Compare,Alloc>::_M_get_root(void) const
		{
			return (this->_M_header._M_parent);
		}

	// Get end (header)
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,Compare,Alloc>::_M_get_end(void) const
		{
			return (&this->_M_header);
		}

	// Get node holding lowest value
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,Compare,Alloc>::_M_get_leftmost(void) const
		{
			return (this->_M_header._M_left);
		}

	// Get node holding greatest value
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,Compare,Alloc>::_M_get_rightmost(void) const
		{
			return (this->_M_header._M_right);
		}

	// Get only key of the pair
	template<typename Key, typename Val, typename Compare, typename Alloc>
		const typename RedBlackTree<Key,Val,Compare,Alloc>::key_type&
		RedBlackTree<Key,Val,Compare,Alloc>::_M_get_key(node_pointer __node) const
		{
			return (static_cast<key_type&>(__node->_get_value_ptr()->first));
		}

	// Get pair<key,value>
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::const_reference
		RedBlackTree<Key,Val,Compare,Alloc>::_M_get_value(node_pointer __node) const
		{
			return (*__node->_get_value_ptr());
		}

	// Rotate left
	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::_M_rotate_left(node_pointer __x)
		{
			node_pointer	__y = __x->_M_right;

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

	// Rotate right
	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::_M_rotate_right(node_pointer __x)
		{
			node_pointer	__y = __x->_M_left;

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

	// Rebalance tree
	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::_M_rebalance(node_pointer __node)
		{
			// if node is not root or has red parent, rebalance
			if ((__node != this->_M_header._M_parent) && (__node->_M_parent->_M_color == RED))
			{
				node_pointer	__grand_parent = __node->_M_parent->_M_parent;
				node_pointer	__uncle;

				if (__node->_M_parent == __grand_parent->_M_left)
				{
					__uncle = __grand_parent->_M_right;

					if (__uncle && __uncle->_M_color == RED) // uncle is red
					{
						__node->_M_parent->_M_color = BLACK;
						__uncle->_M_color = BLACK;
						__grand_parent->_M_color = RED;
						_M_rebalance(__grand_parent);
					}
					else // no uncle or uncle is black
					{
						if (__node == __node->_M_parent->_M_right)
						{
							_M_rotate_left(__node->_M_parent);
							__node = __node->_M_left;
						}
						_M_rotate_right(__grand_parent);
						__node->_M_parent->_M_color = BLACK;
						__grand_parent->_M_color = RED;
					}
				}
				else
				{
					__uncle = __grand_parent->_M_left;

					if (__uncle && __uncle->_M_color == RED) // uncle is red
					{
						__node->_M_parent->_M_color = BLACK;
						__uncle->_M_color = BLACK;
						__grand_parent->_M_color = RED;
						_M_rebalance(__grand_parent);
					}
					else // no uncle or uncle is black
					{
						if (__node == __node->_M_parent->_M_left)
						{
							_M_rotate_right(__node->_M_parent);
							__node = __node->_M_right;
						}
						_M_rotate_left(__grand_parent);
						__node->_M_parent->_M_color = BLACK;
						__grand_parent->_M_color = RED;
					}
				}
			}
			this->_M_header._M_parent->_M_color = BLACK;
		}

	// Insert a node
	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::_M_insert(bool insert_left,
													   node_pointer __node, node_pointer __parent)
		{
			__node->_M_parent = __parent;

			if (this->_M_node_count == 0) // first node becomes the root
			{
				this->_M_header._M_parent = __node;
				this->_M_header._M_left = __node;
				this->_M_header._M_right = __node;
			}
			else if (insert_left)
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
			_M_rebalance(__node);
			++this->_M_node_count;
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		ft::pair<typename RedBlackTree<Key,Val,Compare,Alloc>::iterator,bool>
		RedBlackTree<Key,Val,Compare,Alloc>::_M_insert_node(const value_type& __val)
		{
			const key_type	__key = __val.first;
			bool			__insert_left = true;
			node_pointer	__parent;
			node_pointer	__node = _M_create_node(__val);

			// check whether the new node is lower than the current leftmost node
			if ( _M_key_compare( __key, _M_get_key(_M_get_leftmost()) ) )
			{
				__parent = _M_get_leftmost();
			}
			// check whether the new node is greater than the current rightmost node
			else if ( _M_key_compare(_M_get_key(_M_get_rightmost()), __key ) )
			{
				__insert_left = false;
				__parent = _M_get_rightmost();
			}
			// else move down to the tree until a leaf
			else
			{
				node_pointer	__cursor(_M_get_root());

				while (__cursor != 0)
				{
					__parent = __cursor;

					if (_M_key_compare(__key, _M_get_key(__cursor))) // (node < cursor)
					{
						__cursor = __cursor->_M_left;
						__insert_left = true;
					}
					else if (_M_key_compare(_M_get_key(__cursor), __key)) // (node > cursor)
					{
						__cursor = __cursor->_M_right;
						__insert_left = false;
					}
					else // key already exists
					{
						_M_drop_node(__node);
						// second element is false if no new value was inserted
						return (_pair_it_bool(iterator(__node), false));
					}
				}
			}
			_M_insert(__insert_left, __node, __parent);
			return (_pair_it_bool(iterator(__node), true));
		}

	/* construct/copy/destroy *********************************************** */

	// default constructor
	template<typename Key, typename Val, typename Compare, typename Alloc>
		RedBlackTree<Key,Val,Compare,Alloc>::RedBlackTree(const allocator_type& alloc)
		: _M_alloc(alloc),
		  _M_key_compare()
		{
		}

	// copy constructor
	template<typename Key, typename Val, typename Compare, typename Alloc>
		RedBlackTree<Key,Val,Compare,Alloc>::RedBlackTree(const RedBlackTree& other)
		: _M_alloc(other._M_alloc),
		  _M_key_compare(other._M_key_compare)
		{
		}

	// copy assignment operator
	template<typename Key, typename Val, typename Compare, typename Alloc>
		RedBlackTree<Key,Val,Compare,Alloc>&
		RedBlackTree<Key,Val,Compare,Alloc>::operator=(const RedBlackTree& other)
		{
			if (this != &other)
			{
				_M_erase(this->_M_header._M_parent);
				this->_M_reset();
				this->_M_key_compare = other._M_key_compare;

				const_iterator	it = other.begin();
				const_iterator	ite = other.end();

				while (it != ite)
				{
					value_type	val = *it;
					std::cout << "val: " << val.first << std::endl;
					_M_insert_node(val);
					++it;
				}
			}
			return (*this);
		}

	// destructor
	template<typename Key, typename Val, typename Compare, typename Alloc>
		RedBlackTree<Key,Val,Compare,Alloc>::~RedBlackTree(void)
		{
			_M_erase(this->_M_header._M_parent);
			this->_M_reset();
		}

	/* allocator ************************************************************ */

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::allocator_type
		RedBlackTree<Key,Val,Compare,Alloc>::get_alloc(void) const
		{
			return (allocator_type(this->_M_alloc));
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::_node_alloc_type
		RedBlackTree<Key,Val,Compare,Alloc>::get_node_alloc(void) const
		{
			return (_node_alloc_type(this->_M_alloc));
		}

	/* getters ************************************************************** */

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::key_compare
		RedBlackTree<Key,Val,Compare,Alloc>::key_comp(void) const
		{
			return (this->_M_key_compare);
		}

	/* iterators ************************************************************ */

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::iterator
		RedBlackTree<Key,Val,Compare,Alloc>::begin(void)
		{
			return (iterator(this->_M_header._M_left));
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::const_iterator
		RedBlackTree<Key,Val,Compare,Alloc>::begin(void) const
		{
			return (const_iterator(this->_M_header._M_left));
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::iterator
		RedBlackTree<Key,Val,Compare,Alloc>::end(void)
		{
			return (iterator(&this->_M_header));
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::const_iterator
		RedBlackTree<Key,Val,Compare,Alloc>::end(void) const
		{
			return (const_iterator(&this->_M_header));
		}

	/* capacity ************************************************************* */

	template<typename Key, typename Val, typename Compare, typename Alloc>
		bool
		RedBlackTree<Key,Val,Compare,Alloc>::empty(void) const
		{
			return (this->_M_node_count == 0);
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::size_type
		RedBlackTree<Key,Val,Compare,Alloc>::size(void) const
		{
			return (this->_M_node_count);
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::size_type
		RedBlackTree<Key,Val,Compare,Alloc>::max_size(void) const
		{
			return (this->get_node_alloc().max_size());
		}

	/* modifiers ************************************************************ */

	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::clear(void)
		{
			_M_erase(this->_M_header._M_parent);
			this->_M_reset();
		}

	// tmp (insert from map)
	template<typename Key, typename Val, typename Compare, typename Alloc>
		ft::pair<typename RedBlackTree<Key,Val,Compare,Alloc>::iterator,bool>
		RedBlackTree<Key,Val,Compare,Alloc>::insert(const value_type& val)
		{
			return (_M_insert_node(val));
		}

	/* debug **************************************************************** */

	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::write_node(std::ofstream& outfile, node_pointer node)
		{
			if (node->_M_value.first != 0)
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
			else
			{
				outfile << "\n    \"sentinel\\n" << node << "\"";
			}
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::write_node_next(std::ofstream& outfile, node_pointer node)
		{
			if (node->_M_value.first != 0)
			{
				outfile << " -> \""
						<< node->_M_value.first << "=" << node->_M_value.second
						<< "\\n" << node << "\";";
			}
			else
			{
				outfile << " -> \"sentinel\\n" << node << "\"";
			}
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::write_leaf(std::ofstream& outfile, char side, int count)
		{
			outfile << " -> leaf_" << side << "_" << count << ";";
			outfile << "\n    leaf_" << side << "_" << count << " [shape=plain];";
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::write_branch(std::ofstream& outfile, node_pointer node)
		{
			static int	count = 0;

			write_node(outfile, node);
			if (node->_M_left)
			{
				write_node_next(outfile, node->_M_left);
				write_branch(outfile, node->_M_left);
			}
			else if (!node->_M_left)
				write_leaf(outfile, 'L', count++);
			write_node(outfile, node);
			if (node->_M_right)
			{
				write_node_next(outfile, node->_M_right);
				write_branch(outfile, node->_M_right);
			}
			else if (!node->_M_right)
				write_leaf(outfile, 'R', count++);
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::write_tree_dot(void)
		{
			std::string		filename = "ast.dot";
			std::ofstream	outfile;

			if (size() == 0)
				return ;

			outfile.open(filename.c_str(), std::ios::out);

			if ( !outfile.is_open() )
			{
				std::cout << "Error: Unable to open \'" << filename << "\'" << std::endl;
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
			std::cout << "Successfully created " << filename << " in working dir" << std::endl;
			system("dot -Tsvg ast.dot -o ast.svg");
		}

} // namespace ft

#endif
