/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:28:45 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/21 13:26:04 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <list>

#define SEC_TO_MICRO 1000000.0

template<typename T> void PmergeMe(T &a, char **argv)
{
	for (int i = 0; argv[i]; i++)
	{
		a.push_back(std::atol(argv[i]));
		if (a.back() > INT_MAX || a.back() < 0)
			throw error();
	}
	
}

void	before(char **argv)
{
	std::cout << "Before:";
	for (int i = 1; argv[i]; i++)
	{
		std::cout << " " << argv[i];
	}
	std::cout << std::endl;
}

template<typename T> void	after(T &a)
{
	std::cout << "After:";
	for (T::iterator i = a.begin(); i < a.end(); ++i)
	{
		std::cout << " " << *i;
	}
	std::cout << std::endl;
	/*std::cout << "After:";
	for (int i = 0; i < a.size(); i++)
	{
		std::cout << " " << a[i];
	}
	std::cout << std::endl;*/
}

void	time(clock_t &time_v, clock_t &time_l)
{
	std::cout << "Time to process a range of " << " elements with std::vector : ";
	std::cout << ((time_v / CLOCKS_PER_SEC) * SEC_TO_MICRO) << " us" << std::endl;
	std::cout << "Time to process a range of 5 elements with std::list : ";
	std::cout << ((time_l / CLOCKS_PER_SEC) * SEC_TO_MICRO) << " us" << std::endl;
}

template<typename T> void print(T &a, char **argv, clock_t &time_v, clock_t &time_l)
{
	before(argv);
	after(T &a);
	time(time_v, time_l);
}

class	error : public std::exception
{
	public:
		const char* what() const throw()
		{return ("Error");}
};

#endif


/*
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
*/