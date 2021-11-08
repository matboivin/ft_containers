/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:53:39 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/08 19:48:31 by mboivin          ###   ########.fr       */
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

	struct _RedBlackTreeNode
	{
		// types
		typedef _RedBlackTreeNode*			base_pointer;
		typedef const _RedBlackTreeNode*	const_base_pointer;

		// attributes
		NodeColor		_M_color;
		base_pointer	_M_parent;
		base_pointer	_M_left;
		base_pointer	_M_right;
	};

	template<typename T>
		struct RedBlackTreeNode : public ARedBlackTreeNode
		{
			// types
			typedef T						value_type;
			typedef RedBlackTreeNode<T>*	link_type;

			// attributes
			value_type	_M_value_field;
		};

	template<typename T, typename Alloc = std::allocator<T> >
		class RedBlackTree
		{
		public:
			// types
			typedef Alloc							allocator_type;
			typedef RedBlackTreeNode_base*			base_pointer;
			typedef const RedBlackTreeNode_base*	const_base_pointer;
			typedef RedBlackTreeNode<T>*			link_type;

		private:
			// attributes
			allocator_type	_M_alloc; // internal copy of the allocator

		public:
			// default constructor
			RedBlackTree(void);
			// copy constructor
			RedBlackTree(const RedBlackTree& other);
			// copy assignment operator
			RedBlackTree&	operator=(const RedBlackTree& other);
			// destructor
			~RedBlackTree(void);
		};
} // namespace ft

#endif
