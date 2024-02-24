/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:27:38 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/24 16:24:23 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Default constructor AMateria called" << std::endl;
}

Character::~Character()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

Character::Character(const Character &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Character	&Character::operator=(const Character &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	//this->type = other.type;
	return (*this);
}

std::string const	&Character::getName() const
{
	//return (this->type);
}

void	Character::equip(AMateria* m)
{

}
void	Character::unequip(int idx)
{

}

void	Character::use(int idx, ICharacter& target)
{

}
