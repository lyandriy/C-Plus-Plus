/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:27:38 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/29 17:38:54 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	this->name = "Nameless";
	this->_unequip = 0;
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->unequip_materia[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i])
			delete this->materia[i];
	}
	for (int i = 0; i < this->_unequip; i++)
		delete this->unequip_materia[i];
}

Character::Character(const Character &other)
{
	*this = other;
}

Character	&Character::operator=(const Character &other)
{
	this->name = other.name;
	for(int i = 0; i < 4; i++)
		this->materia[i] = other.materia[i];
	for(int i = 0; i < 100; i++)
		this->unequip_materia[i] = other.unequip_materia[i];
	return (*this);
}

Character::Character(std::string const& name)
{
	this->name = name;
	this->_unequip = 0;
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->unequip_materia[i] = NULL;
}

std::string const	&Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] == NULL)
		{
			this->materia[i] = m;
			return ;
		}
	}
	std::cout << "No space to equip Materia" << std::endl;
}
void	Character::unequip(int idx)
{
	if ((idx >= 0 && idx < 4) && this->materia[idx])
	{
		if (_unequip == 100)
		{
			std::cout << "No space to unequip Materia" << std::endl;
			return ;
		}
		this->unequip_materia[_unequip++] = this->materia[idx];
		this->materia[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx < 4) && this->materia[idx])
		this->materia[idx]->use(target);
}
