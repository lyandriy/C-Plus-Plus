/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:52:09 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/24 15:12:27 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Default constructor Ice called" << std::endl;
	this->type = "ice";
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(const Ice &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Ice	&Ice::operator=(const Ice &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

Ice::Ice(std::string const &type)
{
	std::cout << "Constructor Ice called" << std::endl;
	this->type = type;
}

std::string const	&Ice::getType() const
{
	return (this->type);
}

Ice*	Ice::clone() const
{
	Ice	*clon = new Ice(*this);
	return (clon);
}

void	Ice::use(ICharacter& target)
{
	//std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}