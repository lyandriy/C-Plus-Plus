/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:24:53 by lyandriy          #+#    #+#             */
/*   Updated: 2024/05/23 16:06:58 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	is_num(std::string date_str)
{
	int flag = 0;

	for (int i = 0; date_str[i]; i++)
	{
		if (date_str[i] == '.')
		{
			if (flag != 0)
				throw std::exception();
			flag++;
		}
		else
		{
			if (!isdigit(date_str[i]))
				throw std::exception();
		}
	}
}

int	is_val(std::string date_str)
{
	int flag = 0;

	for (int i = 0; date_str[i]; i++)
	{
		if (date_str[i] == '.')
		{
			if (flag != 0)
				return (0);
			flag++;
		}
		else
		{
			if (!isdigit(date_str[i]))
				return (0);
		}
	}
	return (1);
}

void	map_data(std::map<int,float> &data)
{
	std::string		line;
	std::string		date_str;
	std::ifstream	data_file("data.csv");

	if (data_file.is_open())
	{
		std::getline(data_file, line);
		if (line != "date,exchange_rate")
			throw std::exception();
		while(std::getline(data_file, line))
		{
			if (line.size() >= 12)
			{
				date_str = line.substr(0, 10);
				date_str.erase(7, 1);
				date_str.erase(4, 1);
				is_num(date_str);
				is_num(line.substr(11));
				data.insert(std::pair<int,float>(atol(date_str.c_str()), 
							static_cast<float>(std::atof(line.substr(11).c_str()))));
			}
		}
	}
	else
		throw std::exception();
}

void	mns(float num, std::string line, std::map<int,float>::iterator it, std::map<int,float> data)
{
	if (num > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else if (num < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (!is_val(line.substr(13)))
		std::cout << "Error: bad input => " << line << std::endl;
	else if (it != data.end())
		std::cout << line.substr(0, 10) << " => " << num << " = " << std::fixed << std::setprecision(2) << (it->second * num) << std::endl;
	else
		std::cout << "Error: bad input => " << line << std::endl;
}

void	map_input(std::map<int,float> data, std::string file)
{
	int				date_int;
	float			num;
	std::string		line;
	std::string		date_str;
	std::ifstream	in_file(file.c_str());
	std::map<int,float>::iterator	it;

	if (in_file.is_open())
	{
		std::getline(in_file, line);
		if (line != "date | value")
			throw std::exception();
		while(std::getline(in_file, line))
		{
			if (line.size() >= 14)
			{
				num = (std::atof(line.substr(13).c_str()));
				date_str = line.substr(0, 10);
				date_str.erase(7, 1);
				date_str.erase(4, 1);
				date_int = atol(date_str.c_str());
				it = data.lower_bound(date_int);
				if (it->first != date_int && it == data.end())
				{
					it--;
					if (it->first > date_int)
						it = data.begin();
				}
				mns(num, line, it, data);
			}
			else
				std::cout << "Error: bad input => " << line << std::endl;
		}
	}
	else
		throw std::exception();
}

void	btc(std::string file)
{
	std::map<int,float> data;

	map_data(data);
	map_input(data, file);
}

int main(int argc, char **argv)
{
	try
	{
		if (argc == 2)
			btc(argv[1]);
		else
			throw std::exception();
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
