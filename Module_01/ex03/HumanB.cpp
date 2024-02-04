/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:06:52 by lyandriy          #+#    #+#             */
/*   Updated: 2024/01/31 19:12:06 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name){}

HumanB::~HumanB(){}

void	HumanB::setWeapon(Weapon &weaponB)
{
	this->_WeaponB = &weaponB;
}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << this->_WeaponB->getType() << std::endl;
}
