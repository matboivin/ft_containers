/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:23:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/09/06 14:28:01 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector.hpp>
#include <vector>

int	main( void ) {

	ft::vector<int>		ft_vec;
	std::vector<int>	vec;

	std::cout << "ft_vec size:     " << ft_vec.size()
			  << "\nft_vec capacity: " << ft_vec.capacity()
			  << "\nft_vec max_size: " << ft_vec.max_size() << std::endl;

	std::cout << "\nvec size:        " << vec.size()
			  << "\nvec capacity:    " << vec.capacity()
			  << "\nvec max_size:    " << vec.max_size() << std::endl;

	return (0);
}
