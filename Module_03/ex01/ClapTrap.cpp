/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:14:43 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/15 19:37:14 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void){}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
		: _name(name), _hP(10), _eP(10), _aD(0){
	std::cout << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int _hP_, int _eP_, int _aD_)
		: _name(name), _hP(_hP_), _eP(_eP_), _aD(_aD_){
	std::cout << _name << " has been created" << std::endl;
}

/*std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::get_hP(void) const{
	return (this->_hP);
}

int	ClapTrap::get_eP(void) const{
	return (this->_eP);
}

int	ClapTrap::get_aD(void) const{
	return (this->_aD);
}

void	ClapTrap::set_hP(int hP)
{
	this->_hP = hP;
}

void	ClapTrap::set_eP(int eP)
{
	this->_eP = eP;
}

void	ClapTrap::set_aD(int aD)
{
	this->_aD = aD;
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}*/

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hP = other._hP;
	this->_eP = other._eP;
	this->_aD = other._aD;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_eP > 0)
	{
		this->_eP--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< " causing " << this->_aD << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > 0)
	{
		this->_hP -= amount;
		std::cout << "ClapTrap " << this->_name << " lost " << amount << " Hit Point" << std::endl;
	}
	if (this->_hP <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
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
		std::cout << "ClapTrap " << this->_name << " repairs itself with "
		<< amount << " hit points" << std::endl;
	}
	else
		std::cout << "Insufficient energy point" << std::endl;
}
