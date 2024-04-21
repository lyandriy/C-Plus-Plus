/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:28:42 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/21 13:14:12 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	std::vector<long int>	vect;
	std::list<long int>		lists;
	clock_t				time_v;
	clock_t				time_l;

	try
	{
		if (argc > 1)
		{
			time_v = clock();
			PmergeMe(vect, argv);
			time_v = clock() - time_v;
			time_l = clock();
			PmergeMe(lists, argv);
			time_l = clock() - time_l;
			print(vect, argv, time_v, time_l);
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
