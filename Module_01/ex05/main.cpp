/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:57:35 by lyandriy          #+#    #+#             */
/*   Updated: 2024/01/31 15:58:07 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	void	(Harl::*f_member[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	command[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
	{
		if (level == command[i])
		{
			(this->*f_member[i])();
			return ;
		}
		else if (i == 3)
			std::cout << "error" << std::endl;
	}
}

int	main(void)
{
	std::string	level;
	Harl		_harl;

	while (true)
	{
		std::cout << "The level parameter: " << std::endl;
		std::getline(std::cin, level);
		if (std::cin.eof())
			return (1);
		if (level == "EXIT")
			return (0);
		_harl.complain(level);
	}
	return (0);
}
