/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:51:13 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/21 09:53:54 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

Brain::Brain(void){
	std::cout << "Default constructor Brain called" << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}