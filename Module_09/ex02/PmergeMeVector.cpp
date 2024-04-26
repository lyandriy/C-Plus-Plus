/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:37:32 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/26 19:40:18 by lyandriy         ###   ########.fr       */
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

	for (int i = 1; argv[i]; i++)
	{
		check_argv(argv[i]);
		vect_long = std::atol(argv[i]);
		if (vect_long > INT_MAX)
			throw error();
		vect.push_back(vect_long);
		//std::cout << vect.back() << std::endl;
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
size_t	jacobsthal(size_t a)
{
	size_t susecion[36] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365,
	2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101,
	2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971,
	357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123};

	for (int i = 0; i < 36; i++)
	{
		if ((a - 1) == susecion[i])
			return (susecion[i + 2]);
		else if (a <= susecion[i + 1] && a > susecion[i])
			return (a--);
	}
	return (0);
}

void	bynary_search(int small, std::vector<int> &big, size_t end, size_t begin)
{
	size_t i = (end - begin) / 2;
	std::vector<int>::iterator it = big.begin();

	while (i != 2)
	{
		if (big[i] == small)
			break ;
		else if (big[i] < small)
			bynary_search(small, big, end, i);
		else//(big[i] > small)
			bynary_search(small, big, i, 0);
	}
	big.insert(it + i, small);
}

void	insert(std::vector<int> &big, std::vector<int> &small)
{
	size_t	a = 1;
	std::vector<int>::iterator it = small.begin();

	if (small.front() != -1)
	{
		big.insert(big.begin(), small.front());
		it++;
	}
	for (size_t i = 1; i != small.size(); i++)
	{
		a = jacobsthal(a);
		if (small[a] == -1)
			a = jacobsthal(a);
		bynary_search(small[a], big, a, 0);
	}
}
void	marge(std::vector<int> &big/*, std::vector<int> &small*/)
{
	std::vector<int> _big;
	std::vector<int> _small;
	int	odd = -1;

	if (big.size() % 2 == 1)
	{
		odd = big.back();
		big.pop_back();
	}
		std::cout << big.size() << "******\n";
	for (std::vector<int>::iterator it = big.begin(); (it + 1) != big.end(); it++)
	{
		if (*it > *(it + 1))//si primer elemento es mas grande que el segundo
		{
			_big.push_back(static_cast<int>(*it));
			_small.push_back(static_cast<int>(*(++it)));
			std::cout << _big.back() << " " << _small.back() << "if \n";
		}
		else
		{
			_small.push_back(static_cast<int>(*it));
			_big.push_back(static_cast<int>(*(++it)));
			std::cout << _big.back() << " " << _small.back() << "else \n";
		}
		//it++;
	}
	if (odd != -1)
		_big.push_back(odd);
	std::cout << _big.size() << "******\n";
	if (_big.size() > 2)
	{
		//marge(_big/*, _small*/);
	}
	//insert(_big, _small);
}

/*void	marge(std::vector<int> &big, std::vector<int> &small)
{
	std::vector<int> _big;
	std::vector<int> _small;

	std::vector<int>::iterator it = big.begin();
	std::cout << "\n";
	//while (a < big.size())//big tiene que tener la mitad del tamaño de vect
	for (std::vector<int>::iterator it = big.begin(); it != big.end();)
	{
		if (*it > *(it + 1))//si primer elemento es mas grande que el segundo
		{
			_big.push_back(static_cast<int>(*it));
			_small.push_back(static_cast<int>(*(++it)));
			std::cout << _big.back() << " " << _small.back() << "if \n";
		}
		else
		{
			_small.push_back(static_cast<int>(*it));
			_big.push_back(static_cast<int>(*(++it)));
			std::cout << _big.back() << " " << _small.back() << "else \n";
		}
		//if (it + 1 != big.end())
			it++;
	}
	if (big.size() % 2 == 1)//si vect es impar
	{
		_big.push_back(static_cast<int>(*(--it)));
		_small.push_back(-1);
	}
	std::cout << _big.size() << "******\n";
	if (_big.size() > 2)
	{
		//marge(_big, _small);
	}
	//insert(_big, _small);
}*/

void	merge_insert(std::vector<int> &vect)
{
	std::vector<int>	big;
	//std::vector<int>	small;

	marge(vect/*, small*/);
}

void	pmerge_me_vector(char **argv, clock_t &time_v)
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