/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:52:03 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/25 18:10:59 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
	std::cout << "Default constructor Cure called" << std::endl;
	this->type = "cure";
}

Cure::~Cure()
{
	std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure(const Cure &other)
{
	std::cout << "Copy constructor Cure called" << std::endl;
	*this = other;
}

Cure	&Cure::operator=(const Cure &other)
{
	std::cout << "Copy assignment operator Cure called" << std::endl;
	this->type = other.type;
	return (*this);
}

Cure::Cure(std::string const &type)
{
	std::cout << "Constructor Cure called" << std::endl;
	this->type = type;
}

Cure	*Cure::clone() const
{
	Cure	*clon = new Cure(*this);
	return (clon);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}