/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:52:09 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/29 17:41:28 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice()
{
	this->type = "ice";
}

Ice::~Ice(){}

Ice::Ice(const Ice &other)
{
	*this = other;
}

Ice	&Ice::operator=(const Ice &other)
{
	this->type = other.type;
	return (*this);
}

Ice::Ice(std::string const &type)
{
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
