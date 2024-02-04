/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:29:48 by lyandriy          #+#    #+#             */
/*   Updated: 2024/01/28 13:56:47 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.hpp"

void	aux_replacing(std::ifstream	*in_file, std::ofstream	*on_file,
	std::string s1, std::string s2)
{
	std::string	line;
	size_t		ptr;

	ptr = 0;
	while(std::getline(*in_file, line))
	{
		ptr = line.find(s1);
		while (ptr != std::string::npos)
		{
			ptr = line.find(s1);
			if (ptr != std::string::npos)
			{
				line.erase(ptr, s1.size());
				line.insert(ptr, s2);
			}
		}
		*on_file << line << std::endl;
	}
}

void	replacing(std::string filename, std::string s1, std::string s2)
{
	if (s1.empty() || s2.empty() || filename.empty())
	{
		std::cout << "error" << std::endl;
		return ;
	}
	std::ifstream	in_file(filename);
	if (in_file.is_open())
	{
		std::ofstream	on_file(filename + ".replace");
		if (on_file.is_open())
			aux_replacing(&in_file, &on_file, s1, s2);
		else
			std::cout << "error" << std::endl;
	}
	else
		std::cout << "error" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "error" << std::endl;
		return (1);
	}
	replacing(argv[1], argv[2], argv[3]);
	return (0);
}
