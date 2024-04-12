/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:14:25 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/10 16:38:49 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template<typename T> int easyfind(T &container, int parameter)
{
	for (size_t i = 0; i < container.size(); i++)
	{
		if (container[i] == parameter)
			return (parameter);
	}
	throw std::exception();
	return(0);
}

#endif