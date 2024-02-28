/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:50:57 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/25 19:56:27 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default constructor MateriaSource called" << std::endl;
	this->stock_mat = 0;
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i <= this->stock_mat; i++)
		delete materia[i];
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "Copy constructor MateriaSource called" << std::endl;
	*this = other;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "Copy assignment operator MateriaSource called" << std::endl;
	for(int i = 0; i < 4; i++)
		this->materia[i] = other.materia[i];
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* other)
{
	if (other && this->stock_mat < 4)
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