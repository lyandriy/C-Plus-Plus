/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:53:23 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/31 12:31:21 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("No name"), _signed(false), sign(150), execute(150){}

Form::~Form(){}

Form::Form(std::string _name, int _sign, int _execute) : name(_name), _signed(false), sign(_sign), execute(_execute)
{
	if (this->sign < 1 || this->execute < 1)
		throw GradeTooHighException();
	if (this->sign > 150 || this->execute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), sign(other.sign), execute(other.execute)
{
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	if (this->sign < 1 || this->execute < 1)
		throw GradeTooHighException();
	if (this->sign > 150 || this->execute > 150)
		throw GradeTooLowException();
	this->_signed = other._signed;
	return (*this);
}

std::string	Form::getName()
{
	return (this->name);
}

bool	Form::getSigned()
{
	return (this->_signed);
}

int	Form::getSign()
{
	return (this->sign);
}

int	Form::getExecute()
{
	return (this->execute);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->sign)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High Exception");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low Exception");
}

std::ostream &operator<<(std::ostream& oso, Form &other)
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