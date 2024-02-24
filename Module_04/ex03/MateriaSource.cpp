/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:50:57 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/24 16:17:36 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default constructor AMateria called" << std::endl;
	this->stock_mat = 0;
}

MateriaSource::~MateriaSource()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	//this->type = other.type;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* other)
{
	if (this->stock_mat < 4)
		this->materia[this->stock_mat++] = other;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] && (materia[i]->getType() == type))
			return (materia[i]->clone());
	}
	return (NULL);
}