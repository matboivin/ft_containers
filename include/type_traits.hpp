/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:29:54 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/25 19:22:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

/*
 * This header defines a series of classes to obtain type information on compile-time
 *
 * Credits:
 * Detailed comments mostly from www.cplusplus.com
 */

namespace ft {

	/*
	 * This template is designed to provide compile-time constants as types
	 *
	 * @param T  Type of the integral constant
	 * @param v  Value of the integral constant
	 */
	template< typename T, T v >
	struct integral_constant {

		static const T	value = v;
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
	template< typename T >
	struct base_is_integral : public false_type {};

	// specializations to return true for integral types
	template<>
	struct base_is_integral<bool> : public true_type {};

	template<>
	struct base_is_integral<char> : public true_type {};

	template<>
	struct base_is_integral<wchar_t> : public true_type {};

	template<>
	struct base_is_integral<signed char> : public true_type {};

	template<>
	struct base_is_integral<short int> : public true_type {};

	template<>
	struct base_is_integral<int> : public true_type {};

	template<>
	struct base_is_integral<long int> : public true_type {};

	template<>
	struct base_is_integral<long long int> : public true_type {};

	template<>
	struct base_is_integral<unsigned char> : public true_type {};

	template<>
	struct base_is_integral<unsigned short int> : public true_type {};

	template<>
	struct base_is_integral<unsigned int> : public true_type {};

	template<>
	struct base_is_integral<unsigned long int> : public true_type {};

	template<>
	struct base_is_integral<unsigned long long int> : public true_type {};

	/*
	 * Trait class that identifies whether T is an integral type
	 *
	 * @param T  A type
	 */
	template< typename T >
	struct is_integral : public base_is_integral<T> {};

	/*
	 * If B is true, enable_if has a public member typedef type, equal to T;
	 * otherwise, there is no member typedef
	 */
	template< bool B, typename T = void > struct enable_if;

}

#endif
