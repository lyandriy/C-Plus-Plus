/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:01 by lyandriy          #+#    #+#             */
/*   Updated: 2024/01/17 17:30:23 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	int			index;
	std::string	Command;
	PhoneBook	Phone_Book;

	index = -1;
	while (1)
	{
		std::cout << "Insert a command" << std::endl;
		std::getline(std::cin, Command);
		if (std::cin.eof())
			exit(1);
		if (Command == "ADD")
		{
			index++;
			if (index == 8)
				index = 0;
			Phone_Book.add_contact(index);
		}
		else if (Command == "SEARCH")
			Phone_Book.search_method(index);
		else if (Command == "EXIT")
			return (0);
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
