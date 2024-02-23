/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:35:53 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/23 19:54:11 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

Animal::Animal(void){
	std::cout << "Default constructor Animal called" << std::endl;
	this->type = "No type";
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Animal	&Animal::operator=(const Animal &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
