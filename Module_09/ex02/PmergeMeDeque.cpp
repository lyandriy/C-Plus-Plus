/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:37:30 by lyandriy          #+#    #+#             */
/*   Updated: 2024/05/18 20:27:07 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void	check_argv(char *argv)
{
	for (int i = 0; argv[i]; i++)
	{
		if (!std::isdigit(argv[i]))
			throw error();
	}
}

static void	fill_vector(std::deque<std::pair<int, int> > &deque, char **argv)
{
	long int			deque_long;
	std::pair<int, int>	pair;

	for (int i = 1; argv[i]; i++)
	{
		check_argv(argv[i]);
		deque_long = ::atol(argv[i]);
		if (deque_long > INT_MAX)
			throw error();
		pair.first = static_cast<int>(deque_long);
		pair.second = i - 1;
		deque.push_back(pair);
	}
}

static void	print_after(std::deque<std::pair<int, int> > &deque)
{
	std::cout << "After:";
	for (std::deque<std::pair<int, int> >::iterator i = deque.begin(); i < deque.end(); ++i)
		std::cout << " " << i->first;
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

static void	make_pos(std::deque<size_t> &pos, size_t end)
{
	for (size_t i = 0; i < pos.size(); i++)
	{
		if (pos[i] >= end)
			pos[i]++;
	}
}

static void	bynary_insert(std::pair<int, int> small, std::deque<std::pair<int, int> > &big, size_t end, std::deque<size_t> &pos)
{
	size_t begin = 0;
	size_t new_begin = begin + ((end - begin) / 2);
	std::deque<std::pair<int, int> >::iterator it = big.begin();

	while (1)
	{
		if (big[new_begin].first > small.first)
			end = new_begin;
		else if (big[new_begin].first < small.first)
		{
			begin = new_begin + 1;
		}
		if (big[new_begin].first <= small.first && big[new_begin + 1].first >= small.first)
		{
			big.insert(it + (new_begin + 1), small);
			make_pos(pos, new_begin + 1);
			break;
		}
		new_begin = begin + ((end - begin) / 2);
	}
}

static void	bynary_search(std::pair<int, int> small, std::deque<std::pair<int, int> > &big, size_t end, std::deque<size_t> &pos)
{
	if (small.first <= big[0].first)
	{
		big.insert(big.begin(), small);
		for (size_t i = 0; i < pos.size(); i++)
			pos[i]++;
	}
	else if (small.first >= big[end].first)
	{
		big.insert(big.begin() + end + 1, small);
		make_pos(pos, end);
	}
	else
		bynary_insert(small, big, end, pos);
}

static std::deque<std::pair<int, int> >	insert(std::deque<std::pair<int, int> > &big, std::deque<std::pair<int, int> > &small)
{
	size_t	a = 1;
	size_t	r = 0;
	std::deque<std::pair<int, int> > big_d;
	std::deque<size_t> pos;

	big_d = big;
	for (size_t i = 0; i < big_d.size(); i++)
		pos.push_back(i);
	big.insert(big.begin(), small.front());
	for (size_t i = 0; i < pos.size(); i++)
			pos[i]++;
	for (size_t i = 1; i < (small.size()); i++)
	{
		a = (jacobsthal(a));
		if (a > (small.size()))
			a = (small.size());
		r = a;
		if (a > big_d.size())
			r = big_d.size();
		bynary_search(small[a - 1], big, pos[r - 1], pos);
	}
	return (big);
}

static void	make_containers(std::deque<std::pair<int, int> > &sorted_big, std::deque<std::pair<int, int> > &small, std::deque<std::pair<int, int> > &big,
						std::deque<std::pair<int, int> > &big_dup, std::deque<std::pair<int, int> > &small_dup)
{
	int j = 0;

	 for (size_t i = 0; i < sorted_big.size(); i++)//crear los 4 contenedores
	{
		if (sorted_big[i] > sorted_big[i + 1])
		{
			big_dup.push_back(sorted_big[i]);
			small_dup.push_back(sorted_big[i + 1]);
			big.push_back(std::make_pair(sorted_big[i].first, j));
			small.push_back(std::make_pair(sorted_big[i + 1].first, j));
		}
		else
		{
			small_dup.push_back(sorted_big[i]);
			big_dup.push_back(sorted_big[i + 1]);
			small.push_back(std::make_pair(sorted_big[i].first, j));
			big.push_back(std::make_pair(sorted_big[i + 1].first, j));
		}
		if (i != (sorted_big.size() - 1))
			i++;
		j++;
	}
}

static void	sort_begin(std::deque<std::pair<int, int> > &big_dup, std::deque<std::pair<int, int> > &small_dup, std::pair<int, int> &odd)
{
	if (big_dup.size() == 1)//si contenedor contiene un numero
	{
		if (big_dup[0].first < small_dup[0].first)
		{
			big_dup.push_back(small_dup[0]);
		}
		else
			big_dup.insert(big_dup.begin(), small_dup[0]);
		if (odd.first != -1)
		{
			if (big_dup[1].first <= small_dup.back().first)
				big_dup.push_back(small_dup.back());
			else if (big_dup[0].first >= small_dup.back().first)
			{
				big_dup.insert(big_dup.begin(), small_dup.back());
			}
			else
			{
				big_dup.insert(big_dup.begin() + 1, small_dup.back());
			}
		}
		small_dup.clear();
	}
}

static void	copy(std::deque<std::pair<int, int> > &sorted_big, std::deque<std::pair<int, int> > &sorted_small, std::deque<std::pair<int, int> > &small_dup,
			std::deque<std::pair<int, int> > &big_dup, std::deque<std::pair<int, int> > &small, std::pair<int, int> &odd)
{
	int pos;
	for (size_t i = 0; i < sorted_big.size(); i++)
	{
		pos = sorted_big[i].second;
		sorted_small.push_back(small_dup[pos]);
		sorted_big[i].second = big_dup[pos].second;
	}
	if (sorted_big.size() == 2)
	{
		big_dup = sorted_big;
		small_dup = sorted_small;
	}
	if (odd.first != -1)//insertar el numero impar
	{
		small_dup.push_back(odd);
		small.push_back(std::make_pair(odd.first, small.size()));
		sorted_small.push_back(odd);
	}
}

static std::deque<std::pair<int, int> > merge_insertion(std::deque<std::pair<int, int> > sorted_big)
{
    std::deque<std::pair<int, int> > big;
    std::deque<std::pair<int, int> > small;
	std::deque<std::pair<int, int> > big_dup;
	std::deque<std::pair<int, int> > small_dup;
	std::deque<std::pair<int, int> > sorted_small;
    std::pair<int, int> odd =  std::make_pair(-1, -1);

    if (sorted_big.size() % 2 == 1)//quitar el numero impar
	{
		odd = sorted_big.back();   
		sorted_big.pop_back();
	}
	make_containers(sorted_big, small, big, big_dup, small_dup);
	if (odd.first != -1)//insertar el numero impar
	{
		small_dup.push_back(odd);
		small.push_back(std::make_pair(odd.first, small.size()));
	}
    if (big.size() != 1)//recursividad
		sorted_big = merge_insertion(big);
	sort_begin(big_dup, small_dup, odd);
	if (!small_dup.empty())//ordenar el contenedor peqeño
	{
		copy(sorted_big, sorted_small, small_dup, big_dup, small, odd);
		sorted_big = insert(sorted_big, sorted_small);//ordenado o duplicado
		return (sorted_big);
	}
    return (big_dup);
}

void	pmerge_me_deque(char **argv, clock_t &time_d)
{
	std::deque<std::pair<int, int> >	deque;

	time_d = clock();
	fill_vector(deque, argv);
	if (deque.size() > 1)
		deque = merge_insertion(deque);
	time_d = clock() - time_d;
	print_after(deque);
}