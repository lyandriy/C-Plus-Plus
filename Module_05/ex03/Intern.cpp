/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:32:48 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/24 17:25:31 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern	&Intern::operator=(const Intern &other)
{
	return (*this);
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	std::string	type_form[4] = {"PresidentialPardonForm", "RobotomyRequestForm",
								"ShrubberyCreationForm"};
	int	i = 1;
	int	j = 0;

	while (i != 0 || j <= 3)
	{
		i = form.compare(type_form[j]);
		j++;
	}
	switch (j)
	{
		case 0:
		{
			std::cout << "Intern creates " << type_form[j - 1] << std::endl;
			return (new PresidentialPardonForm(target));
		}
		case 1:
		{
			std::cout << "Intern creates " << type_form[j - 1] << std::endl;
			return (new RobotomyRequestForm(target));
		}
		case 2:
		{
			std::cout << "Intern creates " << type_form[j - 1] << std::endl;
			return (new ShrubberyCreationForm(target));
		}
		case 3:
			throw	WrongTypeForm();
	}
}

const char *Intern::WrongTypeForm::what() const throw()
{
	return ("Wrong type of form");
}
