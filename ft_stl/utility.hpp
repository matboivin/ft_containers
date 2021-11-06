/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:52:44 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/07 00:37:24 by mboivin          ###   ########.fr       */
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
				pair(const pair<U,V>& other);

			// initialization constructor
			pair(const first_type& x, const second_type& y);

			// copy assignment operator
			pair&	operator=(const pair& other);
		};

		// non-member function overloads

		// relational operators

		template<typename T1, typename T2>
			bool	operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

		template<typename T1, typename T2>
			bool	operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

		template<typename T1, typename T2>
			bool	operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

		template<typename T1, typename T2>
			bool	operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

		template<typename T1, typename T2>
			bool	operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

		template<typename T1, typename T2>
			bool	operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);


		/* Pair implementation ************************************************** */

		/* construct/copy/destroy *********************************************** */

		/* Default constructor */
		template<typename T1, typename T2>
			pair<T1,T2>::pair(void)
			: first(), second()
			{
			}

		/* Copy constructor */
		template<typename T1, typename T2>
		template<typename U, typename V>
			pair<T1,T2>::pair(const pair<U,V>& other)
			: first(other.first), second(other.second)
			{
			}

		/* Initialization constructor */
		template<typename T1, typename T2>
			pair<T1,T2>::pair(const first_type& x, const second_type& y)
			: first(x), second(y)
			{
			}

		/* Copy assignment operator */
		template<typename T1, typename T2>
			pair<T1,T2>&	pair<T1,T2>::operator=(const pair& other)
			{
				if (this != &other)
				{
					this->first = other.first;
					this->second = other.second;
				}
				return (*this);
			}

		/* non-member function overloads **************************************** */

		/*
		* Relational operators
		* Make comparison between two pairs
		*/

		template<typename T1, typename T2>
			bool	pair<T1,T2>::operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{
				return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
			}

		template<typename T1, typename T2>
			bool	pair<T1,T2>::operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{
				return (!(lhs == rhs));
			}

		template<typename T1, typename T2>
			bool	pair<T1,T2>::operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{
				return (
					(lhs.first < rhs.first)
					|| (!(rhs.first < lhs.first) && (lhs.second < rhs.second))
					);
			}

		template<typename T1, typename T2>
			bool	pair<T1,T2>::operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{
				return (!(rhs < lhs));
			}

		template<typename T1, typename T2>
			bool	pair<T1,T2>::operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{
				return (rhs < lhs);
			}

		template<typename T1, typename T2>
			bool	pair<T1,T2>::operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{
				return (!(lhs < rhs));
			}

} // namespace ft

#endif
