/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:25:34 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/20 16:52:37 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

long int	make_digit(char *argv, int &i)
{
	std::string	s(argv);
	long int	count = 0;

	while (std::isdigit(argv[i]))
	{
		i++;
		count++;
	}
	count = std::atol(s.substr((i - count), count).c_str());
	if (count < INT_MIN || count > INT_MAX)
		throw error();
	return (count);
}

double	numb_size(char *argv)
{
	std::queue<long int>	numb;
	int	i = 0;
	size_t	oper = 0;

	while (argv[i])
	{
		if (std::isdigit(argv[i]))
			numb.push(make_digit(argv, i));
		else if (argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
		{
			i++;
			oper++;
		}
		else if (argv[i] == ' ')
			i++;
		else
			throw error();
	}
	if (numb.size() == 1 && oper == 0)
		return (numb.front());
	if (numb.size() > 10 || (numb.size() - 1) != oper)
		throw error();
	return (0);
}

std::string	str_isdigit(char *argv, int &i)
{
	std::string	str;

	while (std::isdigit(argv[i]))
	{
		str += argv[i];
		i++;
	}
	if (argv[i] != ' ')
		throw error();
	while (argv[i] == ' ')
		i++;
	return (str);
}

void	str_isit(char *argv, int &i, std::stack<char> &oper)
{
	while ((argv[i] == '+' || argv[i] == '-' || argv[i] == '*' ||
			argv[i] == '/') && argv[i] != '\0')
	{
		oper.push(argv[i]);
		i++;
		while (argv[i] == ' ')
			i++;
	}
}

void	operations(std::stack<char> &oper, std::queue<long int> &numb)
{
	long int	res_num;

	if (numb.empty() || oper.empty())
		throw error();
	while (!numb.empty() && !oper.empty())
	{
		res_num = numb.front();
		numb.pop();
		if (oper.top() == '+')
			numb.push(res_num + numb.front());
		else if (oper.top() == '-')
			numb.push(res_num - numb.front());
		else if (oper.top() == '*')
			numb.push(res_num * numb.front());
		else if (oper.top() == '/')
			numb.push(res_num / numb.front());
		numb.pop();
		oper.pop();
	}
}

int	rpn(char *argv)
{
	std::stack<char>		oper;
	std::queue<long int>	numb;
	int i = 0;

	if (numb_size(argv))
		return (std::atoi(argv));
	while (argv[i])
	{
		while (std::isdigit(argv[i]))
			numb.push(std::atoi(str_isdigit(argv, i).c_str()));
		if (argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
			str_isit(argv, i, oper);
		operations(oper, numb);
	}
	return (numb.front());
}

int	main(int argc, char **argv)
{
	try
	{
		if (argc == 2 && argv[1][0] != '\0')
		{
			int result = rpn(argv[1]);
			std::cout << result << std::endl;
		}
		else
			throw error();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;;
	}
	return (0);
}
