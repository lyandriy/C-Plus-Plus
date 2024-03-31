/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:01:18 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/31 12:35:18 by lyandriy         ###   ########.fr       */
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

AForm::AForm(const AForm &other) : name(other.name), _signed(other._signed), sign(other.sign), _execute(other._execute)
{
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this->sign < 1 || this->_execute < 1)
		throw GradeTooHighException();
	if (this->sign > 150 || this->_execute > 150)
		throw GradeTooLowException();
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
		this->_signed = true;
	else
		throw GradeTooLowException();
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
	oso << other.getName();
	if (other.getSigned())
		oso << " currently is signed.";
	else
		oso << " currently is not signed.";
	oso << " The grade needed to sign is " << other.getSign()
	<< ". The grade needed to execute is " <<  other.getExecute() << ".";
	return (oso);
}