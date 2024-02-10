/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:12:43 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/10 21:28:04 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
		: HitPoint(10), EnergyPoints(10), AttackDamage(0), _name(name){
	std::cout << _name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " has been destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->HitPoint = other.HitPoint;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	this->AttackDamage++;
	std::cout << "ClapTrap " << this->_name
	<< " attacks" << target << " causing" << this->AttackDamage << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{

}
