/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:35:21 by lyandriy          #+#    #+#             */
/*   Updated: 2024/05/08 19:02:15 by lyandriy         ###   ########.fr       */
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

void	print_time_l(clock_t &time_l, int argc)
{
	std::cout << "Time to process a range of " << (argc - 1) << " elements with std::list : ";
	std::cout << ((time_l / CLOCKS_PER_SEC) * SEC_TO_MICRO) << " us" << std::endl;
}

void	print_time_v(clock_t &time_v, int argc)
{
	std::cout << "Time to process a range of " << (argc - 1) << " elements with std::vector : ";
	std::cout << ((time_v / CLOCKS_PER_SEC) * SEC_TO_MICRO) << " us" << std::endl;
}

int	main(int argc, char **argv)
{
	clock_t	time_v;
	//clock_t	time_l;

	try
	{
		if (argc > 1)
		{
			print_before(argv);
			
			pmerge_me_vector(argv, time_v);
			//pmerge_me_list(argc, argv, time_l);
			//print_time_v(time_v, argc);
			//print_time_l(time_l, argc);
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
