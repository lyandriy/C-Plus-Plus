/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:37:32 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/25 20:02:03 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	check_argv(char *argv)
{
	for (int i = 0; argv[i]; i++)
	{
		if (!std::isdigit(argv[i]))
			throw error();
	}
}

void	fill_vector(std::vector<int> &vect, char **argv)
{
	long int	vect_long;

	for (int i = 0; argv[i]; i++)
	{
		check_argv(argv[i]);
		vect_long = std::atol(argv[i]);
		if (vect_long > INT_MAX)
			throw error();
		vect.push_back(vect_long);
	}
}

void	print_after(std::vector<int> &vect)
{
	std::cout << "After:";
	for (std::vector<int>::iterator i = vect.begin(); i < vect.end(); ++i)
	{
		std::cout << " " << *i;
	}
	std::cout << std::endl;
}
int	jacobsthal()
{

}

void	insert(std::vector<int> &big, std::vector<int> &small)
{
	std::vector<int>::iterator it = small.begin();

	if (small.front() != -1)
	{
		big.insert(big.begin(), small.front());
		it++;
	}
	while (it != small.end())
	{
		
	}
}

void	marge(std::vector<int> &big, std::vector<int> &small)
{
	std::vector<int> _big;
	std::vector<int> _small;

	std::vector<int>::iterator it = big.begin();
	while (_big.size() != (big.size() / 2))//big tiene que tener la mitad del tamaño de vect
	{
		if (*it > *(it + 1))//si primer elemento es mas grande que el segundo
		{
			_big.push_back(static_cast<int>(*it));
			_small.push_back(static_cast<int>(*(++it)));
		}
		else
		{
			_small.push_back(static_cast<int>(*it));
			_big.push_back(static_cast<int>(*(++it)));
		}
		if (it != big.end())
			it++;
	}
	if (big.size() % 2 == 1)//si vect es impar
	{
		_big.push_back(static_cast<int>(*it));
		_small.push_back(-1);
	}
	if (_big.size() > 2)
		marge(_big, _small);
	insert(_big, _small);
}

void	merge_insert(std::vector<int> &vect)
{
	std::vector<int>	big;
	std::vector<int>	small;

	marge(vect, small);
}

void	pmerge_me_vector(int argc, char **argv, clock_t &time_v)
{
	std::vector<int>	vect;

	time_v = clock();
	fill_vector(vect, argv);
	merge_insert(vect);
	time_v = clock() - time_v;
	print_after(vect);
}

/*
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
*/