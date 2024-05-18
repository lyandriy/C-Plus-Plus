/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:35:21 by lyandriy          #+#    #+#             */
/*   Updated: 2024/05/18 20:34:24 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_before(char **argv)
{
	std::cout << "Before:";
	for (int i = 1; argv[i]; i++)
	{
		std::cout << " " << argv[i];
	}
	std::cout << std::endl;
}

void	print_time(clock_t &time_d, int argc, std::string conten)
{
	std::cout << "Time to process a range of " << (argc - 1) << " elements with std::" << conten << " : ";
	std::cout << (((float)time_d / CLOCKS_PER_SEC)) << " us" << std::endl;
}

/*void	print_time_v(clock_t &time_v, int argc)
{
	std::cout << "Time to process a range of " << (argc - 1) << " elements with std::vector : ";
	std::cout << (((float)time_v / CLOCKS_PER_SEC)) << " us" << std::endl;
}*/

int	main(int argc, char **argv)
{
	clock_t	time_v;
	clock_t	time_d;

	try
	{
		if (argc > 1)
		{
			print_before(argv);
			pmerge_me_vector(argv, time_v);
			pmerge_me_deque(argv, time_d);
			print_time(time_v, argc, "vector");
			print_time(time_d, argc, "deque");
		}
		else
			throw error();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;;
	}
	return (0);
}
