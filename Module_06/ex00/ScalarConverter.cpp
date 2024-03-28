/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:10:41 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/28 20:08:41 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

int	chek(std::string literal)
{
	int i = 0;
	int	flag_p = 0;

	while(literal[i])
	{
		if ((literal[i] == '-' || literal[i] == '+') && i == 0 && std::isdigit(literal[i + 1]))
			i++;
		if (literal[i] == '.' && std::isdigit(literal[i + 1]) && i != 0 && flag_p == 0)
		{
			i++;
			flag_p++;
		}
		if ((literal[i] == 'f' || literal[i] == 'F' || literal[i] == 'd' || literal[i] == 'D') 
			&& !literal[i + 1] && i != 0 && std::isdigit(literal[i - 1]))
		{
			i++;
			break;
		}
		if (std::isdigit(literal[i]))
		{
			i++;
			if (!literal[i])
				break;
		}
		else
			return (0);
	}
	return (1);
}

int	except_nan(std::string literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (0);
	}
	if (literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return (0);
	}
	return (1);
}

void	messages(char num_char, int num_int, float num_float, double num_double, std::string literal)
{
	size_t	ptr = literal.find('.');

	if (literal[0] == '-')
		std::cout << "char: impossible" << std::endl;
	else if (num_int < 32 || num_int > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << num_char << std::endl;
	std::cout << "int: " << num_int << std::endl;
	if (ptr == std::string::npos)
	{
		std::cout << "float: " << num_float << ".0f" << std::endl;
		std::cout << "double: " << num_double << ".0" << std::endl;
	}
	else if (ptr != std::string::npos && literal[ptr + 1] == '0' && !literal[ptr + 2])
	{
		std::cout << "float: " << num_float << ".0f" << std::endl;
		std::cout << "double: " << num_double << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << num_float << "f" << std::endl;
		std::cout << "double: " << num_double << std::endl;
	}
}

void	ScalarConverter::convert(std::string literal)
{
	char	num_char;
	int		num_int;
	float	num_float;
	double	num_double;
	long int	max_int;

	if (!except_nan(literal))
		return ;
	if (chek(literal))
	{
		max_int = std::atol(literal.c_str());
		if (max_int > 2147483647 || max_int < -2147483648)
		{
			std::cerr << "Error: Input exceeds int value." << std::endl;
			return ;
		}
		num_int = std::atoi(literal.c_str());
		num_char = num_int;
		num_float = static_cast<float>(std::atof(literal.c_str()));
		num_double = std::atof(literal.c_str());
		messages(num_char, num_int, num_float, num_double, literal);
	}
	else
		std::cerr << "Error. Your input is not a number." << std::endl;
}
