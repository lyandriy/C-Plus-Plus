/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:43:53 by lyandriy          #+#    #+#             */
/*   Updated: 2024/01/31 15:59:31 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	void	(Harl::*f_member[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	command[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (level == command[i])
			break ;
	}
	switch(i)
	{
		case 0:
			(this->*f_member[0])();
		case 1:
			(this->*f_member[1])();
		case 2:
			(this->*f_member[2])();
		case 3:
			(this->*f_member[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break ;
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