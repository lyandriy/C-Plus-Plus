/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:01:18 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/23 17:54:10 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("No name"), _signed(false), sign(150), _execute(150){}

AForm::~AForm(){}

AForm::AForm(std::string _name, int _sign, int _execute) : name(_name), _signed(false), sign(_sign), _execute(_execute)
{
	if (this->sign < 1 || this->_execute < 1)
		throw GradeTooHighException();
	if (this->sign > 150 || this->_execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), sign(other.sign), _execute(other._execute)
{
	if (this->sign < 1 || this->_execute < 1)
		throw GradeTooHighException();
	if (this->sign > 150 || this->_execute > 150)
		throw GradeTooLowException();
	this->_signed = other._signed;
}

AForm &AForm::operator=(const AForm &other)
{
	this->_signed = other._signed;
	return (*this);
}

std::string	AForm::getName() const
{
	return (this->name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getSign() const
{
	return (this->sign);
}

int	AForm::getExecute() const
{
	return (this->_execute);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->sign)
	{
		bureaucrat.signForm(*this);
		this->_signed = true;
	}
	else
	{
		bureaucrat.signForm(*this);
		throw GradeTooLowException();
	}
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High Exception");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low Exception");
}

std::ostream &operator<<(std::ostream& oso, AForm &other)
{
	oso << other.getName() << ", have signed " << other.getSigned()
	<< " grade required to sign it " << other.getSign()
	<< " grade required to execute it " <<  other.getExecute();
	return (oso);
}