/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:35:58 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/21 09:33:30 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	std::cout << "Default constructor Cat called" << std::endl;
	this->type = "Cat";
	_cat = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete _cat;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
