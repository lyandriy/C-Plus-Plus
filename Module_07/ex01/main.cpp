/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:24:55 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/04 18:52:05 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	f(int i)
{
	std::cout << "I am function f and I call array " << i << std::endl;
}

int main()
{
	int i[5] = {2, 3, 5, 8, 9};
	::iter(i, 5, f);
	return (0);
}
