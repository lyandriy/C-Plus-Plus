/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:36:05 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/02 16:57:51 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *Brain_dog;
	public:
		Dog();
		~Dog();

		Dog(const Dog &other);
		Dog	&operator=(const Dog &other);

		void	set_(std::string other);
		std::string	getIdea(int i);
		void	makeSound() const;
};

#endif