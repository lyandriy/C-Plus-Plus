/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:25:34 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/21 19:57:59 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	is_neg(char *argv, int &i)
{
	if (argv[i] == '-' && std::isdigit(argv[i + 1]))
		return (1);
	return (0);
}

long int	make_digit(char *argv, int &i)
{
	std::string	s(argv);
	long int	count = 0;
	int			flag = 0;

	if (is_neg(argv, i))
	{
		flag = 1;
		i++;
	}
	while (std::isdigit(argv[i]))
	{
		i++;
		count++;
	}
	count = std::atol(s.substr((i - count), count).c_str());
	if (flag)
		count *= -1;
	if (count < INT_MIN || count > INT_MAX)
		throw error();
	return (count);
}

double	numb_size(char *argv)
{
	std::stack<long int>	numb;
	int	i = 0;
	size_t	oper = 0;

	while (argv[i])
	{
		if (std::isdigit(argv[i]) || is_neg(argv, i))
			numb.push(make_digit(argv, i));
		else if ((argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/') && !std::isdigit(argv[i + 1]))
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
		return (numb.top());
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

void	operations(char *argv, std::stack<long int> &numb, int &i)
{
	long int	first_num;
	long int	second_num;

	if (numb.empty())
		throw error();
	while (!std::isdigit(argv[i]) && argv[i] != '\0')
	{
		first_num = numb.top();
		numb.pop();
		second_num = numb.top();
		numb.pop();
		std::cout << second_num << argv[i] << first_num;
		if (argv[i] == '+')
			numb.push(second_num + first_num);
		else if (argv[i] == '-')
			numb.push(second_num - first_num);
		else if (argv[i] == '*')
			numb.push(second_num * first_num);
		else if (argv[i] == '/')
			numb.push(second_num / first_num);
		std::cout << "= " << numb.top() << std::endl;
		i++;
		while (argv[i] == ' ')
			i++;
	}
}

int	rpn(char *argv)
{
	std::stack<long int>	numb;
	int	i = 0;
	int	flag;

	if (numb_size(argv))
		return (std::atoi(argv));
	while (argv[i])
	{
		while (std::isdigit(argv[i]) || is_neg(argv, i))
		{
			flag = 0;
			if (is_neg(argv, i))
			{
				flag = 1;
				i++;
			}
			numb.push(std::atoi(str_isdigit(argv, i).c_str()));
			if (flag)
				numb.top() *= -1;
		}
		operations(argv, numb, i);
	}
	return (numb.top());
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
