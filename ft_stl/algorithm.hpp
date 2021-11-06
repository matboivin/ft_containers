/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:28:28 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/07 00:06:33 by mboivin          ###   ########.fr       */
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
	/*
	 * Test whether the elements in two ranges are equal
	 *
	 * @param first1, last1  Input iterators to the initial and final positions
	 *                       of the first sequence
	 * @param first2         Input iterator to the initial position of the second sequence
	 *
	 * @return  true if all the elements in the range [first1,last1) compare equal to
	 *          those of the range starting at first2
	 *          false otherwise
	 */
	template<typename InputIterator1, typename InputIterator2>
		bool
		equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
		{
			for ( ; first1 != last1; ++first1, ++first2 )
			{
				if ( !(*first1 == *first2) )
					return (false);
			}
			return (true);
		}

	/*
	 * Test whether the elements in two ranges are equal
	 *
	 * @param first1, last1  Input iterators to the initial and final positions
	 *                       of the first sequence
	 * @param first2         Input iterator to the initial position of the second sequence
	 * @param pred           Binary function that accepts two elements as argument and
	 *                       returns a value convertible to bool
	 *
	 * @return  true if all the elements in the range [first1,last1) compare equal to
	 *          those of the range starting at first2
	 *          false otherwise
	 */
	template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
		bool
		equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
			BinaryPredicate pred)
		{
			for ( ; first1 != last1; ++first1, ++first2 )
			{
				if ( !pred(*first1, *first2) )
					return (false);
			}
			return (true);
		}

	/*
	 * Lexicographical less-than comparison
	 *
	 * @param first1, last1  Input iterators to the initial and final positions
	 *                       of the first sequence
	 * @param first2, last2  Input iterators to the initial and final positions
	 *                       of the second sequence
	 *
	 * @return  true if the first range compares lexicographically less than the second
	 *          false otherwise
	 */
	template<typename InputIterator1, typename InputIterator2>
		bool
		lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
		{
			for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2 )
			{
				if (*first1 < *first2)
					return (true);
				if (*first1 > *first2)
					return (false);
			}
			return ( (first1 == last1) && (first2 != last2) );
		}

	/*
	 * Lexicographical less-than comparison
	 *
	 * @param first1, last1  Input iterators to the initial and final positions
	 *                       of the first sequence
	 * @param first2, last2  Input iterators to the initial and final positions
	 *                       of the second sequence
	 * @param comp           Comparison function which returns ​true if the first
	 *                       argument is less than the second
	 *
	 * @return  true if the first range compares lexicographically less than the second
	 *          false otherwise
	 */
	template<typename InputIterator1, typename InputIterator2, typename Compare>
		bool
		lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2,
								Compare comp)
		{
			for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2 )
			{
				if ( comp(*first1, *first2) )
					return (true);
				if ( comp(*first2, *first1) )
					return (false);
			}
			return ( (first1 == last1) && (first2 != last2) );
		}
} // namespace ft

#endif
