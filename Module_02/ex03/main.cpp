/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:29:42 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/10 17:45:28 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main()
{
	Point	a(1, 1);
	Point	b(1, 5);
	Point	c(3, 4);
	Point	point(3, 2);
	
	if (bsp(a, b, c, point))
		std::cout << "true" << std::endl;
	std::cout << "false" << std::endl;
}
