/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:42:53 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/20 15:26:56 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <queue>
#include <limits>
#include <cfloat>

int	rpn(char **argv);

class	error : public std::exception
{
	public:
		const char* what() const throw()
		{return ("Error");}
};

#endif
