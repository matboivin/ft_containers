/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:52:44 by mboivin           #+#    #+#             */
/*   Updated: 2022/01/24 20:39:08 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

/*
 * This header contains utilities to create pairs objects and retrieve a key
 * from a key,value pair.
 */

namespace ft
{
	/* Represents a pair of values which may be from different types */
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
			: first(), second() { }

			// copy constructor
			template<typename U, typename V>
			pair(const pair<U,V>& other)
			: first(other.first), second(other.second) { }

			// initialization constructor
			pair(const first_type& x, const second_type& y)
			: first(x), second(y) { }

			// copy assignment operator
			pair<T1,T2>&
			operator=(const pair& other)
			{
				if (this != &other)
				{
					this->first = other.first;
					this->second = other.second;
				}
				return (*this);
			}

		}; // struct pair

	/* Relational operators: make comparison between two pairs */

	template<typename T1, typename T2>
		bool
		operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return ((lhs.first == rhs.first) && (lhs.second == rhs.second)); }

	template<typename T1, typename T2>
		bool
		operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return (!(lhs == rhs)); }

	template<typename T1, typename T2>
		bool
		operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return ((lhs.first < rhs.first) || (!(rhs.first < lhs.first) && (lhs.second < rhs.second))); }

	template<typename T1, typename T2>
		bool
		operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return (!(rhs < lhs)); }

	template<typename T1, typename T2>
		bool
		operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return (rhs < lhs); }

	template<typename T1, typename T2>
		bool
		operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return (!(lhs < rhs)); }

	/* Constructs and returns a pair object with x as first and y as second */
	template<typename T1, typename T2>
		pair<T1,T2>	make_pair(T1 x, T2 y)
		{ return (ft::pair<T1,T2>(x, y)); }

	/* Helper class that returns the given parameter */
	template<typename T>
		struct get_key
		{
			T&			operator()(T& __x) const       { return __x; }
			const T&	operator()(const T& __x) const { return __x; }
		};

	/* Helper class that returns the first element of the pair passed as parameter */
	template<typename T, typename Val>
		struct get_key_from_pair
		{
			T&			operator()(Val& __x) const       { return __x.first; }
			const T&	operator()(const Val& __x) const { return __x.first; }
		};
} // namespace ft

#endif
