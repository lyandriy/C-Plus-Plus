/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:51:13 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/02 17:19:11 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

Brain::Brain(void)
{
	std::cout << "Default constructor Brain called" << std::endl;
	this->count = 0;
	for(int i = 0; i < 100; i++)
		this->ideas[i] = "No ideas";
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Copy constructor Brain called" << std::endl;
	*this = other;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Copy assignment operator Brain called" << std::endl;
	this->count = other.count;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

void	Brain::setIdeas(std::string other)
{
	this->ideas[count] = other;
	count++;
}

std::string	Brain::getIdeas(int i)
{
	return (this->ideas[i]);
}
