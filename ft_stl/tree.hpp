/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:53:39 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/17 21:07:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

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
	 * Red Black Tree template class
	 */
	template<typename Val>
		struct RedBlackTreeNode
		{
			// types
			typedef RedBlackTreeNode<Val>*			node_pointer;
			typedef const RedBlackTreeNode<Val>*	const_node_pointer;

			// attributes
			NodeColor		_M_color;
			node_pointer	_M_parent;
			node_pointer	_M_left;
			node_pointer	_M_right;
			Val				_M_value;

			// Retrieve the value address
			Val*		_get_value_ptr(void)
			{
				return (&this->_M_value);
			}

			const Val*	_get_value_ptr(void) const
			{
				return (&this->_M_value);
			}

			// Get node holding lower value
			static node_pointer			_get_leftmost(node_pointer x)
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
			static node_pointer			_get_rightmost(node_pointer x)
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
			static node_pointer			_increment_node(node_pointer x)
			{
				if (x->_M_right != 0)
				{
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
			static node_pointer			_decrement_node(node_pointer x)
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
		}; // struct RedBlackTreeNode

	/* RedBlackTree iterators *********************************************** */

	// RedBlackTree iterator
	template<typename T>
		struct RBtree_iterator
		{
			// types
			typedef T										value_type;
			typedef T&										reference;
			typedef T*										pointer;
			typedef typename ft::bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t							difference_type;
			typedef RedBlackTreeNode<T>*					node_pointer;

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

	// RedBlackTree const_iterator
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
			typedef RedBlackTreeNode<T>*					node_pointer;

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
				this->_M_node = _increment_node(this->_M_node);
				std::cout << "incr: " << _M_get_key(this->_M_node) << " => "
						  << _M_get_value(this->_M_node).second << std::endl; // debug
				return (*this);
			}

			RBtree_const_iterator	operator++(int)
			{
				RBtree_const_iterator	backup = *this;

				this->_M_node = _increment_node(this->_M_node);
				return (backup);
			}

			RBtree_const_iterator&	operator--(void)
			{
				this->_M_node = _decrement_node(this->_M_node);
				return (*this);
			}

			RBtree_const_iterator	operator--(int)
			{
				RBtree_const_iterator	backup = *this;

				this->_M_node = _decrement_node(this->_M_node);
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
		{
		protected:
			// types
			typedef Alloc							allocator_type;
			typedef Key								key_type;
			typedef Val								value_type;
			typedef Compare							key_compare;
			typedef value_type*						pointer;
			typedef const value_type*				const_pointer;
			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef std::ptrdiff_t					difference_type;
			typedef std::size_t						size_type;
			typedef RedBlackTreeNode<Val>*			node_pointer;
			typedef const RedBlackTreeNode<Val>*	const_node_pointer;

		public:
			// iterators
			typedef RBtree_iterator<Val>			iterator;
			typedef RBtree_const_iterator<Val>		const_iterator;

		private:
			// aliases
			typedef typename allocator_type::template rebind<RedBlackTreeNode<Val> >::other	_node_alloc_type;

			// attributes
			allocator_type	_M_alloc; // internal copy of the allocator
			key_compare		_M_key_compare;
			size_type		_M_node_count;
			node_pointer	_M_sentinel;
			node_pointer	_M_reverse_sentinel;
			node_pointer	_M_root;
			node_pointer	_M_minimum;
			node_pointer	_M_maximum;

		protected:
			// helpers
			node_pointer			_M_allocate_node(void);
			void					_M_construct_node(node_pointer __node, const value_type& __val);
			node_pointer			_M_create_node(const value_type& __val);
			void					_M_destroy_node(node_pointer __node);
			void					_M_deallocate_node(node_pointer __node);
			void					_M_drop_node(node_pointer __node);
			void					_M_erase_recursive(node_pointer __node);
			node_pointer			_M_get_root(void) const;
			node_pointer			_M_get_leftmost(void) const;
			node_pointer			_M_get_rightmost(void) const;
			const key_type&			_M_get_key(node_pointer __node) const;
			const_reference			_M_get_value(node_pointer __node) const;
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
			key_compare		key_comp(void) const;

			// iterators
			iterator		begin(void);
			const_iterator	begin(void) const;
			iterator		end(void);
			const_iterator	end(void) const;

			// capacity
			bool			empty(void) const;
			size_type		size(void) const;
			size_type		max_size(void) const;

			// modifiers
			ft::pair<iterator,bool>	insert(const value_type& val); // tmp
			void					clear(void);
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
			_M_destroy_node(__node);
			_M_deallocate_node(__node);
		}

	// Erase recursively the tree from the node passed as parameter
	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::_M_erase_recursive(node_pointer __node)
		{
			if (__node != 0) // reverse in order
			{
				std::cout << "erasing: " << _M_get_value(__node).first << std::endl;
				_M_erase_recursive(__node->_M_right);
				_M_erase_recursive(__node->_M_left);
				_M_drop_node(__node);
			}
		}

	// Get root node
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,Compare,Alloc>::_M_get_root(void) const
		{
			return (this->_M_root);
		}

	// Get node holding lower value
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,Compare,Alloc>::_M_get_leftmost(void) const
		{
			return (this->_M_root->_get_leftmost(this->_M_root));
		}

	// Get node holding greater value
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,Compare,Alloc>::_M_get_rightmost(void) const
		{
			return (this->_M_root->_get_rightmost(this->_M_root));
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

	// Insert a node
	template<typename Key, typename Val, typename Compare, typename Alloc>
		ft::pair<typename RedBlackTree<Key,Val,Compare,Alloc>::iterator,bool>
		RedBlackTree<Key,Val,Compare,Alloc>::_M_insert_node(const value_type& __val)
		{
			node_pointer	__node = _M_create_node(__val);

			if (this->_M_root == 0)
			{
				__node->_M_color = RED;
				this->_M_root = __node;
			}
			else
			{
				node_pointer	__cursor(_M_get_root());
				node_pointer	__parent = 0;
				bool			__insert_left = false;

				this->_M_minimum->_M_left = 0;
				this->_M_maximum->_M_right = 0;

				while (__cursor != 0)
				{
					__parent = __cursor;
					if (_M_key_compare(_M_get_key(__node), _M_get_key(__cursor)))
					{
						__cursor = __cursor->_M_left;
						__insert_left = true;
					}
					else if (_M_key_compare(_M_get_key(__cursor), _M_get_key(__node)))
					{
						__cursor = __cursor->_M_right;
						__insert_left = false;
					}
					else // key already exists
					{
						_M_drop_node(__node);
						return (ft::pair<iterator,bool>(iterator(__cursor), false));
					}
				}
				// todo: rebalance
				__cursor = __node;
				__node->_M_parent = __parent;
				if (__insert_left)
					__parent->_M_left = __node;
				else
					__parent->_M_right = __node;
				//
			}
			++this->_M_node_count;
			this->_M_minimum = _M_get_leftmost();
			this->_M_maximum = _M_get_rightmost();
			this->_M_minimum->_M_left = this->_M_sentinel;
			this->_M_maximum->_M_right = this->_M_reverse_sentinel;
			return (ft::pair<iterator,bool>(iterator(__node), true));
		}

	/* construct/copy/destroy *********************************************** */

	// default constructor
	template<typename Key, typename Val, typename Compare, typename Alloc>
		RedBlackTree<Key,Val,Compare,Alloc>::RedBlackTree(const allocator_type& alloc)
		: _M_alloc(alloc),
		  _M_key_compare(),
		  _M_node_count(0),
		  _M_sentinel(),
		  _M_reverse_sentinel(),
		  _M_root(),
		  _M_minimum(),
		  _M_maximum()
		{
			this->_M_sentinel = _M_create_node(value_type());
			this->_M_reverse_sentinel = _M_create_node(value_type());
		}

	// copy constructor
	template<typename Key, typename Val, typename Compare, typename Alloc>
		RedBlackTree<Key,Val,Compare,Alloc>::RedBlackTree(const RedBlackTree& other)
		: _M_alloc(other._M_alloc),
		  _M_key_compare(other._M_key_compare),
		  _M_node_count(other._M_node_count),
		  _M_sentinel(other._M_sentinel),
		  _M_reverse_sentinel(other._M_reverse_sentinel),
		  _M_root(other._M_root),
		  _M_minimum(other._M_minimum),
		  _M_maximum(other._M_maximum)
		{
		}

	// copy assignment operator
	template<typename Key, typename Val, typename Compare, typename Alloc>
		RedBlackTree<Key,Val,Compare,Alloc>&
		RedBlackTree<Key,Val,Compare,Alloc>::operator=(const RedBlackTree& other)
		{
			if (this != &other)
			{
				// _M_erase_recursive(this->_M_root);
				this->_M_key_compare = other._M_key_compare;
				this->_M_node_count = other._M_node_count;
				this->_M_sentinel = other._M_sentinel;
				// this->_M_root = other._M_root;
			}
			return (*this);
		}

	// destructor
	template<typename Key, typename Val, typename Compare, typename Alloc>
		RedBlackTree<Key,Val,Compare,Alloc>::~RedBlackTree(void)
		{
			_M_erase_recursive(this->_M_root);
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
			return (iterator(this->_M_minimum));
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::const_iterator
		RedBlackTree<Key,Val,Compare,Alloc>::begin(void) const
		{
			return (const_iterator(this->_M_minimum));
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::iterator
		RedBlackTree<Key,Val,Compare,Alloc>::end(void)
		{
			return (iterator(_M_sentinel));
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::const_iterator
		RedBlackTree<Key,Val,Compare,Alloc>::end(void) const
		{
			return (const_iterator(_M_sentinel));
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
			_M_erase_recursive(this->_M_root);
		}

	// tmp (insert from map)
	template<typename Key, typename Val, typename Compare, typename Alloc>
		ft::pair<typename RedBlackTree<Key,Val,Compare,Alloc>::iterator,bool>
		RedBlackTree<Key,Val,Compare,Alloc>::insert(const value_type& val)
		{
			return (_M_insert_node(val));
		}
	//

} // namespace ft

#endif
