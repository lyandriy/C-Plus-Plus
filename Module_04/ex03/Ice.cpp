/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:52:09 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/25 18:11:07 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

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
	std::cout << "Copy constructor Ice called" << std::endl;
	*this = other;
}

Ice	&Ice::operator=(const Ice &other)
{
	std::cout << "Copy assignment operator Ice called" << std::endl;
	this->type = other.type;
	return (*this);
}

Ice::Ice(std::string const &type)
{
	std::cout << "Constructor Ice called" << std::endl;
	this->type = type;
}

Ice*	Ice::clone() const
{
	Ice	*clon = new Ice(*this);
	return (clon);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}