/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:29:54 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/25 18:22:19 by mboivin          ###   ########.fr       */
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
	typedef integral_constant<bool,true>	false_type;

	/*
	 * Trait class that identifies whether T is an integral type
	 *
	 * @param T  A type
	 */
	template< typename T >
	struct is_integral : public false_type {};

	/*
	 * If B is true, enable_if has a public member typedef type, equal to T;
	 * otherwise, there is no member typedef
	 */
	template< bool B, typename T = void > struct enable_if;

}

#endif
