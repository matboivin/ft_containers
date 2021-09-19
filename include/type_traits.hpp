/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:29:54 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/19 23:41:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

/*
 * This header defines a series of classes to obtain type information on compile-time
 */

namespace ft {

	/*
	 * Trait class that identifies whether T is an integral type
	 *
	 * @param T  A type
	 */
	template< typename T > struct is_integral;

	/*
	 * If B is true, enable_if has a public member typedef type, equal to T;
	 * otherwise, there is no member typedef
	 */
	template< bool B, typename T = void > struct enable_if;

}

#endif
