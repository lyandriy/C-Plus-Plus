/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:36:00 by lyandriy          #+#    #+#             */
/*   Updated: 2024/03/02 16:57:56 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *Brain_cat;
	public:
		Cat();
		~Cat();

		Cat(const Cat &other);
		Cat	&operator=(const Cat &other);

		void	set_(std::string other);
		std::string	getIdea(int i);
		void	makeSound() const;
};

#endif