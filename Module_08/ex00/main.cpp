/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:14:27 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/14 19:14:25 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int	main()
{
	std::list<int> vec;

	try
	{
		for (int i = 0; i < 10; i++)
			vec.push_back(i);
		int ret = ::easyfind(vec, 9);
		std::cout << ret << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
