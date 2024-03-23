/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:58:11 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/23 18:46:06 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		ShrubberyCreationForm(std::string target);

		class NotOpenFile : public std::exception
		{
			public:
				const char* what() const throw();
		};
		void	execute(Bureaucrat const & executor) const;
};

#endif