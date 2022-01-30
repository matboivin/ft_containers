/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:28:28 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/30 19:11:13 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

/*
 * This header defines a collection of functions especially designed to be used
 * on ranges of elements
 *
 * Credits:
 * Detailed comments mostly from www.cplusplus.com
 */

namespace ft
{
	/* Test whether the elements in two ranges are equal */
	template<typename InputIterator1, typename InputIterator2>
		bool
		equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
		{
			for ( ; first1 != last1; ++first1, ++first2)
			{
				if (!(*first1 == *first2))
					return (false);
			}
			return (true);
		}

	/* Test whether the elements in two ranges are equal */
	template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
		bool
		equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
			BinaryPredicate pred)
		{
			for ( ; first1 != last1; ++first1, ++first2)
			{
				if (!pred(*first1, *first2))
					return (false);
			}
			return (true);
		}

	/* Lexicographical less-than comparison */
	template<typename InputIterator1, typename InputIterator2>
		bool
		lexicographical_compare(
			InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
		{
			for ( ; first1 != last1 && first2 != last2; ++first1, ++first2)
			{
				if (*first1 < *first2)
					return (true);
				if (*first1 > *first2)
					return (false);
			}
			return (first1 == last1 && first2 != last2);
		}

	/* Lexicographical less-than comparison */
	template<typename InputIterator1, typename InputIterator2, typename Compare>
		bool
		lexicographical_compare(
			InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2,
			Compare comp)
		{
			for ( ; first1 != last1 && first2 != last2; ++first1, ++first2)
			{
				if (comp(*first1, *first2))
					return (true);
				if (comp(*first2, *first1))
					return (false);
			}
			return (first1 == last1 && first2 != last2);
		}
} // namespace ft

#endif
