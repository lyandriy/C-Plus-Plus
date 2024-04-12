/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:14:27 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/10 16:38:42 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int	main()
{
	std::vector<int> vec;

	try
	{
		for (int i = 0; i < 5; i++)
			vec.push_back(i);
		int	ret = ::easyfind(vec, 5);
		std::cout << ret << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
