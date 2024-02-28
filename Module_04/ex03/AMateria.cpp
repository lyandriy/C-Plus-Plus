/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:23:59 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/25 19:56:44 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
	std::cout << "Default constructor AMateria called" << std::endl;
	this->type = "No type";
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "Copy constructor AMateria called" << std::endl;
	*this = other;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	std::cout << "Copy assignment operator AMateria called" << std::endl;
	this->type = other.type;
	return (*this);
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "Constructor AMateria called" << std::endl;
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