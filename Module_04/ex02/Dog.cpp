/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:36:03 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/23 19:03:42 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

Dog::Dog(void) : Animal(){
	std::cout << "Default constructor Dog called" << std::endl;
	this->type = "Dog";
	_dog = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete _dog;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->type = other.type;
	*this->_dog = *other._dog;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof-Woof" << std::endl;
}
