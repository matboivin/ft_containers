/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:29:54 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/30 19:17:26 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

/* This header defines a series of classes to obtain type information on compile-time */

namespace ft
{
	/* This template is designed to provide compile-time constants as types */
	template<typename T, T v>
		struct integral_constant
		{
			static const T					value = v;
			typedef T						value_type;
			typedef integral_constant<T,v>	type;
			operator value_type() const { return (value); }
		};

	/* Represent true and false values */
	typedef integral_constant<bool,true>	true_type;
	typedef integral_constant<bool,false>	false_type;

	/* Remove const qualifier */
	template<typename T>
		struct remove_const
		{
			typedef T	type;
		};

	template<typename T>
		struct remove_const<const T>
		{
			typedef T	type;
		};

	/* Remove volatile qualifier */
	template<typename T>
		struct remove_volatile
		{
			typedef T	type;
		};

	template<typename T>
		struct remove_volatile<volatile T>
		{
			typedef T	type;
		};

	/* Remove const and volatile qualifiers */
	template<typename T>
		struct remove_cv
		{
			typedef typename remove_volatile<typename remove_const<T>::type>::type	type;
		};

	/* Helpers for is_integral */

	/* False by default */
	template<typename T>
		struct __is_integral_helper
		: public false_type { };

	/* Specializations to return true for integral types */
	template<>
		struct __is_integral_helper<bool>
		: public true_type { };

	template<>
		struct __is_integral_helper<char>
		: public true_type { };

	template<>
		struct __is_integral_helper<wchar_t>
		: public true_type { };

	template<>
		struct __is_integral_helper<signed char>
		: public true_type { };

	template<>
		struct __is_integral_helper<short int>
		: public true_type { };

	template<>
		struct __is_integral_helper<int>
		: public true_type { };

	template<>
		struct __is_integral_helper<long int>
		: public true_type { };

	template<>
		struct __is_integral_helper<unsigned char>
		: public true_type { };

	template<>
		struct __is_integral_helper<unsigned short int>
		: public true_type { };

	template<>
		struct __is_integral_helper<unsigned int>
		: public true_type { };

	template<>
		struct __is_integral_helper<unsigned long int>
		: public true_type { };

	/* Trait class that identifies whether T is an integral type */
	template<typename T>
		struct is_integral
		: public __is_integral_helper<typename remove_cv<T>::type>::type { };

	/* Trait class that identifies whether T is the same type as U */
	template<typename T, typename U>
		struct is_same : false_type { };

	template<typename T>
		struct is_same<T,T> : true_type { };

	/* The type T is defined only if Cond is true */
	template<bool Cond, typename T = void>
		struct enable_if { };

	template<typename T>
		struct enable_if<true, T>
		{
			typedef T	type;
		};
} // namespace ft

#endif
