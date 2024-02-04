/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:20 by lyandriy          #+#    #+#             */
/*   Updated: 2024/01/21 18:12:14 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): numb_contact(0)
{
	numb_contact = 0;
}

PhoneBook::~PhoneBook(){}

void	PhoneBook::DisplayContact(int in_number)
{
	std::cout << Contact[in_number].getFirstName() << std::endl;
	std::cout << Contact[in_number].getLastName() << std::endl;
	std::cout << Contact[in_number].getNickname() << std::endl;
	std::cout << Contact[in_number].getPhoneNumber() << std::endl;
	std::cout << Contact[in_number].getDarkestSecret() << std::endl;
}

int	ChooseIndex()
{
	std::string	number;
	int			in_number;

	std::cout << "choose index :";
	std::getline(std::cin, number);
	if (std::cin.eof())
		exit(1);
	in_number = std::atoi(number.c_str());
	if (in_number)
	{
		if (in_number > 0 && in_number < 9)
			return (in_number);
	}
	std::cout << "Error" << std::endl;
	return (0);
	
}

void	PrintColumn(std::string text)
{
	std::size_t	size;

	size = text.length();
	if (size > 10)
	{
		text.resize(9);
		std::cout << text << ".";
	}
	else
	{
		std::cout << text;
		for (std::size_t i = 0; i < (10 - size); i++)
			std::cout << " ";
	}
}

void	PhoneBook::DisplayAllContacts(int index)
{
	int	CountIndex;

	CountIndex = -1;
	while (++CountIndex <= index)
	{
		std::cout << CountIndex + 1 << "         |";
		PrintColumn(Contact[CountIndex].getFirstName());
		std::cout << "|" << std::flush;
		PrintColumn(Contact[CountIndex].getLastName());
		std::cout << "|" << std::flush;
		PrintColumn(Contact[CountIndex].getNickname());
		std::cout << std::endl;
	}
}

void	PhoneBook::search_method(int index)
{
	std::string	number;
	int			in_number;

	in_number = 0;
	if (index >= 0)
		DisplayAllContacts(numb_contact - 1);
	else
	{
		std::cout << "Phone Book is empty" << std::endl;
		return ;
	}
	while (in_number == 0)
		in_number = ChooseIndex();
	if (in_number > (numb_contact))
		std::cout << "Contact does not exist" << std::endl;
	else
		DisplayContact(in_number - 1);
}

std::string	PhoneBook::GetInput(std::string prompt)
{
	std::string	input;

	while (true)
	{
		std::cout << prompt << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		if (input.length() > 0 && !input.empty())
			break ;
	}
	return input;
}

int	check_PhoneNumber(std::string number)
{
	int	count;

	count = 0;
	while (number[count])
	{
		if (!std::isdigit(number[count]))
			return (0);
		count++;
	}
	return (1);
}

void PhoneBook::add_contact(int index)
{
	if (numb_contact < 8)
		numb_contact++;
	Contact[index].setFirstName(GetInput("First Name: "));
	Contact[index].setLastName(GetInput("Last Name: "));
	Contact[index].setNickname(GetInput("Nickname: "));
	while (1)
	{
		Contact[index].setPhoneNumber(GetInput("Phone Number: "));
		if (!check_PhoneNumber(Contact[index].getPhoneNumber()))
			std::cout << "Wrong number" << std::endl;
		else
			break ;
	}
	Contact[index].setDarkestSecret(GetInput("Darkest Secret: "));
}
