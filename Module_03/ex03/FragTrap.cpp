/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:14:59 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/16 20:24:36 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*---DEFAULT CONSTRUCTOR/DESTRUCTOR---*/

FragTrap::FragTrap(void){
	std::cout << "Default constructor FragTrap called" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor called" << std::endl;
}

/*---COPY CONSTRUCTOR/ASSIGNMENT OPERATOR---*/

FragTrap::FragTrap(const FragTrap &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hP = other._hP;
	this->_eP = other._eP;
	this->_aD = other._aD;
	return (*this);
}

/*---CONSTRUCTORS---*/

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " << this->_name << " robot has been created" << std:: endl;
}

/*---METHODS---*/

void	FragTrap::attack(const std::string& target)
{
	if (this->_eP > 0 && this->_hP > 0)
	{
		this->_eP--;
		std::cout << "FragTrap " << this->_name << " attacks " << target
		<< " causing " << this->_aD << " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->_name << " is not available." << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "High fives Guys!!!" << std::endl;
}
