/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:29:54 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/27 15:29:15 by mboivin          ###   ########.fr       */
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
	struct is_integral_type : public false_type {};

	// specializations to return true for integral types
	template<>
	struct is_integral_type<bool> : public true_type {};

	template<>
	struct is_integral_type<char> : public true_type {};

	template<>
	struct is_integral_type<wchar_t> : public true_type {};

	template<>
	struct is_integral_type<signed char> : public true_type {};

	template<>
	struct is_integral_type<short int> : public true_type {};

	template<>
	struct is_integral_type<int> : public true_type {};

	template<>
	struct is_integral_type<long int> : public true_type {};

	template<>
	struct is_integral_type<long long int> : public true_type {};

	template<>
	struct is_integral_type<unsigned char> : public true_type {};

	template<>
	struct is_integral_type<unsigned short int> : public true_type {};

	template<>
	struct is_integral_type<unsigned int> : public true_type {};

	template<>
	struct is_integral_type<unsigned long int> : public true_type {};

	template<>
	struct is_integral_type<unsigned long long int> : public true_type {};

	/*
	 * Trait class that identifies whether T is an integral type
	 *
	 * @param T  A type
	 */
	template< typename T >
	struct is_integral : public is_integral_type<T> {};

	/*
	 * The type T is defined only if Cond is true
	 *
	 * @param Cond  A compile-time constant of type bool
	 * @param T     A type
	 */
	template< bool Cond, typename T = void >
	struct enable_if {};

	template< typename T >
	struct enable_if<true, T> {
		typedef T	type;
	};

}

#endif
