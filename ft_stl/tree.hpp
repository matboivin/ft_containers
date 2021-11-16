/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:53:39 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/16 16:26:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include <memory>

namespace ft
{
	enum NodeColor
	{
		RED = 0,
		BLACK = 1
	};

	// Base node
	template<typename Val>
		struct RedBlackTreeNode
		{
			// types
			typedef RedBlackTreeNode<Val>*			node_pointer;
			typedef const RedBlackTreeNode<Val>*	const_node_pointer;

			// attributes
			NodeColor		_M_color;
			std::size_t		_M_weight;
			node_pointer	_M_parent;
			node_pointer	_M_left;
			node_pointer	_M_right;
			Val				_M_value;

			// getters
			Val*		_get_value_ptr(void)       { return (&this->_M_value); }
			const Val*	_get_value_ptr(void) const { return (&this->_M_value); }

			// Get node holding lower value
			static node_pointer	_getLeftmost(node_pointer x)
			{
				while (x->_M_left != 0)
					x = x->_M_left;
				return (x);
			}

			static const_node_pointer	_getLeftmost(const_node_pointer x)
			{
				while (x->_M_left != 0)
					x = x->_M_left;
				return (x);
			}

			// Get node holding greater value
			static node_pointer	_getRightmost(node_pointer x)
			{
				while (x->_M_right != 0)
					x = x->_M_right;
				return (x);
			}

			static const_node_pointer	_getRightmost(const_node_pointer x)
			{
				while (x->_M_right != 0)
					x = x->_M_right;
				return (x);
			}
		};

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
			typedef value_type*						pointer;
			typedef const value_type*				const_pointer;
			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef std::ptrdiff_t					difference_type;
			typedef RedBlackTreeNode<Val>*			node_pointer;
			typedef const RedBlackTreeNode<Val>*	const_node_pointer;

		private:
			// aliases
			typedef typename allocator_type::template rebind<RedBlackTreeNode<Val> >::other	_node_alloc_type;

			// attributes
			allocator_type	_M_alloc; // internal copy of the allocator
			std::size_t		_M_node_count;
			node_pointer	_M_root;
			node_pointer	_M_nodes;

		protected:
			// helpers
			node_pointer	_M_allocate_node(void)
			{
				return (this->get_node_alloc().allocate(1));
			}

			void	_M_construct_node(node_pointer __node, const value_type& __val)
			{
				this->_M_alloc.construct(__node->_get_value_ptr(), __val);
			}

			node_pointer	_M_create_node(const value_type& __val)
			{
				node_pointer	__node = this->_M_allocate_node();

				_M_construct_node(__node, __val);
				__node->_M_color = RED;
				__node->_M_weight = 0;
				__node->_M_parent = 0;
				__node->_M_left = 0;
				__node->_M_right = 0;
				return (__node);
			}

			void	_M_destroy_node(node_pointer __node)
			{
				this->_M_alloc.destroy(__node->_get_value_ptr());
			}

			void	_M_deallocate_node(node_pointer __node)
			{
				if (__node)
					this->get_node_alloc().deallocate(__node, 1);
			}

			void	_M_drop_node(node_pointer __node)
			{
				_M_destroy_node(__node);
				_M_deallocate_node(__node);
			}

			void	_M_erase_recursive(node_pointer __node) // reverse in order
			{
				node_pointer	__tmp;

				while (__node != 0)
				{
					_M_erase_recursive(__node);
					__tmp = static_cast<node_pointer>(__node->_M_left);
					_M_drop_node(__node);
					__node = __tmp;
				}
			}

			node_pointer	_M_get_root(void)
			{
				return (this->_M_root);
			}

		public:
			// default constructor
			RedBlackTree(const allocator_type& alloc = allocator_type())
			: _M_alloc(alloc), _M_node_count(0), _M_root(), _M_nodes()
			{
				//
			}

			// copy constructor
			RedBlackTree(const RedBlackTree& other)
			: _M_alloc(other._M_alloc),
			  _M_node_count(other._M_node_count),
			  _M_root(other._M_root),
			  _M_nodes(other.M_nodes)
			{
			}

			// copy assignment operator
			RedBlackTree&	operator=(const RedBlackTree& other)
			{
				if (this != &other)
				{
					// _M_erase_recursive(node_pointer(this->_M_root));
					this->_M_node_count = other._M_node_count;
					// this->_M_root = other._M_root;
					// this->_M_nodes = other._M_nodes;
				}
				return (*this);
			}

			// destructor
			~RedBlackTree(void)
			{
				_M_erase_recursive(node_pointer(this->_M_root));
			}

			// allocator
			allocator_type	get_alloc(void) const
			{
				return (allocator_type(this->_M_alloc));
			}

			_node_alloc_type	get_node_alloc(void) const
			{
				return (_node_alloc_type(this->_M_alloc));
			}
		};
} // namespace ft

#endif
