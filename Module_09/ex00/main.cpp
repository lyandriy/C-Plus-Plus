/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:24:53 by lyandriy          #+#    #+#             */
/*   Updated: 2024/05/17 15:26:43 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	map_data(std::map<long int,float> &data)
{
	std::string		line;
	std::string		date_str;
	long int		date;
	std::ifstream	data_file("data.csv");

	if (data_file.is_open())
	{
		std::getline(data_file, line);
		while(std::getline(data_file, line))
		{
			if (line.size() >= 12)
			{
				date_str = line.substr(0, 10);
				date_str.erase(7, 1);
				date_str.erase(4, 1);
				date = atol(date_str.c_str());
				if (date > 20220329 || date < 20090102)
					throw std::exception();
				data.insert(std::pair<int,float>(date,
					static_cast<float>(std::atof(line.substr(11).c_str()))));
			}
		}
	}
	else
		throw std::exception();
}

void	map_input(std::map<long int,float> data, std::string file)
{
	std::string		line;
	std::string		date_str;
	long int		date_int;
	double			num;
	std::ifstream	in_file(file.c_str());
	std::map<long int,float>::iterator	it;

	if (in_file.is_open())
	{
		std::getline(in_file, line);
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
				if (it->first != date_int && it != data.end())
					it--;
				if (num > std::numeric_limits<int>::max())
					std::cout << "Error: too large a number." << std::endl;
				else if (num < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else if (date_int > 20220329 || date_int < 20090102)
					std::cout << "Error: bad input => " << line << std::endl;
				else if (it != data.end())
					std::cout << line.substr(0, 10) << " => " << num << " = " << (it->second * num) << std::endl;
				else
					std::cout << "Error: bad input => " << line << std::endl;
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
	std::map<long int,float> data;

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
