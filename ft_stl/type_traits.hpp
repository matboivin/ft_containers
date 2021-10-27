/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:29:54 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/27 19:11:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

#include "iterator.hpp"

/*
 * This header defines a series of classes to obtain type information on compile-time
 *
 * Credits:
 * Detailed comments mostly from www.cplusplus.com
 */

namespace ft
{
	/*
	 * This template is designed to provide compile-time constants as types
	 *
	 * @param T  Type of the integral constant
	 * @param v  Value of the integral constant
	 */
	template<typename T, T v>
	struct integral_constant
	{
		static const T					value = v;
		typedef T						value_type;
		typedef integral_constant<T,v>	type;
		// integral_constant<T, v>() == integral_constant<T, v>::value
		operator value_type() const { return value; }
	};

	// Helpers to represent true and false values
	typedef integral_constant<bool,true>	true_type;
	typedef integral_constant<bool,false>	false_type;

	/*
	 * Helpers for is_integral
	 */

	// false by default
	template<typename T>
	struct type_is_integral : public false_type {};

	// specializations to return true for integral types
	template<>
	struct type_is_integral<bool> : public true_type {};

	template<>
	struct type_is_integral<char> : public true_type {};

	template<>
	struct type_is_integral<wchar_t> : public true_type {};

	template<>
	struct type_is_integral<signed char> : public true_type {};

	template<>
	struct type_is_integral<short int> : public true_type {};

	template<>
	struct type_is_integral<int> : public true_type {};

	template<>
	struct type_is_integral<long int> : public true_type {};

	template<>
	struct type_is_integral<long long int> : public true_type {};

	template<>
	struct type_is_integral<unsigned char> : public true_type {};

	template<>
	struct type_is_integral<unsigned short int> : public true_type {};

	template<>
	struct type_is_integral<unsigned int> : public true_type {};

	template<>
	struct type_is_integral<unsigned long int> : public true_type {};

	template<>
	struct type_is_integral<unsigned long long int> : public true_type {};

	/*
	 * Trait class that identifies whether T is an integral type
	 *
	 * @param T  A type
	 */
	template<typename T>
	struct is_integral : public type_is_integral<T> {};

	/*
	 * The type T is defined only if Cond is true
	 *
	 * @param Cond  A compile-time constant of type bool
	 * @param T     A type
	 */
	template<bool Cond, typename T = void>
	struct enable_if {};

	template<typename T>
	struct enable_if<true, T>
	{
		typedef T	type;
	};

	/*
	 * Helpers for iter_is_input
	 */

	// false by default
	template<typename Iter>
	struct iter_is_input : public false_type {};

	// specializations to return true for iterators that can be cast to input iterator
	template<>
	struct iter_is_input<ft::input_iterator_tag> : public true_type {};

	template<>
	struct iter_is_input<ft::forward_iterator_tag> : public true_type {};

	template<>
	struct iter_is_input<ft::bidirectional_iterator_tag> : public true_type {};

	template<>
	struct iter_is_input<ft::random_access_iterator_tag> : public true_type {};

	/*
	 * The type T is defined only if Cond (T is not an integral type) is true
	 *
	 * @param Cond  A compile-time constant of type bool
	 * @param T     A type
	 */

	template<bool Cond, typename T = void>
	struct requires_input_iter {};

	template<typename T>
	struct requires_input_iter<true, T>
	: public iter_is_input<typename ft::iterator_traits<T>::iterator_category>
	{
		typedef T	type;
	};
} // namespace ft

#endif
