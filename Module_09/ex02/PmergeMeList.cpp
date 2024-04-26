/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:37:30 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/26 17:21:56 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "PmergeMe.hpp"

void	check_argv(char *argv)
{
	for (int i = 0; argv[i]; i++)
	{
		if (!std::isdigit(argv[i]))
			throw error();
	}
}

void	fill_vector(std::list<long int> &lists, char **argv)
{
	for (int i = 0; argv[i]; i++)
	{
		check_argv(argv[i]);
		lists.push_back(std::atol(argv[i]));
		if (lists.back() > INT_MAX)
			throw error();
	}
}

void	merge_insert(std::list<long int> &lists)
{
	
}

void	pmerge_me_vector(int argc, char **argv, clock_t &time_l)
{
	std::list<long int>	lists;

	time_l = clock();
	fill_vector(lists, argv);
	merge_insert(lists);
	time_l = clock() - time_l;
}*/