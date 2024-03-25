/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:32:48 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/25 18:33:55 by lyandriy         ###   ########.fr       */
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
	(void)other;
	return (*this);
}

AForm	*CreateForm(int form, std::string target)
{
	switch (form)
	{
		case 0:
		{
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return (new PresidentialPardonForm(target));
		}
		case 1:
		{
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return (new RobotomyRequestForm(target));
		}
		case 2:
		{
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(target));
		}
	}
	return (NULL);
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	std::string	_form[3][4] = {{"PresidentialPardonForm", "Presidential Pardon Form", "Presidential Pardon", "presidential pardon"},
								{"RobotomyRequestForm", "Robotomy Request Form", "Robotomy Request", "robotomy request"},
								{"ShrubberyCreationForm", "Shrubbery Creation Form", "Shrubbery Creation", "shrubbery creation"}};

	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if (form == _form[i][j])
				return CreateForm(i, target);
		}
	}
	throw	WrongTypeForm();
	return (NULL);
}

const char *Intern::WrongTypeForm::what() const throw()
{
	return ("Wrong type of form");
}
