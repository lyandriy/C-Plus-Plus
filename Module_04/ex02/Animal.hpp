/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:35:56 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/28 19:18:06 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		virtual ~Animal();

		Animal(const Animal &other);
		Animal	&operator=(const Animal &other);

		/*virtual void	set_(std::string other) = 0;
		virtual std::string	getIdea(int i) = 0;*/
		std::string		getType(void) const;
		virtual void	makeSound() const = 0;
};

#endif