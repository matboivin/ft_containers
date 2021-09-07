/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:23:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/07 18:00:01 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector.hpp>
#include <vector>

template< typename Vec >
static void	displayInfos( const std::string& title, const Vec& v ) {

	std::cout << title
			  << "\n- size:        " << v.size()
			  << "\n- capacity:    " << v.capacity() << std::endl;

	for ( std::size_t i = 0; i < v.capacity(); i++ )
		std::cout << v[i] << ' ';

	std::cout << "\n\n";
}

void	testDefaultConstructors( void ) {

	ft::vector<int>		ft_vec;
	std::vector<int>	vec;

	displayInfos("ft_vec", ft_vec);
	displayInfos("vec", vec);
}

void	testConstructors( void ) {

	std::vector<int>	vec1(14, 1);
	std::vector<int>	vec2(42, 2);
	std::vector<int>	vec3(4,  3);

	displayInfos("vec 1", vec1);
	displayInfos("vec 2", vec2);
	displayInfos("vec 3", vec3);

	vec2 = vec1;
	vec3 = vec1;

	std::cout << "AFTER\n\n";

	displayInfos("vec 2", vec2);
	displayInfos("vec 3", vec3);

	std::cout << "______________\n\n";

	ft::vector<int>	ft_vec1(14, 1);
	ft::vector<int>	ft_vec2(42, 2);
	ft::vector<int>	ft_vec3(4,  3);

	displayInfos("ft_vec 1", ft_vec1);
	displayInfos("ft_vec 2", ft_vec2);
	displayInfos("ft_vec 3", ft_vec3);

	ft_vec2 = ft_vec1;
	ft_vec3 = ft_vec1;

	std::cout << "AFTER\n\n";

	displayInfos("ft_vec 2", ft_vec2);
	displayInfos("ft_vec 3", ft_vec3);
}

void	testCopy( void ) {

	std::vector<int>	vec1(14);
	std::vector<int>	vec2(4);

	vec1.push_back(3);
	vec1.push_back(5);
	vec1.push_back(737);
	vec1.push_back(1);
	vec1.push_back(5);
	vec1.push_back(58);
	vec1.push_back(0);
	vec1.push_back(0);

	displayInfos("vec 1", vec1);
	vec1.pop_back();

	try {
		vec1.at(42) = 42;
	} catch ( std::out_of_range& oor ) {
		std::cout << oor.what() << std::endl;
	}

	displayInfos("vec 1", vec1);
	displayInfos("vec 2", vec2);

	vec2 = vec1;

	std::cout << "AFTER\n\n";

	displayInfos("vec 2", vec2);

	vec1.clear();
	displayInfos("vec 1", vec1);

	std::cout << "______________\n\n";

	ft::vector<int>	ft_vec1(14);
	ft::vector<int>	ft_vec2(4);

	ft_vec1.push_back(3);
	ft_vec1.push_back(5);
	ft_vec1.push_back(737);
	ft_vec1.push_back(1);
	ft_vec1.push_back(5);
	ft_vec1.push_back(58);
	ft_vec1.push_back(0);
	ft_vec1.push_back(0);

	displayInfos("ft_vec 1", ft_vec1);
	ft_vec1.pop_back();

	try {
		ft_vec1.at(42) = 42;
	} catch ( std::out_of_range& oor ) {
		std::cout << oor.what() << std::endl;
	}

	displayInfos("ft_vec 1", ft_vec1);
	displayInfos("ft_vec 2", ft_vec2);

	ft_vec2 = ft_vec1;

	std::cout << "AFTER\n\n";

	displayInfos("ft_vec 2", ft_vec2);

	ft_vec1.clear();
	displayInfos("ft_vec 1", ft_vec1);
}

void	testCapacity( void ) {

	std::vector<int>	vec1(14);

	vec1.push_back(3);
	vec1.push_back(5);
	vec1.push_back(737);
	vec1.push_back(1);
	vec1.push_back(5);
	vec1.push_back(58);
	vec1.push_back(42);

	displayInfos("vec 1", vec1);

	vec1.reserve(100);
	displayInfos("vec 1", vec1);

	std::cout << "______________\n\n";

	ft::vector<int>	ft_vec1(14);

	ft_vec1.push_back(3);
	ft_vec1.push_back(5);
	ft_vec1.push_back(737);
	ft_vec1.push_back(1);
	ft_vec1.push_back(5);
	ft_vec1.push_back(58);
	ft_vec1.push_back(42);

	displayInfos("ft_vec 1", ft_vec1);

	ft_vec1.reserve(100);

	displayInfos("ft_vec 1", ft_vec1);
}

void	testElements( void ) {

	std::vector<int>::iterator	it;
	std::vector<int>::iterator	position;
	std::vector<int>			vec(4, 100);
	std::vector<int>			vec2(20);

	displayInfos("vec", vec);

	vec2 = vec;

	displayInfos("vec2", vec2);

	it = vec.begin();
	position = vec.insert(it, 200);

	displayInfos("vec", vec);

	vec.assign(2, 4);
	displayInfos("vec", vec);

	std::cout << "______________\n\n";

	ft::vector<int>	ft_vec(4, 100);
	ft::vector<int>	ft_vec2(20);

	displayInfos("ft_vec", ft_vec);

	ft_vec2 = ft_vec;

	displayInfos("ft_vec2", ft_vec2);

	// std::vector<int>	ft_vec(3, 100);

	// position = ft_vec.insert(it, 200);

	// displayInfos("ft_vec", ft_vec);
}

int	main( void ) {

	//testDefaultConstructors();
	//testConstructors();
	//testCopy();
	//testCapacity();
	testElements();

	return (0);
}
