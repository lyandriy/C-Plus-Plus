/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:01:20 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/31 12:34:38 by lyandriy         ###   ########.fr       */
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

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn’t sign " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High Exception");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low Exception");
}

const char* Bureaucrat::FormatNotExecuted::what() const throw()
{
	return ("failed execution");
}

const char* Bureaucrat::FormNotSigned::what() const throw()
{
	return ("Form Not Signed");
}

const char* Bureaucrat::GradeTooLowExecute::what() const throw()
{
	return ("Grade Too Low To Execute");
}

std::ostream &operator<<(std::ostream& oso, Bureaucrat& other)
{
	oso << other.getName() << ", bureaucrat grade is " << other.getGrade();
	return (oso);
}
