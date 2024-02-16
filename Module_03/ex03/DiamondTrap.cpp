/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:15:16 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/16 19:59:09 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*---DEFAULT CONSTRUCTOR/DESTRUCTOR---*/

DiamondTrap::DiamondTrap(void){
	std::cout << "Default constructor DiamondTrap called" << std::endl;
}

DiamondTrap::~DiamondTrap(void){
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

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),  DiamName(name)
{
	std::cout << "DiamondTrap " << this->DiamName << " monster has been created" << std::endl;
	this->_hP = 100;
	this->_eP = 50;
	this->_aD = 30;
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
