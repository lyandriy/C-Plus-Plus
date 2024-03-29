/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:14:43 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/23 17:33:34 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*---DEFAULT CONSTRUCTOR/DESTRUCTOR---*/
ClapTrap::ClapTrap(void) : _name("Nameless"), _hP(10), _eP(10), _aD(0){
	std::cout << "Default constructor ClapTrap called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}
/*---COPY CONSTRUCTOR/ASSIGNMENT OPERATOR---*/

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hP = other._hP;
	this->_eP = other._eP;
	this->_aD = other._aD;
	return (*this);
}

/*---CONSTRUCTORS---*/

ClapTrap::ClapTrap(std::string name)
		: _name(name), _hP(10), _eP(10), _aD(0){
	std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

/*---METHODS---*/

void ClapTrap::attack(const std::string& target)
{
	if (this->_eP > 0 && this->_hP > 0)
	{
		this->_eP--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< " causing " << this->_aD << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is not available." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > 0 && this->_hP > 0)
	{
		if (this->_hP > amount)
		{
			this->_hP -= amount;
			std::cout << "ClapTrap " << this->_name << " lost " << amount << " Hit Point" << std::endl;
		}
		else
			this->_hP = 0;
	}
	if (this->_hP <= 0)
		std::cout << "ClapTrap " << this->_name << " is not available." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_eP <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have energy points" << std::endl;
		return ;
	}
	if ((this->_eP - amount) >= 0)
	{
		this->_hP += amount;
		this->_eP -= amount;
		std::cout << "ClapTrap " << this->_name << " repairs itself with " << amount << " hit points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " doesnt have enough energy point" << std::endl;
}
