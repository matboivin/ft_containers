/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:23:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/06 16:12:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector.hpp>
#include <vector>

void	testDefaultConstructors( void ) {

	ft::vector<int>		ft_vec;
	std::vector<int>	vec;

	std::cout << "\n\nft_vec size:     " << ft_vec.size()
			  << "\nft_vec capacity: " << ft_vec.capacity()
			  << "\nft_vec max_size: " << ft_vec.max_size() << std::endl;

	std::cout << "\nvec size:        " << vec.size()
			  << "\nvec capacity:    " << vec.capacity()
			  << "\nvec max_size:    " << vec.max_size() << std::endl;
}

void	testConstructors( void ) {

	std::vector<int>	vec1(14, 1);
	std::vector<int>	vec2(42, 2);
	std::vector<int>	vec3(4,  3);

	std::cout << "VEC 1"
			  << "\nvec size:        " << vec1.size()
			  << "\nvec capacity:    " << vec1.capacity() << std::endl;

	std::cout << "\nVEC 2"
			  << "\nvec size:        " << vec2.size()
			  << "\nvec capacity:    " << vec2.capacity() << std::endl;

	std::cout << "\nVEC 3"
			  << "\nvec size:        " << vec3.size()
			  << "\nvec capacity:    " << vec3.capacity() << std::endl;

	vec2 = vec1;
	vec3 = vec1;

	std::cout << "\n\nVEC 2"
			  << "\nvec size:        " << vec2.size()
			  << "\nvec capacity:    " << vec2.capacity() << std::endl;

	std::cout << "\nVEC 3"
			  << "\nvec size:        " << vec3.size()
			  << "\nvec capacity:    " << vec3.capacity() << std::endl;

	std::vector<int>	ft_vec1(14, 1);
	std::vector<int>	ft_vec2(42, 2);
	std::vector<int>	ft_vec3(4,  3);

		std::cout << "\n\nFT_VEC 1"
			  << "\nvec size:        " << ft_vec1.size()
			  << "\nvec capacity:    " << ft_vec1.capacity() << std::endl;

	std::cout << "\nFT_VEC 2"
			  << "\nvec size:        " << ft_vec2.size()
			  << "\nvec capacity:    " << ft_vec2.capacity() << std::endl;

	std::cout << "\nFT_VEC 3"
			  << "\nvec size:        " << ft_vec3.size()
			  << "\nvec capacity:    " << ft_vec3.capacity() << std::endl;

	ft_vec2 = ft_vec1;
	ft_vec3 = ft_vec1;

	std::cout << "\n\nFT_VEC 2"
			  << "\nvec size:        " << ft_vec2.size()
			  << "\nvec capacity:    " << ft_vec2.capacity() << std::endl;

	std::cout << "\nFT_VEC 3"
			  << "\nvec size:        " << ft_vec3.size()
			  << "\nvec capacity:    " << ft_vec3.capacity() << std::endl;
}

int	main( void ) {

	//testDefaultConstructors();
	testConstructors();

	return (0);
}
