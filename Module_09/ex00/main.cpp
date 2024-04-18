/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:24:53 by lyandriy          #+#    #+#             */
/*   Updated: 2024/04/18 17:41:14 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


void	map_data(std::map<std::string,float> &data)
{
	std::string		line;
	float			num;
	std::ifstream	data_file("data.csv");

	if (data_file.is_open())
	{
		std::getline(data_file, line);
		while(std::getline(data_file, line))
		{
			if (line.size() >= 12)
			{
				num = static_cast<float>(std::atof(line.substr(11).c_str()));
				data.insert(std::pair<std::string,float>(line.substr(0, 10), num));
			}
		}
	}
	else
		throw std::exception();//no abre el archivo
}

void	map_input(std::map<std::string,float> data, std::string file)
{
	std::string		line;
	std::string		_date;
	double			num;
	std::ifstream	in_file(file);
	std::map<std::string,float>::iterator	it;

	if (in_file.is_open())
	{
		std::getline(in_file, line);//saltar "date | value"
		while(std::getline(in_file, line))
		{
			if (line.size() >= 14)
			{
				num = (std::atof(line.substr(13).c_str()));//copia el value
				_date = line.substr(0, 10);//copia date
				it = data.lower_bound(_date);//busca la clave
				if (it->first != _date && it != data.end())
					it--;
				if (num > std::numeric_limits<int>::max())//comprueba si esta bien el num
					std::cout << "Error: too large a number." << std::endl;
				else if (num < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else if (it != data.end())//imprime resultado
				{
					std::cout << _date << " => " << it->first << " = " << it->second << std::endl;
					std::cout << _date << " => " << num << " = " << (it->second * num) << std::endl;
				}
				else
					std::cout << "Error: bad input => " << line << std::endl;
			}
			else
				std::cout << "Error: bad input => " << line << std::endl;
		}
	}
	else
		throw std::exception();//no abre el archivo
}

void	btc(std::string file)
{
	std::map<std::string,float> data;

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