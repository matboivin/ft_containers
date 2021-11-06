/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:52:44 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/07 00:06:08 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

/*
 * This header contains utilities to create pairs objects
 */

namespace ft
{
	/* Pair definition ****************************************************** */

	/*
	 * Represents a pair of values which may be from different types
	 */
	template<typename T1, typename T2>
		struct pair
		{
			// types
			typedef T1	first_type;
			typedef T2	second_type;

			// attributes
			T1	first;
			T2	second;

			// constructor
			pair(void);

			// copy constructor
			template<typename U, typename V>
			pair(const pair<U,V>& pr);

			// initialization constructor
			pair(const first_type& a, const second_type& b);
		};

		/* Pair implementation ************************************************** */

		/* construct/copy/destroy *********************************************** */

		template<typename T1, typename T2>
			pair<T1,T2>::pair(void)
			{
				//
			}

		template<typename T1, typename T2>

		template<typename T1, typename T2>
} // namespace ft

#endif
