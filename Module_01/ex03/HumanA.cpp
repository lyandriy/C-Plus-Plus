/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:06:57 by lyandriy          #+#    #+#             */
/*   Updated: 2024/01/31 18:22:05 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &_weaponA) : _name(name), _WeaponA(_weaponA){}

HumanA::~HumanA(){}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_WeaponA.getType() << std::endl;
}
