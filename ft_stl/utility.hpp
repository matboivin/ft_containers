/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:52:44 by mboivin           #+#    #+#             */
/*   Updated: 2021/11/16 18:29:02 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

/*
 * This header contains utilities to create pairs objects
 */

namespace ft
{
	/* Classes ************************************************************** */

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

			// default constructor
			pair(void)
			: first(), second()
			{
			}

			// copy constructor
			template<typename U, typename V>
			pair(const pair<U,V>& other)
			: first(other.first), second(other.second)
			{
			}

			// initialization constructor
			pair(const first_type& x, const second_type& y)
			: first(x), second(y)
			{
			}

			// copy assignment operator
			pair<T1,T2>&	operator=(const pair& other)
			{
				if (this != &other)
				{
					this->first = other.first;
					this->second = other.second;
				}
				return (*this);
			}

		}; // struct pair

		/* non-member function overloads **************************************** */

		/*
		* Relational operators
		* Make comparison between two pairs
		*/

		template<typename T1, typename T2>
			bool	operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{
				return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
			}

		template<typename T1, typename T2>
			bool	operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{
				return (!(lhs == rhs));
			}

		template<typename T1, typename T2>
			bool	operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{
				return (
					(lhs.first < rhs.first)
					|| (!(rhs.first < lhs.first) && (lhs.second < rhs.second))
					);
			}

		template<typename T1, typename T2>
			bool	operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{
				return (!(rhs < lhs));
			}

		template<typename T1, typename T2>
			bool	operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{
				return (rhs < lhs);
			}

		template<typename T1, typename T2>
			bool	operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{
				return (!(lhs < rhs));
			}


		/* Functions ************************************************************ */

		/*
		 * Constructs and returns a pair object with x as first and y as second
		 */
		template<typename T1, typename T2>
			pair<T1,T2>	make_pair(T1 x, T2 y)
			{
				return ( ft::pair<T1,T2>(x, y) );
			}

} // namespace ft

#endif
