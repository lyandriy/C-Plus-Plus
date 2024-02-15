/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:14:50 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/15 19:37:12 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap " << this->_name << " robot has been created" << std:: endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << _name << " has been destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other){
	*this = other;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	this->_name = other._name;
	this->_hP = other._hP;
	this->_eP = other._eP;
	this->_aD = other._aD;
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hP <= 0)
		return ;
	if (this->_eP > 0)
	{
		this->_eP--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target
		<< " causing " << this->_aD << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}

/*void	ScavTrap::operato(void)
{
	std::cout << "_name " << this->_name << std::endl;
	std::cout << "_hP " << this->_hP << std::endl;
	std::cout << "_eP " << this->_eP << std::endl;
	std::cout << "_aD " << this->_aD << std::endl;
}*/