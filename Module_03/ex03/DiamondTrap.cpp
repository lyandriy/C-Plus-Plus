/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:15:16 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/23 19:26:34 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*---DEFAULT CONSTRUCTOR/DESTRUCTOR---*/

DiamondTrap::DiamondTrap(void) : ClapTrap()
{
	std::cout << "Default constructor DiamondTrap called" << std::endl;
	this->DiamName = "Nameless";
	this->ClapTrap::_name.append("_clap_name");
	this->_hP = FragTrap::_hP;
	this->_eP = 50;//ScavTrap::_eP;
	this->_aD = FragTrap::_aD;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

/*---COPY CONSTRUCTOR/ASSIGNMENT OPERATOR---*/

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hP = other._hP;
	this->_eP = other._eP;
	this->_aD = other._aD;
	return (*this);
}

/*---CONSTRUCTORS---*/

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), DiamName(name)
{
	std::cout << "DiamondTrap " << this->DiamName << " monster has been created" << std::endl;
	this->_hP = FragTrap::_hP;
	this->_eP = 50;//ScavTrap::_eP;
	this->_aD = FragTrap::_aD;
}

/*---METHODS---*/

void	DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << this->DiamName << std::endl;
	std::cout << "ClapTrap name is " << this->ClapTrap::_name << std::endl;
}
