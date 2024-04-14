/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:14:25 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/14 19:13:38 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template<typename T> int easyfind(T &container, int parameter)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), parameter);
	if (it != container.end())
		return (parameter);
	throw std::exception();
}

#endif