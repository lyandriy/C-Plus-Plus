/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:01:26 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/24 16:31:32 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : target("No target"), AForm("RobotomyRequestForm", 75, 42)
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
		throw GradeTooLowException();
	if (executor.getGrade() > this->getExecute())
		throw GradeTooLowException();
	if (random % 2)///seran 50%?
		std::cout << "drilling noises" << std::endl;
	else
		throw RobotomyFailed();
}

const char* RobotomyRequestForm::RobotomyFailed::what() const throw()
{
	return ("the robotomy failed");
}