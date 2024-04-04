/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:09:28 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/04 18:48:00 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T> void iter(T *a, T b, void (*f)(T))
{
	for (int i = 0; i < b; i++)
		f(a[i]);
}

#endif