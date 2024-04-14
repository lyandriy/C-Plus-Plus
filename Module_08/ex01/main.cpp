/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:45:27 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/14 19:15:50 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	std::cout << "***container***" << std::endl;
	Span	c(20);
	std::vector<int> vec;

	vec.push_back(40);
	vec.push_back(200);
	vec.push_back(50);
	vec.push_back(-1);
	c.iterator(vec);

	std::cout << c.shortestSpan() << std::endl;
	std::cout << c.longestSpan() << std::endl;

	std::cout << "***array***" << std::endl;

	Span	b(6);
	int	array[6] = {40, 5, 50, 1, -2, 4};
	b.iterator(array, 6);

	std::cout << b.shortestSpan() << std::endl;
	std::cout << b.longestSpan() << std::endl;

	std::cout << "***addNumber***" << std::endl;
	Span	a(100);
	for (int i = 0; i < 10; i++)
	{
		a.addNumber(i);}

	std::cout << a.shortestSpan() << std::endl;
	std::cout << a.longestSpan() << std::endl;
	return (0);
}
