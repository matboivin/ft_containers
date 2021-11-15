/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:53:39 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/15 18:25:30 by mboivin          ###   ########.fr       */
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
	struct _RedBlackTreeNode
	{
		// types
		typedef _RedBlackTreeNode*			node_pointer;
		typedef const _RedBlackTreeNode*	const_node_pointer;
		// attributes
		NodeColor		_M_color;
		node_pointer	_M_parent;
		node_pointer	_M_left;
		node_pointer	_M_right;

		// Get node holding lower value
		static node_pointer
		_getLeftmost(node_pointer x)
		{
			while (x->_M_left != 0)
				x = x->_M_left;
			return (x);
		}

		static const_node_pointer
		_getLeftmost(const_node_pointer x)
		{
			while (x->_M_left != 0)
				x = x->_M_left;
			return (x);
		}

		// Get node holding greater value
		static node_pointer
		_getRightmost(node_pointer x)
		{
			while (x->_M_right != 0)
				x = x->_M_right;
			return (x);
		}

		static const_node_pointer
		_getRightmost(const_node_pointer x)
		{
			while (x->_M_right != 0)
				x = x->_M_right;
			return (x);
		}
	};

	// Node struct
	template<typename Val>
		struct RedBlackTreeNode : public _RedBlackTreeNode
		{
			// types
			typedef RedBlackTreeNode<Val>*	link_type;

			// attributes
			Val	_M_value;

			Val*		_M_valuePtr(void)       { return (&this->_M_valuePtr); }
			const Val*	_M_valuePtr(void) const { return (&this->_M_valuePtr); }
		};

	template<typename Key, typename Val, typename Compare,
			 typename Alloc = std::allocator<Val> >
		class RedBlackTree
		{
		protected:
			// types
			typedef _RedBlackTreeNode*				node_pointer;
			typedef const _RedBlackTreeNode*		const_node_pointer;
			typedef RedBlackTreeNode<Val>*			link_type;
			typedef const RedBlackTreeNode<Val>*	const_link_type;

			// typedef Key								key_type;
			// typedef Val								value_type;
			// typedef value_type*						pointer;
			// typedef const value_type*				const_pointer;
			// typedef value_type&						reference;
			// typedef const value_type&				const_reference;
			// typedef std::ptrdiff_t					difference_type;
			typedef Alloc							allocator_type;

		private:
			typedef typename allocator_type::template rebind<RedBlackTreeNode<Val> >::other	_node_alloc_type;

			// attributes
			allocator_type	_M_alloc; // internal copy of the allocator
			node_pointer	_M_root;
			node_pointer	_M_nodes;

			// key_type	_M_get_Key(value_type x)
			// {
			// 	return ();
			// }

		public:
			// default constructor
			RedBlackTree(void) : _M_alloc(allocator_type()) {}
			// copy constructor
			RedBlackTree(const RedBlackTree& other) : _M_alloc(other._M_alloc) {}
			// copy assignment operator
			RedBlackTree&	operator=(const RedBlackTree& other)
			{
				if (this != &other)
					//
				return (*this);
			};
			// destructor
			~RedBlackTree(void) {};
		};
} // namespace ft

#endif
