/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:35:58 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/28 16:42:09 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Default constructor Cat called" << std::endl;
	this->type = "Cat";
	this->Brain_cat = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete Brain_cat;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Copy constructor Cat called" << std::endl;
	this->Brain_cat = NULL;
	*this = other;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Copy assignment operator Cat called" << std::endl;
	this->type = other.type;
	if (this->Brain_cat)
		delete this->Brain_cat;
	this->Brain_cat = new Brain(*other.Brain_cat);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

/*void	Cat::set_(std::string other)
{
	this->Brain_cat->setIdeas(other);
}

std::string	Cat::getIdea(int i)
{
	return (this->Brain_cat->getIdeas(i));
}*/