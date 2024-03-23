/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:01:29 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/23 18:46:02 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : target("No target")
{};

ShrubberyCreationForm::~ShrubberyCreationForm(){};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	*this = other;
}
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->target = other.target;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
	this->target = target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() > 145 || this->getExecute() > 137)
		throw GradeTooLowException();
	std::ofstream	file(this->target + "_shrubbery");
	if (!file.is_open())
		throw NotOpenFile();
	file << "   *   " << std::endl;
	file << "  ***  " << std::endl;
	file << " ***** " << std::endl;
	file << "*******" << std::endl;
	file << "   *   " << std::endl;
	file << "   *   " << std::endl;
	file.close();
}

const char* ShrubberyCreationForm::NotOpenFile::what() const throw()
{
	return ("error");
}