/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:35:21 by lyandriy          #+#    #+#             */
/*   Updated: 2024/05/19 16:40:37 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_time(clock_t &time_d, int argc, std::string conten)
{
	std::cout << "Time to process a range of " << (argc - 1) << " elements with std::" << conten << " : ";
	std::cout << std::fixed << std::setprecision(3) << ((time_d / (double)CLOCKS_PER_SEC) * 1000) << " ms" << std::endl;
}

int	main(int argc, char **argv)
{
	clock_t	time_v;
	clock_t	time_d;

	try
	{
		if (argc > 1)
		{
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
