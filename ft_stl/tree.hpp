/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:53:39 by mboivin           #+#    #+#             */
/*   Updated: 2021/12/21 01:17:39 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include <cstdlib> // system
#include <fstream> // debug
#include <iostream> // debug
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
			int				_M_sentinel;

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
					node_pointer	__parent = x->_M_parent;

					while (x == __parent->_M_right)
					{
						x = __parent;
						if (x->_M_sentinel == 1)
							break ;
						__parent = __parent->_M_parent;
					}
					if (x != __parent)
						x = __parent;
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
					node_pointer	__parent = x->_M_parent;

					while (x == __parent->_M_right)
					{
						x = __parent;
						if (x->_M_sentinel == 1)
							break ;
						__parent = __parent->_M_parent;
					}
					if (x != __parent)
						x = __parent;
				}
				return (x);
			}

			// Decrement node
			static node_pointer	_decrement_node(node_pointer x)
			{
				if (x->_M_sentinel == 1)
				{
					x = x->_M_right;
				}
				else if (x->_M_left != 0)
				{
					x = x->_M_left;
					while (x->_M_right != 0)
						x = x->_M_right;
				}
				else
				{
					node_pointer	__parent = x->_M_parent;

					while (x == __parent->_M_left)
					{
						x = __parent;
						__parent = __parent->_M_parent;
					}
					x = __parent;
				}
				return (x);
			}

			static const_node_pointer	_decrement_node(const_node_pointer x)
			{
				if (x->_M_sentinel == 1)
				{
					x = x->_M_right;
				}
				else if (x->_M_left != 0)
				{
					x = x->_M_left;
					while (x->_M_right != 0)
						x = x->_M_right;
				}
				else
				{
					node_pointer	__parent = x->_M_parent;

					while (x == __parent->_M_left)
					{
						x = __parent;
						__parent = __parent->_M_parent;
					}
					x = __parent;
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

			// swap data
			void	_M_swap(RBTreeHeader& other)
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

			void	_M_copy_reset(RBTreeHeader& other)
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

			// set defaults
			void	_M_reset(void)
			{
				_M_header._M_color = RED;
				_M_header._M_parent = 0; // will be the root
				_M_header._M_left = &_M_header; // leftmost
				_M_header._M_right = &_M_header; // rightmost
				_M_header._M_sentinel = 1;
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

	// Relational operators

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
			typedef const T&								reference;
			typedef const T*								pointer;
			typedef RBtree_iterator<T>						iterator;
			typedef typename ft::bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t							difference_type;
			typedef const RBTreeNode<T>*					const_node_pointer;

			const_node_pointer	_M_node; // copy of the original iterator

			// default constructor
			RBtree_const_iterator(void)
			: _M_node(0)
			{
			}

			// initalization constructor
			RBtree_const_iterator(const_node_pointer x)
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
			const_node_pointer	get_node(void) const
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

	// Relational operators

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
	template<typename Key,
			 typename Val,
			 typename Compare = std::less<Key>,
			 typename Alloc = std::allocator<Val> >
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
			// aliases
			typedef typename allocator_type::template rebind<RBTreeNode<Val> >::other	_node_alloc_type;
			typedef typename ft::pair<iterator,bool>									_pair_it_bool;

			// attributes
			allocator_type	_M_alloc; // internal copy of the allocator
			key_compare		_M_key_compare;

		protected:
			// helpers
			node_pointer				_M_allocate_node(void);
			void						_M_construct_node(node_pointer __node, const value_type& __val);
			node_pointer				_M_create_node(const value_type& __val);
			void						_M_destroy_node(node_pointer __node);
			void						_M_deallocate_node(node_pointer __node);
			void						_M_drop_node(node_pointer __node);
			void						_M_erase(node_pointer __node);
			node_pointer				_M_get_root(void) const;
			node_pointer				_M_get_end(void) const;
			node_pointer				_M_get_leftmost(void) const;
			node_pointer				_M_get_rightmost(void) const;
			const key_type&				_M_get_key(node_pointer __node) const;
			const key_type&				_M_get_key(const_node_pointer __node) const;
			const_reference				_M_get_value(node_pointer __node) const;
			const_reference				_M_get_value(const_node_pointer __node) const;
			node_pointer				_M_get_pos_from_hint(iterator __hint, const key_type& __key);
			ft::pair<node_pointer,bool>	_M_get_insert_pos(iterator __hint, const key_type& __key);
			void						_M_rotate_left(node_pointer __x);
			void						_M_rotate_right(node_pointer __x);
			void						_M_rebalance(node_pointer __node);
			void						_M_insert(bool insert_left,
												  node_pointer __node, node_pointer __parent);
			ft::pair<iterator,bool>		_M_insert_node(iterator __pos, const value_type& __val);

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
			ft::pair<iterator,bool>	insert(const value_type& val);
			iterator				insert(iterator position, const value_type& val);
			template<typename InputIterator>
				void				insert(InputIterator first, InputIterator last,
										   typename ft::enable_if<ft::is_same<typename InputIterator::value_type,
										   										value_type>::value>::type* = 0);
			// void				erase(iterator position);
			// size_type			erase(const key_type& k);
			// void				erase(iterator first, iterator last);
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
			ft::pair<iterator,iterator>				equal_range(const key_type& k);
			ft::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;

			// debug
			static void	write_node(std::ofstream& outfile, node_pointer node);
			static void	write_node_next(std::ofstream& outfile, node_pointer node);
			static void	write_leaf(std::ofstream& outfile, char side, int count);
			static void	write_branch(std::ofstream& outfile, node_pointer node);
			void		write_tree_dot(const std::string& filename);
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
			__node->_M_sentinel = 0;
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
			return (static_cast<const key_type&>(_M_get_value(__node).first));
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		const typename RedBlackTree<Key,Val,Compare,Alloc>::key_type&
		RedBlackTree<Key,Val,Compare,Alloc>::_M_get_key(const_node_pointer __node) const
		{
			return (static_cast<const key_type&>(_M_get_value(__node).first));
		}

	// Get pair<key,value>
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::const_reference
		RedBlackTree<Key,Val,Compare,Alloc>::_M_get_value(node_pointer __node) const
		{
			return (*__node->_get_value_ptr());
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::const_reference
		RedBlackTree<Key,Val,Compare,Alloc>::_M_get_value(const_node_pointer __node) const
		{
			return (*__node->_get_value_ptr());
		}

	// Gets position to insert new node
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::node_pointer
		RedBlackTree<Key,Val,Compare,Alloc>::_M_get_pos_from_hint(iterator __hint, const key_type& __key)
		{
			// decrement if hint is past the last element
			if (__hint == end())
				--__hint;

			if (__hint._M_node == this->_M_header._M_parent)
				return (__hint._M_node);

			// find nearest position if hint is not root
			iterator	__prev(__hint);

			// node < hint pos
			if (_M_key_compare( __key, _M_get_key(__hint._M_node) ))
			{
				// node < root && root < hint pos
				if (_M_key_compare( __key, _M_get_key(this->_M_header._M_parent))
					&& _M_key_compare( _M_get_key(this->_M_header._M_parent), _M_get_key(__hint._M_node) ))
				{
					__hint = this->_M_header._M_parent; // start from root directly
				}
				else
				{
					--__hint;
					while (__hint._M_node && _M_key_compare(__key, _M_get_key(__hint._M_node)))
					{
						__prev = __hint;
						--__hint;
					}
				}
			}
			else if (_M_key_compare(_M_get_key(__hint._M_node), __key)) // node > hint pos
			{
				// node > root && root > hint pos
				if (_M_key_compare( _M_get_key(this->_M_header._M_parent),  __key)
					&& _M_key_compare( _M_get_key(__hint._M_node), _M_get_key(this->_M_header._M_parent) ))
				{
					__hint = this->_M_header._M_parent; // start from root directly
				}
				else
				{
					++__hint;
					while (__hint._M_node && _M_key_compare(_M_get_key(__hint._M_node), __key))
					{
						__prev = __hint;
						++__hint;
					}
				}
			}
			return (__hint._M_node);
		}

	// Gets position to insert new node
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename ft::pair<typename RedBlackTree<Key,Val,Compare,Alloc>::node_pointer,bool>
		RedBlackTree<Key,Val,Compare,Alloc>::_M_get_insert_pos(iterator __hint, const key_type& __key)
		{
			bool			__insert_left = true;
			node_pointer	__pos;

			// check whether the new node is lower than the current leftmost node
			if ( _M_key_compare( __key, _M_get_key(_M_get_leftmost()) ) )
			{
				__pos = _M_get_leftmost();
			}
			// check whether the new node is greater than the current rightmost node
			else if ( _M_key_compare(_M_get_key(_M_get_rightmost()), __key ) )
			{
				__insert_left = false;
				__pos = _M_get_rightmost();
			}
			// else move down the tree until finding a leaf
			else
			{
				node_pointer	__cursor = _M_get_pos_from_hint(__hint, __key);

				__pos = __cursor;

				while (__cursor != 0)
				{
					__pos = __cursor;

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
						return (ft::pair<node_pointer,bool>(__cursor, 0));
					}
				}
			}
			return (ft::pair<node_pointer,bool>(__pos, __insert_left));
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
			while ((__node != this->_M_header._M_parent) && (__node->_M_parent->_M_color == RED))
			{
				node_pointer	__grand_parent = __node->_M_parent->_M_parent;

				if (__node->_M_parent == __grand_parent->_M_left)
				{
					node_pointer	__uncle = __grand_parent->_M_right;

					if (__uncle && __uncle->_M_color == RED) // uncle is red
					{
						__node->_M_parent->_M_color = BLACK;
						__uncle->_M_color = BLACK;
						__grand_parent->_M_color = RED;
						__node = __grand_parent;
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
						if (__grand_parent != this->_M_header._M_parent)
							__grand_parent->_M_color = RED;
					}
				}
				else
				{
					node_pointer	__uncle = __grand_parent->_M_left;

					if (__uncle && __uncle->_M_color == RED) // uncle is red
					{
						__node->_M_parent->_M_color = BLACK;
						__uncle->_M_color = BLACK;
						__grand_parent->_M_color = RED;
						__node = __grand_parent;
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
						if (__grand_parent != this->_M_header._M_parent)
							__grand_parent->_M_color = RED;
					}
				}
			}
			this->_M_header._M_parent->_M_color = BLACK;
		}

	// Actually perform the insertion
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

	// Inserts one node with no hint
	template<typename Key, typename Val, typename Compare, typename Alloc>
		ft::pair<typename RedBlackTree<Key,Val,Compare,Alloc>::iterator,bool>
		RedBlackTree<Key,Val,Compare,Alloc>::_M_insert_node(iterator __pos, const value_type& __val)
		{
			const key_type				__key = __val.first;
			ft::pair<node_pointer,bool>	__res = _M_get_insert_pos(__pos, __key);

			if ((__res.first != this->end().get_node()) && (_M_get_key(__res.first) == __key)) // key already exists
				return (_pair_it_bool(iterator(__res.first), false));

			node_pointer	__node = _M_create_node(__val);

			_M_insert(__res.second, __node, __res.first);
			return (_pair_it_bool(iterator(__node), true));
		}

	/* construct/copy/destroy *********************************************** */

	// default constructor
	template<typename Key, typename Val, typename Compare, typename Alloc>
		RedBlackTree<Key,Val,Compare,Alloc>::RedBlackTree(const key_compare& comp, const allocator_type& alloc)
		: _M_alloc(alloc),
		  _M_key_compare(comp)
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

				const_iterator	first = other.begin();
				const_iterator	last = other.end();

				while (first != last)
				{
					_M_insert_node(end(), *first);
					++first;
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

	// Returns an iterator pointing to the first element in the tree
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

	// Returns an iterator representing the past-the-end element in the tree
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

	// Returns a reverse iterator pointing to the last element in the tree
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::reverse_iterator
		RedBlackTree<Key,Val,Compare,Alloc>::rbegin(void)
		{
			return (reverse_iterator(end()));
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::const_reverse_iterator
		RedBlackTree<Key,Val,Compare,Alloc>::rbegin(void) const
		{
			return (const_reverse_iterator(end()));
		}

	/*
	 * Returns a reverse iterator pointing to the theoretical element preceding
	 * the first element in the tree
	 */
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::reverse_iterator
		RedBlackTree<Key,Val,Compare,Alloc>::rend(void)
		{
			return (reverse_iterator(begin()));
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::const_reverse_iterator
		RedBlackTree<Key,Val,Compare,Alloc>::rend(void) const
		{
			return (const_reverse_iterator(begin()));
		}

	/* capacity ************************************************************* */

	// Returns true if the tree is empty, false otherwise
	template<typename Key, typename Val, typename Compare, typename Alloc>
		bool
		RedBlackTree<Key,Val,Compare,Alloc>::empty(void) const
		{
			return (this->_M_node_count == 0);
		}

	// Returns the number of nodes in the tree
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::size_type
		RedBlackTree<Key,Val,Compare,Alloc>::size(void) const
		{
			return (this->_M_node_count);
		}

	/*
	 * Gets the maximum number of elements that the tree can hold.
	 *
	 * This is the maximum potential size the container can reach due to known system
	 * or library implementation limitations.
	 */
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::size_type
		RedBlackTree<Key,Val,Compare,Alloc>::max_size(void) const
		{
			return (this->get_node_alloc().max_size());
		}

	/* modifiers ************************************************************ */

	// Inserts a new element
	template<typename Key, typename Val, typename Compare, typename Alloc>
		ft::pair<typename RedBlackTree<Key,Val,Compare,Alloc>::iterator,bool>
		RedBlackTree<Key,Val,Compare,Alloc>::insert(const value_type& val)
		{
			return (_M_insert_node(iterator(_M_get_root()), val));
		}

	// Inserts a new element with a hint for the position
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::iterator
		RedBlackTree<Key,Val,Compare,Alloc>::insert(iterator position, const value_type& val)
		{
			return (_M_insert_node(position, val).first);
		}

	// Inserts a range of new elements
	template<typename Key, typename Val, typename Compare, typename Alloc>
	template<typename InputIterator>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::insert(InputIterator first, InputIterator last,
													typename ft::enable_if<ft::is_same<typename InputIterator::value_type,
													value_type>::value>::type*)
		{
			while (first != last)
			{
				_M_insert_node(end(), *first);
				++first;
			}
		}

	// Exchanges the content of the tree and the other tree
	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::swap(RedBlackTree& other)
		{
			if (this == &other)
				return ;

			key_compare	tmp(this->_M_key_compare);

			this->_M_key_compare = other._M_key_compare;
			other._M_key_compare = tmp;

			if (size() && other.size())
				this->_M_swap(other);
			else if (other.size())
				this->_M_copy_reset(other);
			else
				other._M_copy_reset(*this);
		}

	// Destroys all elements from the tree, leaving it with a size of 0
	template<typename Key, typename Val, typename Compare, typename Alloc>
		void
		RedBlackTree<Key,Val,Compare,Alloc>::clear(void)
		{
			_M_erase(this->_M_header._M_parent);
			this->_M_reset();
		}

	/* lookup *************************************************************** */

	// Gets the element with the key k, else return end
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::iterator
		RedBlackTree<Key,Val,Compare,Alloc>::find(const key_type& k)
		{
			iterator	it = begin();
			iterator	ite = end();

			while (it != ite)
			{
				if (k == _M_get_key(it._M_node))
					return (it);
				++it;
			}
			return (ite);
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::const_iterator
		RedBlackTree<Key,Val,Compare,Alloc>::find(const key_type& k) const
		{
			const_iterator	it = begin();
			const_iterator	ite = end();

			while (it != ite)
			{
				if (k == _M_get_key(it._M_node))
					return (it);
				++it;
			}
			return (ite);
		}

	// Returns the number of elements matching key k
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::size_type
		RedBlackTree<Key,Val,Compare,Alloc>::count(const key_type& k) const
		{
			size_type		count = 0;
			const_iterator	it = this->find(k);

			while ((it != this->end()) && (k == _M_get_key(it._M_node)))
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
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::iterator
		RedBlackTree<Key,Val,Compare,Alloc>::lower_bound(const key_type& k)
		{
			iterator	it = begin();
			iterator	ite = end();

			while (it != ite)
			{
				if (!_M_key_compare(_M_get_key(it._M_node), k)) // k <= elem
					return (it);
				++it;
			}
			return (ite);
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::const_iterator
		RedBlackTree<Key,Val,Compare,Alloc>::lower_bound(const key_type& k) const
		{
			const_iterator	it = begin();
			const_iterator	ite = end();

			while (it != ite)
			{
				if (!_M_key_compare(_M_get_key(it._M_node), k)) // k <= elem
					return (it);
				++it;
			}
			return (ite);
		}

	/*
	 * Gets the first element that is after k
	 * i.e. The first element for which key_comp(k,element_key) would return true
	 */
	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::iterator
		RedBlackTree<Key,Val,Compare,Alloc>::upper_bound(const key_type& k)
		{
			iterator	it = begin();
			iterator	ite = end();

			while (it != ite)
			{
				if (_M_key_compare(k, _M_get_key(it._M_node))) // k < elem
					return (it);
				++it;
			}
			return (ite);
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		typename RedBlackTree<Key,Val,Compare,Alloc>::const_iterator
		RedBlackTree<Key,Val,Compare,Alloc>::upper_bound(const key_type& k) const
		{
			const_iterator	it = begin();
			const_iterator	ite = end();

			while (it != ite)
			{
				if (_M_key_compare(k, _M_get_key(it._M_node))) // k < elem
					return (it);
				++it;
			}
			return (ite);
		}

	/*
	 * Returns the bounds of a range that have a key equivalent to k.
	 * If k is not found, returns two iterators pointing to the first element after k.
	 */
	template<typename Key, typename Val, typename Compare, typename Alloc>
		ft::pair<typename RedBlackTree<Key,Val,Compare,Alloc>::iterator,typename RedBlackTree<Key,Val,Compare,Alloc>::iterator>
		RedBlackTree<Key,Val,Compare,Alloc>::equal_range(const key_type& k)
		{
			iterator	first = lower_bound(k);
			iterator	last = upper_bound(k);

			return (ft::pair<iterator,iterator>(first, last));
		}

	template<typename Key, typename Val, typename Compare, typename Alloc>
		ft::pair<typename RedBlackTree<Key,Val,Compare,Alloc>::const_iterator,typename RedBlackTree<Key,Val,Compare,Alloc>::const_iterator>
		RedBlackTree<Key,Val,Compare,Alloc>::equal_range(const key_type& k) const
		{
			const_iterator	first = lower_bound(k);
			const_iterator	last = upper_bound(k);

			return (ft::pair<const_iterator,const_iterator>(first, last));
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
		RedBlackTree<Key,Val,Compare,Alloc>::write_tree_dot(const std::string& filename)
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
			std::cout << "Successfully created " << filename_dot << " in working dir" << std::endl;

			// std::string	dot_cmd = "dot -Tsvg ";
			// dot_cmd += filename;
			// dot_cmd += ".dot -o ";
			// dot_cmd += filename;
			// dot_cmd += ".svg";
			// system(dot_cmd.c_str());
		}

} // namespace ft

#endif
