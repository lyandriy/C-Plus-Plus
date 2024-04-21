/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:37:32 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/21 14:05:58 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	check_argv(char *argv)
{
	for (int i = 0; argv[i]; i++)
	{
		if (i == 0 && argv[i] == '+')
		{
			i++;
			argv++;
		}
		if (!std::isdigit(argv[i]))
			throw error();
	}
}

void	fill_vector(std::vector<long int> &vect, char **argv)
{
	for (int i = 0; argv[i]; i++)
	{
		check_argv(argv[i]);
		vect.push_back(std::atol(argv[i]));
		if (vect.back() > INT_MAX)
			throw error();
	}
}

void	print_before(char **argv)
{
	std::cout << "Before:";
	for (int i = 1; argv[i]; i++)
	{
		std::cout << " " << argv[i];
	}
	std::cout << std::endl;
}

void	print_after(std::vector<long int> &vect)
{
	std::cout << "After:";
	for (std::vector<long int>::iterator i = vect.begin(); i < vect.end(); ++i)
	{
		std::cout << " " << *i;
	}
	std::cout << std::endl;
	/*std::cout << "After:";
	for (int i = 0; i < vect.size(); i++)
	{
		std::cout << " " << vect[i];
	}
	std::cout << std::endl;*/
}

void	print_time(clock_t &time_v, int argc)
{
	std::cout << "Time to process a range of " << (argc - 1) << " elements with std::vector : ";
	std::cout << ((time_v / CLOCKS_PER_SEC) * SEC_TO_MICRO) << " us" << std::endl;
}

void	merge_insert(std::vector<long int> &vect)
{
	for (int i = 0; i )
}

void	pmerge_me_vector(int argc, char **argv)
{
	std::vector<long int>	vect;
	clock_t					time_v;

	time_v = clock();
	fill_vector(vect, argv);
	merge_insert(vect);
	time_v = clock() - time_v;
	print_before(argv);
	print_after(vect);
	print_time(time_v, argc);
}