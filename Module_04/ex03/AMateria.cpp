/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:23:59 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/29 17:41:31 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
	this->type = "No type";
}

AMateria::~AMateria(){}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	this->type = other.type;
	return (*this);
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

std::string const	&AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "I am " << target.getName() << std::endl;
}
