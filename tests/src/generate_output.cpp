/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_output.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:32:34 by mboivin           #+#    #+#             */
/*   Updated: 2021/10/05 19:07:28 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "tests.hpp"

/*
 * Output formatters
 */

static void	put_test_title(const std::string& title)
{
	std::cout << COL_BLUE_B << title << COL_RESET << std::endl;
}

static void	put_test_time(const std::string& ft_time, const std::string& std_time)
{
	std::cout << "ft: " << ft_time << "\tstd: " << std_time << std::endl;
}

/*
 * Read the files content
 */

static void	read_files(std::ifstream& ft_file, std::ifstream& std_file)
{
	std::string	ft_res;
	std::string	std_res;

	while (std::getline(ft_file, ft_res) && std::getline(std_file, std_res))
	{
		if ((ft_res[0] == ':' ) || (ft_res[0] == '_'))
			put_test_title(ft_res);
		else if (ft_res.find("time:") != std::string::npos)
			put_test_time(ft_res, std_res);
		else
			std::cout << ft_res << ' ' << std_res << std::endl;
	}

	ft_file.close();
	std_file.close();
}

/*
 * Open files
 */

static int	open_file(std::ifstream& infile, const char* filename)
{
	infile.open(filename, std::ios::in);

	if (!infile.is_open())
	{
		std::cout << "Error: couldn't open file '" << filename << "'\n";
		return (1);
	}
	return (0);
}

/*
 * Generate an output on stdout using the two output files
 */

void	generate_output(void)
{
	std::ifstream	ft_file;
	std::ifstream	std_file;

	if (open_file(ft_file, "tests/outputs/ft_vec.out")
		|| open_file(std_file, "tests/outputs/std_vec.out"))
		return ;

	read_files(ft_file, std_file);
}
