/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:44:19 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/18 20:09:17 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	str_isdigit(char *argv)
{
	for (int i = 0; argv[i]; i++)
	{
		if (!std::isdigit(argv[i]))
			return (0);
	}
	return (1);
}

int	rpn(char **argv)
{
	std::stack<int> numb;

	for (int i = 1; argv[i]; i++)
	{
		if (str_isdigit(argv[i]))
			numb.push(std::atoi(argv[i]));
		if (argv[i] == "+" || argv[i] == "-" || argv[i] == "*" || argv[i] == "/")
			
	}
	return (0);
}

int	main(int argc, char **argv)
{
	try
	{
		if (argc > 1)
			std::cout << "result " << rpn(argv) << std::endl;
		else
			throw std::exception();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	
}
