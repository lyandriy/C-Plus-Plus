/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:36:03 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/28 16:42:18 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Default constructor Dog called" << std::endl;
	this->type = "Dog";
	Brain_dog = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete Brain_dog;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Copy constructor Dog called" << std::endl;
	this->Brain_dog = NULL;
	*this = other;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Copy assignment operator Dog called" << std::endl;
	this->type = other.type;
	if (this->Brain_dog)
		delete this->Brain_dog;
	this->Brain_dog = new Brain(*other.Brain_dog);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof-Woof" << std::endl;
}

/*void	Dog::set_(std::string other)
{
	this->Brain_dog->setIdeas(other);
}

std::string	Dog::getIdea(int i)
{
	return (this->Brain_dog->getIdeas(i));
}*/