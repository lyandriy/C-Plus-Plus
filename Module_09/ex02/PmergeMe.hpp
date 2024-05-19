/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:35:45 by lyandriy          #+#    #+#             */
/*   Updated: 2024/05/19 16:12:11 by lyandriy         ###   ########.fr       */
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
#include <algorithm>
#include <deque>
#include <iomanip>

void	pmerge_me_vector(char **argv, clock_t &time_v);
void	pmerge_me_deque(char **argv, clock_t &time_d);

class	error : public std::exception
{
	public:
		const char* what() const throw()
		{return ("Error");}
};

#endif