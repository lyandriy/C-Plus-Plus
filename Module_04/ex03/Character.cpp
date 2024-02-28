/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:27:38 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/25 19:59:05 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Default constructor Character called" << std::endl;
	this->name = "Nameless";
	this->stock_mat = 0;
	this->_unequip = 0;
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->unequip_materia[i] = NULL;
}

Character::~Character()
{
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i <= this->stock_mat; i++)
		delete this->materia[i];
	for (int i = 0; i <= this->_unequip; i++)
		delete this->unequip_materia[i];
}

Character::Character(const Character &other)
{
	std::cout << "Copy constructor Character called" << std::endl;
	*this = other;
}

Character	&Character::operator=(const Character &other)
{
	std::cout << "Copy assignment operator Character called" << std::endl;
	this->name = other.name;
	for(int i = 0; i < 4; i++)
		this->materia[i] = other.materia[i];
	for(int i = 0; i < 100; i++)
		this->unequip_materia[i] = other.unequip_materia[i];
	return (*this);
}

Character::Character(std::string const& name)
{
	std::cout << "Constructor Character called" << std::endl;
	this->name = name;
	this->stock_mat = 0;
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
	if (this->stock_mat < 4)
		this->materia[this->stock_mat++] = m;
}
void	Character::unequip(int idx)
{
	if ((idx >= 0 && idx < 4) && this->materia[idx])
	{
		if (_unequip == 100)
			return ;
		this->unequip_materia[_unequip] = this->materia[idx];
		this->materia[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx < 4) && this->materia[idx])
		this->materia[idx]->use(target);
}
