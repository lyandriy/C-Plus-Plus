/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:35:45 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/26 17:21:41 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <cstdlib>
#include <climits>
//#include <stdlib.h>

#define SEC_TO_MICRO 1000000.0

void	pmerge_me_vector(char **argv, clock_t &time_v);
void	pmerge_me_list(int argc, char **argv, clock_t &time_l);

class	my_pair
{
	public:
		int	size;
		std::pair<int, int> *pair;
};

class	error : public std::exception
{
	public:
		const char* what() const throw()
		{return ("Error");}
};

#endif