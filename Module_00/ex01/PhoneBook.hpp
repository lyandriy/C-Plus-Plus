/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:48:57 by lyandriy          #+#    #+#             */
/*   Updated: 2024/01/21 16:07:58 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include <cctype>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int		numb_contact;
		Contact	Contact[8];
	public:
		PhoneBook();
		~PhoneBook();

		void		add_contact(int index);
		void		search_method(int index);
		void		DisplayContact(int in_number);
		void		DisplayAllContacts(int index);
		std::string	GetInput(std::string prompt);
};

#endif