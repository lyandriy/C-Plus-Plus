/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:50:56 by lyandriy          #+#    #+#             */
/*   Updated: 2024/05/13 20:54:07 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_contein(std::vector<std::pair<int, int> > &myvector, std::vector<std::pair<int, int> > &myvector_s)
{
	std::cout << "myvector contains big:";
	for (std::vector<std::pair<int, int> >::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << it->first;
		//std::cout << ' ' << it->second;
	std::cout << '\n';

	std::cout << "myvector contains small:";
	for (std::vector<std::pair<int, int> >::iterator it = myvector_s.begin() ; it != myvector_s.end(); ++it)
		std::cout << ' ' << it->first;
		//std::cout << ' ' << it->second;
	std::cout << '\n';

}

void	print_cont(std::vector<std::pair<int, int> > &myvector)
{
	std::cout << "myvector:";
	for (std::vector<std::pair<int, int> >::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << " " << it->first << "/" << it->second;
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

void	fill_vector(std::vector<std::pair<int, int> > &vect, char **argv)
{
	long int			vect_long;
	std::pair<int, int>	pair;

	for (int i = 1; argv[i]; i++)
	{
		check_argv(argv[i]);
		vect_long = ::atol(argv[i]);
		if (vect_long > INT_MAX)
			throw error();
		pair.first = static_cast<int>(vect_long);
		pair.second = i - 1;
		vect.push_back(pair);
	}
}

void	print_after(std::vector<std::pair<int, int> > &vect)
{
	std::cout << "After:";
	for (std::vector<std::pair<int, int> >::iterator i = vect.begin(); i < vect.end(); ++i)
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

void	bynary_search(std::pair<int, int> small, std::vector<std::pair<int, int> > &big, size_t begin, size_t end, std::vector<std::pair<int, int> > &big_dup, std::pair<int, int> &small_dup)
{
	size_t new_begin = begin + ((end - begin) / 2);
	std::vector<std::pair<int, int> >::iterator it = big.begin();
	std::vector<std::pair<int, int> >::iterator it_ = big_dup.begin();

	std::cout << "bynary_search\n";
	print_cont(big);
	//std::cout << "bynary_search " << small.first << std::endl;
	if (small.first <= big[0].first)
	{
		std::cout << "bynary_search 2 " << small.first << std::endl;
		big.insert(it, small);
		big_dup.insert(it_, small_dup);
	}
	else if (small.first >= big[end].first)
	{
		std::cout << end << " bynary_search 3 " << small.first << std::endl;
		//print_cont(big_dup);
		//print_cont(big);
		big.insert(big.end(), small);
		big_dup.insert(big_dup.end(), small_dup);
		
	}
	else
	{
		std::cout << "bynary_search 4 " << small.first << std::endl;
		while (1)
		{
			if (big[new_begin].first > small.first)
				end = new_begin;
			if (big[new_begin].first < small.first)
				begin = new_begin + 1;
			if (big[new_begin].first <= small.first && big[new_begin + 1].first >= small.first)
			{
				big.insert(it + (new_begin + 1), small);
				big_dup.insert(it_ + (new_begin + 1), small_dup);
				break;
			}
			new_begin = begin + ((end - begin) / 2);
		}
	}
}

std::vector<std::pair<int, int> >	insert(std::vector<std::pair<int, int> > &big, std::vector<std::pair<int, int> > &small, std::vector<std::pair<int, int> > &big_dup, std::vector<std::pair<int, int> > &small_dup)
{
	size_t	a = 1;

	//print_cont(big);
	//print_cont(small);
	big.insert(big.begin(), small.front());
	big_dup.insert(big_dup.begin(), small_dup.front());
	/*if (small.size() == 2)
	{
		bynary_search(small[1], big, 0, 1, big_dup, small_dup[1]);
	}*/
	for (size_t i = 1; i != (small.size()/* - 1*/); i++)
	{
		a = (jacobsthal(a));
		if (a > (small.size() - 1))
			a = (small.size());
		std::cout << small.size() << "jacobsthal " << a - 1 << std::endl;
		bynary_search(small[a - 1], big, 0, a - 1, big_dup, small_dup[a - 1]);
	}
	return (big);
}

std::vector<std::pair<int, int> > merge_insrtion(std::vector<std::pair<int, int> > sorted_big)
{
    std::vector<std::pair<int, int> > big;
    std::vector<std::pair<int, int> > small;
	std::vector<std::pair<int, int> > big_dup;
	std::vector<std::pair<int, int> > small_dup;
	std::vector<std::pair<int, int> > sorted_small;
    std::pair<int, int> odd =  std::make_pair(-1, -1);
	int j = 0;
    if (sorted_big.size() % 2 == 1)//quitar el numero impar
	{
		odd = sorted_big.back();   
		sorted_big.pop_back();
	}
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
	if (odd.first != -1)//insertar el numero impar
	{
		small_dup.push_back(odd);
		small.push_back(std::make_pair(odd.first, small.size()));
		//print_cont(small_dup);
		//print_cont(small);
	}
    if (big.size() != 1)//recursividad
	{
		sorted_big = merge_insrtion(big);
		//print_cont(sorted_big);
	}
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
				big_dup.insert(big_dup.begin(), small_dup.back());
			else
				big_dup.insert(big_dup.begin() + 1, small_dup.back());
		}
		small_dup.clear();
		
	}
	
	int pos;
	if (!small_dup.empty())//ordenar el contenedor peqeño
	{
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
		//print_cont(small_dup);
		//print_cont(small);
	}
		//print_cont(sorted_big);
		//print_cont(sorted_small);
		sorted_big = insert(sorted_big, sorted_small, big_dup, small_dup);//ordenado o duplicado
		return (sorted_big);
	}
    return (big_dup);
}

void	pmerge_me_vector(char **argv, clock_t &time_v)
{
	std::vector<std::pair<int, int> >	vect;

	time_v = clock();
	fill_vector(vect, argv);
	//print_cont(vect);
	vect = merge_insrtion(vect);
	time_v = clock() - time_v;
	print_after(vect);
}