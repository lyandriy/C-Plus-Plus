/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:42 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/14 15:33:08 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main()
{
	Point	a(0, 0);
	Point	b(4, 0);
	Point	c(2, 5);
	Point	point(1, 2);
	
	if (bsp(a, b, c, point))
	{
		std::cout << "true" << std::endl;
		return (0);
	}
	std::cout << "false" << std::endl;
	return (0);
}
