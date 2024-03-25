/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:01:26 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/25 18:24:49 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 75, 42), target("No target")
{};

RobotomyRequestForm::~RobotomyRequestForm(){};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("RobotomyRequestForm", 75, 42)
{
	*this = other;
}
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->target = other.target;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 75, 42)
{
	this->target = target;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int random = rand();

	if (!this->getSigned())
		throw Bureaucrat::FormNotSigned();
	if (executor.getGrade() > this->getExecute())
		throw Bureaucrat::GradeTooLowExecute();
	if (random % 2)
		std::cout << "drilling noises" << std::endl;
	else
		throw RobotomyFailed();
}

const char* RobotomyRequestForm::RobotomyFailed::what() const throw()
{
	return ("the robotomy failed");
}