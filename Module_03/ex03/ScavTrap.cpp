/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:14:50 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/23 17:40:59 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*---DEFAULT CONSTRUCTOR/DESTRUCTOR---*/

ScavTrap::ScavTrap(void) : ClapTrap("Nameless"){
	std::cout << "Default constructor ScavTrap called" << std::endl;
	this->_hP = 100;
	this->_eP = 50;
	this->_aD = 20;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor called" << std::endl;
}

/*---COPY CONSTRUCTOR/ASSIGNMENT OPERATOR---*/

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hP = other._hP;
	this->_eP = other._eP;
	this->_aD = other._aD;
	return (*this);
}

/*---CONSTRUCTORS---*/

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->_name << " robot has been created" << std:: endl;
	this->_hP = 100;
	this->_eP = 50;
	this->_aD = 20;
}

/*---METHODS---*/

void ScavTrap::attack(const std::string& target)
{
	if (this->_eP > 0 && this->_hP > 0)
	{
		this->_eP--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target
		<< " causing " << this->_aD << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is not available." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
