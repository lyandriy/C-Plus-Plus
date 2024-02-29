/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:52:03 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/29 17:44:10 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::~Cure(){}

Cure::Cure(const Cure &other)
{
	*this = other;
}

Cure	&Cure::operator=(const Cure &other)
{
	this->type = other.type;
	return (*this);
}

Cure::Cure(std::string const &type)
{
	this->type = type;
}

Cure	*Cure::clone() const
{
	Cure	*clon = new Cure(*this);
	return (clon);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
