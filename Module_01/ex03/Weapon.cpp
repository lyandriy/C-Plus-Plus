/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:06:47 by lyandriy          #+#    #+#             */
/*   Updated: 2024/01/31 18:54:13 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon(){}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string	&Weapon::getType(void)
{
	return (this->_type);
}
