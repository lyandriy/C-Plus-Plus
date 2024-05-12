/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:50:56 by lyandriy          #+#    #+#             */
/*   Updated: 2024/05/12 11:47:30 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_contein(std::vector<int> &myvector, std::vector<int> &myvector_s)
{
	std::cout << "myvector contains big:";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "myvector contains small:";
	for (std::vector<int>::iterator it = myvector_s.begin() ; it != myvector_s.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

}

void	print_cont(std::vector<int> &myvector)
{
	std::cout << "myvector:";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

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
		vect_long = ::atol(argv[i]);
		if (vect_long > INT_MAX)
			throw error();
		vect.push_back(vect_long);
	}
}

void	print_after(std::vector<int> &vect)
{
	std::cout << "After:";
	for (std::vector<int>::iterator i = vect.begin(); i < vect.end(); ++i)
		std::cout << " " << *i;
	std::cout << std::endl;
}
size_t	jacobsthal(size_t a)
{
	size_t susecion[36] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365,
	2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101,
	2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971,
	357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123};

	for (int i = 0; i < 35; i++)
	{
		if ((a - 1) == susecion[i])
			return (susecion[i + 2]);
		else if (a <= susecion[i + 1] && a > susecion[i])
			return (--a);
	}
	return (0);
}

void	bynary_search(int small, std::vector<int> &big, size_t begin, size_t end)
{
	size_t new_begin = begin + ((end - begin) / 2);
	std::vector<int>::iterator it = big.begin();

	if (small <= big[0])
		big.insert(it, small);
	else if (small >= big[end])
		big.insert(it + end + 1, small);
	else
	{
		while (1)
		{
			if (big[new_begin] > small)
				end = new_begin;
			if (big[new_begin] < small)
				begin = new_begin + 1;
			if (big[new_begin] <= small && big[new_begin + 1] >= small)
			{
				big.insert(it + (new_begin + 1), small);
				break;
			}
			new_begin = begin + ((end - begin) / 2);
		}
	}
}

std::vector<int>	insert(std::vector<int> big, std::vector<int> small)
{
	size_t	a = 1;

	big.insert(big.begin(), small.front());
	for (size_t i = 1; i != (small.size() - 1); i++)
	{
		a = (jacobsthal(a));
		if (a > (small.size() - 1))
			a = (small.size());
		bynary_search(small[a - 1], big, a - 1, 0);
	}
	return (big);
}

std::vector<int> merge_insrtion(std::vector<int> _big/*, std::vector<std::vector<int>> &all_small*/)
{
    std::vector<int> big;
    std::vector<int> small;
	std::vector<int> ord_small;
    int odd =  -1;

    if (_big.size() % 2 == 1)
	{
		odd = _big.back();   
        //std::cout << odd << std::endl;
		_big.pop_back();
	}
    for (size_t i = 0; i < _big.size(); i++)
	{
		if (_big[i] > _big[i + 1])
		{
			big.push_back(static_cast<int>(_big[i]));
			small.push_back(static_cast<int>(_big[i + 1]));
		}
		else
		{
			small.push_back(static_cast<int>(_big[i]));
			big.push_back(static_cast<int>(_big[i + 1]));
		}
		if (i != (_big.size() - 1))
			i++;
	}
	//all_small.push_back(small);
    if (big.size() != 1)
		_big = merge_insrtion(big/*, all_small*/);
	print_cont(big);
	if (big.size() == 1)
	{
		if (big[0] < small[0])
			big.push_back(small[0]);
		else
			big.insert(big.begin(), small[0]);
	}
	if (odd != -1)
		bynary_search(odd, _big, (_big.size() - 1), 0);
	/*if (!small.empty())
	{
		for (size_t i = 0; i < _big.size(); i++)
		{
			for (size_t j = 0; j < big.size(); j++)
			{
				if (big[j] == _big[i])
				{
					ord_small.push_back(small[j]);
					break;
				}
			}
		}
	}
	print_contein(big, ord_small);
	_big = insert(big, ord_small);//_big es el big ordenado*/
    return (_big);
}

void	pmerge_me_vector(char **argv, clock_t &time_v)
{
	std::vector<int>	vect;
	//std::vector<std::vector<int>>	all_small;

	time_v = clock();
	fill_vector(vect, argv);
	vect = merge_insrtion(vect/*, all_small*/);
	time_v = clock() - time_v;
	//print_after(vect);
}