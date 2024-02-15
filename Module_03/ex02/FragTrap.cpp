/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:14:59 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/15 19:51:12 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void){}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " << this->_name << " robot has been created" << std:: endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << _name << " has been destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other){
	*this = other;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	this->_name = other._name;
	this->_hP = other._hP;
	this->_eP = other._eP;
	this->_aD = other._aD;
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_hP <= 0)
		return ;
	if (this->_eP > 0)
	{
		this->_eP--;
		std::cout << "FragTrap " << this->_name << " attacks " << target
		<< " causing " << this->_aD << " points of damage!" << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "High fives Guys!!!" << std::endl;
}