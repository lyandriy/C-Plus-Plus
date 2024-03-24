/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:01:29 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/24 16:30:10 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : target("No target"), AForm("ShrubberyCreationForm", 145, 137)
{};

ShrubberyCreationForm::~ShrubberyCreationForm(){};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = other;
}
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->target = other.target;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw GradeTooLowException();
	if (executor.getGrade() > this->getExecute())
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