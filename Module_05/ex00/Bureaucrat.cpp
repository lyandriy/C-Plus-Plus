/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:22:41 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/27 17:46:20 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name ("No name"), Grade(150){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(int grade, std::string _name) : name (_name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->Grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	*this = other;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat & other)
{
	if (other.Grade < 1)
		throw GradeTooHighException();
	if (other.Grade > 150)
		throw GradeTooLowException();
	this->Grade = other.Grade;
	return(*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->Grade);
}

void	Bureaucrat::iGrade()
{
	if (this->Grade == 1)
		throw GradeTooHighException();
	this->Grade--;
}

void	Bureaucrat::dGrade()
{
	if (this->Grade == 150)
		throw GradeTooLowException();
	this->Grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High Exception");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low Exception");
}

std::ostream &operator<<(std::ostream& oso, Bureaucrat& other)
{
	oso << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (oso);
}
