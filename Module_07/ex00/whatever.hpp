/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:17:50 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/04 18:04:27 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T> void swap(T &a, T &b)
{
	T	c;
	c = a;
	a = b;
	b = c;
}

template<typename T> T min(T &a, T &b)
{
	if (a < b)
		return (a);
	else if (a > b)
		return (b);
	return (b);
}

template<typename T> T max(T &a, T &b)
{
	if (a < b)
		return (b);
	else if (a > b)
		return (a);
	return (b);
}

#endif