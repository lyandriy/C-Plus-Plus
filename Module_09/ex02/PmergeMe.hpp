/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:35:45 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/21 14:06:24 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <list>

#define SEC_TO_MICRO 1000000.0

void	pmerge_me_vector(int argc, char **argv);
void	pmerge_me_list(int argc, char **argv);

class	error : public std::exception
{
	public:
		const char* what() const throw()
		{return ("Error");}
};

#endif