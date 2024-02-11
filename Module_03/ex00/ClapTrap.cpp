/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:12:43 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/11 19:24:31 by lyandriy         ###   ########.fr       */
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

void ClapTrap::attack(const std::string& target)//atacar
{
	if (EnergyPoints > 0)
	{
		this->EnergyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< " causing " << this->AttackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)//recibir el ataque
{
	if (amount > 0)
	{
		this->HitPoint -= amount;
		std::cout << this->_name << " lost " << amount << " Hit Point" << std::endl;
	}
	if (this->HitPoint <= 0)
		std::cout << this->_name << " is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)//repararse
{
	if (amount > 0 && )
	{
		if (this->EnergyPoints > 0 && this->HitPoint < 10 && )
		this->HitPoint += amount;
		this->EnergyPoints -= amount;
	}
}
